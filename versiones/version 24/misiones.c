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
    int cant=0;
    stMision aux;


    aux.estado = 1;   // autoincremental
    aux.IDMision = 1; // autoincremental

    do
    {
        limpiarPantalla();
        mostrarTodasLasNaves(archivoNaves);
        printf("Ingrese el ID de la nave que desea utilizar: ");
        aux.IDNave = preguntarDato();
    }
    while (validarIDNave(archivoNaves,aux.IDNave) == 0 && validarEstadoNaveMision(archivoNaves,aux.IDNave) == 0);

    cant= cantidadMaximaDeTripulantes(archivoNaves,aux.IDNave); // retorno los validos de la nave

    elegirDestino(archivoMisiones, aux.destino);  // destino

    elegirCargamento(aux.cargamento); // cargamento

    cargarTripulantesMision(archivoAstro,cant,aux.tripulantes); // tripulantes

    detallesMisionXdestino(aux.detalleMision,aux.destino); // detalle
    //printf("%s",aux.detalleMision);

    return aux;
}

int cantidadMaximaDeTripulantes(char archivoNaves[],int naveID)
{
    int cant=0;
    char auxTipoNave[DIM_MAX_STR];
    stNaves aux;
    FILE * buffer=fopen(archivoNaves,"rb");
    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stNaves),1,buffer)>0)
        {
            if(aux.idNave == naveID)
            {
                strcpy(auxTipoNave,aux.tipoDeNave);
                cant=disponibilidadTripulantesMision(auxTipoNave);
            }
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }


    return cant;
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

    }
    while(flag == 1);

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
int validarIdMision(char archivoMisiones[], int datoID)
{
    int flag = 0;
    stMision aux;
    FILE* buffer = fopen(archivoMisiones,"rb");

    if (buffer != NULL)
    {
        while(fread(&aux,sizeof(stNaves),1,buffer) > 0 && flag == 0)
        {
            if (aux.IDMision == datoID)
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
        puts("Error, ID incorrecto...");
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
    }
    while(flag==1);


}


int disponibilidadTripulantesMision(char tipoNave[])
{
    int dato=0;

    if(strcmpi(tipoNave, "starship")==0)
    {
        dato= 7;

    }

    if(strcmpi(tipoNave, "falcon 9")==0)
    {
        dato= 5;

    }

    if(strcmpi(tipoNave,"falcon heavy")==0)
    {
        dato= 3;
    }

    return dato;
}


void cargarTripulantesMision(char archivoAstro[],int maxi,int IDTripulantes[])
{
    int estado=3;
    int i=0;
    int IDAstro = 0;
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
        cambiarEstadoAstronauta(archivoAstro,IDAstro,estado); //modificar estado a 3 (EN MISION)


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

void cambiarEstadoAstronauta(char archivoAstro[],int datoID,int estado)
{

    stAstronauta aux;
    int flag =0;
    FILE* buffer=fopen(archivoAstro,"r+b");

    int posAstro=0;

    if(buffer != NULL)
    {


        posAstro=encontrarPosicionAstroXID(archivoAstro,datoID)-1;
        fseek(buffer,sizeof(stAstronauta)*posAstro,SEEK_SET);
        fread(&aux,sizeof(stAstronauta),1,buffer);
        aux.estado = estado;

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
        strcpy(detalles, "Mision a la Orbita Terrestre: Se debe entregar el cargamento dentro de la Orbita terrestre, a la Sala de Investigacion. Una vez entregado, volver a la base");
    }
    if(strcmpi(destino,"eei") ==0)
    {
        strcpy(detalles, "Mision a la E.E.I: Se debe entregar el cargamento a la E.E.I, al centro de Operaciones Especiales. Una vez entregado, volver a la base");
    }
    if(strcmpi(destino,"marte") ==0)

    {
        strcpy(detalles, "Mision a Marte: Se debe entregar el cargamento a la estacion de Marte, al Capitan Matias S. Doe. Una vez entregado, volver a la base");
    }
    if(strcmpi(destino,"saturno") ==0)
    {
        strcpy(detalles, "Mision a Saturno: Se debe entregar el cargamento a la estacion de Saturno, al Oficial Leonardo K. Smith. Una vez entregado, volver a la base");
    }
    if(strcmpi(destino,"la luna") ==0)
    {
        strcpy(detalles, "Mision a la Luna: Se debe entregar el cargamento al campamento espacial, al Guardia Fabrizio Lemus. Una vez entregado, volver a la base");

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

void mostrarUnaMision(stMision aux,int maxTripulantes)
{
    puts("\n------------------------MISION-------------------------");
    printf("ID de la mision..............: %i \n",aux.IDMision);
    printf("Destino......................: %s \n",aux.destino);
    printf("Estado.......................: %i \n",aux.estado);
    printf("ID de la nave................: %i \n",aux.IDNave);
    printf("Cargamento...................: %s \n",aux.cargamento);
    printf("ID de los tripulantes........: ");

    for(int i=0; i < maxTripulantes; i++)
    {
        printf("|%i|",aux.tripulantes[i]);
    }


    printf("\nDetalles de la mision........: \n%s\n",aux.detalleMision);

    puts("---------------------------------------------------------");
}

//mostrar TODAS las misiones

void mostrarTodasLasMisiones(char archivoMisiones[],char archivoNaves[])
{
    stMision aux;
    int cant=0;

    FILE* buffer= fopen(archivoMisiones,"rb");

    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stMision),1,buffer)>0)
        {
            //me retorna el tipo de nave para poder saber el maximo de tripulantes y de carga de la nave
            //cant=maxTripulantes(archivoMisiones,aux.IDNave);//ya sabiendo el tipo de nave puedo sacar los validos de tripulantes

            cant = 3;
            mostrarUnaMision(aux,cant); // muestro la mision
        }

        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

}


//mostrar misiones disponibles


void mostrarMisionesListas(char archivoMisiones[],char archivoNaves[])
{
    stMision aux;
    int cant=0;



    FILE* buffer=fopen(archivoMisiones,"rb");

    if(buffer!= NULL)
    {
        while(fread(&aux,sizeof(stMision),1,buffer) >0)
        {
            if(aux.estado == 1)
            {
                cant=cantidadMaximaDeTripulantes(archivoNaves,aux.IDNave);
                mostrarUnaMision(aux,cant);
            }
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }
}
//retornar una mision por ID

stMision retornarMisionXID(char archivoMisiones[], int datoID)
{
    stMision aux;
    int flag=0;
    FILE* buffer=fopen(archivoMisiones,"rb");

    if(buffer != NULL)
    {
        while((fread(&aux,sizeof(stMision),1,buffer)>0) && flag ==0)
        {
            if(aux.IDMision == datoID)
            {
                flag=1;
            }
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }

    return aux;
}

//validar si la mision esta lista
int validarSiMisionLista(char archivoMisiones[], int misionID)
{
    stMision aux;
    int flag=0;
    int disponible=1;
    FILE* buffer=fopen(archivoMisiones,"rb");

    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stMision),1,buffer) >0 && flag==0)
        {
            if(aux.IDMision == misionID && aux.estado == disponible)
            {
                flag= 1;
            }
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }
    return flag;
}

