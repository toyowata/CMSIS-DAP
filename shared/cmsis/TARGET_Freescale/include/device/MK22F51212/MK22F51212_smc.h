/*
 * Copyright (c) 2014, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL FREESCALE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 */
/*
 * WARNING! DO NOT EDIT THIS FILE DIRECTLY!
 *
 * This file was generated automatically and any changes may be lost.
 */
#ifndef __HW_SMC_REGISTERS_H__
#define __HW_SMC_REGISTERS_H__

#include "regs.h"

/*
 * MK22F51212 SMC
 *
 * System Mode Controller
 *
 * Registers defined in this header file:
 * - HW_SMC_PMPROT - Power Mode Protection register
 * - HW_SMC_PMCTRL - Power Mode Control register
 * - HW_SMC_STOPCTRL - Stop Control Register
 * - HW_SMC_PMSTAT - Power Mode Status register
 *
 * - hw_smc_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_SMC_BASE
#define HW_SMC_INSTANCE_COUNT (1U) //!< Number of instances of the SMC module.
#define REGS_SMC_BASE (0x4007E000U) //!< Base address for SMC.
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_SMC_PMPROT - Power Mode Protection register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SMC_PMPROT - Power Mode Protection register (RW)
 *
 * Reset value: 0x00U
 *
 * This register provides protection for entry into any low-power run or stop
 * mode. The enabling of the low-power run or stop mode occurs by configuring the
 * Power Mode Control register (PMCTRL). The PMPROT register can be written only
 * once after any system reset. If the MCU is configured for a disallowed or
 * reserved power mode, the MCU remains in its current power mode. For example, if the
 * MCU is in normal RUN mode and AVLP is 0, an attempt to enter VLPR mode using
 * PMCTRL[RUNM] is blocked and PMCTRL[RUNM] remains 00b, indicating the MCU is
 * still in Normal Run mode. This register is reset on Chip Reset not VLLS and by
 * reset types that trigger Chip Reset not VLLS. It is unaffected by reset types
 * that do not trigger Chip Reset not VLLS. See the Reset section details for more
 * information.
 */
typedef union _hw_smc_pmprot
{
    uint8_t U;
    struct _hw_smc_pmprot_bitfields
    {
        uint8_t RESERVED0 : 1;         //!< [0]
        uint8_t AVLLS : 1;             //!< [1] Allow Very-Low-Leakage Stop Mode
        uint8_t RESERVED1 : 1;         //!< [2]
        uint8_t ALLS : 1;              //!< [3] Allow Low-Leakage Stop Mode
        uint8_t RESERVED2 : 1;         //!< [4]
        uint8_t AVLP : 1;              //!< [5] Allow Very-Low-Power Modes
        uint8_t RESERVED3 : 1;         //!< [6]
        uint8_t AHSRUN : 1;            //!< [7] Allow High Speed Run mode
    } B;
} hw_smc_pmprot_t;
#endif

/*!
 * @name Constants and macros for entire SMC_PMPROT register
 */
//@{
#define HW_SMC_PMPROT_ADDR       (REGS_SMC_BASE + 0x0U)

#ifndef __LANGUAGE_ASM__
#define HW_SMC_PMPROT            (*(__IO hw_smc_pmprot_t *) HW_SMC_PMPROT_ADDR)
#define HW_SMC_PMPROT_RD()       (HW_SMC_PMPROT.U)
#define HW_SMC_PMPROT_WR(v)      (HW_SMC_PMPROT.U = (v))
#define HW_SMC_PMPROT_SET(v)     (HW_SMC_PMPROT_WR(HW_SMC_PMPROT_RD() |  (v)))
#define HW_SMC_PMPROT_CLR(v)     (HW_SMC_PMPROT_WR(HW_SMC_PMPROT_RD() & ~(v)))
#define HW_SMC_PMPROT_TOG(v)     (HW_SMC_PMPROT_WR(HW_SMC_PMPROT_RD() ^  (v)))
#endif
//@}

/*
 * Constants & macros for individual SMC_PMPROT bitfields
 */

/*!
 * @name Register SMC_PMPROT, field AVLLS[1] (RW)
 *
 * Provided the appropriate control bits are set up in PMCTRL, this write once
 * bit allows the MCU to enter any very-low-leakage stop mode (VLLSx).
 *
 * Values:
 * - 0 - Any VLLSx mode is not allowed
 * - 1 - Any VLLSx mode is allowed
 */
