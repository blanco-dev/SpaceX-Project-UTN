#ifndef MISIONES_H_INCLUDED
#define MISIONES_H_INCLUDED
#define DIM_MAX_ARCHI 15
#define DIM_MAX_STR 20
#define DIM_MAX_TXT

typedef struct {
    int IDMision;
    int IDNave;
    int estado; // 1.Listo 2.En vuelo 3.Retornada 4.Cancelada 5.Fallida)
    char destino[DIM_MAX_STR];
    char cargamento[DIM_MAX_STR];
    int tripulantes[DIM_MAX_STR];
    char detalleMision[DIM_MAX_TXT];

} stMision;

// validaciones
int validarIdMision(char archivoNaves[], int datoID);
int validarDestinoMision(char archivoMisiones[], char destino[]);
int validarEstadoNaveMision(char archivoNaves[], int datoID);
int validarCaracteresEnEntero(int dato);


// crear mision
stMision crearUnaMision(char archivoMisiones[], char archivoNaves[], char archivoAstro[]);
void elegirDestino(char archivoMisiones[], char destino[]);
void elegirCargamento(char cargamento[]);
int disponibilidadCargamentoMision(char tipoNave[]);
void retornarTipoDeNave(char archivoNaves[], char tipoNave[], int datoID);
void cargarTripulantesMision(char archivoAstro[],char tipoNave[],int IDTripulantes[]);
int disponibilidadTripulantesMision(char tipoNave[]);
void cambiarEstadoAstronauta(char archivoAstro[],int datoID);
void elegirDetallesDeLaMision(char detalles[]);
void detallesMisionXdestino(char detalles[],char destino[]);

// mostrar
void mostrarDestino();
void mostrarCargamento();
void mostrarAstronautasDisponibles(char archivoAstro[]);
void mostrarTodasLasNavesDisponibles(char archivoNaves[]);
void mostrarUnaMision(stMision aux,int maxTripulantes);



//archivo
void cargarArchivoMisiones(char archivoAstro[], char archivoNaves[], char archivoMision[]);





#endif // MISIONES_H_INCLUDED
