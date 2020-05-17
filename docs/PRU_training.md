# PRU Training: Hands-on Labs

## Introduction

The labs provided on this page will give you a hands on tutorial of the PRU, C-compiler,
and Linux driver.
Each of the following sections below will walk you through a particular Lab exercise,
including the step-by-step instructions to complete the lab.

<b>NOTE:</b> In this guide commands to be executed for each step will be marked in <b>BOLD</b>.

## Lab Configuration

The following are the hardware and software configurations for this lab.
The steps in this lab are written against this configuration.
The concepts of the lab will apply to other configurations but will need to be adapted accordingly.

### Hardware

- AM335x Beaglebone Black - Order Now

- BeagleBone PRU Cape - Order Now

- 5V power supply or USB cable connection

- JTAG emulator

- FTDI cable

### Software

- [Linux Processor SDK](http://www.ti.com/tool/PROCESSOR-SDK-AM335X) installed.
  This lab assumes the latest Linux Processor SDK is installed in /home/sitara.
  If you use a different location please modify the below steps accordingly.

- The PRU Software Support Package is now included in the 'example-applications/pru-icss-x.y.z/'
  folder of the Linux Processor SDK (as of v2.0.2.11).
  If you are using RTOS or running Windows on your development machine, you can download
  the support package from the git repository [here](https://git.ti.com/pru-software-support-package/pru-software-support-package/trees/master).
  This lab assumes that the software package is installed in /home/sitara/<ti-sdk...>/example-applications/pru-icss-x.y.z.
  However, the notation <PRU_SW_PATH> will be used throughout the labs to reference
  this assumed installation location.
  If you use a different location please modify the steps below.

- [CCSv6](http://processors.wiki.ti.com/index.php/Download_CCS#Code_Composer_Studio_Version_6_Downloads)

- [PRU Code Generation Tools](http://software-dl.ti.com/codegen/non-esd/downloads/download.htm#PRU)
  (also available through the CCS App Center)

### Supported Platforms

This hands-on guide is focused on the AM335x processor on the Beaglebone Black due to the
availability of the PRU cape for this platform as well as access to the PRU pins externally.
However, the concept of loading/running firmwares described here will translate to the
AM437x and AM57xx devices as well.
The PRU Software Support Package supports all three of these devices.

## LAB 1: Toggle LED with PRU GPO

### Objective

Toggle an LED using the PRU0 R30 GPO in Direct Output Mode (default).

### Key Points

- Compile PRU code

- Load PRU code using CCS

- Step through PRU code in CCS

### Lab Steps

<b>NOTE :</b>
Before beginning, ensure that the kernel is not booting and/or already up and running.
BeagleBone Black has an eMMC device with a kernel pre-built and flashed ready for boot;
however, if the kernel loads prior to our connection to the ARM in CCS then you may
experience issues with the debugger.
These are primarily caused by the kernel enabling the MMU.
Use a minicom console to stop U-Boot to prevent the kernel from booting.

To work around this, first try popping out the microSD card if one is inserted.
If the blue LEDs on the BBB are toggling when power is applied, then the board is still
booting off the eMMC. On the BBB opposite the RJ-45 (Ethernet) connector, there is a push
button almost directly under the audio jack that may be difficult to access with the PRU
cape on.
Press and hold this while power is applied, then release.
You should no longer see the flashing lights.

1. Launch CCSv6 and select the default Workspace.

2. Create a new PRU project.

   a. Select <b>File->New->CCS Project</b>.

   b. In the far-right dropdown next to Target, <b>select BeagleBone_Black</b>.

   c. Select <b>PRU tab</b>, specify a <b>Project Name (toggle_led works well)</b>, and verify that Compiler version is <b>TI v2.1.0</b> or higher.

   d. Select <b>Finish</b>.
   
