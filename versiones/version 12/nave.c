#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astronauta.h"
#include "naves.h"
#include "menu.h"
#define DIM_MAX_ARCHI 15
#define DIM_MAX_STR 20

// validar

void validarTipoNave(char tipoNave[])
{

    int flag = 0, dato=0;
    tiposDeNave();
    dato=preguntarDato();
    do
    {
        switch(dato)
        {
        case 1:
            strcpy(tipoNave,"StarShip");
            flag = 1;
            break;
        case 2:
            strcpy(tipoNave,"Falcon 9");
            flag = 1;
            break;
        case 3:
            strcpy(tipoNave,"Falcon Heavy");
            flag = 1;
            break;
        default:
            printf("ERROR,ingrese una nave valida...\n");
            break;
        }

    }
    while(flag == 0);

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

// cargar nave

stNaves cargarUnaNave(char archivoNaves[])
{
    int dato = 0;
    stNaves aux;

///Datos default
    int ultimaID = encontrarUltimaIDNave(archivoNaves);
    aux.idNave =ultimaID + 1;
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
    else
    {
        puts("error con el archivo");
    }
    return ultimaID;
}

void tiposDeNave()
{
    puts("----------------SELECCIONE UN TIPO DE NAVE------------------\n");
    puts("1-StarShip (Lleva 7 astronautas obligatorio)");
    puts("2-Falcon 9 (Lleva 5 astronautas obligatorio)");
    puts("3-Falcon Heavy (Lleva 3 astronautas obligatorio)");
}

// carga del archivo
void cargarArchivoNaves(char archivoNaves[])
{
    char op='s';
    int contStarship=1;
    int contFalcon9=1;
    int contFalconHeavy=1;
    stNaves aux;
    int i=0;
    int comprobar=0;

    FILE * buffer=fopen(archivoNaves,"ab");

    if(buffer != NULL)
    {
        while((op == 's' || op=='S') && i < 15)
        {
            aux=cargarUnaNave(archivoNaves);


            if(strcmpi(aux.tipoDeNave,"starship") == 0)
            {
                comprobar=validarCantNave(contStarship);
                {
                    if (comprobar ==0)
                    {
                        fwrite(&aux,sizeof(stNaves),1,buffer);
                        contStarship++;
                    }

                }

            }
            if(strcmpi(aux.tipoDeNave,"falcon 9") == 0)
            {
                comprobar=validarCantNave(contFalcon9);
                {
                    if (comprobar ==0)
                    {
                        fwrite(&aux,sizeof(stNaves),1,buffer);
                        contFalcon9++;
                    }

                }
            }
            if (strcmpi(aux.tipoDeNave,"falcon heavy") == 0)
            {
                comprobar=validarCantNave(contFalconHeavy);
                {
                    if (comprobar ==0)
                    {
                        fwrite(&aux,sizeof(stNaves),1,buffer);
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
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

    if(i == 14)
    {
        puts("Ha alcanzado el limite de naves disponible");
    }

}

int contarRegistrosNave(char archivoNaves[])
{
    int cant=0;
    FILE* buffer= fopen(archivoNaves,"rb");
    if(buffer != NULL)
    {
        fseek(buffer,sizeof(stNaves) -1,SEEK_END);
        cant=ftell(buffer)/sizeof(stNaves);
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

    return cant;
}
// mostrar naves

void mostrarUnaNave(stNaves aux)
{
    puts("---------------------NAVE---------------------");
    printf("ID...............................:|%i|  \n",aux.idNave);
    printf("Tipo de nave.....................:|%s|  \n",aux.tipoDeNave);
    printf("Cantidad de vuelos realizados....:|%i|  \n",aux.CantidadDeVuelosRealizados);
    printf("Horas de vuelo acumuladas........:|%i|  \n",aux.HorasDeVueloAcumuladas);
    printf("ESTADO...........................:|%i|  \n",aux.estado);
    puts("----------------------------------------------");

}
void mostrarTodasLasNaves(char archivoNaves[])
{
    stNaves aux;
    FILE * buffer=fopen(archivoNaves,"rb");

    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stNaves),1,buffer) > 0)
        {
            mostrarUnaNave(aux);
        }
        fclose(buffer);
    }
    else
    {
        printf("Error con el archivo\n");
    }

}
void mostrarNavesXEstado(char archivoNaves[], int estado)
{
    stNaves aux;
    FILE * buffer=fopen(archivoNaves,"rb");
    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stNaves),1,buffer) > 0)
        {
            if(aux.estado == estado)
            {
                mostrarUnaNave(aux);
            }

        }
        fclose(buffer);
    }
    else
    {
        printf("Error con el archivo\n");
    }
}

