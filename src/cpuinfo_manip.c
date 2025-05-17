#include "cpuinfo_manip.h"

void cpu_model_fabric(char *model, char *fabric) {
    FILE *fp = fopen("/proc/cpuinfo", "r");

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "model name") && model[0] == '\0') {
            sscanf(line, "model name\t: %[^\n]", model);
        } else if (strstr(line, "vendor_id") && fabric[0] == '\0') {
            sscanf(line, "vendor_id\t: %[^\n]", fabric);
        }
    }

    fclose(fp);
}

void virtual_cores(int *count) {
    FILE *fp = fopen("/proc/cpuinfo", "r");

    int cont = 0;
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "processor"))
            cont++;
    }

    fclose(fp);
    *count = cont;
}

void real_cores(int *cores){
    FILE *fp = fopen("/proc/cpuinfo","r");
    char line[256];

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "cpu cores")) {
            sscanf(line, "cpu cores\t: %d", cores);
        }
    }

    fclose(fp);
}

void cpu_usage() {
    FILE *fp;
    char buffer[1024];

    // Run mpstat and get per-CPU stats
    fp = popen("mpstat -P ALL 1 1", "r");  // 1 sample, 1-second interval

    printf("\nUso de CPU por hilo:\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (strstr(buffer, "all") || strstr(buffer, "CPU") || strstr(buffer, "Average"))
            continue;  // Skip headers
        printf("%s", buffer);  // Output line: CPU X %usr %nice %sys %iowait %irq %soft %steal %idle
    }

    pclose(fp);
}
