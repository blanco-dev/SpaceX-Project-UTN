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
void validarTipoNave(char tipoNave[]);
int validarCantNave(int cont);
int validarSiNaveEstaOcupada(int estado);
int validarIDNave(char archivoNave[], int dato);


// Cargar nave
stNaves cargarUnaNave(char archivoNaves[]);
int encontrarUltimaIDNave(char archivoNaves[]);
void tiposDeNave();

// archivos
void cargarArchivoNaves(char archivoNaves[]);
int contarRegistrosNave(char archivoNaves[]);


// mostrar
void mostrarUnaNave(stNaves aux);
void mostrarTodasLasNaves(char archivoNaves[]);
void mostrarNavesXEstado(char archivoNaves[], int estado);

// modificar
int validarIDNave(char archivoNave[], int dato);
int encontrarPosicionNaveXID(char archivoNaves[], int IDNave);
void cargarNaveModificada(char archivoNaves[]);
void modificarUnaNave(stNaves * aux);



// arreglo
int archivoToArregloNaves(char archivoNaves[],stNaves arrNaves[]);
stNaves* crearArregloDinamicoNave(int tam);
void mostrarArregloNave(stNaves arrNaves[], int validos);

// consulta

void ConsultaNave(char archivoNaves[]);
void opcionesParaConsultarNaves();
void menuConsultarPorNave(char archivoNaves[],stNaves arrNaves[], int validos);
int buscarNaveXID(stNaves arr[],int validos, int datoID);






#endif // NAVES_H_INCLUDED



