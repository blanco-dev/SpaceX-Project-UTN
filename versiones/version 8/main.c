#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astronauta.h"
#include "naves.h"
#include "menu.h"
#define DIM_MAX_ARCHI 15
#define DIM_MAX_STR 20
//**asdasadsasd
int main()
{
    char archivoAstronautas[DIM_MAX_ARCHI] = "astronautas";
    char archivoNaves[DIM_MAX_ARCHI]="naves";
    char archivoMisiones[DIM_MAX_ARCHI]="misiones";
<<<<<<< HEAD
    //menuPrincipal(archivoAstronautas,archivoNaves,archivoMisiones);
=======
    menuPrincipal(archivoAstronautas,archivoNaves,archivoMisiones);
>>>>>>> 9d369ad48dc6f93549f47499f72b754fa58ebeee
    //elegirLaConsulta(archivoAstronautas);
    //cargarAstroModificado(archivoAstronautas);

    stNaves arrNave[DIM_MAX_ARCHI];
<<<<<<< HEAD
 cargarArregloNave(arrNave, archivoNaves);
=======
    //cargarArregloNave(arrNave, archivoNaves);
>>>>>>> 9d369ad48dc6f93549f47499f72b754fa58ebeee

    return 0;
}
