#ifndef ASTRONAUTA_H_INCLUDED
#define ASTRONAUTA_H_INCLUDED
#define DIM_MAX_ARCHI 15
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

stAstronauta crearUnAstro(char astronauta[]);
int validarString(char auxNombre[]);
int validarEdad(int edad);
int validarNacionalidad(char nacionalidad[]);
void validarEspecialidad(char especialidad[]);
void mostrarEspecialidad();
int verificarEstadoAstro(int datoEstado);
int validarEstado(int datoEstado);

void cargarUnAstroToArchivo(char archivoAstronautas[]);
void mostrarAstronautas(char archivoAstronautas[]);
void mostrarUnAstronauta(stAstronauta aux);

int encontrarUltimaID(char astronauta[]);///autoincrementar ID


void modificarUnAstro(stAstronauta* astro);
int encontrarPosId(char archivoAstronautas[],int datoID);
void cargarAstroModificado(char archivoAstronauta[]);


void elegirLaConsulta(char astronauta[]);
void opcionesParaConsultarAstronauta();
void menuConsultarPorAstronauta(stAstronauta arregloAstro[],int validos);
int buscarIDastro(stAstronauta astro[],int idBuscado,int validos);
int buscarNombreAstro(stAstronauta arregloAstro[],char nombre[],int validos);
int buscarApellidoAstro(stAstronauta arregloAstro[],char apellido[],int validos);
int buscarApodoAstro(stAstronauta arregloAstro[],char apodo[],int validos);
int buscarPorEdadUnAstro(stAstronauta arregloAstro[],int dato,int validos);
int buscarPaisAstro(stAstronauta arregloAstro[],char auxPais[],int validos);
int buscarAstronautasPorEstado(stAstronauta arregloAstro[],int estadoAstro,int validos);
stAstronauta buscarAstroConMayorExpHorasVuelo(stAstronauta arregloAstro[],int validos);
stAstronauta buscarAstroConMayorExpEnMisiones(stAstronauta arregloAstro[],int validos);

#endif // ASTRONAUTA_H_INCLUDED
