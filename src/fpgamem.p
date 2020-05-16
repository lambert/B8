// fpgamem.p

// Authors: Haolin Li, Joris Van Kerrebrouck
// Acknowledgment: Intec Design, University Ghent
// Project Name: Etherscope v1.0

//
// BBB Schematic  BBB Port  Assign  Bit
// -------------  --------  ------  -----------
// LCD_DATA0      P8.45     D0      PRU1_R31_0
// LCD_DATA1      P8.46     D1      PRU1_R31_1
// LCD_DATA2      P8.43     D2      PRU1_R31_2
// LCD_DATA3      P8.44     D3      PRU1_R31_3
// LCD_DATA4      P8.41     D4      PRU1_R31_4
// LCD_DATA5      P8.42     D5      PRU1_R31_5
// LCD_DATA6      P8.39     D6      PRU1_R31_6
// LCD_DATA7      P8.40     D7      PRU1_R31_7
// LCD_PCLK       P8.28     CLK     PRU1_R31_10
// LCD_VSYNC      P8.27     START   PRU1_R31_8
// LCD_HSYNC      P8.29     EN      PRU1_R31_9

.origin 0
.entrypoint START

#include "fpgamem.hp"

#define MASK0 0x000000ff

// Memory location where to store the data to be acquired:
#define ACQRAM 0x00010004

// Length of acquisition:
#define RECORDS 4096  // 1024

START:
// Enable OCP master port
LBCO r0, CONST_PRUCFG, 4, 4
CLR r0, r0, 4  // lear SYSCFG[STANDBY_INIT] to enable OCP master port
SBCO r0, CONST_PRUCFG, 4, 4

// Configure the programmable pointer register for PRU1
// by setting c28_pointer[15:0] field to 0x0100.
// This will make c28 point to 0x00010000 (PRU shared RAM), see 'fpgamem.hp'.
MOV r0, 0x00010000
MOV r1, CTPPR_1
ST32 r0, r1

MOV r7, RECORDS  // This will be the loop counter to read the entire set of data
MOV r4, MASK0  // r4 is the mask for the lowest 8 bits

MOV r2.w0, 0x0000
SBCO 0x0, CONST_PRUDRAM, 0, 2  // Clear the flag for data RAM1
MOV r3, 0x00002000
SBCO 0x0, CONST_PRUDRAM, r3, 2  // Clear the flag for data RAM0
