#include "tui.h"
#include "meminfo_manip.h"
#include "cpuinfo_manip.h"
#include <termios.h>
#include <fcntl.h>
#include <sys/select.h>
#include <time.h>

void print_info(){
    char modelo[256]="";
    char fabric[256]="";
    int number_rc, number_vc;
    float MemTotal, SwapTotal, UsedSpace, UsedSwap;

    cpu_model_fabric(modelo,fabric);
    real_cores(&number_rc);
    virtual_cores(&number_vc);

    meminfo(&MemTotal,&SwapTotal,&UsedSpace,&UsedSwap);

    printf("\033[H\033[J"); // Clear screen
    printf("Modelo         : %s\n", modelo);
    printf("Fabricante     : %s\n", fabric);
    printf("Núcleos Virtuales : %d\n", number_vc);
    printf("Núcleos Reales    : %d\n", number_rc);
    cpu_usage();
    printf("Memoria Total  : %.2f MB\n", MemTotal / 1024);
    printf("Swap Total     : %.2f MB\n", SwapTotal / 1024);
    printf("Used Mem       : %.2f%%\n", (UsedSpace / MemTotal) * 100);
    printf("Used Swap      : %.2f%%\n", (UsedSwap / SwapTotal) * 100);
    printf("\n'q' Para salir.");
    printf("\n'ctrl + c' Para salir. \n");
}

void set_input_mode(int enable) {
    static struct termios oldt, newt;

    if (!enable) {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return;
    }

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);
    newt.c_cc[VMIN] = 1;
    newt.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

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
