#ifndef NAVES_H_INCLUDED
#define NAVES_H_INCLUDED
#define DIM_MAX_ARCHI 15
#define DIM_MAX_STR 20

typedef struct{
int id;
char tipoDeNave[DIM_MAX_STR]; //(Starship, Falcon 9, Falcon Heavy) sólo pueden ser esas tres naves, ningún otro tipo se acepta.
int CantidadDeVuelosRealizados;
int HorasDeVueloAcumuladas;
int estado; // (0- mantenimiento 1- Lista para su uso 2- Actualmente en misión 3- De baja)
}stNaves;

// validar
void validarTipoNave(char archivoNaves[]);

// Cargar nave
stNaves cargarUnaNave(char archivoNaves[]);
int encontrarUltimaIDNave(char archivoNaves[]);
void tiposDeNave();

// arreglo
int cargarArregloNave(stNaves arrNave[], char archivoNaves[]);



// archivos

// modificar ?

// consulta

#endif // NAVES_H_INCLUDED



