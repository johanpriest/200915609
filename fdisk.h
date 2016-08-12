#ifndef FDISK_H_INCLUDED
#define FDISK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Lexico.h"

struct MBR{
int mbr_tamano;
char mbr_fecha_creacion[25];
int mbr_disk_signature;
int part_status;
char part_type[1];
char part_fit[1];
int part_start;
int part_size;
char part_name[25];

};

struct fd{
 int tamano;
char* unidad;
char* direccion;
char* nombre;
char* type;
char* fit;
char* delet;
int agregar;


};
typedef struct fd fd1;


void instrucciones(Lista lista){
pNodo nodo=lista;

fd1 disk;

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

            }else if(strcasecmp(q,"+type")==0){
                p=strtok(NULL,"::");
                disk.type=p;
            }else if(strcasecmp(q,"+fit")==0){
                p=strtok(NULL,"::");
                disk.fit=p;

            }else if(strcasecmp(q,"+delete")==0){
                p=strtok(NULL,"::");
                disk.delet=p;
            }else if(strcasecmp(q,"+add")==0){
                p =strtok(NULL,"::");
                int j1=atoi(p);
                disk.agregar=j1;


            }

         nodo = nodo->siguiente;
     }
     printf("tamano: %d\n",disk.tamano);
     printf("unit: %s\n",disk.unidad);
     printf("path: %s\n",disk.direccion);
     printf("name: %s\n",disk.nombre);
     printf("add: %d\n",disk.agregar);
     printf("fit: %s\n",disk.fit);
     printf("type: %s\n",disk.type);
     printf("delete: %s\n",disk.delet);
    printf("\n");
    if(strcasecmp(disk.unidad,"b")==0){


crearParticion(disk.tamano,disk.unidad,disk.direccion,disk.nombre,disk.agregar,disk.fit,disk.type,disk.delet);
}else if(strcasecmp(disk.unidad,"k")==0){

crearParticion(disk.tamano,disk.unidad,disk.direccion,disk.nombre,disk.agregar,disk.fit,disk.type,disk.delet);


}else if(strcasecmp(disk.unidad,"m")==0){

crearParticion(disk.tamano,disk.unidad,disk.direccion,disk.nombre,disk.agregar,disk.fit,disk.type,disk.delet);


}else{
strcpy(disk.unidad,"k");
crearParticion(disk.tamano,disk.unidad,disk.direccion,disk.nombre,disk.agregar,disk.fit,disk.type,disk.delet);

}
   }
   ListaVacia(lista);

}



void crearParticion(int tamano,char *unidad,char *direccion,char *nombre,int agregar, char *fit,char *type, char* delet){
struct MBR mbr;
   FILE *fa;
   int opcion;
   long numero;
   char dir[256];
   strcpy(dir,"/home/gary7559/Documentos/ProyectoF1");
   strcat(dir,direccion);
   fa = fopen(dir, "r+b");          // Este modo permite leer y escribir
   if(fa==NULL){
    printf("No SE ENCUENTRA EL DISCO");
   }else{
    fa = fopen(dir, "rb+");
strcpy(dir,"0");
        fseek(fa, 0, SEEK_SET);
        fread(&mbr, sizeof(struct MBR),1,fa);



            if(strcasecmp(mbr.part_name,nombre)){

fseek(fa,0,SEEK_SET);
  strcpy(mbr.part_name,nombre);
  strcpy(mbr.part_type,type);
  strcpy(mbr.part_fit,fit);

  mbr.part_start=4*sizeof(struct MBR);
long nBytes;
fseek(fa, 0, SEEK_END); // Colocar el cursor al final del fichero
nBytes = ftell(fa);
mbr.mbr_tamano=nBytes;
if(strcasecmp(unidad,"b")==0){
        mbr.part_size=tamano;

}else if(strcasecmp(unidad,"k")==0){
        mbr.part_size=tamano*1024;

}else if(strcasecmp(unidad,"m")==0){
        mbr.part_size=tamano*1024*1024;

}





fseek(fa,0,SEEK_SET);
strcpy(mbr.part_name,nombre);
fwrite(&mbr, sizeof(struct MBR),1,fa);

          }else{
            printf("ds");

            }


        }  // si el fichero no existe, lo crea.


   fclose(fa);
   return 0;
}





#endif // FDISK_H_INCLUDED