//modificar nave

int validarIDNave(char archivoNave[], int dato)
{
    stNaves aux;
    int flag=0;
    FILE * buffer=fopen(archivoNave, "rb");
    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stNaves),1,buffer))
        {
            if(dato == aux.idNave)
            {
                flag = 1;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("Error con el archivo");
    }
    return flag;

}
int encontrarPosicionNaveXID(char archivoNaves[], int IDNave)
{
    stNaves aux;
    int posNave=0, flag=0;
    FILE * buffer = fopen(archivoNaves,"rb");

    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stNaves),1,buffer) > 0 && flag == 0)
        {
            if (aux.idNave == IDNave)
            {
                posNave = ftell(buffer)/sizeof(stNaves);
                flag = 1;
            }
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }
    return posNave;

}
int validarSiNaveEstaOcupada(int estado)
{
    int alta=1,baja=3;
    if (estado ==alta || estado == baja)
    {
        return 0;
    }

    if(estado==0)
    {
        puts("Error la nave esta en mantenimiento");
    }
    if(estado==2)
    {
        puts("Error la nave esta actualmente en mision");
    }

    return 1;
}
void cargarNaveModificada(char archivoNaves[])
{
    int datoID=0, posNave=0;
    stNaves aux;
    FILE * buffer=fopen(archivoNaves,"r+b");

    if(buffer != NULL)
    {
        do
        {

            mostrarTodasLasNaves(archivoNaves);
            puts("-----------INGRESE EL ID DE LA NAVE QUE QUIERE MODIFICAR-------------");
            datoID = preguntarDato();

        }
        while(validarIDNave(archivoNaves,datoID)== 0 || validarSiNaveEstaOcupada(aux.estado));


        posNave=encontrarPosicionNaveXID(archivoNaves,datoID);

        fseek(buffer,sizeof(stNaves)*posNave,SEEK_SET);
        fread(&aux,sizeof(stNaves),1,buffer);
        modificarUnaNave(&aux);
        fseek(buffer,sizeof(stNaves)*-1,SEEK_CUR);
        fwrite(&aux,sizeof(stNaves),1,buffer);



        fclose(buffer);
    }
    else
    {
        printf("Error con el archivo \n");
    }

}
void modificarUnaNave(stNaves* aux)
{
    int opsw, dato;
    char op='s';

    do
    {

        puts("------------------NAVE ELEGIDA------------------");
        mostrarUnaNave(*aux);

        puts("1. Estado (Alta/Baja)");
        puts("2. Volver al menu de naves");
        printf("Que desea modificar?: ");
        scanf("%i",&opsw);

        switch(opsw)
        {
        case 1:
            do
            {
                puts("1 ALTA ; 2 DE BAJA");
                aux->estado=preguntarDato();
            }
            while(validarEstado(dato));
            break;
        case 2:
            break;
        default:
            puts("Ingrese una opcion valida");
            break;
        }
        puts("--------------------NAVE MODIFICADA----------------------");
        mostrarUnaNave(*aux);

        printf("\nDesea seguir modificando la nave? s/n");
        fflush(stdin);
        scanf("%c",&op);

    }
    while(op == 's' || op =='S');

}


//arreglo

int archivoToArregloNaves(char archivoNaves[],stNaves arrNaves[])
{
    stNaves aux;
    int i=0;
    FILE* buffer=fopen(archivoNaves,"rb");

    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stNaves),1,buffer)>0)
        {
            arrNaves[i]= aux;
            i++;
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }
    return i;
}
//stNaves * crearArregloDinamicoNave(int tam)
//{
//
//    stNaves* arrNave= malloc(sizeof(stNaves)*2);
//    return arrNave;
//}
void mostrarArregloNave(stNaves arrNaves[], int validos)
{
    for (int i=0; i < validos; i++)
    {
        mostrarUnaNave(arrNaves[i]);
    }

}

//consultar nave