//@{
#define BP_SMC_PMPROT_AVLLS  (1U)          //!< Bit position for SMC_PMPROT_AVLLS.
#define BM_SMC_PMPROT_AVLLS  (0x02U)       //!< Bit mask for SMC_PMPROT_AVLLS.
#define BS_SMC_PMPROT_AVLLS  (1U)          //!< Bit field size in bits for SMC_PMPROT_AVLLS.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the SMC_PMPROT_AVLLS field.
#define BR_SMC_PMPROT_AVLLS  (BITBAND_ACCESS8(HW_SMC_PMPROT_ADDR, BP_SMC_PMPROT_AVLLS))
#endif

//! @brief Format value for bitfield SMC_PMPROT_AVLLS.
#define BF_SMC_PMPROT_AVLLS(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_SMC_PMPROT_AVLLS), uint8_t) & BM_SMC_PMPROT_AVLLS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AVLLS field to a new value.
#define BW_SMC_PMPROT_AVLLS(v) (BITBAND_ACCESS8(HW_SMC_PMPROT_ADDR, BP_SMC_PMPROT_AVLLS) = (v))
#endif
//@}

/*!
 * @name Register SMC_PMPROT, field ALLS[3] (RW)
 *
 * Provided the appropriate control bits are set up in PMCTRL, this write-once
 * field allows the MCU to enter any low-leakage stop mode (LLS).
 *
 * Values:
 * - 0 - Any LLSx mode is not allowed
 * - 1 - Any LLSx mode is allowed
 */
//@{
#define BP_SMC_PMPROT_ALLS   (3U)          //!< Bit position for SMC_PMPROT_ALLS.
#define BM_SMC_PMPROT_ALLS   (0x08U)       //!< Bit mask for SMC_PMPROT_ALLS.
#define BS_SMC_PMPROT_ALLS   (1U)          //!< Bit field size in bits for SMC_PMPROT_ALLS.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the SMC_PMPROT_ALLS field.
#define BR_SMC_PMPROT_ALLS   (BITBAND_ACCESS8(HW_SMC_PMPROT_ADDR, BP_SMC_PMPROT_ALLS))
#endif

//! @brief Format value for bitfield SMC_PMPROT_ALLS.
#define BF_SMC_PMPROT_ALLS(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_SMC_PMPROT_ALLS), uint8_t) & BM_SMC_PMPROT_ALLS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ALLS field to a new value.
#define BW_SMC_PMPROT_ALLS(v) (BITBAND_ACCESS8(HW_SMC_PMPROT_ADDR, BP_SMC_PMPROT_ALLS) = (v))
#endif
//@}

/*!
 * @name Register SMC_PMPROT, field AVLP[5] (RW)
 *
 * Provided the appropriate control bits are set up in PMCTRL, this write-once
 * field allows the MCU to enter any very-low-power mode (VLPR, VLPW, and VLPS).
 *
 * Values:
 * - 0 - VLPR, VLPW, and VLPS are not allowed.
 * - 1 - VLPR, VLPW, and VLPS are allowed.
 */
//@{
#define BP_SMC_PMPROT_AVLP   (5U)          //!< Bit position for SMC_PMPROT_AVLP.
#define BM_SMC_PMPROT_AVLP   (0x20U)       //!< Bit mask for SMC_PMPROT_AVLP.
#define BS_SMC_PMPROT_AVLP   (1U)          //!< Bit field size in bits for SMC_PMPROT_AVLP.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the SMC_PMPROT_AVLP field.
#define BR_SMC_PMPROT_AVLP   (BITBAND_ACCESS8(HW_SMC_PMPROT_ADDR, BP_SMC_PMPROT_AVLP))
#endif

//! @brief Format value for bitfield SMC_PMPROT_AVLP.
#define BF_SMC_PMPROT_AVLP(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_SMC_PMPROT_AVLP), uint8_t) & BM_SMC_PMPROT_AVLP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AVLP field to a new value.
#define BW_SMC_PMPROT_AVLP(v) (BITBAND_ACCESS8(HW_SMC_PMPROT_ADDR, BP_SMC_PMPROT_AVLP) = (v))
#endif
//@}

/*!
 * @name Register SMC_PMPROT, field AHSRUN[7] (RW)
 *
 * Provided the appropriate control bits are set up in PMCTRL, this write-once
 * field allows the MCU to enter High Speed Run mode (HSRUN).
 *
 * Values:
 * - 0 - HSRUN is not allowed
 * - 1 - HSRUN is allowed
 */
