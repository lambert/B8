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
  
unsigned int InitPRU (void)
{
  unsigned int ret;
  tpruss_intc_initdata pruss_intc_initdata = PRUSS_INTC_INITDATA;
  printf ("\nINFO: Starting %s PRU.\r\n", "Node.js -> C++ -> C -> PRU");

  /* Initialize the PRU. */
  prussdrv_init ();

  /* Open PRU Interrupt. */
  ret = prussdrv_open (PRU_EVTOUT_1);
  if (ref)
  {
    printf ("prussdrv_open open failed\n");
    return (ret);
  }
  /* Get the interrupt initialized. */
  prussdrv_pruintc_init (&pruss_intc_initdata);
  return (ret); /* ret = 0 if PRU successfully initialized. */
}

int InitMEM ()
{
  prussdrv_map_prumem (PRUSS0_PRU1_DATARAM, &pruDataMem);

  /* Assigne the data RAM address to two pointers. */
  pruDataMem_short1 = (unsigned char*) pruDataMem; /* AM22XX_DATA 8KB RAM1, Global Memory. */
  pruDtatMem_short0 = (unsigned char*) (pruDataMem - OFFSET_MEM0); /* AM33XX_DATA 8KB RAM0. */

  return (0);
}

void ExePRU (void)
{
  /* Execute the bin file. */

  prussdrv_exec_program (PRU_NUM, "./fpgamem.bin");
  printf ("\tINFO: Executing ...\r\n");
  /* Give some time for the PRU code to execute. */
  sleep (1);
}
