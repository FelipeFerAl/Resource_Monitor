#ifndef CPUINFO_MANIP_H
#define CPUINFO_MANIP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void cpu_model_fabric(char *model, char *fabric);
void virtual_cores(int *count);
void real_cores(int *cores);
void cpu_usage();

#endif
