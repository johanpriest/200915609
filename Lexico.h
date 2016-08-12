#ifndef LEXICO_H_INCLUDED
#define LEXICO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
 #include <sys/types.h>
//#include "fdisk.h"

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
char *com=q;

if(strcasecmp(com,"mkdisk")==0){
        while(q!=NULL){
            Insertar(&lista, q);
            q=strtok(NULL," ");


            }
 MostrarLista(lista);


}else if(strcasecmp(com,"rmdisk")==0){
 while(q!=NULL){
            Insertar(&lista, q);
            q=strtok(NULL,"");


            }
EliminarArchivo(lista);

}else if(strcasecmp(com,"fdisk")==0){
while(q!=NULL){

Insertar(&lista,q);
q=strtok(NULL," ");

}
instrucciones(lista);

}

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
   disk.unidad="M";
   if(ListaVacia(lista)) printf("No se Ingreso Ningun Comando!!\n");
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
                char *dir=strtok(p,"\"");
                disk.direccion=dir;
            }else if(strcasecmp(q,"-name")==0){
                p =strtok(NULL,"::");
                char *t;
                t=strtok(p,"\"\"");
                disk.nombre=t;

            }

         nodo = nodo->siguiente;
     }
     printf("%d\n",disk.tamano);
     printf("%s\n",disk.unidad);
     printf("%s\n",disk.direccion);
     printf("%s\n",disk.nombre);
    printf("\n");

    CrearDisco(disk.nombre,disk.tamano,disk.unidad,disk.direccion);
   }
   ListaVacia(lista);
}

int ListaVacia(Lista lista) {
   return (lista == NULL);
}

//Creacion de disco sung el tamaña  dado
struct datos{
char nombre[1];


};

typedef struct datos DATO;




void CrearDisco(char *nombre,int tamano,char *unidad, char *direccion){

 //creacion del path del archivo

 char *directorio=strtok(direccion,"/");
 char resultado[512];





char direc[256];
strcpy(direc,"/home/gary7559/Documentos/ProyectoF1");

while(directorio!=NULL){

 strcat(direc,"/");
 strcat(direc,directorio);
 int fd2 = mkdir(direc, 0777); // Originally 777 (see comments)

if (fd2 != -1) {
    // use file descriptor
    close(fd2);
}
directorio=strtok(NULL,"/");
}



strcat(direc,"/");
strcat(direc,nombre);


FILE *fich;
DATO e;
strcpy(e.nombre,"0");
//strcat(resultado,nombre);
if((fich=fopen(direc,"w+b"))==NULL){

  printf("FICHERO NO EXISTE!!");
  }else{
      if(strcasecmp(unidad,"k")==0){
          int i=0;

        for(i=0;i<tamano*1024;i++){

           fwrite(&e,sizeof(e),1,fich);

        }
            fclose(fich);
      }else if(strcasecmp(unidad,"m")==0){
              int i=0;
              int kb=tamano*1024;
              char buffer1[] = {'\0'};
         fwrite (buffer1 , sizeof(char), sizeof(buffer1), fich);
        for(i=0;i<kb*1024;i++){

            fwrite(&e,sizeof(e),1,fich);

        }
            fclose(fich);

      }else{
      printf("ERROR NO SE RECONOCIO EL TAMAÑO DE LA UNIDAD A CREA",163);

      }

  }

}

void EliminarArchivo(Lista lista){
  pNodo nodo = lista;
   MKDISK disk;
    char resultado[1024];
   if(ListaVacia(lista)) printf("Lista vacía\n");
   else {
      while(nodo) {

            char *q;
            q =strtok(nodo->parametro,"::");
            char *p;

            if(strcasecmp(q,"-path")==0){
                p =strtok(NULL,"::");
                char *di=strtok(p,"\"\"");
  char *directorio=strtok(di,"/");
char* OutputFolder1=directorio;
strcpy(resultado,OutputFolder1);
directorio=strtok(NULL,"/");
     while(directorio!=NULL){
            strcat(resultado,"/");
            strcat(resultado,directorio);
            directorio=strtok(NULL,"/");



    }
            }

         nodo = nodo->siguiente;
     }





   if( remove(resultado) != 0 ) {
            printf( "\nNo Se pudo Borrar\n" );
   }else{
        printf( "\nBorrado\n" );
      }

   }
   ListaVacia(lista);

}


#endif // LEXICO_H_INCLUDED
