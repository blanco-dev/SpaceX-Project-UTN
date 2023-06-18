#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astronauta.h"
#include "naves.h"
#define DIM_MAX_ARCHI 15
#define DIM_MAX_STR 20


// VOID inicioPredeterminado(recibe todos los archivos)
    //creamos 3 (para poder utilizar al menos la nave mas mala)
    //creamos 1 nave de cada tipo asi el usuario puede seguir creando naves hasta un maximo de 6
    //misiones reseatado a 0

void menuPrincipal(char archivoAstronautas[],char archivoNaves[],char archivoMisiones[])
{
    int opsw;

    pantallaDeCarga();
    limpiarPantalla();

    do
    {

        printf("Bienvenido, que desea elegir? \n");

        printf("1. Opciones Astronauta \n");
        printf("2. Opciones Naves \n");
        printf("3. Opciones Misiones \n");


        printf("\nIngrese su opcion: ");
        scanf("%i",&opsw);


        limpiarPantalla();

        switch(opsw)
        {
        case 1:
            menuAstronauta(archivoAstronautas);
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
        }

    }
    while(validarOpcionMenu(opsw));

}


int validarOpcionMenu(int dato)
{
    int maximo=3;
    if (dato < 0 || dato > maximo)
    {
        printf("Ingrese una opcion valida por favor \n \n");
        return 1;
    }
    else
    {
        return 0;
    }


}



void pantallaDeCarga()
{
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

void menuAstronauta(char archivoAstronauta[])
{
    char op;
    int opsw;

    do
    {

    dibujoAstronauta();

    printf("Que desea hacer?: ");
    scanf("%i",&opsw);

    limpiarPantalla();

    switch(opsw)
    {
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

    }while(op=='s');
}

void opcionMostrarAstronautas(char archivoAstro[])
{
    int opsw,estado;
    char op;
    int validosAstro= contarRegistros(archivoAstro);
    int tam = validosAstro;
    stAstronauta * arregloAstro;
    arregloAstro= crearArregloDinamicoAstro(arregloAstro,tam);

    archivoToArregloAstro(arregloAstro,archivoAstro);

    do
    {

    puts("--------------------------------------------------------");
    puts("1. Mostrar todos los astronautas en la base de datos");
    puts("2. Mostrar los astronautas disponibles (Estado= 1)");
    puts("3. Mostrar los astronautas dados de baja (Estado= 0)");
    puts("--------------------------------------------------------");
    opsw= preguntarDato();
    limpiarPantalla();
    switch(opsw)
    {
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

    }while(op=='s');
}


void dibujoAstronauta()
{
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





