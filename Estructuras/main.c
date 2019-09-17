#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define C 5

int main()
{
eAlumno listadodeAlumnos[C];//definicion//[]cantidad de lugares

    int option;

    //inicializarAlumnos(listadodeAlumnos,C,0);

    harcodeoAlumnos(listadodeAlumnos,C);

    //indice=buscarIndice(listadodeAlumnos,C);

    //printf("\n\nindice[%d]\n",indice);

    //buscar_1_Alumno(listadodeAlumnos,C);
    //buscar_2_Legajo(listadodeAlumnos,C);


do
    {

        printf("1. Cargar\n");
        printf("2. Mostrar\n");
        printf("3. Ordenar\n");
        printf("4. Borrar\n");
        printf("5.Salir\n\n");

        printf("Elija una opcion:");
        scanf("%d",&option);

        switch(option)
        {

        case 1:
            borrar();
            cargarAlumno(listadodeAlumnos,C);
            pausa();
            break;
        case 2:
            borrar();
            mostrarAlumnos(listadodeAlumnos,C);
            pausa();
            break;
        case 3:

            break;
        case 4:
            borrar();
            mostrarAlumnos(listadodeAlumnos,C);
            borrarAlumnos(listadodeAlumnos,C);
            pausa();
            break;
        case 5:
            printf("\nHASTA LUEGO..");
            break;
        default:
            borrar();
            printf("ERROR. Elija una opcion del 1-5\n");
            pausa();
            break;

        }
        borrar();

    }
    while(option!=5);


    return 0;
}
