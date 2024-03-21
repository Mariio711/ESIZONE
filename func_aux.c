#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "usuarios.h"
#include "func_aux.h"


//cabecera: void iguales(char* cab, char* stringadd).
//precondicion: recibe dos punteros a caracteres (char*), representando una cadena de caracteres (cab) y otra cadena de caracteres a añadir (stringadd).
//postcondicion: muestra por pantalla una línea de caracteres igual (=) con la longitud de la suma de ambas cadenas más un salto de línea (\n) al final.
void iguales(char* cab, char* stringadd){

    int i;
    for (i=0;i < ((strlen(cab))+(strlen(stringadd))); i++){
        printf("=");
    }
    printf("\n");
}

//cabecera: int leer_string(char aux, int MAX)
//precondicion: recibe un puntero a caracteres (char) y un entero MAX que indica la longitud máxima de caracteres que se pueden leer
//postcondicion: lee una cadena de caracteres de la entrada del usuario y la almacena en aux. Devuelve 1 si la entrada supera MAX caracteres y 0 en caso contrario.
int leer_string(char *aux, int MAX) {
    // Leer la entrada del usuario
    fflush(stdin);
    if (fgets(aux, MAX+2, stdin) == NULL) {
        // Si fgets() falla, establecer aux[0] en '\0'
        aux[0] = '\0';
        return 1;
    }

    // Verificar si la entrada excede el tamaño máximo del buffer
    if (strlen(aux) == MAX+1 && aux[MAX] != '\n') {
        // Si la entrada es demasiado larga, descartar el resto de la entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // Eliminar el salto de línea final, si existe
    aux[strcspn(aux, "\n")] = '\0';
}

//cabecera: void error_scanf()
//precondicion: no recibe nada
//postcondicion: muestra por pantalla un mensaje de error por una entrada no compatible con scanf.
void error_scanf(){

    printf("\n\tError: Entrada no compatible, introduzca de nuevo\n");
    printf("\n\tPulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada       
    getchar();      //pausa
    system("cls");
}

//cabecera: int control_modif(char *modificador, char aux)
//precondicion: recibe dos punteros a caracteres (char): modificador, que representa el valor original, y aux, que representa el nuevo valor propuesto
//postcondicion: muestra por pantalla una confirmación para cambiar de modificador a aux y devuelve un entero indicando si se realizó o no la modificación
int control_modif(char *modificador, char *aux, int MAX){


    int auxi;
    printf("\n\tEstas seguro de cambiar de %s a %s, si(1) o no (0): ",modificador, aux);
    if (scanf("%i", &auxi) != 1 || (auxi!=1 && auxi!=0)) {                      // Si scanf no pudo leer un número entero
        error_scanf();
        return 0;
    }
    
    if (auxi==0){
        return 0;
    }
    fflush(stdin);
    if(strcmp(strcpy(modificador,aux),aux) == 0 && strlen(aux) <= MAX){
        printf("\n\n\tLA MODIFIACION SE REALIZO CON EXITO");
        return 1;
    }else{
        printf("\n\n\tLA MODIFIACION NO SE REALIZO CORRECTAMENTE, VUELVA A INTENTARLO");
        return 0;
    }
}