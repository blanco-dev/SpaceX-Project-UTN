#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astronauta.h"
const char* paises[] =
{
    "Afganistan",
    "Albania",
    "Alemania",
    "Andorra",
    "Angola",
    "Antigua y Barbuda",
    "Arabia Saudita",
    "Argelia",
    "Argentina",
    "Armenia",
    "Australia",
    "Austria",
    "Azerbaiyan",
    "Bahamas",
    "Banglades",
    "Barbados",
    "Barein",
    "Belgica",
    "Belice",
    "Benin",
    "Bielorrusia",
    "Birmania",
    "Bolivia",
    "Bosnia",
    "Botsuana",
    "Brasil",
    "Brunei",
    "Bulgaria",
    "Burkina Faso",
    "Burundi",
    "Butan",
    "Cabo Verde",
    "Camboya",
    "Camerun",
    "Canada",
    "Catar",
    "Chad",
    "Chile",
    "China",
    "Chipre",
    "Vaticano",
    "Colombia",
    "Comoras",
    "Corea del Norte",
    "Corea del Sur",
    "Costa de Marfil",
    "Costa Rica",
    "Croacia",
    "Cuba",
    "Dinamarca",
    "Dominica",
    "Ecuador",
    "Egipto",
    "El Salvador",
    "Emiratos Arabes Unidos",
    "Eritrea",
    "Eslovaquia",
    "Eslovenia",
    "España",
    "Estados Unidos",
    "Estonia",
    "Eswatini",
    "Etiopia",
    "Filipinas",
    "Finlandia",
    "Fiyi",
    "Francia",
    "Gabon",
    "Gambia",
    "Georgia",
    "Ghana",
    "Granada",
    "Grecia",
    "Guatemala",
    "Guinea",
    "Guinea-Bisau",
    "Guinea Ecuatorial",
    "Guyana",
    "Haiti",
    "Honduras",
    "Hungria",
    "India",
    "Indonesia",
    "Irak",
    "Iran",
    "Irlanda",
    "Islandia",
    "Islas Marshall",
    "Islas Salomon",
    "Israel",
    "Italia",
    "Jamaica",
    "Japon",
    "Jordania",
    "Kazajistan",
    "Kenia",
    "Kirguistan",
    "Kiribati",
    "Kuwait",
    "Laos",
    "Lesoto",
    "Letonia",
    "Libano",
    "Liberia",
    "Libia",
    "Liechtenstein",
    "Lituania",
    "Luxemburgo",
    "Madagascar",
    "Malasia",
    "Malaui",
    "Maldivas",
    "Mali",
    "Malta",
    "Marruecos",
    "Mauricio",
    "Mauritania",
    "México",
    "Micronesia",
    "Moldavia",
    "Monaco",
    "Mongolia",
    "Montenegro",
    "Mozambique",
    "Namibia",
    "Nauru",
    "Nepal",
    "Nicaragua",
    "Niger",
    "Nigeria",
    "Noruega",
    "Nueva Zelanda",
    "Oman",
    "Paises Bajos",
    "Pakistan",
    "Palaos",
    "Panama",
    "Papua Nueva Guinea",
    "Paraguay",
    "Peru",
    "Polonia",
    "Portugal",
    "Reino Unido",
    "Republica Centroafricana",
    "Republica Checa",
    "Republica Democrática del Congo",
    "Republica Dominicana",
    "Ruanda",
    "Rumania",
    "Rusia",
    "Samoa",
    "San Cristobal y Nieves",
    "San Marino",
    "San Vicente y las Granadinas",
    "Santa Lucia",
    "Santo Tome y Príncipe",
    "Senegal",
    "Serbia",
    "Seychelles",
    "Sierra Leona",
    "Singapur",
    "Siria",
    "Somalia",
    "Sri Lanka",
    "Sudafrica",
    "Sudan",
    "Sudan del Sur",
    "Suecia",
    "Suiza",
    "Surinam",
    "Tailandia",
    "Tanzania",
    "Tayikistan",
    "Timor Oriental",
    "Togo",
    "Tonga",
    "Trinidad y Tobago",
    "Tunez",
    "Turkmenistan",
    "Turquia",
    "Tuvalu",
    "Ucrania",
    "Uganda",
    "Uruguay",
    "Uzbekistan",
    "Vanuatu",
    "Venezuela",
    "Vietnam",
    "Yemen",
    "Yibuti",
    "Zambia",
    "Zimbabue"
};


void limpiarPantalla()
{
    system("cls");
}

