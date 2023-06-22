#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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

    stMision aux;


    aux.estado = 1;   // autoincremental
    aux.IDMision = 1; // autoincremental

    do
    {
        limpiarPantalla();
        mostrarTodasLasNavesDisponibles(archivoNaves);
        printf("Ingrese el ID de la nave que desea utilizar: ");
        aux.IDNave = preguntarDato();
    }
    while (validarIdMision(archivoNaves,aux.IDNave) == 0 && validarEstadoNaveMision(archivoNaves,aux.IDNave) == 0);

    retornarTipoDeNave(archivoNaves,tipoNave,aux.IDNave); // esto es para saber el tipo de nave

    elegirDestino(archivoMisiones, aux.destino);  // destino

    elegirCargamento(aux.cargamento); // cargamento

    cargarTripulantesMision(archivoAstro,tipoNave,aux.tripulantes); // tripulantes

    detallesMisionXdestino(aux.detalleMision,aux.destino); // detalle
    printf("%s",aux.detalleMision);

    return aux;
}

void mostrarTodasLasNavesDisponibles(char archivoNaves[])
{
    stNaves aux;
    int disponible=1;

    FILE*buffer=fopen(archivoNaves,"rb");

    if (buffer != NULL)
    {
        while(fread(&aux,sizeof(stNaves),1,buffer) >0)
        {
            if(aux.estado == disponible)
            {
                mostrarUnaNave(aux);
            }
        }

        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

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

    int opsw = 0;
    int flag = 0;

    do
    {
        limpiarPantalla();
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
                strcpy(destino,"La luna");
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
            flag =1;
            printf("Dato incorrecto, ingrese una opcion valida...");
            break;
        }

        limpiarPantalla();

    }while(flag == 1);

    system("pause");

}

