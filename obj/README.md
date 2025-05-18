# Carpeta Obj
Esta carpeta almacena los archivos objeto `.o` generados durante el proceso de compilación del programa `Resource_Monitor`.

## Contenido
Una vez ejecutado el bloque Makefile (dependiendo el tipo de ejecución que se haya decidido realizar), esta carpeta contendrá los
archivos correspondientes a cada bloque funcional del programa:

- `cpuinfo_manip.o`
- `meminfo_manip.o`
- `resource_mon.o`
- `tui.o`


> - Estos archivos son utilizados en la etapa de enlazado para generar los ejecutables finales del programa.
> - El comando `make clean` elimina automáticamente los archivos `.o` pertenecientes a esta carpeta independientemente
del tipo de ejecución aplicado.
