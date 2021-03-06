#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE 100        // Tamaño máximo de una línea
#define MAX_ARGS 10         // Cantidad máxima de argumentos

// Comandos disponibles

#define QUIT 0
#define OPEN 1
#define USER 2
#define PASS 3
#define PWD 4
#define CD 5
#define LIST 6
#define PUT 7
#define GET 8
#define PASSIVE 9
#define ACTIVE 10
#define HELP 11


// Variable global de control

int keepWorking = 1;

// Declaraciones de funciones

int getvalorcomando(char * comando);

void ejecutarComando(char * comando, char * args[]);

void cadenaAMinuscula(char * str);

// Programa principal

int main(int argc, char * argv[]) {

    char * argumentos[MAX_ARGS]; // TODAVIA NO LO USE
    char linea[MAX_LINE];
    char * token;
    char * comando;

    if (argc > 1) {
        // BUSCAR SI SE PIDIO AYUDA O SI SE ESPECIFICO EL SERVER Y PORT PARA EL OPEN
        char* ip = "localhost";
        char* puerto = "21";
        printf("%s\t%s\n", ip, puerto);
        openFTP(ip, puerto);
    }

    while (keepWorking) {

        printf("FTP CLIENT $  ");

        // Se obtiene la línea ingresada por el usuario

        fgets(linea, MAX_LINE, stdin);

        // Se captura el nombre del comando

        token = strtok(linea, "\n ' '");

        // Si no se ingresó nada, el programa no realiza acciones.

        if (token == NULL)
            continue;

        // Se capturan los argumentos del comando

        int i = 0;
        comando = token;
        while (token != NULL) {
            i++;
            token = strtok(NULL, "\n ' '");
            argumentos[i] = token;
        }

        // Se ejecuta el comando con sus argumentos correspondientes

        ejecutarComando(comando, argumentos);

        // Se "limpian" los argumentos para el próximo comando
        int j;
        for (j = 0; j < MAX_ARGS; j++) {
            argumentos[j] = NULL;
        }


    }

    return (0);
}

/**
 * Transforma el string recibido en el mismo string pero en minúsculas.
 */
void cadenaAMinuscula(char * str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = tolower(str[i]);
    }
}

/**
    La función mapea un comando recbido en un string a un valor entero.
 */

int getvalorcomando(char * comando) {

    cadenaAMinuscula(comando);
    if (strcmp(comando, "exit") == 0 || strcmp(comando, "salir") == 0)
        return QUIT;
    if (strcmp(comando, "open") == 0 || strcmp(comando, "conectar") == 0)
        return OPEN;
    if (strcmp(comando, "user") == 0 || strcmp(comando, "usuario") == 0)
        return USER;
    if (strcmp(comando, "pass") == 0 || strcmp(comando, "clave") == 0)
        return PASS;
    if (strcmp(comando, "pwd") == 0 || strcmp(comando, "actual") == 0)
        return PWD;
    if (strcmp(comando, "cd") == 0)
        return CD;
    if (strcmp(comando, "list") == 0 || strcmp(comando, "mostrar") == 0)
        return LIST;
    if (strcmp(comando, "put") == 0 || strcmp(comando, "subir") == 0)
        return PUT;
    if (strcmp(comando, "get") == 0 || strcmp(comando, "bajar") == 0)
        return GET;
    if (strcmp(comando, "passive") == 0 || strcmp(comando, "pasivo") == 0)
        return PASSIVE;
    if (strcmp(comando, "active") == 0 || strcmp(comando, "activo") == 0)
        return ACTIVE;
    if (strcmp(comando, "-h") == 0)
        return HELP;

    return -1;

}

/**
    La función recibe el nombre del comando a ejecutar en 'comando'
    y los argumentos para dicho comando en 'args'.
 */
void ejecutarComando(char * comando, char * argumentos[]) {

    int valorComando = getvalorcomando(comando);

    switch (valorComando) {

        case QUIT:
        {
            keepWorking = 0;
            break;
        }

        case OPEN:
        {
            printf("OPEN COMMAND\n");
            break;
        }

        case USER:
        {
            printf("USER COMMAND\n");
            break;
        }

        case PASS:
        {
            printf("PASS COMMAND\n");
            break;
        }

        case PWD:
        {
            printf("PWD COMMAND\n");
            break;
        }

        case CD:
        {
            printf("CD COMMAND\n");
            break;
        }

        case LIST:
        {
            printf("LIST COMMAND\n");
            break;
        }

        case PUT:
        {
            printf("PUT COMMAND\n");
            break;
        }

        case GET:
        {
            printf("GET COMMAND\n");
            break;
        }

        case PASSIVE:
        {
            printf("PASSIVE COMMAND\n");
            break;
        }

        case ACTIVE:
        {
            printf("ACTIVE COMMAND\n");
            break;
        }

        case HELP:
        {
            printf("Comandos disponibles:\n\n");
            printf("..........\n\n");
            break;
        }

        case -1:
        {
            printf("El comando ingresado no es válido. Tipear '-h' para recibir ayuda sobre los comandos disponibles.\n");
        }

    }


}


