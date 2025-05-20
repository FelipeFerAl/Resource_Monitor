#include "tui.h"
#include "meminfo_manip.h"
#include "cpuinfo_manip.h"
#include <termios.h>
#include <fcntl.h>
#include <sys/select.h>
#include <time.h>

//Función para imprimir la información del sistema.
void print_info(){
    char modelo[256]="";                                //Almacena el modelo de la CPU
    char fabric[256]="";                                //Almacena el fabricante de la CPU
    int number_rc, number_vc;                           //Núcleos reales y virtuales
    float MemTotal, SwapTotal, UsedSpace, UsedSwap;

    cpu_model_fabric(modelo,fabric);                    //Llena modelo y fabricante
    real_cores(&number_rc);                             //Obtiene núcleos reales
    virtual_cores(&number_vc);                          //Obtiene núcles virtuales

    meminfo(&MemTotal,&SwapTotal,&UsedSpace,&UsedSwap); //Lee información de memoria

    printf("\033[H\033[J");                             //Limpia la pantalla
    //Imprime la información en la pantalla
    printf("Modelo         : %s\n", modelo);
    printf("Fabricante     : %s\n", fabric);
    printf("Núcleos Virtuales : %d\n", number_vc);
    printf("Núcleos Reales    : %d\n", number_rc);
    cpu_usage(); //Muestra el uso de la CPU en MB
    printf("Memoria Total  : %.2f MB\n", MemTotal / 1024);
    printf("Swap Total     : %.2f MB\n", SwapTotal / 1024);
    printf("Used Mem       : %.2f%%\n", (UsedSpace / MemTotal) * 100);
    printf("Used Swap      : %.2f%%\n", (UsedSwap / SwapTotal) * 100);
    //Muestra las opciones de interrupción del programa
    printf("\n'q' Para salir.");                        
    printf("\n'ctrl + c' Para salir. \n");
}
/**
 * Cambia el modo de entrada del terminal.
 * Si `enable` es 1, pone el terminal en modo no canónico (sin enter).
 * Si `enable` es 0, restaura el modo anterior.
 */ 
void set_input_mode(int enable) {
    static struct termios oldt, newt;

    if (!enable) {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);                //Restaura la configuración
        return;
    }

    tcgetattr(STDIN_FILENO, &oldt);                             //Obtiene la configuración actual
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);                           //Desactiva modo canónico y eco
    newt.c_cc[VMIN] = 1;                                        //Espera mínimo un caracter 
    newt.c_cc[VTIME] = 0;                                       //Sin tiempo de espera adicional

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);                    //Actualiza la configuración
}

/**
 * Inicia la interfaz en el terminal.
 * Actualiza la pantalla cada segundo y permite salir presionando 'q' o la combinación de teclas 'ctrl + c'.
 */
void start_interface(){
    set_input_mode(1);

    char c = 0;
    while (1) {
        print_info();

        // Esperar 1 segundo o tecla del usuario
        fd_set set;
        struct timeval timeout;
        FD_ZERO(&set);
        FD_SET(STDIN_FILENO, &set);
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        int rv = select(STDIN_FILENO+1, &set, NULL, NULL, &timeout);
        if (rv > 0) {
            read(STDIN_FILENO, &c, 1);
            if (c == 'q') break;
        }
    }

    set_input_mode(0);
}
