#include <stdio.h>
#include "../../src/cpuinfo_manip.h"

int main() {
    char model[256] = "";
    char fabric[256] = "";
    int real, virt;

    cpu_model_fabric(model, fabric);
    printf("Modelo CPU: %s\n", model);
    printf("Fabricante: %s\n", fabric);

    real_cores(&real);
    virtual_cores(&virt);
    printf("Núcleos Reales: %d\n", real);
    printf("Núcleos Virtuales: %d\n", virt);

    cpu_usage();  // should print usage (even if approximate)

    return 0;
}
