#include <stdio.h>
#include <string.h>
#include "Transportista.h"

int main(){ 
    FILE *fichero_transporte;
    transportista trans
    menu_transporte(fichero_transporte);
}

transportista carga_txt(){ //funcion dedicada a la carga de la informacion del txt a la estructura
    
}

int who_are_you()

void intro_transportista(){
    printf("Transportista %s\n"/*funcion que obtenga el nombre transportista del txt*/);
    printf("1.Perfil\n");
    printf("2.Pedidos\n");
    printf("3.Retornos\n");
    printf("6.Salir del sistema\n");

}

void menu_transporte(FILE *fichero){
    int option;

    if((fichero=fopen("transportistas.txt","w"))==NULL){ //control de apertura del fichero
        printf("Error de apertura del fichero\n");
    }
    else{
        intro_transportista();

        do{                                 //bucle para control de entrada
            scanf("%i",&option);
        }while(0>=option && option>=5); 
        switch(option){
            case 1:
                /*funcion que nos permita modificar el fichero con la informacion del transportista*/
                break;
            case 2:
                /*funcion que nos permita ver los estados de los pedidos */
                break;
            case 3:
                /*funcion que gestione un txt con los pedidos en tramite de devolucion*/
                break;
            case 4:
                /*exit*/
                break;
            }


    }

    fclose(fichero);
}

void intro_transportista(){
    printf("Transportista %s\n"/*funcion que obtenga el nombre transportista del txt*/);
    printf("1.Perfil\n");
    printf("2.Pedidos\n");
    printf("3.Retornos\n");
    printf("6.Salir del sistema\n");

}
