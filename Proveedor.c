#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Proveedor.h"
#include "Productos.h"

///inicio provedor
//cabezera: void inicio_prov();
//precondicion: tiene que ser llamado por un usuario y recive su id
//poscondicion: llama a la funcion fichero_prov para que inicialice la estructura cliente y luego da paso a bienvenido para que comience el modulo
int main(){//void inicio_prov()
    provedor_estr x;
    provedor_estr *provedor;
    provedor=&x;

    system("cls");
    ficheros_prov(1,provedor);            //la idea es que le de la id y en el fichechos_prov busque el usuario o con otra funcion
    bienvenida_prov(provedor); 
}

///bienvenida_prov
//cabecera: void bienvenida_prov(provedor_estr *);
//precondicion: recibe la estructura cliente ya inicializada
//postcondicion: llama a la funcion deseada
void bienvenida_prov(provedor_estr * provedor){
    int elec_b;
    do{
        system("cls");

        printf("Empresa: %s\nQue desea hacer?\n1. Perfil\n2. Productos\n3. Pedidos\n4. Salir <-\n",provedor->nombre_empresa);
        do{
            scanf("%i",&elec_b);
            if(elec_b<1||elec_b>6)
                printf("Eleccion no valida, intentelo de nuevo:");           //control de entrada
            fflush(stdin);
        }while(elec_b<1||elec_b>4);

        switch(elec_b){
           case 1:perfil_prov(provedor);
               break;
           case 2:productos_prov();
                break;
           case 3:pedidos_prov();
               break;
           case 4:printf("\nadios");        ///llamar a login
               break;
          }
    }while(elec_b!=4);
}

///perfil
//cabecera: void perfil(provedor_estr *);
//precondicion: estructura provedor ya inicializada
//poscondicion: elige que funcion llamar y muestra los datos de la empresa
void perfil_prov(provedor_estr * provedor){
    int elec_perfil;
    do{
        system("cls");
        printf("empresa: %s\n",provedor->nombre_empresa);
        printf("correo: %s\n",provedor->correo);
        printf("-----------------------------------------------------\n");
        printf("Que quieres hacer?\n1. Modificar nombre de la empresa\n2. Modificar correo\n3. Modificar clave\n4. volver <-\n");

        do{
          scanf("%i",&elec_perfil);
          if(elec_perfil<1||elec_perfil>4)
              printf("Eleccion no valida, intentelo de nuevo:");           //control de entrada
           fflush(stdin);
        }while(elec_perfil<1||elec_perfil>4);

        switch(elec_perfil){
          case 1:mod_nom_prov(provedor);
              break;
           case 2:mod_email_prov(provedor);
               break;
           case 3:mod_contr_prov(provedor);
               break;
        }
    }while(elec_perfil!=4);
}

///modificar nombre_prov
//cabecera: void mod_nom_prov(provedor_estr *);
//precondicion: estructura provedor ya inicializada
//poscondicion: cambia el nombre en la estructura cliente y llama a la funcion ficheros_prov para guardarlo
void mod_nom_prov(provedor_estr * provedor){
    char nombre_introducido[20];
    char clave_introducida[15];
    system("cls");
    printf("el nombre de la empresa actual es: %s\nintroduce tu nuevo nombre:",provedor->nombre_empresa);
    gets(nombre_introducido);
    fflush(stdin);

    printf("introduzca su clave para confirmar:");
    gets(clave_introducida);
    fflush(stdin);
        if(strcmp(provedor->clave,clave_introducida)==0){
            printf("Clave correcta :)\n");                          
            system("pause");
            strcpy(provedor->nombre_empresa,nombre_introducido);
            ficheros_prov(2,provedor); //guarda el nombre
        }
        else{
            printf("Clave incorrecta :(\n");
            system("pause");
        }
}

//modificar correo_prov
//cabecera: void mod_email_prov(provedor_estr *);
//precondicion: estructura provedor ya inicializada
//poscondicion: cambia el correo en la estructura cliente y llama a la funcion ficheros_prov para guardarlo
void mod_email_prov(provedor_estr * provedor){
    char email_introducido[30];
    char clave_introducida[15];
    system("cls");
    printf("Tu correo actual es: %s\nintroduce tu nuevo correo:",provedor->correo);
    gets(email_introducido);
    fflush(stdin);

    printf("introduzca su clave para confirmar:");
    gets(clave_introducida);
    fflush(stdin);
        if(strcmp(provedor->clave,clave_introducida)==0){
            printf("Clave correcta :)\n");                          
            system("pause");
            strcpy(provedor->correo,email_introducido);
            ficheros_prov(2,provedor); //guarda el correo
        }
        else{
            printf("Clave incorrecta :(\n");
            system("pause");
        }
}

//modificar contraseña_prov
//cabecera: void mod_contr_prov(provedor_estr *);
//precondicion: estructura provedor ya inicializada
//poscondicion: cambia la clave en la estructura cliente y llama a la funcion ficheros_prov para guardarla
void mod_contr_prov(provedor_estr * provedor){
    char clave_introducida[15];
    char clave_nueva[15];
    char confirmar[15];
    system("cls");
    printf("introduzca su antigua clave para confirmar:");
    gets(clave_introducida);
    fflush(stdin);
        if(strcmp(provedor->clave,clave_introducida)==0){
            printf("Clave correcta :)\n");                          
            system("pause");
            do{
                printf("introduce tu nueva clave:");
                gets(clave_nueva);
                fflush(stdin);
                printf("introducela de nuevo para confirmar:");
                gets(confirmar);
                fflush(stdin);
                if(strcmp(clave_nueva,confirmar)!=0)
                    printf("\nlas claves no coinciden :(\n");
            }while(strcmp(clave_nueva,confirmar)!=0);
            strcpy(provedor->clave,clave_nueva);
            ficheros_prov(2,provedor); //guarda las claves
        }
        else{
            printf("Clave incorrecta :(\n");
            system("pause");
        }
}

//productos_prov
void productos_prov(){
    printf("modulo productos");     ///ANTONIO----------------------------
}

//pedidos_prov
void pedidos_prov(){
    printf("modulo pedidos");      ///SALAS----------------------------------
}

///fichero_prov
//cabecera: ficheros_prov(int,provedor_estr *);
//precondicion: se le introduce 1 si se quiere que inicialice la estructura y 2 si quiere que guarde los datos en el fichero
//poscondicion: inicializa la estructura o guarda datos en el fichero
void ficheros_prov(int palanca,provedor_estr * provedor){
    system("cls");
    //FILE*f;
    if(palanca==1){
        if(1==1){                                  //((f=fopen("AdminProv.txt","r"))!=NULL){    
            provedor->id_empresa=0001;
            strcpy(provedor->nombre_empresa,"Marisco recio");                 ///pilla los datos del fichero
            strcpy(provedor->correo,"mariscos@gmail.com");
            strcpy(provedor->clave,"1234");
            strcpy(provedor->perfil_usuario,"proveedor");

            //fclose(f);

        }
        else
            printf("no se puede abrir clientes.txt");   //si no se puede abrir el fichero no hace nada
    }
    else{
        printf("datos guardados\n");                   //-----------------------------------
        system("pause");
    }
}