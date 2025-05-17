#include "meminfo_manip.h"

void meminfo(float *MemTotal, float *SwapTotal, float *UsedSpace, float *UsedSwap){
    FILE *fp = fopen("/proc/meminfo", "r");

    char line[256];
    float MemFree, SwapFree;
    while(fgets(line, sizeof(line), fp)){
        if(strstr(line, "MemTotal")){
            sscanf(line, "MemTotal\t:%f", MemTotal);
        } else if(strstr(line, "SwapTotal")){
            sscanf(line, "SwapTotal\t:%f", SwapTotal);
        } else if(strstr(line, "MemFree")){
	    sscanf(line, "MemFree\t:%f", &MemFree);
	} else if(strstr(line, "SwapFree")){
	    sscanf(line, "SwapFree\t:%f", &SwapFree);
	}
    }
    *UsedSpace = *MemTotal - MemFree;
    *UsedSwap = *SwapTotal - SwapFree;
}
