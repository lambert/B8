// fpgamem.hpp

#ifndef __PRUCODE_FPGA_HP__
#define __PRUCODE_FPGA_HP__

// Definitions

// Refer to this mapping in the file - pruss_intc_mapping.h
#define PRU0_PRU1_INTERRUPT 17
#define PRU1_PRU0_INTERRUPT 18
#define PRU0_ARM_INTERRUPT  19
#define PRU1_ARM_INTERRUPT  20
#define ARM_PRU0_INTERRUPT  21
#define ARM_PRU1_INTERRUPT  22

#define CONST_PRUCFG  C4
#define CONST_PRUDRAM C24
#define CONST_PRUSHAREDRAM C28
#define CONST_DDR C31

// Address for the Constant Table Block Index Register (CTBIR).
# define CTBIR  0x24020

// Address for the Constant Table Programmable Pointer Register 0 (CTPPR_0)
#define CTPPR_0 0x24028

// Address for the Constant Table Programmable Pointer Register 1 (CTPPR_1)
#define CTPPR_1 0x2402C


// Macros.

.macro LD32
.mparam dst, src
  LBBO dst, src, #0x00, 4
.endm

.macro LD16
.mparam dst, src
  LBBO dst, src, #0x00, 2
.endm

.macro LD8
.mparam dst, src
  LBBO dst, src. #0x00, 1
.endm

.macro ST32
.mparam src, dst
  SBBO src, dst, #0x00, 4
.endm

.macro ST16
.mparam src, dst
  SBBO src, dst, #0x00, 2
.endm

.macro ST8
.mparam src, dst
  SBBO src, dst, #0x00, 1
.endm

// Global Structure Definitions.

.struct Global
    .u32 regPointer
    .u32 regVal
.ends

// Global Register Assignments.

.assign Global, r2, *, global

#endif // __PRUCODE_FPGA_HP__