//@{
#define BP_SMC_PMPROT_AHSRUN (7U)          //!< Bit position for SMC_PMPROT_AHSRUN.
#define BM_SMC_PMPROT_AHSRUN (0x80U)       //!< Bit mask for SMC_PMPROT_AHSRUN.
#define BS_SMC_PMPROT_AHSRUN (1U)          //!< Bit field size in bits for SMC_PMPROT_AHSRUN.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the SMC_PMPROT_AHSRUN field.
#define BR_SMC_PMPROT_AHSRUN (BITBAND_ACCESS8(HW_SMC_PMPROT_ADDR, BP_SMC_PMPROT_AHSRUN))
#endif

//! @brief Format value for bitfield SMC_PMPROT_AHSRUN.
#define BF_SMC_PMPROT_AHSRUN(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_SMC_PMPROT_AHSRUN), uint8_t) & BM_SMC_PMPROT_AHSRUN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AHSRUN field to a new value.
#define BW_SMC_PMPROT_AHSRUN(v) (BITBAND_ACCESS8(HW_SMC_PMPROT_ADDR, BP_SMC_PMPROT_AHSRUN) = (v))
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_SMC_PMCTRL - Power Mode Control register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SMC_PMCTRL - Power Mode Control register (RW)
 *
 * Reset value: 0x00U
 *
 * The PMCTRL register controls entry into low-power Run and Stop modes,
 * provided that the selected power mode is allowed via an appropriate setting of the
 * protection (PMPROT) register. This register is reset on Chip POR not VLLS and by
 * reset types that trigger Chip POR not VLLS. It is unaffected by reset types
 * that do not trigger Chip POR not VLLS. See the Reset section details for more
 * information.
 */
typedef union _hw_smc_pmctrl
{
    uint8_t U;
    struct _hw_smc_pmctrl_bitfields
    {
        uint8_t STOPM : 3;             //!< [2:0] Stop Mode Control
        uint8_t STOPA : 1;             //!< [3] Stop Aborted
        uint8_t RESERVED0 : 1;         //!< [4]
        uint8_t RUNM : 2;              //!< [6:5] Run Mode Control
        uint8_t RESERVED1 : 1;         //!< [7] Reserved.
    } B;
} hw_smc_pmctrl_t;
#endif

/*!
 * @name Constants and macros for entire SMC_PMCTRL register
 */
//@{
#define HW_SMC_PMCTRL_ADDR       (REGS_SMC_BASE + 0x1U)

#ifndef __LANGUAGE_ASM__
#define HW_SMC_PMCTRL            (*(__IO hw_smc_pmctrl_t *) HW_SMC_PMCTRL_ADDR)
#define HW_SMC_PMCTRL_RD()       (HW_SMC_PMCTRL.U)
#define HW_SMC_PMCTRL_WR(v)      (HW_SMC_PMCTRL.U = (v))
#define HW_SMC_PMCTRL_SET(v)     (HW_SMC_PMCTRL_WR(HW_SMC_PMCTRL_RD() |  (v)))
#define HW_SMC_PMCTRL_CLR(v)     (HW_SMC_PMCTRL_WR(HW_SMC_PMCTRL_RD() & ~(v)))
#define HW_SMC_PMCTRL_TOG(v)     (HW_SMC_PMCTRL_WR(HW_SMC_PMCTRL_RD() ^  (v)))
#endif
//@}

/*
 * Constants & macros for individual SMC_PMCTRL bitfields
 */

/*!
 * @name Register SMC_PMCTRL, field STOPM[2:0] (RW)
 *
 * When written, controls entry into the selected stop mode when Sleep-Now or
 * Sleep-On-Exit mode is entered with SLEEPDEEP=1 . Writes to this field are
 * blocked if the protection level has not been enabled using the PMPROT register.
 * After any system reset, this field is cleared by hardware on any successful write
 * to the PMPROT register. When set to VLLSxor LLSx, the LLSM in the STOPCTRL
 * register is used to further select the particular VLLSor LLS submode which will
 * be entered. When set to STOP, the PSTOPO bits in the STOPCTRL register can be
 * used to select a Partial Stop mode if desired.
 *
 * Values:
 * - 000 - Normal Stop (STOP)
 * - 001 - Reserved
 * - 010 - Very-Low-Power Stop (VLPS)
 * - 011 - Low-Leakage Stop (LLSx)
 * - 100 - Very-Low-Leakage Stop (VLLSx)
 * - 101 - Reserved
 * - 110 - Reseved
 * - 111 - Reserved
 */
