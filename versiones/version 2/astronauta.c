#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astronauta.h"
#include <ctype.h>





stAstronauta crearUnAstro(int* idAstro) {

    stAstronauta aux;
    *idAstro += 1; // arranca en 10 , de 10 para abajo son los predeterminados y luego de 10 para arriba los del usuario


    /// Validacion del astronauta

    do {
        printf("Ingrese el nombre del astronauta: \n");
        fflush(stdin);
        gets(aux.nombre);
    } while(validarString(aux.nombre)==0);

    do {
        printf("Ingrese el apellido del astronauta: \n");
        fflush(stdin);
        gets(aux.apellido);
    } while(validarString(aux.apellido)==0);

    do {
        printf("Ingrese el apodo del astronauta: \n");
        fflush(stdin);
        gets(aux.apodo);
    } while(validarString(aux.apodo)==0);

    do {
        printf("Ingrese la edad del astronauta: \n");
        fflush(stdin);
        scanf("%i",&aux.edad);
    } while(validarEdad(aux.edad)==0);
    ///VALIDAR NACIONALIDAD
    verificarEspecialidad(aux.especialidad);

    return aux;
}

int validarString(char auxNombre[]) {
    if (strlen(auxNombre) > 20 || strlen(auxNombre) < 3) {
        printf("Ingrese una palabra mayor a 3 letras y menor a 20 letras\n");
        return 0;
    } else {
        return 1;
    }


}

int validarEdad(int edad) {

    if (edad < 18  || edad > 60) {
        printf("Ingrese una edad mayor a 18 y menor a 60 anios\n");
        return 0;
    } else {
        return 1;
    }
}
const char paises[] = {
    "Afganist�n",
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
    "Azerbaiy�n",
    "Bahamas",
    "Banglad�s",
    "Barbados",
    "Bar�in",
    "B�lgica",
    "Belice",
    "Ben�n",
    "Bielorrusia",
    "Birmania (Myanmar)",
    "Bolivia",
    "Bosnia y Herzegovina",
    "Botsuana",
    "Brasil",
    "Brun�i",
    "Bulgaria",
    "Burkina Faso",
    "Burundi",
    "But�n",
    "Cabo Verde",
    "Camboya",
    "Camer�n",
    "Canad�",
    "Catar",
    "Chad",
    "Chile",
    "China",
    "Chipre",
    "Ciudad del Vaticano",
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
    "Emiratos �rabes Unidos",
    "Eritrea",
    "Eslovaquia",
    "Eslovenia",
    "Espa�a",
    "Estados Unidos",
    "Estonia",
    "Eswatini (Suazilandia)",
    "Etiop�a",
    "Filipinas",
    "Finlandia",
    "Fiyi",
    "Francia",
    "Gab�n",
    "Gambia",
    "Georgia",
    "Ghana",
    "Granada",
    "Grecia",
    "Guatemala",
    "Guinea",
    "Guinea-Bis�u",
    "Guinea Ecuatorial",
    "Guyana",
    "Hait�",
    "Honduras",
    "Hungr�a",
    "India",
    "Indonesia",
    "Irak",
    "Ir�n",
    "Irlanda",
    "Islandia",
    "Islas Marshall",
    "Islas Salom�n",
    "Israel",
    "Italia",
    "Jamaica",
    "Jap�n",
    "Jordania",
    "Kazajist�n",
    "Kenia",
    "Kirguist�n",
    "Kiribati",
    "Kuwait",
    "Laos",
    "Lesoto",
    "Letonia",
    "L�bano",
    "Liberia",
    "Libia",
    "Liechtenstein",
    "Lituania",
    "Luxemburgo",
    "Madagascar",
    "Malasia",
    "Malaui",
    "Maldivas",
    "Mal�",
    "Malta",
    "Marruecos",
    "Mauricio",
    "Mauritania",
    "M�xico",
    "Micronesia",
    "Moldavia",
    "M�naco",
    "Mongolia",
    "Montenegro",
    "Mozambique",
    "Namibia",
    "Nauru",
    "Nepal",
    "Nicaragua",
    "N�ger",
    "Nigeria",
    "Noruega",
    "Nueva Zelanda",
    "Om�n",
    "Pa�ses Bajos (Holanda)",
    "Pakist�n",
    "Palaos",
    "Panam�",
    "Pap�a Nueva Guinea",
    "Paraguay",
    "Per�",
    "Polonia",
    "Portugal",
    "Reino Unido",
    "Rep�blica Centroafricana",
    "Rep�blica Checa",
    "Rep�blica Democr�tica del Congo",
    "Rep�blica Dominicana",
    "Ruanda",
    "Rumania",
    "Rusia",
    "Samoa",
    "San Crist�bal y Nieves",
    "San Marino",
    "San Vicente y las Granadinas",
    "Santa Luc�a",
    "Santo Tom� y Pr�ncipe",
    "Senegal",
    "Serbia",
    "Seychelles",
    "Sierra Leona",
    "Singapur",
    "Siria",
    "Somalia",
    "Sri Lanka",
    "Sud�frica",
    "Sud�n",
    "Sud�n del Sur",
    "Suecia",
    "Suiza",
    "Surinam",
    "Tailandia",
    "Tanzania",
    "Tayikist�n",
    "Timor Oriental",
    "Togo",
    "Tonga",
    "Trinidad y Tobago",
    "T�nez",
    "Turkmenist�n",
    "Turqu�a",
    "Tuvalu",
    "Ucrania",
    "Uganda",
    "Uruguay",
    "Uzbekist�n",
    "Vanuatu",
    "Venezuela",
    "Vietnam",
    "Yemen",
    "Yibuti",
    "Zambia",
    "Zimbabue"
}

int validarNacionalidad(char nacionalidad[]){

int j = 0;

nacionalidad[j]=tolower(nacionalidad);
paises[i] =tolower(paises);

strcmp///TERMINAR LA LOGICA

}

void verificarEspecialidad(char especialidad[])
{

int flag = 0;
int op = 0;
do{
    switch(op){
case 1:
    strcpy(especialidad,"Piloto\n");
    break;
case 2:
        strcpy(especialidad,"Astrofisico\n");
    break;
case 3:
        strcpy(especialidad,"Ingeniero Espacial\n");
    break;
case 4:
    strcpy(especialidad,"Biologo\n");
    break;
case 5:
    strcpy(especialidad,"Tecnico Superior en Programacion\n");
    break;
default:

    printf("OPCION INCORRECTA...Reintente\n");
    break;

    }

}while(flag == 0);

}
void mostrarEspecialidad(){

printf("1-Piloto\n");
printf("2-Astrofico\n");
printf("3-Ingeniero Espacial\n");
printf("4-Biologo\n");
printf("5-Tecnico Superior en Programacion\n");


}













