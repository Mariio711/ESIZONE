#include <stdio.h>
#include "pedidos.h"

int main(int aux,int id){ //si aux=0 el usuario sera un usuario normal, pero si es un transportista aux=1
   FILE *fichero_pedidos;
   pedidos *pedido;

   carga_txt(*fichero_pedidosm,*pedido,id,aux);
   switch_pedidos(aux);

   return 0;
}

void carga_txt(FILE *f, pedidos *pedido, int id,int aux){
    int i=0;
    if(aux==0){
        do{
            recopilacion_pedidos(*(pedido+i),id)
        }while(i<numero_pedidos(*f,id,aux))
    }
    else{
        do{
            recopilacion_pedidos(*(pedido+i),id)
        }while(i<numeros_pedidos(*f,id,aux))
    }
}

int numero_pedidos(fILE *f, int id, int aux){
    int i=0;
  
    if(aux==0){
        if(f=fopen("Pedidos.txt","r")==NULL){
            printf("Error\n");
            exit(1);
        }
        else{
        /*comparador con el txt*/
        }
    }
    else{
        if(f=fopen("ProductosPedidos.txt","r")==NULL){
            printf("Error\n");
            exit(1);
        }
        else{
        /*comparador con el txt*/
        }
    }
    fclose(f);
    return(i);
}

void recopilacion_pedidos(pedidos *pedido){

}

void menu_pedidos(int aux){
    if(aux==0){                                 /*Menu para usuarios*/
        printf("Seleccione una opcion\n");
        printf("1. Ver pedidos\n");
        printf("2. Cancelar pedido\n");
        printf("3. Devolver pedido\n");
        printf("4. Salir\n");
    }
    else{                                       /*Menu para transportista*/
        printf("Seleccione una opcion\n");
        printf("1. Ver pedidos\n");
        printf("2. Ver devoluciones\n");
        printf("3. Salir\n");
    }
}

void switch_pedidos(int aux){
    int option;

    menu_pedidos(aux);

    do{
            scanf("%i",&option);
        }while()

    if(aux==0){   
        switch (option)
        {
            case 1:
                mostrar_pedidos(aux);
                break;
            case 2:
                /*funcion para cancelar pedidos*/
                break;
            case 3:
                /*funcion para devolver pedidos*/
                break;
            case 4:
                exit(1);
                break;
        }
    }
    else{
        switch (option)
        {
            case 1:
                /* funcion que muestre los pedidos */
                
                break;
            case 2:
                /*funcion que muestre las devoluciones pendientes*/
                break;
            case 3:
                exit(1);
                break;
        }
    }
}

void mostrar_pedidos(int aux){
    if(aux==0){

    }
    else{

    }
}