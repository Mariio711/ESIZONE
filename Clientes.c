#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Clientes.h"

///inicio cliente
//cabezera: inicio_cliente();
//precondicion: tiene que ser llamado por un usuario
//poscondicion: llama a la funcion fichero para que inicialice la estructura cliente y luego da paso a bienvenido para que comience el modulo
void inicio_cliente(){
    cliente_estr x;
    cliente_estr *cliente;
    cliente=&x;

    system("cls");
    ficheros(1,cliente);
    bienvenida(cliente);
    
}
///bienvenida
//cabecera: void bienvenida(cliente_estr *);
//precondicion: recibe la estructura cliente ya inicializada
//postcondicion: llama a la funcion deseada
void bienvenida(cliente_estr * cliente){
    int elec_b;
    system("cls");

    printf("Bienvenido %s\nQue quieres hacer?\n1. Perfil\n2. Productos\n3. Descuentos\n4. Pedidos\n5. Devoluciones\n6. Salir <-\n",cliente->nombre);
    do{
        scanf("%i",&elec_b);
        if(elec_b<1||elec_b>6)
            printf("Eleccion no valida, intentelo de nuevo:");           //control de entrada
        fflush(stdin);
    }while(elec_b<1||elec_b>6);

    switch(elec_b){
        case 1:perfil(cliente);
            break;
        case 2:productos();
            break;
        case 3:descuentos();
            break;
        case 4:pedidos();
            break;
        case 5:devolucion();
            break;
        case 6:printf("\nadios %s!",cliente->nombre);
            break;
        }
}
//perfil
void perfil(cliente_estr * cliente){
    int elec_perfil;
    do{
        system("cls");
        printf("%s\n",cliente->nombre);
        printf("%s\n%s\n%s\n",cliente->direccion,cliente->localidad,cliente->provincia);
        printf("%s\n",cliente->correo);
        printf("saldo:%.2f$\n",cliente->dinero);
        printf("-----------------------------------------------------\n");
        printf("Que quieres hacer?\n1. Modificar nombre\n2. Modificar direccion\n3. Modificar email\n4. Modificar clave\n5. Meter dinero\n6. volver <-\n");

        do{
          scanf("%i",&elec_perfil);
          if(elec_perfil<1||elec_perfil>6)
              printf("Eleccion no valida, intentelo de nuevo:");           //control de entrada
           fflush(stdin);
        }while(elec_perfil<1||elec_perfil>6);

        switch(elec_perfil){
          case 1:mod_nom(cliente);
              break;
          case 2:mod_dir(cliente);
              break;
           case 3:mod_email(cliente);
               break;
           case 4:mod_contr(cliente);
               break;
           case 5:cartera(cliente);
               break;
        }
    }while(elec_perfil!=6);
    bienvenida(cliente);
}
//modificar nombre
void mod_nom(cliente_estr * cliente){
    char nombre_introducido[20];
    char clave_introducida[15];
    system("cls");
    printf("Tu nombre actual es: %s\nintroduce tu nuevo nombre:",cliente->nombre);
    scanf("%s",nombre_introducido);
    fflush(stdin);

    printf("introduzca su clave para confirmar:");
    scanf("%s",clave_introducida);
    fflush(stdin);
        if(strcmp(cliente->clave,clave_introducida)==0){
            printf("Clave correcta :)\n");                          
            system("pause");
            strcpy(cliente->nombre,nombre_introducido);
            ficheros(2,cliente); //guarda el nombre
        }
        else{
            printf("Clave incorrecta :(\n");
            system("pause");
        }
}
//modificar direccion
void mod_dir(cliente_estr * cliente){
    char dir_introducida[50];
    char localidad_introducida[20];
    char provincia_introducida[20];
    char clave_introducida[15];
    int elec_mod_dir;
    system("cls");
    printf("Tu direccion actual es: %s\n",cliente->direccion);
    printf("Tu localidad actual es: %s\n",cliente->localidad);
    printf("Tu provincia actual es: %s\n",cliente->provincia); 
    printf("que quieres editar?\n1-direccion\n2-localidad\n3-provincia\n");

    do{
        scanf("%i",&elec_mod_dir);
        if(elec_mod_dir<1||elec_mod_dir>3)
            printf("Eleccion no valida, intentelo de nuevo:");           //control de entrada
        fflush(stdin);
    }while(elec_mod_dir<1||elec_mod_dir>3);

    switch(elec_mod_dir){
        case 1:{
                printf("introduce nueva direccion:");
                scanf("%s",dir_introducida);
                fflush(stdin);
            }
            break;
        case 2:{
                printf("introduce nueva localidad:");
                scanf("%s",localidad_introducida);
                fflush(stdin);
            }
            break;
        case 3:{
                printf("introduce nueva provincia:");
                scanf("%s",provincia_introducida);
                fflush(stdin);
            }
            break;
    }

    printf("introduzca su clave para confirmar:");
    scanf("%s",clave_introducida);
    fflush(stdin);
        if(strcmp(cliente->clave,clave_introducida)==0){
            printf("Clave correcta :)\n");                          
            system("pause");
            
            switch(elec_mod_dir){
                case 1:strcpy(cliente->direccion,dir_introducida);
                    break;
                case 2:strcpy(cliente->localidad,localidad_introducida);
                    break;
               case 3:strcpy(cliente->provincia,provincia_introducida);
                    break;
            }
            ficheros(2,cliente); //guarda los datos
        }
        else{
            printf("Clave incorrecta :(\n");
            system("pause");
        }

}
//modificar correo
void mod_email(cliente_estr * cliente){
    char email_introducido[30];
    char clave_introducida[15];
    system("cls");
    printf("Tu correo actual es: %s\nintroduce tu nuevo correo:",cliente->correo);
    scanf("%s",email_introducido);
    fflush(stdin);

    printf("introduzca su clave para confirmar:");
    scanf("%s",clave_introducida);
    fflush(stdin);
        if(strcmp(cliente->clave,clave_introducida)==0){
            printf("Clave correcta :)\n");                          
            system("pause");
            strcpy(cliente->correo,email_introducido);
            ficheros(2,cliente); //guarda el correo
        }
        else{
            printf("Clave incorrecta :(\n");
            system("pause");
        }
}
//modificar contraseña
void mod_contr(cliente_estr * cliente){
    char clave_introducida[15];
    char clave_nueva[15];
    char confirmar[15];
    system("cls");
    printf("introduzca su antigua clave para confirmar:");
    scanf("%s",clave_introducida);
    fflush(stdin);
        if(strcmp(cliente->clave,clave_introducida)==0){
            printf("Clave correcta :)\n");                          
            system("pause");
            do{
                printf("introduce tu nueva clave:");
                scanf("%s",clave_nueva);
                fflush(stdin);
                printf("introducela de nuevo para confirmar:");
                scanf("%s",confirmar);
                fflush(stdin);
                if(strcmp(clave_nueva,confirmar)!=0)
                    printf("\nlas claves no coinciden :(\n");
            }while(strcmp(clave_nueva,confirmar)!=0);
            strcpy(cliente->clave,clave_nueva);
            ficheros(2,cliente); //guarda las claves
        }
        else{
            printf("Clave incorrecta :(\n");
            system("pause");
        }
}