//@{
#define BP_SMC_PMCTRL_STOPM  (0U)          //!< Bit position for SMC_PMCTRL_STOPM.
#define BM_SMC_PMCTRL_STOPM  (0x07U)       //!< Bit mask for SMC_PMCTRL_STOPM.
#define BS_SMC_PMCTRL_STOPM  (3U)          //!< Bit field size in bits for SMC_PMCTRL_STOPM.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the SMC_PMCTRL_STOPM field.
#define BR_SMC_PMCTRL_STOPM  (HW_SMC_PMCTRL.B.STOPM)
#endif

//! @brief Format value for bitfield SMC_PMCTRL_STOPM.
#define BF_SMC_PMCTRL_STOPM(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_SMC_PMCTRL_STOPM), uint8_t) & BM_SMC_PMCTRL_STOPM)

#ifndef __LANGUAGE_ASM__
//! @brief Set the STOPM field to a new value.
#define BW_SMC_PMCTRL_STOPM(v) (HW_SMC_PMCTRL_WR((HW_SMC_PMCTRL_RD() & ~BM_SMC_PMCTRL_STOPM) | BF_SMC_PMCTRL_STOPM(v)))
#endif
//@}

/*!
 * @name Register SMC_PMCTRL, field STOPA[3] (RO)
 *
 * When set, this read-only status bit indicates an interrupt occured during the
 * previous stop mode entry sequence, preventing the system from entering that
 * mode. This field is cleared by reset or by hardware at the beginning of any
 * stop mode entry sequence and is set if the sequence was aborted.
 *
 * Values:
 * - 0 - The previous stop mode entry was successsful.
 * - 1 - The previous stop mode entry was aborted.
 */
//@{
#define BP_SMC_PMCTRL_STOPA  (3U)          //!< Bit position for SMC_PMCTRL_STOPA.
#define BM_SMC_PMCTRL_STOPA  (0x08U)       //!< Bit mask for SMC_PMCTRL_STOPA.
#define BS_SMC_PMCTRL_STOPA  (1U)          //!< Bit field size in bits for SMC_PMCTRL_STOPA.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the SMC_PMCTRL_STOPA field.
#define BR_SMC_PMCTRL_STOPA  (BITBAND_ACCESS8(HW_SMC_PMCTRL_ADDR, BP_SMC_PMCTRL_STOPA))
#endif
//@}

/*!
 * @name Register SMC_PMCTRL, field RUNM[6:5] (RW)
 *
 * When written, causes entry into the selected run mode. Writes to this field
 * are blocked if the protection level has not been enabled using the PMPROT
 * register. This field is cleared by hardware on any exit to normal RUN mode. RUNM
 * may be set to VLPR only when PMSTAT=RUN. After being written to VLPR, RUNM
 * should not be written back to RUN until PMSTAT=VLPR. RUNM may be set to HSRUN only
 * when PMSTAT=RUN. After being programmed to HSRUN, RUNM should not be
 * programmed back to RUN until PMSTAT=HSRUN. Also, stop mode entry should not be
 * attempted while RUNM=HSRUN or PMSTAT=HSRUN.
 *
 * Values:
 * - 00 - Normal Run mode (RUN)
 * - 01 - Reserved
 * - 10 - Very-Low-Power Run mode (VLPR)
 * - 11 - High Speed Run mode (HSRUN)
 */
//@{
#define BP_SMC_PMCTRL_RUNM   (5U)          //!< Bit position for SMC_PMCTRL_RUNM.
#define BM_SMC_PMCTRL_RUNM   (0x60U)       //!< Bit mask for SMC_PMCTRL_RUNM.
#define BS_SMC_PMCTRL_RUNM   (2U)          //!< Bit field size in bits for SMC_PMCTRL_RUNM.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the SMC_PMCTRL_RUNM field.
#define BR_SMC_PMCTRL_RUNM   (HW_SMC_PMCTRL.B.RUNM)
#endif

//! @brief Format value for bitfield SMC_PMCTRL_RUNM.
#define BF_SMC_PMCTRL_RUNM(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_SMC_PMCTRL_RUNM), uint8_t) & BM_SMC_PMCTRL_RUNM)

