# PRU Cape Hardware User Guide

## Introduction

This document describes the hardware architecture of the PRU Cape  which is compatible
with the Beagle Bone Black development platform. 

## Description

The PRU Cape is a test, development, and evaluation module system that enables developers
to write software and develop hardware around the PRU subsystem.
Examples of basic I/O such as push buttons and LEDs as well as more complicated examples such as audio and 1-Wire for temperature sensing are available on this cape to showcase what the PRU can accomplish in terms of inputs and outputs.

The following sections give more details regarding the PRU Cape

## EVM System View

The PRU Cape is shown below in Figure 1.

![fig_1](prucape.jpg)

## Schematics/Design/Errata Files

[Design Files](http://www.ti.com/tool/prucape) (located under Technical Documents), includes:

- Schematic

- Layout

- Assembly Drawings

- CAD Files

- Bill of Materials (BOM)

[Errata](https://processors.wiki.ti.com/index.php/PRU_Cape_Hardware_User_Guide#Schematics.2FDesign.2FErrata_Files)

- I2C SCL and SDA signals swapped (REV 1.2A)
  The AM335x I2C2_SDA signal (routed to BBB Header P9-20) is connected to the EEPROM SCL pin.
  The AM335x I2C2_SCL signal (routed to BBB Header P9-19) is connected to the EEPROM SDA pin.
  The EEPROM is blank, and if it is to be used, the cape needs to be modified to physically swap the SDA and SCL signals.

[PRU Cape Getting Started Guide](PRU_GS.md)

## System Description

### System Board Diagram

The system block diagram of the PRU Cape are shown in Figure 2 and Figure 3.

![fig_2](./Board_Layout.jpg)

![fig_3](./System_Diagram.jpg)

## Signals Used

| CAPE NAME	| BBB HEADER NUMBER	| BBB MODE 0 NAME	| CAPE USE |
|-----------|-------------------|-----------------|----------|
| PR1_PRU0_GPO0 |	P9-31 |	MCASP0_ACLKX |	PRU0 Blue LED |
| PR1_PRU0_GPO1 |	P9-29 |	MCASP0_FSX |	PRU0 Green LED |
| PR1_PRU0_GPO2 |	P9-30 |	MCASP0_AXR0 |	PRU0 Orange LED |
| PR1_PRU0_GPO3 |	P9-28 |	MCASP0_AHCLKR |	PRU0 Red LED |
| PR1_PRU1_GPO3 |	P8-44 |	LCD_DATA3 |	PRU1 Blue LED |
| PR1_PRU1_GPO4 |	P8-41 |	LCD_DATA4 |	PRU1 Green LED |
| PR1_PRU1_GPO5 |	P8-42 |	LCD_DATA5 |	PRU1 Red LED |
| PR1_PRU0_GPI7 |	P9-27 |	GPIO3_19 |	SW1 |
| PR1_PRU0_GPI5 |	P9-25 |	GPIO3_21 |	SW2 |
| PR1_PRU1_GPO0 |	P8-45 |	LCD_DATA0 |	Audio Data |
| PR1_PRU1_GPO1 |	P8-46 |	LCD_DATA1 |	Audio Clock |
| PR1_PRU1_GPO2 |	P8-43 |	LCD_DATA2 |	Audio Sync |
| PR1_UART0_TXD |	P9-24 |	UART1_TXD |	UART TxD |
| PR1_UART0_RXD |	P9-26 |	UART1_RXD |	UART RxD |
| PR1_UART0_RTS |	P9-21 |	UART2_TXD |	UART RTS |
| PR1_UART0_CTS |	P9-22 |	UART2_RXD |	UART CTS |
| PR1_PRU_EDIO_DATA_OUT6 |	P8-39 |	LCD_DATA6 |	LCD RS |
| PR1_PRU_EDIO_DATA_OUT4 |	P8-28 |	LCD_PCLK |	LCD E |
| PR1_PRU_EDIO_DATA_OUT0 |	P9-18 |	I2C1_SDA |	LCD Data4 |
| PR1_PRU_EDIO_DATA_OUT1 |	P9-17 |	I2C1_SCL |	LCD Data5 |
| PR1_PRU_EDIO_DATA_OUT2 |	P8-27 |	LCD_VSYNC |	LCD Data6 |
| PR1_PRU_EDIO_DATA_OUT3 |	P8-29 |	LCD_HSYNC |	LCD Data7 |
| PR1_PRU_EDIO_DATA_OUT5 |	P8-30 |	LCD_DE |	HDQ input |
| PR1_PRU0_GPI14 |	P8-16 |	GPIO1_14 |	HDQ output |
| I2C2_SDA |	P9-20 |	I2C2_SDA |	I2C SCL |
| I2C2_SCL |	P9-19 |	I2C2_SCL |	I2C SDA |
| PR1_ECAP0_IN_PWM0_OUT |	P9-42 |	ECAP0_IN_PWM0_OUT |	ECAP0_IN_PWM0_OUT |
| PR1_PRU0_GPI15 |	P8-15 |	GPMC_AD15 |	PRU0_GPI_15 |
| VDD_3V3C |	P9-3, P9-4 | 	VDD_3V3C |	VDD_3V3C |
| DGND |	P8-1, P8-2, P9-1,P9-2 |	DGND |	DGND |
| DGND |	P9-43, P9-44, P9-45, P9-46 |	DGND |	DGND |
