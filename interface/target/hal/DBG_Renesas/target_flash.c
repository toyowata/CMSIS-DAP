/* CMSIS-DAP Interface Firmware
 * Copyright (c) 2009-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "target_flash.h"
#include "target_config.h"
#include "swd_host.h"
#include "flash_blob.h"
#include "target_reset.h"
#include "DAP_config.h"
#include "string.h"


uint8_t validate_bin_nvic(uint8_t *buf)
{
	// Very dirty hacking here for ARMv7-A (non Cortex-M) binary detection
	//
	// This returns validated result when start instrunction
	// of the buffer is 0xE59FF0** (LDR  PC, Label)
	
	if (buf[1] == 0xF0 && buf[2] == 0x9F && buf[3] == 0xE5)
		return 1;
	else
		return 0;
	
}

uint8_t validate_hexfile(uint8_t *buf)
{
    return 0;
}

target_flash_status_t target_flash_init(extension_t ext)
{
    PORT_SWD_SETUP();
    if (!target_set_state(RESET_PROGRAM)) {
        return TARGET_FAIL_RESET;
    }

    // Download flash programming algorithm to target and initialise.
    if (!swd_write_memory(flash.algo_start, (uint8_t *)flash.image, flash.algo_size)) {
        return TARGET_FAIL_ALGO_DL;
    }

    if (!swd_flash_syscall_exec(&flash.sys_call_param, flash.init, 0, 0 /* clk value is not used */, 0, 0)) {
        return TARGET_FAIL_INIT;
    }

    return TARGET_OK;
}

target_flash_status_t target_flash_erase_sector(unsigned int sector)
{
    if (!swd_flash_syscall_exec(&flash.sys_call_param, flash.erase_sector, sector, 0, 0, 0)) {
        return TARGET_FAIL_ERASE_SECTOR;
    }
    return TARGET_OK;
}

target_flash_status_t target_flash_erase_chip(void)
{
    if (!swd_flash_syscall_exec(&flash.sys_call_param, flash.erase_chip, 0, 0, 0, 0)) {
        return TARGET_FAIL_ERASE_ALL;
    }

    return TARGET_OK;
}

target_flash_status_t target_flash_program_page(uint32_t addr, uint8_t * buf, uint32_t size)
{
    uint32_t bytes_written = 0;
    target_flash_status_t status = TARGET_OK;
    // we need to erase a sector
    if (addr % target_device.sector_size == 0) {
        status = target_flash_erase_sector(addr / target_device.sector_size);
        if (status != TARGET_OK) {
            return status;
        }
    }

    // Program a page in target flash.
    if (!swd_write_memory(flash.program_buffer, buf, size)) {
        return TARGET_FAIL_ALGO_DATA_SEQ;
    }

    while(bytes_written < size) {
        if (!swd_flash_syscall_exec(&flash.sys_call_param,
                                    flash.program_page,
                                    addr,
                                    flash.ram_to_flash_bytes_to_be_written,
                                    flash.program_buffer + bytes_written, 0)) {
            return TARGET_FAIL_WRITE;
        }

        bytes_written += flash.ram_to_flash_bytes_to_be_written;
        addr += flash.ram_to_flash_bytes_to_be_written;
    }

    return TARGET_OK;
}
