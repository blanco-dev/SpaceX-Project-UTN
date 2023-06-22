#ifndef MISIONES_H_INCLUDED
#define MISIONES_H_INCLUDED
#define DIM_MAX_ARCHI 15
#define DIM_MAX_STR 20

typedef struct
{
    int IDMision;
    int IDNave;
    int estado; // 1.Listo 2.En vuelo 3.Retornada 4.Cancelada 5.Fallida)
    char destino[DIM_MAX_STR];
    char cargamento[DIM_MAX_STR]; //
    int tripulantes[DIM_MAX_STR];
    char detalleMision[DIM_MAX_STR];

}stMision;







#endif // MISIONES_H_INCLUDED