void ConsultaNave(char archivoNaves[])
{
//    int tam= contarRegistrosNave(archivoNaves);
//    stNaves* arrNaves;
//    arrNaves= crearArregloDinamicoNave(tam);
    int validosNaves=0;
    stNaves arrNaves[DIM_MAX_ARCHI];

    validosNaves=archivoToArregloNaves(archivoNaves,arrNaves);


    //printf("valiidoooooo%i",validosNaves);



    menuConsultarPorNave(archivoNaves,arrNaves,validosNaves);


}
void opcionesParaConsultarNaves()
{
    puts("1.Mostrar nave por ID");
    puts("2.Preguntar cuantas naves existen en total");
    puts("3.Preguntar cuantas naves de un tipo especifico existen"); //menu tipo nave
    puts("4.Buscar nave con mayor horas de vuelo acumuladas");
    puts("5.Buscar nave con menor horas de vuelo acumuladas");
    puts("6.Buscar nave con mayor cantidad de vuelos realizados");
    puts("7.Buscar nave con menor cantidad de vuelos realizados");
    puts("8.Preguntar cuantas naves en mantenimiento hay (Estado= 0)");
    puts("9.Preguntar cuantas naves listas para su uso hay (Estado= 1)");
    puts("10.Preguntar cuantas naves actualmente en mision hay (Estado= 2)");
    puts("11.Preguntar cuantas naves dadas de baja hay (Estado= 3)");

}
void menuConsultarPorNave(char archivoNaves[],stNaves arrNaves[], int validos)
{
    char op='s';
    int opsw=0, dato=0,pos=0;


    do
    {
        mostrarArregloNave(arrNaves,validos);

        opcionesParaConsultarNaves();

        printf("\nElija una opcion: ");
        opsw = preguntarDato();

        switch(opsw)
        {
        case 1:
            puts("-------Ingrese el ID de la nave que quiere buscar----------");

            dato = preguntarDato();
            pos= buscarNaveXID(arrNaves,validos,dato);
            if(pos != -1)
            {
                printf("La nave con el ID: %i\n",dato);
                mostrarUnaNave(arrNaves[pos]);

            }
            else
            {
                printf("No se encontro ninguna nave con el ID: %i",pos);
            }
            break;
        case 2:
            dato = contarRegistrosNave(archivoNaves);
            printf("En total hay un total de |%i| naves\n", dato);

            break;
        case 3:
            dato = menuTipoNaves(arrNaves,validos);
            printf("En total hay un total de |%i| naves del tipo de nave elegido\n", dato);
            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        default:
            puts("Por favor ingrese una opcion valida");
            break;

        }

        printf("\nQuiere seguir consultando datos? s/n: ");
        fflush(stdin);
        op = getch(op);
        limpiarPantalla();

    }
    while(op=='s');



}

int menuTipoNaves(stNaves arregloNave[], int validos)
{
    int dato=0, resultado=0;
    char tipo[DIM_MAX_STR];

    limpiarPantalla();

    puts("Elija el tipo de nave que desea saber su cantidad:");
    puts("------------------------------------------");
    puts("1. StarShip");
    puts("2. Falcon 9");
    puts("3. Falcon Heavy");
    puts("------------------------------------------");
    dato = preguntarDato();



    switch(dato)
    {
    case 1:
        strcpy(tipo,"starship");
        resultado = cantNavesXTipos(arregloNave,validos,tipo);
       break;
    case 2:
        strcpy(tipo,"falcon 9");
        resultado = cantNavesXTipos(arregloNave,validos,tipo);


       break;
    case 3:
        strcpy(tipo,"falcon heavy");
        resultado = cantNavesXTipos(arregloNave,validos,tipo);
        break;
    default:
        puts("Por favor ingrese una opcion correcta");
        break;
    }

    return resultado;




}

int buscarNaveXID(stNaves arr[],int validos, int datoID)
{
    int i=0;
    while(i < validos)
    {
        if(arr[i].idNave == datoID)
        {
            return i;
        }
        i++;

    }
    return -1;
}

int cantNavesXTipos(stNaves arr[], int validos, char tipo[])
{
    int cant=0;
    for(int i=0; i < validos; i++)
    {
        if(strcmpi(arr[i].tipoDeNave,tipo)==0)
        {
            cant++;
        }
    }
    return cant;
}


















