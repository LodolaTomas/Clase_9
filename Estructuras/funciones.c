#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define LIBRE 0
#define OCUPADO 1

void inicializarAlumnos(eAlumno listaDeAlumnos[],int cantidad,int inicializo)
{
    int i;
    int legajo=0;
    for(i=0; i<cantidad; i++)
    {
        legajo+=1;
        listaDeAlumnos[i].isEmpy=inicializo;
        listaDeAlumnos[i].legajo=legajo;
    }


}

void harcodeoAlumnos(eAlumno listaDeAlumnos[],int cantidad)
{
    int i;

    int legajo[]= {0,1,2,3,4};
    int isEmpy[]= {1,0,1,1,0};
    char nombre[][20]= {"juan","pedro","maria","julieta","pepe"};
    int nota[]= {10,2,9,4,6};

    for(i=0; i<cantidad; i++)
    {
        strcpy(listaDeAlumnos[i].nombre,nombre[i]);
        listaDeAlumnos[i].legajo=legajo[i];
        listaDeAlumnos[i].isEmpy=isEmpy[i];
        listaDeAlumnos[i].nota=nota[i];

    }
}
void mostrarAlumnos(eAlumno listaDeAlumnos[],int cantidad)
{

    int i;
    int flag=0;
    printf("%5s %10s %10s %10s\n","legajo","nombre","nota","presente");
    for(i=0; i<cantidad; i++)
    {
        if(listaDeAlumnos[i].isEmpy==OCUPADO)
        {
            flag=1;
            mostrarAlumno(listaDeAlumnos[i]);
            //printf("indice[%d],estaVacio[%d]\n",i,listaDeAlumnos[i].isEmpy);
        }
    }
    if(flag==0)
    {
        printf("\n No hay alumnos para mostrar\n");
    }

}
void mostrarAlumno(eAlumno alumno)
{
    char estado[]={"no"};
    if(alumno.isEmpy==OCUPADO)
    {
        strcpy(estado,"si");
    }

    printf("%5d %10s %10d %10s\n",alumno.legajo,alumno.nombre,alumno.nota,estado);

}
int buscarIndice(eAlumno listaDeAlumnos[], int cantidad)
{
    int i;
    int retorno=-1;
    for(i=0; i<cantidad; i++)
    {
        if(listaDeAlumnos[i].isEmpy==LIBRE)//define
        {
            retorno=i;
            break;
        }
    }


    return retorno;
}
void buscar_1_Alumno(eAlumno listaDeAlumnos[],int cantidad)
{
    char nombreSearch[20];
    int i;
    int retorno=-1;
    printf("\nIngrese el nombre al buscar:");
    scanf("%s",nombreSearch);
    printf("\n");
    for(i=0; i<cantidad; i++)
    {

        if(listaDeAlumnos[i].isEmpy==OCUPADO)
        {
            if(strcmp(listaDeAlumnos[i].nombre,nombreSearch)==0)
            {

                mostrarAlumno(listaDeAlumnos[i]);
                retorno=i;
                break;
            }
        }

    }
    if(retorno==-1)
    {

        printf("\n No existe ese Nombre \n");

    }

}
int buscar_2_Legajo(eAlumno listaDeAlumnos[],int cantidad)
{
    int legajoSearch;
    int i;
    int retorno=-1;
    printf("\nIngrese el legajo a buscar:");
    fflush(stdin);
    scanf("%d",&legajoSearch);

    for(i=0; i<cantidad; i++)
    {

        if(listaDeAlumnos[i].isEmpy==OCUPADO)
        {
            if(listaDeAlumnos[i].legajo==legajoSearch)
            {

                retorno=i;
                break;
            }
        }

    }
    if(retorno==-1)
    {

        printf("\n No existe ese Legajo \n");

    }

    return retorno;
}
void borrarAlumnos(eAlumno listaDeAlumnos[],int cantidad)
{
    int borrarLegajo;
     borrarLegajo= buscar_2_Legajo(listaDeAlumnos,cantidad);

        listaDeAlumnos[borrarLegajo].isEmpy=LIBRE;

        mostrarAlumnos(listaDeAlumnos,cantidad);

}


void cargarAlumno(eAlumno listaDeAlumno[],int cantidad)
{
    eAlumno auxAlumno;
    auxAlumno.legajo=buscarIndice(listaDeAlumno,cantidad);
    printf("Legajo[%d]\n",auxAlumno.legajo);
    pedirString("ingese Nombre:",auxAlumno.nombre,50);

    auxAlumno.isEmpy=OCUPADO;

    mostrarAlumno(auxAlumno);



}
void pedirString(char* menssage,char* lettlers,int len)
{
    char auxString[100];
    printf("%s",menssage);
    fflush(stdin);
    scanf("%s",auxString);
    while(strlen(auxString)>len)
    {
        printf("ERROR, Re%s",menssage);
        fflush(stdin);
        scanf("%s",auxString);
    }
    strcpy(lettlers,auxString);
}
void pedirInt(char* menssage,int* entero,int len)
{
    char auxString[100];
    printf("%s",menssage);
    fflush(stdin);
    scanf("%s",auxString);
    while(strlen(auxString)>len)
    {
        printf("ERROR, Re%s",menssage);
        fflush(stdin);
        scanf("%s",auxString);
    }
    entero=atoi(auxString);

}
void pausa()
{
    /*if(option==1)
    {
    system("read -p 'Press Enter to continue...' var");
    }
    else
    {
        system("pause");
    }*/
    system("read -p 'Press Enter to continue...' var");

}
void borrar()
{
    /*if(option==1)
    {
    system("clear");
    }else
    {
    system("cls");
    }*/
    system("clear");
}