//modificar mision (decidir si despegar o cancelar)

void modificarMision(char archivoAstro[],char archivoMisiones[], char archivoNaves[])
{
    int misionID=0, dato=0,flag=0;
    stMision aux;

    do
    {
        //limpiarPantalla();
        mostrarMisionesListas(archivoMisiones,archivoNaves);
        puts("\n-------------------------------------------------------");
        puts("Estas son todas las misiones listas");
        puts("Ingrese el ID de la mision que quiere modificar");
        misionID= preguntarDato();
    }
    while(validarSiMisionLista(archivoMisiones,misionID)==0);

    aux= retornarMisionXID(archivoMisiones,misionID);
    dato= cantidadMaximaDeTripulantes(archivoNaves,aux.IDNave);


    do
    {
        limpiarPantalla();
        mostrarUnaMision(aux,dato);
        puts("----------------------------------------------------");
        puts("Usted eligio esta mision");
        puts("----------------------------------------------------");
        puts("Que desea hacer?");
        puts("1. Lanzar mision (esto hara que el estado de mision pasara a 'En vuelo', la nave a 'Actualmente en mision' y los tripulantes a 'En mision')");
        puts("2. Cancelar mision(se cambiara el estado de la mision a 'cancelado' y todos los tripulantes se liberaran a estado 'Listo')");
        dato=preguntarDato();
        switch(dato)
        {
        case 1:

            lanzarMision(&aux,archivoAstro,archivoNaves);
            flag= 0;
            break;
        case 2:
            // cancelar mision y cambiar el estado a 2
            flag= 0;
            break;
        default:
            puts("Ingrese un dato correcto");
            flag= 1;
            break;
        }

    }
    while(flag == 1);

}

