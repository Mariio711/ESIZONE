#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Proveedor.h"

int main(){
    provedor_estr x;
    provedor_estr *provedor;
    provedor=&x;

    system("cls");
    ficheros(1,provedor);            //la idea es que le de la id y en el fichechos busque el usuario o con otra funcion
    bienvenida(provedor); 
}

///bienvenida
//cabecera: void bienvenida(provedor_estr *);
//precondicion: recibe la estructura cliente ya inicializada
//postcondicion: llama a la funcion deseada
void bienvenida(provedor_estr * provedor){
    int elec_b;
    do{
        system("cls");

        printf("Empresa: %s\nQue desea hacer?\n1. Perfil\n2. Productos\n3. Descuentos\n4. Pedidos\n5. Devoluciones\n6. Salir <-\n",provedor->nombre_empresa);
        do{
            scanf("%i",&elec_b);
            if(elec_b<1||elec_b>6)
                printf("Eleccion no valida, intentelo de nuevo:");           //control de entrada
            fflush(stdin);
        }while(elec_b<1||elec_b>4);

        switch(elec_b){
           case 1:perfil(provedor);
               break;
           case 2:productos();
                break;
            case 3:pedidos();
               break;
           case 4:printf("\nadios");        ///llamar a login
               break;
          }
    }while(elec_b!=4);
}


//productos
void productos(){
    printf("modulo productos");     ///ANTONIO----------------------------
}

//pedidos
void pedidos(){
    printf("modulo pedidos");      ///SALAS----------------------------------
}