//cartera
void cartera(cliente_estr * cliente){
    int elec_cartera;
    char clave_introducida[15];
    do{
        system("cls");
        printf("saldo actual:%.2f$\n",cliente->dinero);
        printf("-------------------------\n");
        printf("1-meter 5$(nivel minimo de fondos)\n\n2-meter 10$\n\n3-meter 25$\n\n4-meter 50$\n\n5-meter 100$\n\n6-volver <-\n");
        do{
            scanf("%i",&elec_cartera);
            if(elec_cartera<1||elec_cartera>6)
                printf("Eleccion no valida, intentelo de nuevo:");           //control de entrada
            fflush(stdin);
        }while(elec_cartera<1||elec_cartera>6);

        if(elec_cartera!=6){
            printf("introduzca su clave para confirmar:");

            scanf("%s",clave_introducida);

            if(strcmp(cliente->clave,clave_introducida)==0){
                printf("Clave correcta :)\n");                          //introduce la clave del usuario para poder ingresar dinero
                system("pause");
                switch(elec_cartera){
                    case 1:cliente->dinero=cliente->dinero+5;
                        break;
                    case 2:cliente->dinero=cliente->dinero+10;
                        break;
                    case 3:cliente->dinero=cliente->dinero+25;
                        break;
                    case 4:cliente->dinero=cliente->dinero+50;
                        break;
                    case 5:cliente->dinero=cliente->dinero+100;
                        break;
                }
                ficheros(2,cliente); //guarda el dinero editado
            }
            else{
                printf("Clave incorrecta :(\n");
                system("pause");
            }
        }

    }while(elec_cartera!=6);
    perfil(cliente);
}


//productos
void productos(){
    printf("modulo productos");
}

//descuentos
void descuentos(){
    system("cls");
    printf(" _________________________________\n");
    printf("|  |                           |  |\n");
    printf("|  |                           |  |\n");
    printf(" > |   $$$  Descuentos  $$$    | <\n");
    printf("|  |                           |  |\n");
    printf("|__|___________________________|__|\n\n");

    //hace faltaque imprima todos los descuentos que concuerden con este cliente y decir si estan caducados o no
}

//pedidos
void pedidos(){
    printf("modulo pedidos");
}

//devolucion
void devolucion(){
    printf("devolucion");
}

///fichero
//cabecera: ficheros(int,cliente_estr *);
//precondicion: se le introduce 1 si se quiere que inicialice la estructura y el resto si quiere que guarde los datos en el fichero
//poscondicion: inicializa la estructura o guarda datos en el fichero
void ficheros(int palanca,cliente_estr * cliente){
    system("cls");
    //FILE*f;
    if(palanca==1){
        if(1==1){                                  //((f=fopen("Clientes.txt","r"))!=NULL){    
            cliente->id=00001;
            strcpy(cliente->nombre,"Antonio Ruiz");
            strcpy(cliente->direccion,"123 calle mentira");
            strcpy(cliente->localidad,"linea");
            strcpy(cliente->provincia,"cadi");                              ///pilla los datos del fichero
            strcpy(cliente->correo,"correo@gmail.com");
            strcpy(cliente->clave,"1234");
            cliente->dinero=50;

            //fclose(f);

        }
        else
            printf("no se puede abrir clientes.txt");   //si no se puede abrir el fichero no hace nada
    }
    else{
        printf("datos guardados\n");
        system("pause");
    }
}

