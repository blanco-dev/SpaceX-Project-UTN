#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astronauta.h"
#include "naves.h"
#include "menu.h"
#define DIM_MAX_ARCHI 15
#define DIM_MAX_STR 20

// VOID inicioPredeterminado(recibe todos los archivos)
//creamos 3 (para poder utilizar al menos la nave mas mala)
//creamos 1 nave de cada tipo asi el usuario puede seguir creando naves hasta un maximo de 6
//misiones reseatado a 0

void menuPrincipal(char archivoAstronautas[],char archivoNaves[],char archivoMisiones[]) {
    int opsw;

    pantallaDeCarga();
    limpiarPantalla();

    do {
        logoUTN();

        printf("Bienvenido, que desea elegir? \n");

        printf("1. Opciones Astronauta \n");
        printf("2. Opciones Naves \n");
        printf("3. Opciones Misiones \n");


        printf("\nIngrese su opcion: ");
        scanf("%i",&opsw);


        limpiarPantalla();

        switch(opsw) {
        case 1:
            menuAstronauta(archivoAstronautas);
            break;
        case 2:
            menuNaves(archivoNaves);
            break;
        case 3:
            break;
        default:
            break;
        }

    } while(validarOpcionMenu(opsw));

}

void logoUTN() {
    puts(" .----------------.  .----------------.  .------------------.      ");
    puts("| .--------------. || .--------------. || .---------------. |      ");
    puts("| | _____  _____ | || |  _________   | || |  ____  _____  | |      ");
    puts("| ||_   _||_   _|| || | |  _   _  |  | || | |_   \\|_   _| | |     ");
    puts("| |  | |    | |  | || | |_/ | | \\_|  | || |   |   \\ | |   | |    ");
    puts("| |  | |    | |  | || |     | |      | || |   | |\\ \\| |   | |    ");
    puts("| |   \\ '--' /   | || |    _| |_     | || |  _| |_\\   |   | |    ");
    puts("| |    `.__.'    | || |   |_____|    | || | |_____|\\__|   | |     ");
    puts("| |              | || |              | || |               | |      ");
    puts("| '--------------' || '--------------' || '---------------' |      ");
    puts(" '----------------'  '----------------'  '-----------------'       ");
    puts("\n");
}


int validarOpcionMenu(int dato) {
    int maximo=3;
    if (dato < 0 || dato > maximo) {
        printf("Ingrese una opcion valida por favor \n \n");
        return 1;
    } else {
        return 0;
    }


}



