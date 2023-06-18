#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "astronauta.h"
#include <ctype.h>

void limpiarPantalla()
{
    system("cls");
}



stAstronauta crearUnAstro(int* idAstro)
{

    stAstronauta aux;
    *idAstro += 1; // arranca en 10 , de 10 para abajo son los predeterminados y luego de 10 para arriba los del usuario


    /// Validacion del astronauta

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
        printf("Ingrese la nacionalidad del astronauta: \n");
        fflush(stdin);
        scanf("%s",&aux.nacionalidad);
    }
    while(validarNacionalidad(aux.nacionalidad)==0);
    verificarEspecialidad(aux.especialidad);

    printf("|%s|",aux.especialidad);

    return aux;
}

int validarString(char auxNombre[])
{
    if (strlen(auxNombre) > 20 || strlen(auxNombre) < 3)
    {
        printf("Ingrese una palabra mayor a 3 letras y menor a 20 letras\n");
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
        printf("Ingrese una edad mayor a 18 y menor a 60 anios\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

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
    "Bosnia y Herzegovina",
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

int validarNacionalidad(char nacionalidad[])
{
    int i = 0;
    int j = 0;
    while(i<192)
    {
        if(strcmpi(nacionalidad,paises[i])== 0)
        {
            return 1;
        }
        i++;
    }
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













