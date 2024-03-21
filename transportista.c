#include <stdio.h>
#include <string.h>
#include "Transportista.h"
#include "func_aux.h"


int main(){ 
    FILE *fichero_transporte;
    transportista_estr *transportista_estr
    menu_transporte(fichero_transporte);
}

transportista carga_txt(){ //funcion dedicada a la carga de la informacion del txt a la estructura
    
}

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

void mod_nom(transportista_estr *transportista_estr){
    char nombre_introducido[20];
    system("cls");
    printf("Tu nombre actual es: %s\nintroduce tu nuevo nombre:",*transportista_estr->nombre);
    if(leer_string(*transportista_estr->nombre,N_nombre)==1){
        printf("Error de alamacenamiento")
    }
}

void mod_ciudad(transportista_estr *transportista_estr){
    char ciudad_nueva[50];
    system("cls");

}

void mod_email(cliente_estr cliente){
    char email_introducido[30];
    system("cls");

}

void mod_contr(cliente_estr cliente){
    char clave_introducida;
    system("cls");

}