#include "cpuinfo_manip.h"  

// Extrae el modelo de CPU y el fabricante desde /proc/cpuinfo
void cpu_model_fabric(char *model, char *fabric) {
    FILE *fp = fopen("/proc/cpuinfo", "r");  // Abre el archivo del sistema que contiene info de CPU

    char line[256];
    while (fgets(line, sizeof(line), fp)) {  // Lee línea por línea
        if (strstr(line, "model name") && model[0] == '\0') {
            // Extrae el nombre del modelo de CPU 
            sscanf(line, "model name\t: %[^\n]", model);
        } else if (strstr(line, "vendor_id") && fabric[0] == '\0') {
            // Extrae el identificador del fabricante (Intel, AMD, etc.) 
            sscanf(line, "vendor_id\t: %[^\n]", fabric);
        }
    }

    fclose(fp);  // Cierra el archivo
}

// Cuenta el número total de núcleos virtuales (hilos de ejecución)
void virtual_cores(int *count) {
    FILE *fp = fopen("/proc/cpuinfo", "r");

    int cont = 0;
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        // Cada entrada "processor" representa un núcleo lógico
        if (strstr(line, "processor"))
            cont++;
    }

    fclose(fp);
    *count = cont;  // Retorna el conteo
}

// Obtiene el número de núcleos físicos por procesador (CPU)
void real_cores(int *cores){
    FILE *fp = fopen("/proc/cpuinfo","r");
    char line[256];

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "cpu cores")) {
            // Extrae el número de núcleos físicos por CPU (típicamente aparece una sola vez)
            sscanf(line, "cpu cores\t: %d", cores);
        }
    }

    fclose(fp);
}

// Muestra el uso de CPU por hilo usando el comando mpstat
void cpu_usage() {
    FILE *fp;
    char buffer[1024];

    // Ejecuta "mpstat -P ALL 1 1" para obtener una muestra de uso por CPU durante 1 segundo
    fp = popen("mpstat -P ALL 1 1", "r");

    printf("\nUso de CPU por hilo:\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Ignora las líneas de encabezado y promedios generales
        if (strstr(buffer, "all") || strstr(buffer, "CPU") || strstr(buffer, "Average"))
            continue;
        // Imprime solo líneas con datos individuales por CPU lógico
        printf("%s", buffer);
    }

    pclose(fp);  // Cierra el pipe del comando
}

