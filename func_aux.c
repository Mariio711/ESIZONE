#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "login.h"
#include "func_aux.h"
#include "admin.h"


char poblacion[N_localidad][50] = {
    "Sanlucar de Bda",
    "Jerez de la Fra",
    "Cadiz",
    "Puerto real",
    "San Fernando",
    "Chiclana de la Fra",
    "El Pto de Santa Maria", 
    "Chipiona",
};

//cabecera: void mostrar_poblaciones(char* seleccionado)
//precondicion: recibe un puntero a caracteres (char*) que representa la población seleccionada
//postcondicion: muestra por pantalla las poblaciones disponibles y permite seleccionar una de ellas.
void mostrar_poblaciones(char* seleccionado) {

    int i,opcion=0;
     do {
    printf("\n\n\tSeleccione una población:\n\n");
    for (i = 0; i < N_localidad; i++){
        printf("\t\t%d. %s\n", i+1, poblacion[i]);
    }
    printf("\n\n\tOpcion: ");

    opcion = 0;
        if (scanf("%d", &opcion) != 1 || ( opcion < 1 || opcion > N_localidad)) {
            error_scanf();
        }
    } while (opcion < 1 || opcion > N_localidad);

    strcpy(seleccionado, poblacion[opcion-1]);

}



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

//cabecera: int modif(char *modificador, int N)
//precondicion: modificador es un puntero a una cadena de caracteres y N es un entero que indica la longitud máxima de la cadena. modificador debe tener al menos N+1 elementos.
//postcondicion: La función lee una cadena de caracteres desde el teclado y la almacena en modificador, siempre y cuando la cadena no supere la longitud máxima indicada por N.
// La función retorna 1 si la cadena se pudo modificar y 0 en caso contrario.
int modif(char *modificador, int N){

    char aux[50];
    int auxi, control=0;;

    do{
        leer_string(aux, 50);
        
        if(strlen(aux)>N){
            control=1;
            printf("\n\tLa cadena no puede tener mas de %i caracteres", N);
            printf("\n\tIntroduce de nuevo (max %i caracteres): ", N);
        }else{
            control=0;
        }
        
    }while(control==1);

    control_modif(modificador, aux, N);
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

//cabecera: void layer_esizon()
//precondicion: no recibe nada
//postcondicion: muestra por pantalla el nombre del proyecto en ASCII art
void layer_esizon(){

    printf("\n\n");
    printf("%40s", "███████╗░██████╗██╗███████╗░█████╗░███╗░░██╗\n");
    printf("%40s", "██╔════╝██╔════╝██║╚════██║██╔══██╗████╗░██║\n");
    printf("%40s", "█████╗░░╚█████╗░██║░░███╔═╝██║░░██║██╔██╗██║\n");
    printf("%40s", "██╔══╝░░░╚═══██╗██║██╔══╝░░██║░░██║██║╚████║\n");
    printf("%40s", "███████╗██████╔╝██║███████╗╚█████╔╝██║░╚███║\n");
    printf("%40s", "╚══════╝╚═════╝░╚═╝╚══════╝░╚════╝░╚═╝░░╚══╝\n");
    printf ("\n\n");
}