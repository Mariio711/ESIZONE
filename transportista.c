#include <stdio.h>
#include <string.h>
#include "Transportista.h"
#include "func_aux.h"


int main(){ 
    FILE *fichero_transporte;
    transportista_estr *transportista
    if(fopen("Transportista.txt","r")==NULL){
        printf("Error de apertura del fichero\n");
        exit (-1);
    }
    void transportista_carga_txt(*fichero_transporte, *transportista);
    fclose(*fichero_transporte);
    menu_transporte(*transportista);
}

void transportista_carga_txt(FILE *fichero_transporte, transportista_estr *transportista){ //funcion dedicada a la carga de la informacion del txt a la estructura
    
}

void intro_transportista(transportista_estr *transportista){
    printf("Transportista %s\n",*transportista->nombre);
    printf("1.Perfil\n");
    printf("2.Pedidos\n");
    printf("3.Devoluciones\n");
    printf("6.Salir del sistema\n");
}

void intro_transportista(){
    printf("Bienvenido transportista %s\n"/*funcion que obtenga el nombre transportista del txt*/);
    printf("1. Perfil\n");
    printf("2. Pedidos\n");
    printf("3. Retornos\n");
    printf("4. Salir del sistema\n");
}

void menu_transporte(transportista_estr *transportista){
    int option;

    intro_transportista();

    do{                                 //bucle para control de entrada
          scanf("%i",&option);
     }while(0>=option && option>=5); 
     switch(option){
         case 1:
                perfil_transportista(transportista_estr *transportista)
              break;
          case 2:
              /*funcion que nos permita ver los estados de los pedidos */
              break;
          case 3:
             /*funcion que gestione un txt con los pedidos en tramite de devolucion*/
             break;
         case 4:
               exit(-1);
               break;
    }
    
}

void menu_perfil(){
    printf("1. Mostrar informacion\n");
    printf("2. Modificar perfil\n");
    printf("3. Volver atras\n");
    printf("4. Salir\n");
}

void perfil_transportista(transportista_estr *transportista){
    int option;
    menu_perfil();
    
    do{                                 //bucle para control de entrada
          scanf("%i",&option);
     }while(0>=option && option>=5); 
     switch(option){
         case 1:
                mostrar_info_transportista(*transportista);
                break;
          case 2:
                mod_transporte(*transportista);
                break;
          case 3:
                menu_transporte(*transportista);
                break;
         case 4:
                 exit(-1);
                break;
    }
}


void mostrar_info_transportista(transportista_estr *transportista){

}

void mod_transporte(transportista_estr *transportista){

}

void mod_nom(transportista_estr *transportista){
    char nombre_introducido[20];
    system("cls");
    printf("Tu nombre actual es: %s\nintroduce tu nuevo nombre:",*transportista->nombre);
    
    do{
        if(leer_string(*transportista_estr->nombre,N_nombre)==1){
            printf("Error de alamacenamiento")
        }
    }while (leer_string(*transportista_estr->nombre,N_nombre)==1);
}

void mod_ciudad(transportista_estr *transportista){
    system("cls");
    mostrar_poblaciones(*transportista->ciudad)   
}

void mod_email(cliente_estr cliente){
    char email_introducido[30];
    system("cls");
     do{
        if(leer_string(*transportista->email,N_nombre)==1){
            printf("Error de alamacenamiento")
        }
    }while (leer_string(*transportista->email,N_nombre)==1);

}

void mod_contr(cliente_estr cliente){
    char clave_introducida;
    system("cls");

}