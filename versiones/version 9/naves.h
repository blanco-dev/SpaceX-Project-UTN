#ifndef NAVES_H_INCLUDED
#define NAVES_H_INCLUDED
#define DIM_MAX_ARCHI 15
#define DIM_MAX_STR 20

typedef struct{
int idNave;
char tipoDeNave[DIM_MAX_STR]; //(Starship, Falcon 9, Falcon Heavy) sólo pueden ser esas tres naves, ningún otro tipo se acepta.
int CantidadDeVuelosRealizados;
int HorasDeVueloAcumuladas;
int estado;// (0- mantenimiento 1- Lista para su uso 2- Actualmente en misión 3- De baja)
}stNaves;

///CARGA DE NAVE
stNaves cargarUnaNave(char naves[]);

int encontrarUltimaIDNave(char naves[]);
void validarTipoNave(char nave[]);

#endif // NAVES_H_INCLUDED
