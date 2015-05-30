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
#ifndef TARGET_FLASH_H
#define TARGET_FLASH_H

#include "target_struct.h"
#include "swd_host.h"
#include <stdint.h>

//#define FLASH_SECTOR_SIZE           (512)  /* 512 is assuming that this value is in number of uint32_t's */

//#define TARGET_AUTO_INCREMENT_PAGE_SIZE    (0x1000)

static const uint32_t W7500x_FLM[] = {
    0xE00ABE00, 0x062D780D, 0x24084068, 0xD3000040, 0x1E644058, 0x1C49D1FA, 0x2A001E52, 0x4770D1F2,
    0x4c11b430, 0xbc3046a4, 0x20004760, 0x20004770, 0x23004770, 0x461ab510, 0x20144619, 0xfff0f7ff, 
    0xbd102000, 0x2300b510, 0x461a4601, 0xf7ff2012, 0x2000ffe7, 0x460bbd10, 0x4601b510, 0xf7ff2022, 
    0x2000ffdf, 0x0000bd10, 0x1fff1001, 0x00000000, 
};



static const TARGET_FLASH flash = {
    0x2000002B, // Init
    0x2000002F, // UnInit
    0x20000033, // EraseChip
    0x20000045, // EraseSector
    0x20000057, // ProgramPage
    
    // RSB : base address is address of Execution Region PrgData in map file
    //       to access global/static data
    // RSP : Initial stack pointer
    {
        0x20000001,
        0x20000000 + 0x20 + 0x4c,
        0x20004000
    }, // {breakpoint, RSB, RSP}

    0x20001000, // program_buffer
    0x20000000, // algo_start
    sizeof(W7500x_FLM), // algo_size
    W7500x_FLM, // image

    256          // ram_to_flash_bytes_to_be_written
};

#endif
