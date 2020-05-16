# PRU Cape Getting Started Guide

## Introduction

This guide is intended to walk through the basic instructions on how to get started with your
PRU Cape using the available demo software.

The PRU Cape is a test, development, and evaluation module system that enables developers to
write software and develop hardware around the PRU subsystem.
The diagram below shows the basic features supported by the cape.
For more details about the PRU Cape hardware, please refer to the [PRU Cape Hardware User Guide]().

![fig_1](Pru_cape-wiki-blockdiagram.png)

## Prerequisites

The hardware and software prerequisites needed to run the getting started demo are listed below.

### Hardware

- BeagleBone or BeagleBone Black (Can be ordered from beagleboard.org)

- BeagleBone PRU Cape (Can be ordered from ti.com)

- MicroSD card formatted as FAT32

- USB cable to power BeagleBone or BeagleBone Black

- FTDI cable for BeagleBone Black serial debug port (not required for original BeagleBone)

- Speakers or headphones for audio demo

- RS-232 serial cable for hardware UART demo

### Software

The PRU Cape Demo Software is available in the
[PRU Software Support Package](https://git.ti.com/pru-software-support-package/pru-software-support-package/)
hosted on git.ti.com.
To download this package, select the "Source Tree" button from the PRU Software Support Package
webpage and then click "Download master as tar.gz."
In Windows, a program such as 7-zip can be used to open the downloaded file and extract the
software package contents.

To RUN the PRU Cape demos, the following software is required:

- [PRU Cape Demo Binaries](https://git.ti.com/pru-software-support-package/pru-software-support-package/trees/master/pru_cape/bin)
  (available in the pru_cape/bin directory of the PRU Software Support Package)

- Terminal program (such as Teraterm or Hyperterminal)

<b>NOTE:</b> This wiki will specifically cover how to run the demos based on Starterware and thus,
provides an example of interacting with the PRU using a non-Linux OS.
However, Linux or CCS can also be used to load and run the demos.
The basic procedure for using Linux with the PRU is described in the PRU-SW Getting Started Guide.

