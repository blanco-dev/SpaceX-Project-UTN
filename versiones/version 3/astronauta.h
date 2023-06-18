#ifndef ASTRONAUTA_H_INCLUDED
#define ASTRONAUTA_H_INCLUDED
#define DIM_MAX_STR 20

///Estructura astronauta

typedef struct
{

int id;///automatico
char nombre[DIM_MAX_STR];
char apellido[DIM_MAX_STR];
char apodo[DIM_MAX_STR];
int edad;
char nacionalidad[DIM_MAX_STR];
char especialidad[DIM_MAX_STR]; //(piloto, astrofísico, ingeniero espacial, biólogo, etc)
int horasDeVuelo;           ///automatico
int cantMisionesRealizadas; ///automatico
int horasEnEEI;             ///automatico
int estado; //(1- Activo 2- Retirado)

}stAstronauta;


void limpiarPantalla();
///Prototipados astronauta

stAstronauta crearUnAstro(int* idAstro);
int validarString(char auxNombre[]);
int validarEdad(int edad);
int validarNacionalidad(char nacionalidad[]);
int validarNacionalidad(char nacionalidad[]);
void verificarEspecialidad(char especialidad[]);
void mostrarEspecialidad();

#endif // ASTRONAUTA_H_INCLUDED
