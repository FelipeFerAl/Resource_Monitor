# **Carpeta Source (src)**

Esta carpeta contiene el código fuente del programa 'Resource_monitor' organizado por bloques funcionales (cada uno con sus respectivos archivos):

- `cpuinfo_manip.h` - Definición de las funciones (librería estándar)

- `cpuinfo_manip.c` - Implementación de la función 

- `meminfo_manip.h` - Definición

- `meminfo_manip.c` - Implementación

- `tui.h` - Definición

- `tui.c` - Implementación

- `resource_mon.c` - Código principal

- `Makefile` - Compilación y Ejecución


## Funcionalidad de cada bloque:

### **- Bloque cpuinfo_manip:**

Funciones que acceden a `/proc/cpuinfo` y `/proc/stat` para obtener datos sobre el procesador y el uso de cada hilo.
``` bash
como se ve cada función ej: cpu_model(char *model ...) #Obtiene el nombre y fabricante ... etc. y asi con todas, solo los titulos no el código obvi
y todas juntas como una listica :)
```
lo mismo que arriba para el resto de los módulos

### **- Bloque meminfo_manip:**


### **- Bloque tui:**


### **- Bloque resource_mon:**

Contiene la función principal `main()` que:

### **- Makefile:**

Se encarga de compilar y ejecutar los archivos en la carpeta 'src' con los comandos `make`, `make resource_mon` o `make all`.
