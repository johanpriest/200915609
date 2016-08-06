#include <stdio.h>
#include <stdlib.h>
#include "Lexico.h"
struct datos{
char nombre[1024];


};





typedef struct datos DATO;
char menu();
void insertar();
int main (void)
{
    char *pch;
  char op;
  do{
    op=menu();
    switch(op){
        case '1':
        system("cls");
          char cadena[256] ;
  printf ("Introduzca una cadena: ");
  fgets(cadena, 257, stdin);
   pch = strchr(cadena, 10);
    // Si la encontro, reemplazas nueva linea con nulo, que es el fin
    // de cadena ('')
    if (pch != NULL)
    {
        *pch =' ';
    }

    mostrarToken(cadena);



        break;
        case '2':
        system("cls");
//        mostrar();
        break;

    }

  }while(op!='3');

return 0;
}
char menu(){
    char op;
    system("cls");
    printf("\n  *** MENU ***");
    printf("\n (1)Insertar COMANDO :");
    printf("\n (2)Insertar SCRIPT :");
    printf("\n (3)Salir");
    printf("\n Opcion--> "); fflush(stdin);
    op=getch();

return op;

}
void insertar(){
FILE *fich;
DATO e;
if((fich=fopen("Registros.dsk","ab"))==NULL){

  printf("FICHERO NO EXISTE!!");
  }else{
int i=0;
for(i=0;i<1024;i++){

    fwrite(&e,sizeof(e),1,fich);

  }
  fclose(fich);
  }
}

