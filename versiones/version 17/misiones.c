#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astronauta.h"
#include "naves.h"
#include "menu.h"
#include "misiones.h"
#define DIM_MAX_ARCHI 15
#define DIM_MAX_STR 20

// crear una mision

stMision crearUnaMision(char archivoMisiones[], char archivoNaves[], char archivoAstro[])
{
    char tipoNave[DIM_MAX_STR];
    int dato = 0;
    stMision aux;
    aux.IDMision = 1;
    do
    {
        mostrarTodasLasNaves(archivoNaves);
        printf("Ingrese el ID de la nave que desea utilizar: ");
        aux.IDNave = preguntarDato();
    }
    while (validarIdMision(archivoNaves,aux.IDNave) == 0 && validarEstadoNaveMision(archivoNaves,aux.IDNave) == 0);

    retornarTipoDeNave(archivoNaves,tipoNave,aux.IDNave); // esto es para saber el tipo de nave

    aux.estado = 1;
    elegirDestino(archivoMisiones, aux.destino);

    elegirCargamento(archivoMisiones,aux.cargamento,tipoNave);




    // tripulantes
    // detalle
    return aux;
}

void mostrarDestino()
{
    puts("--------------------Destinos--------------------");
    puts("1. Orbita Terrestre");
    puts("2. Estacion Espacial Internacional");
    puts("3. La Luna");
    puts("4. Marte");
    puts("5. Saturno");
}
void elegirDestino(char archivoMisiones[], char destino[])
{

    int aux = 0;
    int opsw = 0;
    int flag = 0;

    do
    {
        mostrarDestino();
        puts("Ingrese el destino que desea ir: ");
        opsw = preguntarDato();

        switch(opsw)
        {
        case 1:
            flag = validarDestinoMision(archivoMisiones, "Orbita Terrestre");
            if (flag == 1 )
            {
                puts("Ya existe una mision a ese destino, intente con otro destino..");
            }
            else
            {
                strcpy(destino,"Orbita Terrestre");
                flag = 0;
            }
            break;
        case 2:
            flag = validarDestinoMision(archivoMisiones, "EEI");
            if (flag == 1)
            {
                puts("Ya existe una mision a ese destino, intente con otro destino..");
            }
            else
            {
                strcpy(destino, "EEI");
                flag = 0;
            }
            break;
        case 3:
            flag = validarDestinoMision(archivoMisiones, "La luna");
            if (flag == 1)
            {
                puts("Ya existe una mision a ese destino, intente con otro destino..");
            }
            else
            {
                strcpy(destino, "La luna");
                flag = 0;
            }
            break;

        case 4:
            flag = validarDestinoMision(archivoMisiones, "Marte");
            if (flag == 1)
            {
                puts("Ya existe una mision a ese destino, intente con otro destino..");
            }
            else
            {
                strcpy(destino, "Marte");
                flag = 0;
            }
            break;

        case 5:
            flag = validarDestinoMision(archivoMisiones, "Saturno");
            if (flag == 1)
            {
                puts("Ya existe una mision a ese destino, intente con otro destino..");
            }
            else
            {
                strcpy(destino, "Saturno");
                flag = 0;
            }
            break;

        default:
            printf("Dato incorrecto, ingrese una opcion valida...");
            break;
        }
    }
    while(flag == 1);
}
int validarDestinoMision(char archivoMisiones[], char destino[])
{
    stMision aux;
    int flag = 0;
    FILE * buffer = fopen(archivoMisiones, "rb");

    if (buffer != NULL)
    {
        while (fread(&aux,sizeof(stMision),1,buffer) > 0)
        {
            if (strcmpi(aux.destino,destino) == 0)
            {
                flag = 1;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("Error en el archivo");
    }

    return flag;
}
int validarIdMision(char archivoNaves[], int datoID)
{
    int flag = 0;
    stNaves aux;
    FILE* buffer = fopen(archivoNaves,"rb");

    if (buffer != NULL)
    {
        while(fread(&aux,sizeof(stNaves),1,buffer) > 0 && flag == 0)
        {
            if (aux.idNave == datoID)
            {
                flag = 1;
            }
        }
        fclose(buffer);
    }
    else
    {
        puts("ERROR, archivo invalido");
    }
    if(flag == 0)
    {
        puts("ERROR, Id incorrecto...");
    }

    return flag;
}
int validarEstadoNaveMision(char archivoNaves[], int datoID)
{

    int flag = 0;
    stNaves aux;
    FILE* buffer = fopen(archivoNaves,"rb");

    if (buffer != NULL)
    {
        while(fread(&aux,sizeof(stNaves),1,buffer) > 0 && flag == 0)
        {
            if (aux.estado == 1 && aux.idNave == datoID)
            {
                flag = 1;
            }
        }
        fclose(buffer);
    }
    else
    {
        puts("ERROR, archivo invalido");
    }

    if(flag == 0)
    {
        puts("La nave no esta disponible");
    }
    return flag;
}

void mostrarCargamento()
{
    puts("--------------------Tipos de Cargamento--------------------");
    puts("1. Satelite");
    puts("2. Insumos para la EEI");
    puts("3. R.O.V.E.R.");
    puts("4. Aparatos Electronicos");
    puts("5. Kit de primeros auxilios");
    puts("6. Kit mecanico");
}
void elegirCargamento(char archivoMisiones[], char cargamento[DIM_MAX_STR][DIM_MAX_STR], char tipoNave[])
{
    int i=1;
    int flag = 0;
    int opsw = 0;
    int dato = 0;
    int max= disponibilidadCargamentoMision(tipoNave);
    char op = 's';




    do
    {
        mostrarCargamento();
        puts("Ingrese el tipo de cargamento que desea llevar: ");
        opsw = preguntarDato();
        switch(opsw)
        {
        case 1:
            strcpy(cargamento[i],"Satelite");
            break;
        case 2:
            strcpy(cargamento[i],"Insumos para la EEI");
            break;
        case 3:
            strcpy(cargamento[i],"R.O.V.E.R.");
            break;
        case 4:
            strcpy(cargamento[i],"Aparatos Electronicos");
            break;
        case 5:
            strcpy(cargamento[i],"Kit de primeros auxilios");
            break;
        case 6:
            strcpy(cargamento[i],"Kit mecanico");
            break;
        default:
            printf("Dato incorrecto, ingrese una opcion valida...");
            break;

        }
        puts("(S/N) para cargar otro cargamento");
        fflush(stdin);
        op = getch(op);
    i++;
    }
    while(op== 's' || i <= max);

    if(i == max)
    {
        puts("El inventario de la nave ya esta lleno. No puede llevar mas cargamento");
    }
}

int disponibilidadCargamentoMision(char tipoNave)
{

    int dato=0;

    if(strcmpi(tipoNave, "starship"))
    {
        dato= 10;
        return dato;
    }

    if(strcmpi(tipoNave, "falcon 9"))
    {
        dato= 7;
        return dato;
    }

    if(strcmpi(tipoNave, "falcon heavy"))
    {
        dato= 5;
        return dato;
    }

    return 0;

}

void retornarTipoDeNave(char archivoNaves[], char tipoNave[], int datoID)
{
    FILE* buffer= fopen(archivoNaves,"rb");
    stNaves aux;

    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stNaves),1,buffer) >0)
        {
            if(datoID == aux.idNave)
            {
                strcpy(tipoNave,aux.tipoDeNave);
            }
        }


        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

}

