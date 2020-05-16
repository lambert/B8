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