stAstronauta crearUnAstro(char astronauta[])
{
    stAstronauta aux;
    ///datos por defecto para crear un astro
    int ultimaID = encontrarUltimaID(astronauta);
    aux.id = ultimaID + 1;// arranca en 10 , de 10 para abajo son los predeterminados y luego de 10 para arriba los del usuario
    aux.horasDeVuelo = 0;
    aux.cantMisionesRealizadas = 0;
    aux.horasEnEEI = 0;
    aux.estado = 1;// 1 activo, 2 retirado

    /// Validacion del astronauta
    puts("-----------------------DATOS DEL ASTRONAUTA-----------------------");
    do
    {
        printf("Ingrese el nombre del astronauta: \n");
        fflush(stdin);
        gets(aux.nombre);
    }
    while(validarString(aux.nombre)==0);

    do
    {
        printf("Ingrese el apellido del astronauta: \n");
        fflush(stdin);
        gets(aux.apellido);
    }
    while(validarString(aux.apellido)==0);

    do
    {
        printf("Ingrese el apodo del astronauta: \n");
        fflush(stdin);
        gets(aux.apodo);
    }
    while(validarString(aux.apodo)==0);

    do
    {
        printf("Ingrese la edad del astronauta: \n");
        fflush(stdin);
        scanf("%i",&aux.edad);
    }
    while(validarEdad(aux.edad)==0);
    do
    {
        printf("Ingrese el pais el astronauta: \n");
        fflush(stdin);
        scanf("%s",&aux.nacionalidad);
    }
    while(validarNacionalidad(aux.nacionalidad)==0);

    verificarEspecialidad(aux.especialidad);
    // como ya cargo todo el astronauta se incrementan las id para que se pueda cargar el siguiente astro con su nueva id


    return aux;
}

int validarString(char auxNombre[])
{
    if (strlen(auxNombre) > 20 || strlen(auxNombre) < 3)
    {
        printf("Ingrese una palabra entre 3 y 20 letras\n\n");
        return 0;
    }
    else
    {
        return 1;
    }


}

int validarEdad(int edad)
{

    if (edad < 18  || edad > 60)
    {
        printf("Ingrese una edad mayor a 18 y menor a 60 anios\n\n");
        return 0;
    }
    else
    {
        return 1;
    }
}


int validarNacionalidad(char nacionalidad[])
{
    int i = 0;

    while(i<192)
    {
        if(strcmpi(nacionalidad,paises[i])== 0)
        {
            return 1;
        }
        i++;
    }
    printf("|Error|ingrese un pais existente\n\n");
    return 0;
}

void verificarEspecialidad(char especialidad[])
{

    int flag = 0;
    int op = 0;

    do
    {
        puts("------------------INGRESE UNA OPCION--------------------\n");
        mostrarEspecialidad();
        scanf("%i",&op);
        limpiarPantalla();
        switch(op)
        {
        case 1:
            strcpy(especialidad,"Piloto");
            flag = 1;
            break;
        case 2:
            strcpy(especialidad,"Astrofisico");
            flag = 1;
            break;
        case 3:
            strcpy(especialidad,"Ingeniero Espacial");
            flag = 1;
            break;
        case 4:
            strcpy(especialidad,"Biologo");
            flag = 1;
            break;
        case 5:
            strcpy(especialidad,"Tecnico Superior en Programacion");
            flag = 1;
            break;
        default:
            limpiarPantalla();
            printf("OPCION INCORRECTA...Reintente\n");
            break;
        }
    }
    while(flag == 0);

}
void mostrarEspecialidad()
{

    printf("1-Piloto\n");
    printf("2-Astrofico\n");
    printf("3-Ingeniero Espacial\n");
    printf("4-Biologo\n");
    printf("5-Tecnico Superior en Programacion\n");

}
int encontrarUltimaID(char astronauta[])
{

    int ultimaID;
    stAstronauta astroAux;
    FILE* aux;
    aux = fopen(astronauta,"rb");
    if(aux != NULL)
    {

        fseek(aux,sizeof(stAstronauta)*-1,SEEK_END);
        fread(&astroAux,sizeof(stAstronauta),1,aux);
        ultimaID = astroAux.id;
        fclose(aux);
    }
    return ultimaID;
}
///CARGA DEL ARCHIVO

void cargarUnAstroToArchivo(char archivoAstronautas[])
{

    FILE* astro;
    stAstronauta aux;
    astro = fopen(archivoAstronautas,"ab");
    if(astro != NULL)
    {
        aux = crearUnAstro(archivoAstronautas);
        fwrite(&aux,sizeof(stAstronauta),1,astro);
        fclose(astro);
    }
}