void cargarTripulantesMision(char archivoAstro[],char tipoNave[],int IDTripulantes[])
{
    char op;
    int i=0;
    int dato = 0;
    int maxi= disponibilidadTripulantesMision(tipoNave);
    do{
    mostrarAstronautasDisponibles(archivoAstro);
    puts("------------Estos son todos los astronautas disponibles---------------\n");
    puts("Ingrese el ID del astronauta que desea mandar a la mision");
    puts("|Aclaracion: es necesario completar el maximo de la nave elegida|");
    printf("MAXIMO :%i \n",maxi);
    dato= preguntarDato();

    i++;
    printf("%i de %i",i,maxi);


    //cargar un tripulante a la mision


    //modificar estado a 3


    limpiarPantalla();
    }while(i <= maxi);

    if(i == maxi)
    {
        puts("Se alcanzo el limite maximo de tripulantes");
    }


}

int disponibilidadTripulantesMision(char tipoNave[])
{
    int dato=0;

    if(strcmpi(tipoNave, "starship"))
    {
        dato= 7;
        return dato;
    }

    if(strcmpi(tipoNave, "falcon 9"))
    {
        dato= 5;
        return dato;
    }

    if(strcmpi(tipoNave, "falcon heavy"))
    {
        dato= 3;
        return dato;
    }
}

void mostrarAstronautasDisponibles(char archivoAstro[])
{
    stAstronauta aux;
    FILE * buffer= fopen(archivoAstro, "rb");

    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stAstronauta),1,buffer)>0)
        {
            if(aux.estado == 1)
            {
                mostrarUnAstronauta(aux);
            }
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }


}


