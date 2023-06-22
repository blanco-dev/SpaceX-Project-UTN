#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astronauta.h"
#include "naves.h"
#include "menu.h"
#define DIM_MAX_ARCHI 15
#define DIM_MAX_STR 20

int main()
{
    char archivoAstronautas[DIM_MAX_ARCHI] = "astronautas";
    char archivoNaves[DIM_MAX_ARCHI]="naves";
    char archivoMisiones[DIM_MAX_ARCHI]="misiones";
    menuPrincipal(archivoAstronautas,archivoNaves,archivoMisiones);

    //cargarArchivoNaves(archivoNaves);
    //mostrarTodasLasNaves(archivoNaves);
    //ConsultaNave(archivoNaves);


    return 0;
}
