# Taller #1 de Programación de Sistemas Linux Embebidos

Programa para monitoreo de los recursos del sistema en Linux llamado 'Resource Monitor'.

## Autores:

- Cristian Marcelo Quenguan Malte - C.C.1004532387
- Felipe Fernández Alzate - C.C.1056120378
- Gabriela Romo Mendoza - C.C.1080691539
- Paulina Ruiz Bonilla - C.C.1002609493

## Descripción:

'Resource_Monitor' es una interfaz de línea de comandos (CLI) que muestra en tiempo real la información sobre el estado de
los recursos del sistema mediante Linux, incluyendo el uso de CPU por hilo y memoria RAM. El código del programa esta desarrollado
en lenguaje C, organizado por módulos y con un desarrollo orientado a pruebas (test driven development).

## Objetivos: 
- Fortalecer habilidades de trabajo colaborativo mediante el uso de `git` y plataformas como GitHub.
- Familiarizarse con la herramienta GNU make para automatizar la gestión de compilado y
enlazado de proyectos en C y/o C++.
- Familiarizarse con elementos del desarrollo de software con base en requerimientos y del
desarrollo orientado a pruebas (test driven development).
- Fortalecer las competencias relacionadas con la generación de documentación técnica efectiva.

## Funcionalidades:
- Imprime el nombre del modelo y fabricante de la CPU.
- Indica el número de núcleos fisicos, núcleos virtuales y número total de hilos.
- Muestra el porcentaje de uso por cada hilo.
- Indica la cantidad total de memoria RAM y swap en MB.
- Calcula y muestra el porcentaje de uso de RAM y swap.
- Controla la interfaz de usuario en la terminal (con actualizaciones a tiempo real).
- El programa tiene tres modos de cierre: presionando la letra 'q', con 'ctrl + c' o al cerrar la terminal.

## Estructura del proyecto:
```bash
Resource_Monitor
├── Makefile # Script principal de compilación
├── README.md # Este archivo
├── bin # Ejecutables compilados
│   ├── cpuinfo_test
│   ├── meminfo_test
│   ├── resource_mon
│   └── tui_test
├── obj # Archivos Objeto (.o)
│   ├── README.md
│   ├── cpuinfo_manip.o
│   ├── meminfo_manip.o
│   ├── resource_mon.o
│   └── tui.o
├── src # Código fuente del programa
│   ├── Makefile
│   ├── README.md
│   ├── cpuinfo_manip.c
│   ├── cpuinfo_manip.h
│   ├── meminfo_manip.c
│   ├── meminfo_manip.h
│   ├── resource_mon.c
│   ├── tui.c
│   └── tui.h
└── test # Archivos de prueba
    ├── README.md
    └── src
        ├── cpuinfo_test.c
        ├── meminfo_test.c
        └── tui_test.c
```
## Compilación:
Desde la carpeta principal del proyecto, se pueden usar los siguientes comandos:
- `make` - Compila todo el proyecto.
- `make resource_mon` - Compila solo el ejecutable principal.
- `make tests` - Compila los ejecutables de prueba (`cpuinfo_test`, `meminfo_test`, `tui_test`).
- `make all` - Compila todos los ejecutables existentes.
- `make clean` - Elimina archivos `.o` y ejecutables generados.
> Los archivos `.o` se almacenan en 'obj' y los ejecutables se almacenan en 'bin'.

## Ejecución:
Desde la carpeta principal:
``` bash
./bin/resource_mon
```
Obteniendo como resultado de la ejecución total:
``` bash
![WhatsApp Image 2025-05-21 at 21 08 00_df7defa7](https://github.com/user-attachments/assets/f7ff108e-8ff6-4f39-a551-8906515a35e8)
![WhatsApp Image 2025-05-21 at 21 08 01_51794fd9](https://github.com/user-attachments/assets/10adb175-339a-45fd-8330-d2027d22e4c8)
Como se puede apreciar entre ambas imágenes, se dan cambios en el porcentaje de consumo en cada hilo del procesador debido a la actualización
constante de los datos
```

## Descripción de la implementación por módulo: 

### Módulo `cpuinfo_manip`
Se ingresa al archivo `/proc/cpuinfo` y `/proc/stat` para obtener la información relacionada a las características (Fabricante, modelo y número de hilos) y porcentajes de uso de cada hilo del procesador (CPU).

### Módulo `meminfo_manip`
Se ingresa al archivo `/proc/meminfo` para tomar los datos de la memoria RAM y swap, convertirlos a un número legible en MB y observar su uso en valor porcentual.

### Módulo `tui`
Administra la interacción usuario-máquina para determinar el comportamiento del sistema, incluidas funciones relacionadas a la muestra de los datos esperados con actualizaciones cada segundo, y finalización del programa (3 modos: al presionar la letra 'q', con el comando `ctrl + c` o al cerrar el terminal). 

### Archivo `resource_mon`
Contiene la función principal de ejecución del programa.