void pantallaDeCarga() {
    puts("-------------------------------------------------------------------------------------------------------------------------------------");
    puts("|     SSSSSSSSSSSSSSS                                                                                      XXXXXXX       XXXXXXX     |");
    puts("|   SS:::::::::::::::S                                                                                     X:::::X       X:::::X     |");
    puts("|  S:::::SSSSSS::::::S                                                                                     X:::::X       X:::::X     |");
    puts("|  S:::::S     SSSSSSS                                                                                     X::::::X     X::::::X     |");
    puts("|  S:::::S             ppppp   ppppppppp       aaaaaaaaaaaaa        cccccccccccccccc      eeeeeeeeeeee       X:::::X   X:::::X       |");
    puts("|  S:::::S             p::::ppp:::::::::p      a::::::::::::a     cc:::::::::::::::c    ee::::::::::::ee      X:::::X X:::::X        |");
    puts("|   S::::SSSS          p:::::::::::::::::p     aaaaaaaaa:::::a   c:::::::::::::::::c   e::::::eeeee:::::ee     X:::::X:::::X         |");
    puts("|    SS::::::SSSSS     pp::::::ppppp::::::p             a::::a  c:::::::cccccc:::::c  e::::::e     e:::::e      X:::::::::X          |");
    puts("|      SSS::::::::SS    p:::::p     p:::::p      aaaaaaa:::::a  c::::::c     ccccccc  e:::::::eeeee::::::e      X:::::::::X          |");
    puts("|         SSSSSS::::S   p:::::p     p:::::p    aa::::::::::::a  c:::::c               e:::::::::::::::::e      X:::::X:::::X         |");
    puts("|              S:::::S  p:::::p     p:::::p   a::::aaaa::::::a  c:::::c               e::::::eeeeeeeeeee      X:::::X X:::::X        |");
    puts("|              S:::::S  p:::::p    p::::::p  a::::a    a:::::a  c::::::c     ccccccc  e:::::::e             XX:::::X   X:::::XX      |");
    puts("|  SSSSSSS     S:::::S  p:::::ppppp:::::::p  a::::a    a:::::a  c:::::::cccccc:::::c  e::::::::e           X::::::X     X::::::X     |");
    puts("|  S::::::SSSSSS:::::S  p::::::::::::::::p   a:::::aaaa::::::a   c:::::::::::::::::c   e::::::::eeeeeeee   X:::::X       X:::::X     |");
    puts("|  S:::::::::::::::SS   p::::::::::::::pp     a::::::::::aa:::a   cc:::::::::::::::c    ee:::::::::::::e   X:::::X       X:::::X     |");
    puts("|   SSSSSSSSSSSSSSS     p::::::pppppppp        aaaaaaaaaa  aaaa     cccccccccccccccc      eeeeeeeeeeeeee   XXXXXXX       XXXXXXX     |");
    puts("|                       p:::::p                                                                                                      |");
    puts("|                       p:::::p                                                                                                      |");
    puts("|                      p:::::::p                                                                                                     |");
    puts("|                      p:::::::p                                                                                                     |");
    puts("|                      p:::::::p                                                                                                     |");
    puts("|                      ppppppppp                                                                                                     |");
    puts("-------------------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("\t \t \t \t \t \t \t \t \t \t\t By: Leonardo Caimmi, Matias Blanco & Fabrizio Golisciano \n");
    system("pause");
}

void menuAstronauta(char archivoAstronauta[]) {
    char op;
    int opsw;

    do {

        dibujoAstronauta();

        printf("Que desea hacer?: ");
        scanf("%i",&opsw);

        limpiarPantalla();

        switch(opsw) {
        case 1:
            cargarUnAstroToArchivo(archivoAstronauta);
            break;
        case 2:
            cargarAstroModificado(archivoAstronauta);
            break;
        case 3:
            opcionMostrarAstronautas(archivoAstronauta);
            break;
        case 4:
            elegirLaConsulta(archivoAstronauta);
            break;
        case 5:
            break;
        default:
            printf("Por favor ingrese un dato valido \n");
            break;
        }

        printf("Quiere volver al menu de astronauta? s/n: ");
        fflush(stdin);
        op = getch(op);
        limpiarPantalla();

    } while(op=='s');
}

void opcionMostrarAstronautas(char archivoAstro[]) {
    int opsw,estado;
    char op;
    int validosAstro= contarRegistros(archivoAstro);
    int tam = validosAstro;
    stAstronauta * arregloAstro;
    arregloAstro= crearArregloDinamicoAstro(arregloAstro,tam);

    archivoToArregloAstro(arregloAstro,archivoAstro);

    do {

        puts("--------------------------------------------------------");
        puts("1. Mostrar todos los astronautas en la base de datos");
        puts("2. Mostrar los astronautas disponibles (Estado= 1)");
        puts("3. Mostrar los astronautas dados de baja (Estado= 0)");
        puts("--------------------------------------------------------");
        opsw= preguntarDato();
        limpiarPantalla();
        switch(opsw) {
        case 1:
            mostrarAstronautas(archivoAstro);
            break;
        case 2:
            estado = 1;
            buscarAstronautasPorEstado(arregloAstro,estado,validosAstro);
            break;
        case 3:
            estado = 0;
            buscarAstronautasPorEstado(arregloAstro,estado,validosAstro);
            break;
        default:
            printf("Por favor ingrese una opcion valida \n");
            break;
        }

        printf("Quiere seguir mostrando astronautas? s/n: ");
        fflush(stdin);
        op = getch(op);
        limpiarPantalla();

    } while(op=='s');
}

void dibujoAstronauta() {
    puts("----------------------------------------");
    puts("        _..._                          ");
    puts("      .'     '.      _                 ");
    puts("     /    .-''-\\   _/ \\              ");
    puts("   .-|   /: ^ ^ |  |   |                ");
    puts("   |  \\  |:    /.-'-./                ");
    puts("   | .-'-;:__.'    =/                  ");
    puts("   .'=  *=| UTN _.='                   ");
    puts("  /   _.  |    ;                       ");
    puts(" ;-.-'|    \\   |                      ");
    puts("/   | \\    _\\  _\\                   ");
    puts("\\__/'._;.  ==' ==\\                   ");
    puts("         \\    \\   |                  ");
    puts("         /    /   /                    ");
    puts("         /-._/-._/                     ");
    puts("        \\   `\\  \\                   ");
    puts("          `-._/._/                     ");
    puts("----------------------------------------");
    puts("\t   MENU ASTRONAUTAS");
    puts("----------------------------------------\n");
    puts("1. Dar de Alta a un astronauta (Crear uno nuevo)");
    puts("2. Modificar un astronauta");
    puts("3. Mostrar astronautas");   //1. TODOS 2.Disponibles 3. Dados de baja
    puts("4. Consultar datos de astronautas");
    puts("5. Volver al menu principal");

}

void menuNaves(char archivoNaves[]){
    char op = 's';
    int opsw = 0;
    int validos = 0;
    stNaves arrNave[DIM_MAX_STR];
    do {

        dibujoNaves();
        printf("Que desea realizar? ");
        fflush(stdin);
        scanf("%i", &opsw);
        limpiarPantalla();

        switch(opsw) {
        case 1:
            validos = cargarArregloNave(arrNave, archivoNaves);
            printf("Validos: %i",validos);
            arregloNavesToArchivoNaves(archivoNaves, arrNave, validos);
            break;
        case 2:  // Modificar nave
            break;
        case 3:
            opcionMostrarNaves(archivoNaves);
            break;
        case 4:   // Consultar nave
            break;
        case 5: // Menu principal
            break;
        default:
            printf("Has ingresado mal un dato, vuelve a intentarlo!!");
            break;
        }

    } while(op=='s');

}

void dibujoNaves() {
    puts("----------------------------------------------------------");
    puts(" /\/\/\                            /  \                   ");
    puts("| \  / |                         /      \                 ");
    puts("|  \/  |                       /          \               ");
    puts("|  /\  |----------------------|     /\     |              ");
    puts("| /  \ |                      |    /  \    |              ");
    puts("|/    \|                      |   /    \   |              ");
    puts("|\    /|                      |  | (  ) |  |              ");
    puts("| \  / |                      |  | (  ) |  |              ");
    puts("|  \/  |                 /\   |  |      |  |   /\         ");
    puts("|  /\  |                /  \  |  |      |  |  /  \        ");
    puts("| /  \ |               |----| |  |      |  | |----|       ");
    puts("|/    \|---------------|    | | /|   .  |\ | |    |       ");
    puts("|\    /|               |    | /  |   .  |  \ |    |       ");
    puts("| \  / |               |    /    |   .  |    \    |       ");
    puts("|  \/  |               |  /      |   .  |      \  |       ");
    puts("|  /\  |---------------|/        |   .  |        \|       ");
    puts("| /  \ |              /   UTN    |   .  |  UTN    \       ");
    puts("|/    \|              (          |      |          )      ");
    puts("|/\/\/\|               |    | |--|      |--| |    |       ");
    puts("------------------------/  \-----/  \/  \-----/  \--------");
    puts("                        \\//     \\//\\//     \\//        ");
    puts("                         \/       \/  \/       \/         ");
    puts("----------------------------------------------------------");

    puts("----------------------------------------------------------");
    puts("\t  MENU NAVES");
    puts("----------------------------------------------------------");
    puts("1. Cargar una nave");
    puts("2. Modificar una nave");
    puts("3. Mostrar todas las naves");  // Estado: (0- mantenimiento 1- Lista para su uso 2- Actualmente en misión 3- De baja)
    puts("4. Consultar datos de naves");
    puts("5. Volver al menu principal");
}

void opcionMostrarNaves(char archivoNaves[]) {
    char opsw;

    puts("--------------------------------------------------------");
    puts("1. Mostrar todas las naves en la base de datos");
    puts("2. Mostrar las naves disponibles (Estado = Lista para el uso)");
    puts("3. Mostrar las naves dadas de baja (Estado = Dadas de baja");
    puts("4. Mostrar las naves en mantenimiento (Estado = Mantenimiento");
    puts("5. Mostrar las naves en mision (Estado = Actualmente en mision)");
    puts("--------------------------------------------------------");

    int op= preguntarDato();
    limpiarPantalla();

    do {
        switch(op) {
        case 1:
            mostrarTodasLasNaves(archivoNaves);
            break;
        case 2:
            mostrarNavesXEstado(archivoNaves, 1);
            break;
        case 3:
            mostrarNavesXEstado(archivoNaves, 3);
            break;
        case 4:
            mostrarNavesXEstado(archivoNaves, 0);
            break;
        case 5:
            mostrarNavesXEstado(archivoNaves, 2);
            break;
        default :
            printf("Has ingresado mal un dato, vuelve a intentarlo!!");
            break;
        }

        printf("Quiere seguir mostrando naves? s/n: ");
        fflush(stdin);
        opsw = getch(opsw);
        limpiarPantalla();

    } while(opsw=='s');
}

