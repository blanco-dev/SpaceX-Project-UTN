#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astronauta.h"
#include "naves.h"
#include "menu.h"
#include "misiones.h"
#define DIM_MAX_ARCHI 15
#define DIM_MAX_STR 20

int main()
{
    char archivoAstronautas[DIM_MAX_ARCHI] = "astronautas";
    char archivoNaves[DIM_MAX_ARCHI]="naves";
    char archivoMisiones[DIM_MAX_ARCHI]="misiones";
    //menuPrincipal(archivoAstronautas,archivoNaves,archivoMisiones);

    //cargarArchivoNaves(archivoNaves);
    //mostrarTodasLasNaves(archivoNaves);
    //ConsultaNave(archivoNaves);
    //stMision aux;
    //aux=crearUnaMision(archivoMisiones,archivoNaves,archivoAstronautas);
    cargarArchivoMisiones(archivoAstronautas,archivoNaves,archivoMisiones);
    //mostrarTodasLasMisiones(archivoMisiones,archivoNaves);

    return 0;
}
