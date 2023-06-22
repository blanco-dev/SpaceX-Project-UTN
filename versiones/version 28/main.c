#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astronauta.h"
#include "nave.h"
#include "menu.h"
#include "misiones.h"
#include "windows.h"
#define DIM_MAX_ARCHI 15
#define DIM_MAX_STR 20


int main()
{
    srand(time(NULL));

    char archivoAstronautas[DIM_MAX_ARCHI] = "astronautas";
    char archivoNaves[DIM_MAX_ARCHI]="naves";
    char archivoMisiones[DIM_MAX_ARCHI]="misiones";



    menuPrincipal(archivoAstronautas,archivoNaves,archivoMisiones);






    //cargarArchivoMisiones(archivoAstronautas,archivoNaves,archivoMisiones);
    //mostrarTodasLasMisiones(archivoMisiones,archivoNaves);


    //modificarMision(archivoAstronautas,archivoMisiones,archivoNaves);



    return 0;
}
