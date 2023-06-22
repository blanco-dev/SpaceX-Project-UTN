#ifndef MISIONES_H_INCLUDED
#define MISIONES_H_INCLUDED
#define DIM_MAX_ARCHI 15
#define DIM_MAX_STR 20

typedef struct {
    int IDMision;
    int IDNave;
    int estado; // 1.Listo 2.En vuelo 3.Retornada 4.Cancelada 5.Fallida)
    char destino[DIM_MAX_STR];
    char cargamento[DIM_MAX_STR][DIM_MAX_STR];
    int tripulantes[DIM_MAX_STR];
    char detalleMision[DIM_MAX_STR];

} stMision;

// validaciones
int validarDestinoMision(char archivoMisiones[], char destino[]);
int validarIdMision(char archivoNaves[], int datoID);
int validarEstadoNaveMision(char archivoNaves[], int datoID);
int validarCaracteresEnEntero(int dato);

// crear mision
stMision crearUnaMision(char archivoMisiones[], char archivoNaves[], char archivoAstro[]);
void elegirDestino(char archivoMisiones[], char destino[]);
int disponibilidadCargamentoMision(char tipoNave);
void retornarTipoDeNave(char archivoNaves[], char tipoNave[], int datoID);
void mostrarDestino();
void mostrarCargamento();
void elegirDestino(char archivoMisiones[], char destino[]);
void elegirCargamento(char archivoMisiones[], char cargamento[DIM_MAX_STR][DIM_MAX_STR], char tipoNave[]);

void cambiarEstadoAstronauta(char archivoAstro[],int datoID);

// mostrar



// consulta

#endif // MISIONES_H_INCLUDED
