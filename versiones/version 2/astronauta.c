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
    "Afganistán",
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
    "Azerbaiyán",
    "Bahamas",
    "Bangladés",
    "Barbados",
    "Baréin",
    "Bélgica",
    "Belice",
    "Benín",
    "Bielorrusia",
    "Birmania (Myanmar)",
    "Bolivia",
    "Bosnia y Herzegovina",
    "Botsuana",
    "Brasil",
    "Brunéi",
    "Bulgaria",
    "Burkina Faso",
    "Burundi",
    "Bután",
    "Cabo Verde",
    "Camboya",
    "Camerún",
    "Canadá",
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
    "Emiratos Árabes Unidos",
    "Eritrea",
    "Eslovaquia",
    "Eslovenia",
    "España",
    "Estados Unidos",
    "Estonia",
    "Eswatini (Suazilandia)",
    "Etiopía",
    "Filipinas",
    "Finlandia",
    "Fiyi",
    "Francia",
    "Gabón",
    "Gambia",
    "Georgia",
    "Ghana",
    "Granada",
    "Grecia",
    "Guatemala",
    "Guinea",
    "Guinea-Bisáu",
    "Guinea Ecuatorial",
    "Guyana",
    "Haití",
    "Honduras",
    "Hungría",
    "India",
    "Indonesia",
    "Irak",
    "Irán",
    "Irlanda",
    "Islandia",
    "Islas Marshall",
    "Islas Salomón",
    "Israel",
    "Italia",
    "Jamaica",
    "Japón",
    "Jordania",
    "Kazajistán",
    "Kenia",
    "Kirguistán",
    "Kiribati",
    "Kuwait",
    "Laos",
    "Lesoto",
    "Letonia",
    "Líbano",
    "Liberia",
    "Libia",
    "Liechtenstein",
    "Lituania",
    "Luxemburgo",
    "Madagascar",
    "Malasia",
    "Malaui",
    "Maldivas",
    "Malí",
    "Malta",
    "Marruecos",
    "Mauricio",
    "Mauritania",
    "México",
    "Micronesia",
    "Moldavia",
    "Mónaco",
    "Mongolia",
    "Montenegro",
    "Mozambique",
    "Namibia",
    "Nauru",
    "Nepal",
    "Nicaragua",
    "Níger",
    "Nigeria",
    "Noruega",
    "Nueva Zelanda",
    "Omán",
    "Países Bajos (Holanda)",
    "Pakistán",
    "Palaos",
    "Panamá",
    "Papúa Nueva Guinea",
    "Paraguay",
    "Perú",
    "Polonia",
    "Portugal",
    "Reino Unido",
    "República Centroafricana",
    "República Checa",
    "República Democrática del Congo",
    "República Dominicana",
    "Ruanda",
    "Rumania",
    "Rusia",
    "Samoa",
    "San Cristóbal y Nieves",
    "San Marino",
    "San Vicente y las Granadinas",
    "Santa Lucía",
    "Santo Tomé y Príncipe",
    "Senegal",
    "Serbia",
    "Seychelles",
    "Sierra Leona",
    "Singapur",
    "Siria",
    "Somalia",
    "Sri Lanka",
    "Sudáfrica",
    "Sudán",
    "Sudán del Sur",
    "Suecia",
    "Suiza",
    "Surinam",
    "Tailandia",
    "Tanzania",
    "Tayikistán",
    "Timor Oriental",
    "Togo",
    "Tonga",
    "Trinidad y Tobago",
    "Túnez",
    "Turkmenistán",
    "Turquía",
    "Tuvalu",
    "Ucrania",
    "Uganda",
    "Uruguay",
    "Uzbekistán",
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