#ifndef __LANGUAGE_ASM__
//! @brief Set the RUNM field to a new value.
#define BW_SMC_PMCTRL_RUNM(v) (HW_SMC_PMCTRL_WR((HW_SMC_PMCTRL_RD() & ~BM_SMC_PMCTRL_RUNM) | BF_SMC_PMCTRL_RUNM(v)))
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_SMC_STOPCTRL - Stop Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SMC_STOPCTRL - Stop Control Register (RW)
 *
 * Reset value: 0x03U
 *
 * The STOPCTRL register provides various control bits allowing the user to fine
 * tune power consumption during the stop mode selected by the STOPM field. This
 * register is reset on Chip POR not VLLS and by reset types that trigger Chip
 * POR not VLLS. It is unaffected by reset types that do not trigger Chip POR not
 * VLLS. See the Reset section details for more information.
 */
typedef union _hw_smc_stopctrl
{
    uint8_t U;
    struct _hw_smc_stopctrl_bitfields
    {
        uint8_t LLSM : 3;              //!< [2:0] LLS or VLLS Mode Control
        uint8_t LPOPO : 1;             //!< [3] LPO Power Option
        uint8_t RESERVED0 : 1;         //!< [4]
        uint8_t PORPO : 1;             //!< [5] POR Power Option
        uint8_t PSTOPO : 2;            //!< [7:6] Partial Stop Option
    } B;
} hw_smc_stopctrl_t;
#endif

/*!
 * @name Constants and macros for entire SMC_STOPCTRL register
 */
//@{
#define HW_SMC_STOPCTRL_ADDR     (REGS_SMC_BASE + 0x2U)

#ifndef __LANGUAGE_ASM__
#define HW_SMC_STOPCTRL          (*(__IO hw_smc_stopctrl_t *) HW_SMC_STOPCTRL_ADDR)
#define HW_SMC_STOPCTRL_RD()     (HW_SMC_STOPCTRL.U)
#define HW_SMC_STOPCTRL_WR(v)    (HW_SMC_STOPCTRL.U = (v))
#define HW_SMC_STOPCTRL_SET(v)   (HW_SMC_STOPCTRL_WR(HW_SMC_STOPCTRL_RD() |  (v)))
#define HW_SMC_STOPCTRL_CLR(v)   (HW_SMC_STOPCTRL_WR(HW_SMC_STOPCTRL_RD() & ~(v)))
#define HW_SMC_STOPCTRL_TOG(v)   (HW_SMC_STOPCTRL_WR(HW_SMC_STOPCTRL_RD() ^  (v)))
#endif
//@}

/*
 * Constants & macros for individual SMC_STOPCTRL bitfields
 */

/*!
 * @name Register SMC_STOPCTRL, field LLSM[2:0] (RW)
 *
 * This field controls which LLS or VLLS sub-mode to enter if STOPM=LLSx or
 * VLLSx.
 *
 * Values:
 * - 000 - VLLS0 if PMCTRL[STOPM]=VLLSx, LLS2 if PMCTRL[STOPM]=LLSx
 * - 001 - VLLS1 if PMCTRL[STOPM]=VLLSx, LLS2 if PMCTRL[STOPM]=LLSx
 * - 010 - VLLS2 if PMCTRL[STOPM]=VLLSx, LLS2 if PMCTRL[STOPM]=LLSx
 * - 011 - VLLS3 if PMCTRL[STOPM]=VLLSx, LLS3 if PMCTRL[STOPM]=LLSx
 * - 100 - Reserved
 * - 101 - Reserved
 * - 110 - Reserved
 * - 111 - Reserved
 */
//@{
#define BP_SMC_STOPCTRL_LLSM (0U)          //!< Bit position for SMC_STOPCTRL_LLSM.
#define BM_SMC_STOPCTRL_LLSM (0x07U)       //!< Bit mask for SMC_STOPCTRL_LLSM.
#define BS_SMC_STOPCTRL_LLSM (3U)          //!< Bit field size in bits for SMC_STOPCTRL_LLSM.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the SMC_STOPCTRL_LLSM field.
#define BR_SMC_STOPCTRL_LLSM (HW_SMC_STOPCTRL.B.LLSM)
#endif

