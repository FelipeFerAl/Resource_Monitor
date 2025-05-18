# **Carpeta Source (src)**

Esta carpeta contiene el código fuente del programa 'Resource_monitor' organizado por bloques funcionales (cada uno con sus respectivos archivos):

- cpuinfo_manip.h -> Definición de las funciones (librería estándar)

- cpuinfo_manip.c -> Implementación de la función 

- meminfo_manip.h -> Definición

- meminfo_manip.c -> Implementación

- tui.h		 -> Definición

- tui.c		 -> Implementación

- resource_mon.c  -> Código principal

- Makefile        -> Compilación y Ejecución


### **Bloque cpuinfo_manip:**
	
 Se ingresa al archivo "/proc/cpuinfo" y "/proc/stat" para obtener la información relacionada a las características
(Fabricante, modelo y número de hilos) y porcentajes de uso del procesador.

### **Bloque meminfo_manip:**

Se ingresa al archivo "/proc/meminfo" para tomar los datos de la memoria, convertirlos a un número legible en MB y
observar su uso en valor porcentual.

### **Bloque tui:**

Administra la interacción usuario-máquina para determinar el comportamiento del sistema.

### **Bloque resource_mon:**

Contiene la función principal del programa en base a los demás bloques.

### **Makefile:**

Se encarga de compilar y ejecutar los archivos en la carpeta 'src' con el comando:

```bash
make
