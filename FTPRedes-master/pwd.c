#include "ftp.h"

#define MAXCOMMAND 50  //Máximo largo del nombre del user


void pwdFTP(){
    char buffer[MAXCOMMAND] = "PWD"; //Espacio al final del comando
    strcat(&buffer,"\n"); //Salto de linea al final de los parametros
    
    if(send(sd, buffer, strlen(buffer), 0) <0){
        printf("%i\n",errno);
    };
    bzero(buffer,MAXCOMMAND);
    leerRespuesta();
}