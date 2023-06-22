#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#define DIM_MAX_ARCHI 15
#define DIM_MAX_STR 20

//menu
void menuPrincipal(char archivoAstronautas[],char archivoNaves[],char archivoMisiones[]);
int validarOpcionMenu(int dato);
void pantallaDeCarga();
void logoUTN();

//menu astro
void menuAstronauta(char archivoAstronauta[]);
void opcionMostrarAstronautas(char archivoAstro[]);
void dibujoAstronauta();

//menu nave
void dibujoNaves();
void opcionMostrarNaves(char archivoNaves[]);
void menuNaves(char archivoNaves[]);

// menu misiones




#endif // MENU_H_INCLUDED
