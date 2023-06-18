#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astronauta.h"
#include "naves.h"
#define DIM_MAX_ARCHI 15
#define DIM_MAX_STR 20

// validar

void validarTipoNave(char archivoNaves[])
{

    int flag = 0, dato=0;
    tiposDeNave();
    dato=preguntarDato();
    do
    {
        switch(dato)
        {
        case 1:
            strcpy(archivoNaves,"StarShip");
            flag = 1;
            break;
        case 2:
            strcpy(archivoNaves,"Falcon 9");
            flag = 1;
            break;
        case 3:
            strcpy(archivoNaves,"Falcon Heavy");
            flag = 1;
            break;
        default:
            printf("ERROR,ingrese una nave valida...\n");
            break;
        }

    }
    while(flag == 0);

}

// cargar nave

stNaves cargarUnaNave(char archivoNaves[])
{

    int dato = 0;
    stNaves aux;
///Datos default
    int ultimaID = encontrarUltimaIDNave(archivoNaves);
    aux.idNave = ultimaID + 1;
    aux.CantidadDeVuelosRealizados = 0;
    aux.HorasDeVueloAcumuladas = 0;
    aux.estado = 1;

    validarTipoNave(aux.tipoDeNave);



    return aux;
}

int encontrarUltimaIDNave(char archivoNaves[])
{

    int ultimaID;
    stNaves naveAux;
    FILE* aux;
    aux = fopen(archivoNaves,"rb");
    if(aux != NULL)
    {

        fseek(aux,sizeof(stNaves)*-1,SEEK_END);
        fread(&naveAux,sizeof(stNaves),1,aux);
        ultimaID = naveAux.idNave;
        fclose(aux);
    }
    return ultimaID;
}

void tiposDeNave()
{
    puts("----------------SELECCIONE UN TIPO DE NAVE------------------\n");
    puts("1-StarShip (7 astronautas obligatorio)");
    puts("2-Falcon 9 (5 astronautas obligatorio)");
    puts("3-Falcon Heavy (3 astronautas obligatorio)");
}

// cargar arreglo

int cargarArregloNave(stNaves arrNave[], char archivoNaves[])
{
    char op='s';
    int contStarship=1, contFalcon9=1, contFalconHeavy=1;
    stNaves aux;
    int i=0, comprobar=0;

    while((op == 's' || op=='S') && i < 15)
    {
        aux=cargarUnaNave(archivoNaves);


        if(strcmp(aux.tipoDeNave,"StarShip") == 0)
        {
            comprobar=validarCantNave(contStarship);
            {
                if (comprobar ==0)
                {
                    arrNave[i]=aux;
                    contStarship++;
                }

            }

        }
        if(strcmp(aux.tipoDeNave,"Falcon 9") == 0)
        {
            comprobar=validarCantNave(contFalcon9);
            {
                if (comprobar ==0)
                {
                    arrNave[i]=aux;
                    contFalcon9++;
                }

            }
        }
        if (strcmp(aux.tipoDeNave,"Falcon Heavy") == 0)
        {
            comprobar=validarCantNave(contFalconHeavy);
            {
                if (comprobar ==0)
                {
                    arrNave[i]=aux;
                    contFalconHeavy++;
                }

            }
        }
        i++;


        printf("Desea seguir cargando naves? s/n:");
        fflush(stdin);
        op= getch(op);
        limpiarPantalla();
    }
    if(i == 14)
    {
        puts("Ha alcanzado el limite de naves disponible");
    }

    return i;
}

int validarCantNave(int cont)
{
    int maximo=5;
    // esta funcion sirve para los 3 tipos de nave

    if(cont > maximo)
    {
        printf("La cantidad de naves esta llena \n");
        return 1; // Aqui ya excedio el maximo de naves
    }
        printf("Tiene esta cantidad de naves fabricadas: %i \n",cont);
        return 0; // El usuario va a poder seguir cargando ya que no excede el maximo de naves

}



// carga del archivo

void arregloNavesToArchivoNaves(char archivoNaves[],stNaves arrNaves[], int validos)
{
    FILE * buffer=fopen(archivoNaves,"ab");
    stNaves aux;

    if (buffer != NULL)
    {
        for (int i=0; i < validos; i++)
        {
            fwrite(&aux,sizeof(stNaves),1,buffer);
        }

        fclose(buffer);
    }
    else
    {
        printf("Error con archivo");
    }
}



