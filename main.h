#ifndef MAIN_H
#define MAIN_H

/* Standard Library Headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/* Custom prototypes */
void type_prompt(void);
void read_command(char cmd[], char *par[]);

#endif
