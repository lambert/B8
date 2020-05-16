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

#include "fpgamem.hpp"

#define MASK0 0x000000ff
