#ifndef PRU_H
#define PRU_H

char convertdata (unsigned char);
unsigned int InitPRU (void); /* Initialize PRU and PRU Interrupt. */
int InitMEM (void); /* Initialize PRU DATARAM mapping. */
void ExePRU (void); /* Execute the bin file. */
void communication1 (unsigned char *); /* Communication Protocol and Data Transfer. */
void communication0 (unsigned char *); /* Communication Protocol and Data Transfer. */
void ExitPRU (void);

#endif /* PRU_H */