// lanzo la mision por lo tanto modifico todo

void lanzarMision(stMision* auxMision, char archivoAstro[], char archivoNaves[])
{
    int pos = 0, estado=0;
    int numRand=rand()%100;

    auxMision->estado= 2; // mision en vuelo


    int cantTripu = cantidadMaximaDeTripulantes(archivoNaves,auxMision->IDNave);

    //cambiarEstadoDeTripulantesMision(archivoAstro,cantTripu,(*auxMision),3); //astronautas en mision
    cambiarEstadoDeNaveMision(archivoNaves,(*auxMision), 2); //nave en vuelo

    //aca ponemos el dibujo de carga dependiendo la mision

    Sleep(4000);

    estado=posibilidadDeEstadoMision(numRand);

    printf("ESTADO=%i",estado);

    if (estado == 3) //mision retornada
    {
        cambiarEstadoDeTripulantesMision(archivoAstro,cantTripu,(*auxMision),1); // si la mision es retornada cambio el estado de los astros a activo
        cambiarEstadoDeNaveMision(archivoNaves,(*auxMision),1); // si la mision termino bien la nave vuelve a estar lista
    }
    else if(estado == 5) //mision fallida
    {
        cambiarEstadoDeTripulantesMision(archivoAstro,cantTripu,(*auxMision),1); // si la mision falla los tripulantes se liberan
        cambiarEstadoDeNaveMision(archivoNaves,(*auxMision),0); //si la mision falla la nave pasa a en mantenimiento
    }
}

int posibilidadDeEstadoMision(int numRand)
{
    if(numRand > 50)
    {
        return 3;
    }

    return 5;
}



void cambiarEstadoDeTripulantesMision(char archivoAstro[], int cantTripu,stMision auxMision, int estado)
{
    stAstronauta auxAstro;
    int pos=0;
    FILE* buffer;
    buffer = fopen(archivoAstro,"r+b");
    if(buffer != NULL)
    {
        for(int i = 0; i<cantTripu; i++)
        {
            cambiarEstadoAstronauta(archivoAstro,auxMision.tripulantes[i],estado);
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }


}

void cambiarEstadoDeNaveMision(char archivoNaves[],stMision auxMision,int estado)
{
    int pos=0;
    stNaves auxNave;

    FILE* bufferNave= fopen(archivoNaves,"r+b");

    if(bufferNave != NULL)
    {

        pos = encontrarPosicionNaveXID(archivoNaves,auxMision.IDNave)-1;
        fseek(bufferNave,sizeof(stNaves)*pos,SEEK_SET);
        fread(&auxNave,sizeof(stNaves),1,bufferNave);

        auxNave.estado = estado;

        fseek(bufferNave,sizeof(stNaves)*pos,SEEK_SET);
        fwrite(&auxNave,sizeof(stNaves),1,bufferNave);

        fclose(bufferNave);
    }
    else
    {
        puts("Error con el archivo");
    }

}






void cancelarMision(stMision* aux, char archivoAstro[], char archivoNaves[])
{

    //falta cancelar mision

}










