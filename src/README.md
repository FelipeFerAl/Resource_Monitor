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

Este archivo implementa una serie de funciones para extraer información del sistema relacionado con la CPU, usando el archivo `/proc/cpuinfo` y `/proc/stat`. 
  -cpu_model_fabric(char *model, char *fabric): 
  Obtiene el modelo del procesador (model name) y el fabricante (vendor_id) y    los guarda en las variables correspondientes.

  -virtual_cores(int *count): 
  Cuenta el número total de hilos de ejecución lógicos (núcleos virtuales) disponibles.

  -real_cores(int *cores): 
  Obtiene el número de núcleos físicos (cpu_cores) del sistema. 

  -cpu_usage(): 
  Ejecuta el comando mpstat para mostrar el porcentaje de uso de CPU por cada hilo lógico.

### **- Bloque meminfo_manip:**

Este archivo proporciona una función para leer y calcular el uso actual de memoria física y swap directamente desde /proc/meminfo:

  -meminfo(float *MemTotal, float *SwapTotal, float *UsedSpace, float *UsedSwap): los parámetros de la función extraen: 
  
      -MemTotal: Memoria RAM total (en MB).
      
      -SwapTotal: Tamaño total de la partición de swap (en MB).
      
      -UsedSpace: Memoria RAM usada (MemTotal - MemFree).
      
      -UsedSwap: Swap usada (SwapTotal - SwapFree).
      
### **- Bloque tui:**
Este archivo implementa una interfaz interactiva en terminal para mostrar información en tiempo real sobre el sistema, incluyendo CPU, memoria y uso de recursos

  -void print_info(void): 
  Muestra en pantalla las variables relacionadas a las funciones vistas anteriormente, es decir: 
  
    Modelo y fabricante del procesador.
    
    Número de núcleos físicos y lógicos.
    
    Porcentaje de uso de CPU por hilo (utiliza mpstat).

    Memoria total y swap en MB.
    
    Porcentaje de memoria y swap usada.
    
    La pantalla se limpia en cada actualización.

  -set_input_mode(int enable): 
  Restaura la configuración del sistema al salir de la interfa, espera un tiempo mínimo para ingresar un caracter.  

  -start_interface(): 
  Inicia la visualización interactiva, actualiza la nformación del sistema cada segundo y permite al usuario salir presionando 'q'   o usando Ctrl + C
  
### **- Bloque resource_mon:**

Contiene la función principal `main()` que se encarga de ejecutar la función start_interface para comenzar con la visualización de los parámetros en pantalla. 

### **- Makefile:**

Se encarga de compilar y ejecutar los archivos en la carpeta 'src' con los comandos `make`, `make resource_mon` o `make all`.