//! @brief Format value for bitfield SMC_STOPCTRL_LLSM.
#define BF_SMC_STOPCTRL_LLSM(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_SMC_STOPCTRL_LLSM), uint8_t) & BM_SMC_STOPCTRL_LLSM)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LLSM field to a new value.
#define BW_SMC_STOPCTRL_LLSM(v) (HW_SMC_STOPCTRL_WR((HW_SMC_STOPCTRL_RD() & ~BM_SMC_STOPCTRL_LLSM) | BF_SMC_STOPCTRL_LLSM(v)))
#endif
//@}

/*!
 * @name Register SMC_STOPCTRL, field LPOPO[3] (RW)
 *
 * Controls whether the 1kHZ LPO clock is enabled in LLS/VLLSx modes. During
 * VLLS0 mode, the LPO clock is disabled by hardware and this bit has no effect.
 *
 * Values:
 * - 0 - LPO clock is enabled in LLS/VLLSx
 * - 1 - LPO clock is disabled in LLS/VLLSx
 */
//@{
#define BP_SMC_STOPCTRL_LPOPO (3U)         //!< Bit position for SMC_STOPCTRL_LPOPO.
#define BM_SMC_STOPCTRL_LPOPO (0x08U)      //!< Bit mask for SMC_STOPCTRL_LPOPO.
#define BS_SMC_STOPCTRL_LPOPO (1U)         //!< Bit field size in bits for SMC_STOPCTRL_LPOPO.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the SMC_STOPCTRL_LPOPO field.
#define BR_SMC_STOPCTRL_LPOPO (BITBAND_ACCESS8(HW_SMC_STOPCTRL_ADDR, BP_SMC_STOPCTRL_LPOPO))
#endif

//! @brief Format value for bitfield SMC_STOPCTRL_LPOPO.
#define BF_SMC_STOPCTRL_LPOPO(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_SMC_STOPCTRL_LPOPO), uint8_t) & BM_SMC_STOPCTRL_LPOPO)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LPOPO field to a new value.
#define BW_SMC_STOPCTRL_LPOPO(v) (BITBAND_ACCESS8(HW_SMC_STOPCTRL_ADDR, BP_SMC_STOPCTRL_LPOPO) = (v))
#endif
//@}

/*!
 * @name Register SMC_STOPCTRL, field PORPO[5] (RW)
 *
 * This bit controls whether the POR detect circuit is enabled in VLLS0 mode.
 *
 * Values:
 * - 0 - POR detect circuit is enabled in VLLS0
 * - 1 - POR detect circuit is disabled in VLLS0
 */
//@{
#define BP_SMC_STOPCTRL_PORPO (5U)         //!< Bit position for SMC_STOPCTRL_PORPO.
#define BM_SMC_STOPCTRL_PORPO (0x20U)      //!< Bit mask for SMC_STOPCTRL_PORPO.
#define BS_SMC_STOPCTRL_PORPO (1U)         //!< Bit field size in bits for SMC_STOPCTRL_PORPO.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the SMC_STOPCTRL_PORPO field.
#define BR_SMC_STOPCTRL_PORPO (BITBAND_ACCESS8(HW_SMC_STOPCTRL_ADDR, BP_SMC_STOPCTRL_PORPO))
#endif

//! @brief Format value for bitfield SMC_STOPCTRL_PORPO.
#define BF_SMC_STOPCTRL_PORPO(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_SMC_STOPCTRL_PORPO), uint8_t) & BM_SMC_STOPCTRL_PORPO)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PORPO field to a new value.
#define BW_SMC_STOPCTRL_PORPO(v) (BITBAND_ACCESS8(HW_SMC_STOPCTRL_ADDR, BP_SMC_STOPCTRL_PORPO) = (v))
#endif
//@}

/*!
 * @name Register SMC_STOPCTRL, field PSTOPO[7:6] (RW)
 *
 * These bits control whether a Partial Stop mode is entered when STOPM=STOP.
 * When entering a Partial Stop mode from RUN mode, the PMC, MCG and flash remain
 * fully powered, allowing the device to wakeup almost instantaneously at the
 * expense of higher power consumption. In PSTOP2, only system clocks are gated
 * allowing peripherals running on bus clock to remain fully functional. In PSTOP1,
 * both system and bus clocks are gated.
 *
 * Values:
 * - 00 - STOP - Normal Stop mode
 * - 01 - PSTOP1 - Partial Stop with both system and bus clocks disabled
 * - 10 - PSTOP2 - Partial Stop with system clock disabled and bus clock enabled
 * - 11 - Reserved
 */
