#include <stdio.h>
#include "../../src/meminfo_manip.h"

int main() {
    float total, swap, used, used_swap;

    meminfo(&total, &swap, &used, &used_swap);

    printf("Memoria Total: %.2f MB\n", total / 1024);
    printf("Swap Total   : %.2f MB\n", swap / 1024);
    printf("Used Mem     : %.2f %%\n", (used / total) * 100);
    printf("Used Swap    : %.2f %%\n", (used_swap / swap) * 100);

    return 0;
}
