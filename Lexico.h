#ifndef LEXICO_H_INCLUDED
#define LEXICO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <string.h>

typedef struct _nodo {
   char*  parametro;
   struct _nodo *siguiente;
} tipoNodo;
typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

/* Funciones con listas: */
void Insertar(Lista *l,char* parametro);
void MostrarLista(Lista lista);


int ListaVacia(Lista l);



void mostrarToken(char comando[256]){
char cadena[256];
strcpy(cadena,comando);
  Lista lista = NULL;
   pNodo p;
char *q;
q =strtok(cadena," ");

while(q!=NULL){
//printf("%s",q);

Insertar(&lista, q);
q=strtok(NULL," ");


}
MostrarLista(lista);
/*
    char* OutputFolder = "C:\\test";
if (CreateDirectory(OutputFolder, NULL) || ERROR_ALREADY_EXISTS == GetLastError())

{
   char* OutputFolder1 = "C:\\test\\test2";
    CreateDirectory(OutputFolder1, NULL);
}
else
{
     // Failed to create directory.
}


*/
}






void Insertar(Lista *lista,char* parametro) {
   pNodo nuevo, anterior;

   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->parametro = parametro;

   /* Si la lista está vacía */
   if(ListaVacia(*lista)) {
      /* Añadimos la lista a continuación del nuevo nodo */
      nuevo->siguiente = *lista;
      /* Ahora, el comienzo de nuestra lista es en nuevo nodo */
      *lista = nuevo;
   } else {
      /* Buscar el nodo de valor menor a v */
      anterior = *lista;


      /* Insertamos el nuevo nodo después del nodo anterior */
      nuevo->siguiente = anterior->siguiente;
      anterior->siguiente = nuevo;
   }
}

struct  mkdisk{
 int tamano;
char* unidad;
char* direccion;
char* nombre;


};

typedef struct mkdisk MKDISK;

void MostrarLista(Lista lista) {
   pNodo nodo = lista;
   MKDISK disk;
   if(ListaVacia(lista)) printf("Lista vacía\n");
   else {
      while(nodo) {

            char *q;
            q =strtok(nodo->parametro,"::");
            char *p;

            if(strcasecmp(q,"-size")==0){
                p =strtok(NULL,"::");
                int j=atoi(p);
                disk.tamano=j;


            }else if(strcasecmp(q,"+unit")==0){
                p =strtok(NULL,"::");
                disk.unidad=p;
            }else if(strcasecmp(q,"-path")==0){
                p =strtok(NULL,"::");
                disk.direccion=p;
            }else if(strcasecmp(q,"-name")==0){
                p =strtok(NULL,"::");
                disk.nombre=p;

            }



         nodo = nodo->siguiente;
     }
     printf("%d\n",disk.tamano);
      printf("%s\n",disk.unidad);
       printf("%s\n",disk.direccion);
        printf("%s\n",disk.nombre);



     printf("\n");
   }
}

int ListaVacia(Lista lista) {
   return (lista == NULL);
}

#endif // LEXICO_H_INCLUDED
