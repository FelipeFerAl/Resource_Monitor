#include "meminfo_manip.h"
#include "cpuinfo_manip.h"
#include "tui.h"

void print_info(){
    char modelo[256]="";
    char fabric[256]="";
    int number_rc, number_vc;
    float MemTotal, SwapTotal, UsedSpace, UsedSwap;

    cpu_model_fabric(modelo,fabric);
    printf("Modelo  :  %s\n", modelo);
    printf("Fabricante  :  %s\n", fabric);

    real_cores(&number_rc);
    virtual_cores(&number_vc);
    printf("Núcleos Virtuales : %d\n", number_vc);
    printf("Núcleos Reales    : %d\n", number_rc);

    cpu_usage();

    meminfo(&MemTotal,&SwapTotal,&UsedSpace,&UsedSwap);
    printf("Memoria Total  :  %.2f MB\n", MemTotal/1024);
    printf("Swap Total  :  %.2f MB\n", SwapTotal/1024);
    printf("Used Mem  :  %.2f%%\n", (UsedSpace/MemTotal)*100);
    printf("Used Swap  :  %.2f%%\n", (UsedSwap/SwapTotal)*100);
}