int validarDestinoMision(char archivoMisiones[], char destino[])
{
    stMision aux;
    int flag = 0;
    FILE * buffer = fopen(archivoMisiones, "rb");

    if (buffer != NULL)
    {
        while ((fread(&aux,sizeof(stMision),1,buffer) > 0) && flag == 0)
        {

            if ((strcmpi(aux.destino,destino) == 0) && aux.estado == 2)
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
    puts("------------------------------------------------------------");
}
void elegirCargamento(char cargamento[])
{
    int flag=0;
    int opsw = 0;

    do
    {
        mostrarCargamento();
        printf("Ingrese el tipo de cargamento que desea llevar: ");
        opsw = preguntarDato();

        switch(opsw)
        {
        case 1:
            strcpy(cargamento,"Satelite ");
            flag=0;
            break;
        case 2:
            strcpy(cargamento,"Insumos para la EEI ");
            flag=0;
            break;
        case 3:
            strcpy(cargamento,"R.O.V.E.R. ");
            flag=0;
            break;
        case 4:
            strcpy(cargamento,"Aparatos Electronicos ");
            flag=0;
            break;
        case 5:
            strcpy(cargamento,"Kit de primeros auxilios ");
            flag=0;
            break;
        case 6:
            strcpy(cargamento,"Kit mecanico ");
            flag=0;
            break;
        default:
            printf("Dato incorrecto, ingrese una opcion valida...");
            flag=1;
            break;

        }

    limpiarPantalla();
    }while(flag==1);


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

    int i=0;
    int IDAstro = 0;
    int maxi= disponibilidadTripulantesMision(tipoNave);
    do
    {
        mostrarAstronautasDisponibles(archivoAstro);
        puts("------------Estos son todos los astronautas disponibles---------------\n");
        puts("|Aclaracion: es necesario completar el maximo de astronautas de la nave elegida|");
        printf("MAXIMO :%i \n",maxi);
        printf("|Usted va %i de %i|\n",i,maxi);
        puts("\nIngrese el ID del astronauta que desea mandar a la mision");

        do
        {
            IDAstro= preguntarDato();
        }
        while(validarIDastro(IDAstro,archivoAstro)== 0);
        cambiarEstadoAstronauta(archivoAstro,IDAstro); //modificar estado a 3 (EN MISION)


        IDTripulantes[i]=IDAstro; //cargar un tripulante a la mision

        i++;
        printf("%i de %i astronautas \n",i,maxi);



        limpiarPantalla();
    }
    while(i < maxi);

    if(i == maxi)
    {
        puts("Se alcanzo el limite maximo de tripulantes");
    }


}

int disponibilidadTripulantesMision(char tipoNave[])
{
    int dato=0;

    if(strcmpi(tipoNave, "starship")==0)
    {
        dato= 7;
        return dato;
    }

    if(strcmpi(tipoNave, "falcon 9")==0)
    {
        dato= 5;
        return dato;
    }

    if(strcmpi(tipoNave,"falcon heavy")==0)
    {
        dato= 3;
        return dato;
    }
    return 0;
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

void cambiarEstadoAstronauta(char archivoAstro[],int datoID)
{

    stAstronauta aux;

    FILE* buffer=fopen(archivoAstro,"r+b");

    int posAstro=0;

    if(buffer != NULL)
    {


        posAstro=encontrarPosicionAstroXID(archivoAstro,datoID);
        fseek(buffer,sizeof(stAstronauta)*posAstro,SEEK_SET);
        aux.estado = 3;

        fseek(buffer,sizeof(stAstronauta)*-1,SEEK_CUR);
        fwrite(&aux,sizeof(stAstronauta),1,buffer);


        fclose(buffer);
    }
    else
    {

        puts("ERROR en el archivo");
    }

}

void detallesMisionXdestino(char detalles[],char destino[])
{
   if(strcmpi(destino,"orbita terrestre") ==0)
   {
       strcpy(detalles, "Detalle de la mision a la Orbita Terrestre: Se debe entregar el cargamento dentro de la Orbita, a la Sala de Investigacion. Una vez entregado, volver a la base");
   }
   if(strcmpi(destino,"eei") ==0)
   {
       strcpy(detalles, "Detalle de la mision a la E.E.I: Se debe entregar el cargamento a la E.E.I, al centro de Operaciones Especiales. Una vez entregado, volver a la base");
   }
   if(strcmpi(destino,"marte") ==0)
   {
       strcpy(detalles, "Detalle de la mision a Marte: Se debe entregar el cargamento a la estacion de Marte, al Capitan Matias S. Doe. Una vez entregado, volver a la base");
   }
   if(strcmpi(destino,"saturno") ==0)
   {
       strcpy(detalles, "Detalle de la mision a Saturno: Se debe entregar el cargamento a la estacion de Saturno, al Oficial Leonardo K. Smith. Una vez entregado, volver a la base");
   }
   if(strcmpi(destino,"la luna") ==0)
   {
       strcpy(detalles, "Detalle de la mision a la Luna: Se debe entregar el cargamento al campamento espacial, al Guardia Fabrizio Sanchez. Una vez entregado, volver a la base");

   }
}



// cargar archivo mision

void cargarArchivoMisiones(char archivoAstro[], char archivoNaves[], char archivoMision[])
{
    stMision aux;
    FILE* buffer= fopen(archivoMision,"ab");

    if(buffer != NULL)
    {
        aux =crearUnaMision(archivoMision,archivoNaves,archivoAstro);
        fwrite(&aux,sizeof(stMision),1,buffer);
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }
}

//mostrar UNA mision

void mostrarUnaMision(stMision aux,int maxtrip)
{
    puts("------------------------MISION-------------------------");
    printf("ID de la mision..............: %i \n",aux.IDMision);
    printf("Destino......................: %s \n",aux.destino);
    printf("Estado.......................: %i \n",aux.estado);
    printf("ID de la nave................: %i \n",aux.IDNave);
    printf("Cargamento...................: %s \n",aux.cargamento);
    printf("ID de los tripulantes........: ");

    for(int i=0; i < maxtrip; i++)
    {
        printf("|%i|",aux.tripulantes[i]);
    }


    printf("\nDetalles de la mision........: \n%s",aux.detalleMision);
    puts("---------------------------------------------------------");

}

//mostrar TODAS las mision

void mostrarTodasLasMisiones(char archivoMisiones[],char archivoNaves[])
{
    stMision aux;
    int maxtripulantes=0;
    char auxTipoNave[DIM_MAX_STR];

    FILE* buffer= fopen(archivoMisiones,"rb");
    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stMision),1,buffer)>0)
        {
            retornarTipoDeNave(archivoNaves,auxTipoNave,aux.IDNave); //me retorna el tipo de nave para poder saber el maximo de tripulantes y de carga de la nave
            maxtripulantes=disponibilidadTripulantesMision(auxTipoNave);//ya sabiendo el tipo de nave puedo sacar los validos de tripulantes

            mostrarUnaMision(aux,maxtripulantes); // muestro la mision
        }

    fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

}
