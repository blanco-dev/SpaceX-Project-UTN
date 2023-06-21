#ifndef MISIONES_H_INCLUDED
#define MISIONES_H_INCLUDED
#define DIM_MAX_ARCHI 15
#define DIM_MAX_STR 20
#define DIM_MAX_TXT 256

typedef struct {
    int IDMision;
    int IDNave;
    int estado; // 1.Listo 2.En vuelo 3.Retornada 4.Cancelada 5.Fallida)
    char destino[DIM_MAX_STR];
    char cargamento[DIM_MAX_STR];
    int tripulantes[DIM_MAX_STR];
    char detalleMision[DIM_MAX_TXT];

} stMision;

//varios
stMision retornarMisionXID(char archivoMisiones[], int datoID);


// validaciones
int validarIdMision(char archivoMisiones[], int datoID);
int validarDestinoMision(char archivoMisiones[], char destino[]);
int validarEstadoNaveMision(char archivoNaves[], int datoID);
int validarCaracteresEnEntero(int dato);
int validarSiMisionLista(char archivoMisiones[], int misionID);


// crear mision
stMision crearUnaMision(char archivoMisiones[], char archivoNaves[], char archivoAstro[]);
void elegirDestino(char archivoMisiones[], char destino[]);
void elegirCargamento(char cargamento[]);
void retornarTipoDeNave(char archivoNaves[], char tipoNave[], int datoID);
void cargarTripulantesMision(char archivoAstro[],int maxi,int IDTripulantes[]);
int disponibilidadTripulantesMision(char tipoNave[]);
void cambiarEstadoAstronauta(char archivoAstro[],int datoID,int estado);
void elegirDetallesDeLaMision(char detalles[]);
void detallesMisionXdestino(char detalles[],char destino[]);
int cantidadMaximaDeTripulantes(char archivoNaves[],int naveID);



// mostrar
void mostrarDestino();
void mostrarCargamento();
void mostrarAstronautasDisponibles(char archivoAstro[]);
void mostrarTodasLasNavesDisponibles(char archivoNaves[]);
void mostrarUnaMision(stMision aux,int maxTripulantes);


//archivo
void cargarArchivoMisiones(char archivoAstro[], char archivoNaves[], char archivoMision[]);


//modificar
void modificarMision(char archivoAstro[],char archivoMisiones[], char archivoNaves[]);
int posibilidadDeEstadoMision(int numRand);
void cambiarEstadoDeTripulantesMision(char archivoAstro[], int cantTripu,stMision auxMision, int estado);
void lanzarMision(stMision* auxMision, char archivoAstro[], char archivoNaves[]);
void cambiarEstadoDeNaveMision(char archivoNaves[],stMision auxMision,int estado);

#endif // MISIONES_H_INCLUDED