void mostrarAstronautas(char archivoAstronautas[])
{

    FILE* astro;
    stAstronauta aux;
    astro = fopen(archivoAstronautas,"rb");
    if(astro != NULL)
    {
        while(fread(&aux,sizeof(stAstronauta),1,astro)>0)
        {
            mostrarUnAstronauta(&aux);
        }
        fclose(astro);
    }
}

void mostrarUnAstronauta(stAstronauta* aux)
{

    puts("\n--------------------------------------------------------------------------\n");
    printf("............................ID: |%i|\n",aux->id);
    printf("........................Nombre: |%s|\n",aux->nombre);
    printf(".......................apellido:|%s|\n",aux->apellido);
    printf(".........................apodo: |%s|\n",aux->apodo);
    printf("..........................edad: |%i|\n",aux->edad);
    printf("..................nacionalidad: |%s|\n",aux->nacionalidad);
    printf("..................especialidad: |%s|\n",aux->especialidad);
    printf("......horas de vuelo acumulado: |%i|\n",aux->horasDeVuelo);
    printf("misiones espaciales realizadas: |%i|\n",aux->cantMisionesRealizadas);
    printf("...............horas en la EEI: |%i|\n",aux->horasEnEEI);
    printf("........................estado: |%i|\n",aux->estado);

}
///MODIFICAR ASTRONAUTA
void cargarAstroModificado(char archivoAstronauta[]){

int datoID = 0;
stAstronauta astro;
FILE* aux;

aux = fopen(archivoAstronauta,"r+b");
if(aux != NULL){

    limpiarPantalla();
    mostrarAstronautas(archivoAstronauta);
    puts("----------------------INGRESE LA ID DEL ASTRONAUTA A MODIFICAR----------------------\n");
    datoID = preguntarDatoAModificar()-1;///averiguar en que posicion esta este dato
    int posiscionDelId = encontrarPosId(archivoAstronauta,datoID);
        fseek(aux,sizeof(stAstronauta)*posiscionDelId,SEEK_SET);
        fread(&astro,sizeof(stAstronauta),1,aux);
        modificarUnAstro(&astro);
        fseek(aux,sizeof(stAstronauta)*-1, SEEK_CUR);
        fwrite(&astro,sizeof(stAstronauta),1,aux);

fclose(aux);
    }

}


int preguntarDatoAModificar(){
int datoID = 0;
printf("Ingrese el dato solicitado: \n");
fflush(stdin);
scanf("%i",&datoID);
return datoID;
}

int encontrarPosId(char archivoAstronautas[],int datoID){

int posID;

FILE* aux;
stAstronauta astro;
aux = fopen(archivoAstronautas,"rb");

if(aux !=NULL){
    while(fread(&astro,sizeof(stAstronauta),1,aux)>0){
        if(astro.id != datoID){
            posID++;
                }
            }
    fclose(aux);
        }
return posID;
}

void modificarUnAstro(stAstronauta* astro){

    int op = 0;
    limpiarPantalla();
    puts("-----------ASTRONAUTA ELEGIDO-------\n");
     mostrarUnAstronauta(astro);

    printf("Que desea cambiar\n");
    printf("1-Modificar Nombre\n");
    printf("2-Modificar apellido\n");
    printf("3-Modificar apodo\n");
    printf("4-Modificar edad\n");
    printf("5-Modificar estado\n");
    printf("6-No realizar ninguna modificacion\n");

    puts("Elija una opcion: \n");
    scanf("%i",&op);

switch(op){
case 1:
    printf("Ingrese el nuevo nombre\n");
    fflush(stdin);
    gets(astro->nombre);
break;
case 2:
    printf("ingrese el nuevo apellido\n");
    fflush(stdin);
    gets(astro->apellido);
break;
case 3:
    printf("Ingrese el nuevo apodo\n");
    fflush(stdin);
    gets(astro->apodo);
break;
case 4:
    printf("Ingrese la nueva edad\n");
    fflush(stdin);
    scanf("%i",&astro->edad);
break;
case 5:
    printf("Ingrese el nuevo estado\n");
    fflush(stdin);
    scanf("%i",&astro->estado);
break;
case 6:
    op == 7;
break;
default:
    printf("Opcion no valida, reintente...\n");
}
puts("-----------Astronauta modificado-------\n");
   mostrarUnAstronauta(astro);


}

