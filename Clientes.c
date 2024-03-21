#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int id;
    char nombre[20];
    char direccion[50];
    char localidad[20];
    char provincia[20];
    char correo[30];
    char clave[15];
    float dinero;
}cliente_estr;

void ficheros(int,cliente_estr);//
void bienvenida(cliente_estr);//

void perfil(cliente_estr);//
void productos();
void descuentos();
void pedidos();
void devolucion();

void mod_nom();
void mod_dir();
void mod_email();
void mod_contr();
void cartera();

int main(){
    cliente_estr cliente;

    system("cls");
    ficheros(1,cliente);

    return 0;
}
///fichero
void ficheros(int palanca,cliente_estr cliente){
    system("cls");
    FILE*f;
    if(palanca==1){
        if((f=fopen("Clientes.txt","r"))!=NULL){
            cliente.id=00001;
            strcpy(cliente.nombre,"Antonio Ruiz");
            strcpy(cliente.direccion,"123 calle mentira");
            strcpy(cliente.localidad,"linea");
            strcpy(cliente.provincia,"cadi");                              ///pilla los datos del fichero
            strcpy(cliente.correo,"correo@gmail.com");
            strcpy(cliente.clave,"1234");
            cliente.dinero=50;

            fclose(f);

            bienvenida(cliente);
        }
        else
            printf("no se puede abrir clientes.txt");   //si no se puede abrir el fichero no hace nada
        }
    else
        printf("datos guardados,adios");
}
///bienvenida
void bienvenida(cliente_estr cliente){
    int elec_b;
    printf("Bienvenido %s\nQue quieres hacer?\n1. Perfil\n2. Productos\n3. Descuentos\n4. Pedidos\n5. Devoluciones\n6. Salir <-\n",cliente.nombre);
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
        case 6:printf("\nadios %s!",cliente.nombre);
            break;
        }
}
///perfil
void perfil(cliente_estr cliente){
    int elec_perfil;
    system("cls");
    printf("%s\n",cliente.nombre);
    printf("%s\n%s\n%s\n",cliente.direccion,cliente.localidad,cliente.provincia);
    printf("%s\n",cliente.correo);
    printf("saldo:%.2f$\n",cliente.dinero);
    printf("-----------------------------------------------------\n");
    printf("Que quieres hacer?\n1. Modificar nombre\n2. Modificar direccion\n3. Modificar email\n4. Modificar clave\n5. Meter dinero\n6. volver <-\n");

    do{
        scanf("%i",&elec_perfil);
        if(elec_perfil<1||elec_perfil>6)
            printf("Eleccion no valida, intentelo de nuevo:");           //control de entrada
        fflush(stdin);
    }while(elec_perfil<1||elec_perfil>6);

    switch(elec_perfil){
        case 1:mod_nom();
            break;
        case 2:mod_dir();
            break;
        case 3:mod_email();
            break;
        case 4:mod_contr();
            break;
        case 5:cartera(cliente);
            break;
        case 6:main();
            break;
        }
}
void mod_nom(){
}

void mod_dir(){
}

void mod_email(){
}

void mod_contr(){
}

void cartera(cliente_estr cliente){
    int elec_cartera;
    char clave_introducida[15];
    do{
        system("cls");
        printf("saldo actual:%.2f$\n",cliente.dinero);
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

            if(strcmp(cliente.clave,clave_introducida)==0){
                printf("Clave correcta :)\n");                          //introduce la clave del usuario para poder ingresar dinero
                system("pause");
                switch(elec_cartera){
                    case 1:cliente.dinero=cliente.dinero+5;
                        break;
                    case 2:cliente.dinero=cliente.dinero+10;
                        break;
                    case 3:cliente.dinero=cliente.dinero+25;
                        break;
                    case 4:cliente.dinero=cliente.dinero+50;
                        break;
                    case 5:cliente.dinero=cliente.dinero+100;
                        break;
                }
            }
            else{
                printf("Clave incorrecta :(\n");
                system("pause");
            }
        }
    }while(elec_cartera!=6);

    ficheros(2,cliente);
    perfil(cliente);
}


///resto
void productos(){
    printf("modulo productos");
}
void descuentos(){
    system("cls");
    printf(" _________________________________\n");
    printf("|  |                           |  |\n");
    printf("|  |                           |  |\n");
    printf(" > |   $$$  Descuentos  $$$    | <\n");
    printf("|  |                           |  |\n");
    printf("|__|___________________________|__|\n\n");

    ///hace faltaque imprima todos los descuentos que concuerden con este cliente y decir si estan caducados o no
}
void pedidos(){
    printf("modulo pedidos");
}
void devolucion(){
    printf("devolucion");
}


