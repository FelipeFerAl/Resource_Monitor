#include "meminfo_manip.h"  

void meminfo(float *MemTotal, float *SwapTotal, float *UsedSpace, float *UsedSwap){
    FILE *fp = fopen("/proc/meminfo", "r");  // Abre el archivo del sistema con info de memoria

    char line[256];
    float MemFree, SwapFree;  // Variables auxiliares para calcular uso

    // Recorre el archivo línea por línea buscando etiquetas específicas
    while(fgets(line, sizeof(line), fp)){
        if(strstr(line, "MemTotal")){  // RAM total
            sscanf(line, "MemTotal\t:%f", MemTotal);
        } else if(strstr(line, "SwapTotal")){  // Swap total
            sscanf(line, "SwapTotal\t:%f", SwapTotal);
        } else if(strstr(line, "MemFree")){  // RAM libre
            sscanf(line, "MemFree\t:%f", &MemFree);
        } else if(strstr(line, "SwapFree")){  // Swap libre
            sscanf(line, "SwapFree\t:%f", &SwapFree);
        }
    }

    // Calcula memoria usada como total - libre
    *UsedSpace = *MemTotal - MemFree;
    *UsedSwap  = *SwapTotal - SwapFree;
}
