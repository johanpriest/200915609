#include <stdio.h>
#include <stdlib.h>
#include "fdisk.h"
#include <fcntl.h>


char menu();

int main (void)
{



char comando[256];
char *p;
char *pch;
fflush(stdin);
        printf( "\nIngresar linea de comando: ", 163 );
        fgets( comando, 257, stdin );
        printf("linea %s",comando);

        pch = strchr(comando, 10);
    // Si la encontro, reemplazas nueva linea con nulo, que es el fin
    // de cadena ('')
    if (pch != NULL)
    {
        *pch =' ';
    }
mostrarToken(comando);
if(strcasecmp(comando,"exit ")==0){

    return 0;
}else{

main();
}
return 0;
}

