# Top-level Makefile para compilar un monitor de recursos y sus pruebas en Linux

# Compilador a usar
CC = gcc

# Definición de directorios
SRC_DIR = src          # Código fuente principal
OBJ_DIR = obj          # Archivos objeto (*.o)
BIN_DIR = bin          # Ejecutables generados
TEST_DIR = test        # Carpeta de pruebas
TEST_SRC_DIR = $(TEST_DIR)/src  # Código fuente de las pruebas

# Lista de archivos fuente (.c) dentro del directorio src
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)   # Busca todos los .c en src/
SRC_NAMES = $(notdir $(basename $(SRC_FILES)))  
# Obtiene solo el nombre base de cada archivo fuente 

# Nombres de los archivos de prueba 
TEST_NAMES = cpuinfo_test meminfo_test tui_test

# Ruta completa a los archivos fuente de prueba
TEST_SRCS = $(patsubst %, $(TEST_SRC_DIR)/%.c, $(TEST_NAMES))

# Ruta a los ejecutables de prueba generados
TEST_BINS = $(patsubst %, $(BIN_DIR)/%, $(TEST_NAMES))

# Archivos objeto generados desde los archivos fuente del programa principal
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_NAMES)))

# Regla general para compilar un .c a .o dentro del obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c $< -o $@
# $< representa el archivo fuente (.c)
# $@ representa el archivo de salida (.o)

# Crea los directorios obj/ y bin/ si no existen
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Declaración de objetivos que no son archivos reales
.PHONY: all resource_mon tests clean

# Objetivo por defecto: compila el programa y las pruebas
all: resource_mon tests

# Compila el programa principal (resource monitor)
resource_mon: $(OBJ_FILES)
	$(CC) -o $(BIN_DIR)/resource_mon $^


# Objetivo para compilar todas las pruebas
tests: $(TEST_BINS)

# Regla para compilar cada prueba individual

$(BIN_DIR)/%: $(TEST_SRC_DIR)/%.c $(filter-out $(OBJ_DIR)/resource_mon.o, $(OBJ_FILES))
	$(CC) $^ -o $@


# Limpia archivos temporales: objetos y ejecutables
clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/*



//Limpia archivos temporales: objetos y ejecutables
clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/*

