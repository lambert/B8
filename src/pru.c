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
 
 #include "pru.h
 
/* Driver header file. */
#include "prussdrv.h"
#include <pruss_intc_mapping.h>