//@{
#define BP_SMC_STOPCTRL_PSTOPO (6U)        //!< Bit position for SMC_STOPCTRL_PSTOPO.
#define BM_SMC_STOPCTRL_PSTOPO (0xC0U)     //!< Bit mask for SMC_STOPCTRL_PSTOPO.
#define BS_SMC_STOPCTRL_PSTOPO (2U)        //!< Bit field size in bits for SMC_STOPCTRL_PSTOPO.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the SMC_STOPCTRL_PSTOPO field.
#define BR_SMC_STOPCTRL_PSTOPO (HW_SMC_STOPCTRL.B.PSTOPO)
#endif

//! @brief Format value for bitfield SMC_STOPCTRL_PSTOPO.
#define BF_SMC_STOPCTRL_PSTOPO(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_SMC_STOPCTRL_PSTOPO), uint8_t) & BM_SMC_STOPCTRL_PSTOPO)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PSTOPO field to a new value.
#define BW_SMC_STOPCTRL_PSTOPO(v) (HW_SMC_STOPCTRL_WR((HW_SMC_STOPCTRL_RD() & ~BM_SMC_STOPCTRL_PSTOPO) | BF_SMC_STOPCTRL_PSTOPO(v)))
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_SMC_PMSTAT - Power Mode Status register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SMC_PMSTAT - Power Mode Status register (RO)
 *
 * Reset value: 0x01U
 *
 * PMSTAT is a read-only, one-hot register which indicates the current power
 * mode of the system. This register is reset on Chip POR not VLLS and by reset
 * types that trigger Chip POR not VLLS. It is unaffected by reset types that do not
 * trigger Chip POR not VLLS. See the Reset section details for more information.
 */
typedef union _hw_smc_pmstat
{
    uint8_t U;
    struct _hw_smc_pmstat_bitfields
    {
        uint8_t PMSTAT : 8;            //!< [7:0]
    } B;
} hw_smc_pmstat_t;
#endif

/*!
 * @name Constants and macros for entire SMC_PMSTAT register
 */
//@{
#define HW_SMC_PMSTAT_ADDR       (REGS_SMC_BASE + 0x3U)

#ifndef __LANGUAGE_ASM__
#define HW_SMC_PMSTAT            (*(__I hw_smc_pmstat_t *) HW_SMC_PMSTAT_ADDR)
#define HW_SMC_PMSTAT_RD()       (HW_SMC_PMSTAT.U)
#endif
//@}

/*
 * Constants & macros for individual SMC_PMSTAT bitfields
 */

/*!
 * @name Register SMC_PMSTAT, field PMSTAT[7:0] (RO)
 *
 * When debug is enabled, the PMSTAT will not update to STOP or VLPS When a
 * PSTOP mode is enabled, the PMSTAT will not update to STOP or VLPS
 */
//@{
#define BP_SMC_PMSTAT_PMSTAT (0U)          //!< Bit position for SMC_PMSTAT_PMSTAT.
#define BM_SMC_PMSTAT_PMSTAT (0xFFU)       //!< Bit mask for SMC_PMSTAT_PMSTAT.
#define BS_SMC_PMSTAT_PMSTAT (8U)          //!< Bit field size in bits for SMC_PMSTAT_PMSTAT.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the SMC_PMSTAT_PMSTAT field.
#define BR_SMC_PMSTAT_PMSTAT (HW_SMC_PMSTAT.B.PMSTAT)
#endif
//@}

//-------------------------------------------------------------------------------------------
// hw_smc_t - module struct
//-------------------------------------------------------------------------------------------
/*!
 * @brief All SMC module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_smc
{
    __IO hw_smc_pmprot_t PMPROT;           //!< [0x0] Power Mode Protection register
    __IO hw_smc_pmctrl_t PMCTRL;           //!< [0x1] Power Mode Control register
    __IO hw_smc_stopctrl_t STOPCTRL;       //!< [0x2] Stop Control Register
    __I hw_smc_pmstat_t PMSTAT;            //!< [0x3] Power Mode Status register
} hw_smc_t;
#pragma pack()

//! @brief Macro to access all SMC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_SMC</code>.
#define HW_SMC         (*(hw_smc_t *) REGS_SMC_BASE)
#endif

#endif // __HW_SMC_REGISTERS_H__
// v22/130726/0.9
// EOF
