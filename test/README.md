# **Carpeta Test**

Esta carpeta contiene los archivos de prueba (test) correspondientes a cada bloque funcional dentro del programa 'Resource_Monitor'.
Estas pruebas permiten verificar el correcto funcionamiento de los códigos implementados (estructuras, funciones) en los módulos 'cpuinfo_manip', 'meminfo_manip'
y 'tui'.

## _Archivos de prueba (test):_

### **cpuinfo_test.c**: 
Verifica las funciones del módulo 'cpuinfo_manip.c', encargado de obtener información sobre la CPU y el uso de sus hilos.

- **Valores esperados**:
   - El nombre del modelo y fabricante deben coincidir con la información presente en '/proc/cpuinfo'.
   - El número de núcleos e hilos debe ser mayor a cero.
   - Los porcentajes de uso deben estar entre 0% y 100%.

### **meminfo_test.c**:
Verifica las funciones del módulo 'meminfo_manip.c', encargado de obtener la información de la memoria RAM.

- **Valores esperados**:
  - Valores totales en MB que coincidad con la información presente en '/proc/meminfo'.
  - Porcentaje de uso dentro de un rango válido (0% - 100%).

### **tui_test.c**:
Verifica las funciones del módulo 'tui', que se encarga de la interacción usuario-máquina.

- **Valores esperados**:
  - La información debe mostrarse correctamente en la termnial durante la ejecución.
  - El programa debe finalizar correctamente al presionar la letra q, ctrl + c o al cerrar la terminal.

### **Makefile**:
Desde la carpeta principal del proyecto, se puede compilar estos test con el comando:
```bash
make tests
