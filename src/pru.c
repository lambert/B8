/* pru.c
 *
 * Copyright (C) 2014 ADLab - http://www.analogdigitallab.org/
 * Authors: Haolin Li, Jorsi Van Kerrebrouck
 * Acknowledgment : Intec Design, University Ghent
 * Project Name: Etherscope v1.0
 * Create Date: 23:32:38 02/27/2013
 */

/* Include Files. */

/* Standard header files. */
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#include "pru.h"

/* Driver header file. */
#include "prussdrv.h"
#include <pruss_intc_mapping.h>


/* Local Macro Declarations. */
#define PRU_NUM 1
#define OFFSET_MEM0 0x00002000
#define OFFSET_SHAREDRAM 0x00010000


/* Local Function Declarations. */

/* Global Variable Definitions. */
static void *pruDataMem;
static unsigned char *pruDataMem_short0; /* AM33XX_DATA 8KB RAM0 */
static unsigned char *pruDataMem_short1; /* AM33XX_DATA 8KB RAM1 */
int num = 4096;

/* Global Function Definitions. */

char convertdata (unsigned char d)
{
  /* Convert 2-complementary binary data to decimal. */
  int sign;
  char converted;
  sign = (d >> 7) & 0x01;
  if (sign == 1)
  {
    converted = d - 128; /* Negative. */
  }
  else
  {
    converted = d + 128; /* Positive. */
  }
  return converted;
}
  
