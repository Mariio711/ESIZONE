#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h> // Para dirname()
#include <time.h>// Para saber la hora actual
#include "Productos.h"
#include "Clientes.h"

///inicio cliente
//cabezera: void inicio_cliente();
//precondicion: tiene que ser llamado por un usuario y recive su id
//poscondicion: llama a la funcion fichero para que inicialice la estructura cliente y luego da paso a bienvenido para que comience el modulo
int main(){//inicio_cliente(){
    cliente_estr x;
    cliente_estr *cliente;
    cliente=&x;

    system("cls");
    ficheros(1,cliente);            //la idea es que le de la id y en el fichechos busque el usuario o con otra funcion
    bienvenida(cliente);            
    
    return 0;  //prueba
}
///bienvenida
//cabecera: void bienvenida(cliente_estr *);
//precondicion: recibe la estructura cliente ya inicializada
//postcondicion: llama a la funcion deseada
void bienvenida(cliente_estr * cliente){
    int elec_b;
    do{
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
           case 2:printf("hola");//inicio_prod(1);------------------------------------------
                break;
           case 3:descuentos(cliente);
               break;
            case 4:pedidos();//-----------------------------------------
               break;
           case 5:devolucion();//-------------------------------------
              break;
           case 6:printf("\nadios %s!",cliente->nombre);        ///llamar a login
               break;
          }
    }while(elec_b!=6);
}

///perfil
//cabecera: void perfil(cliente_estr *);
//precondicion: estructura cliente ya inicializada
//poscondicion: elige que funcion llamar y muestra los datos del cliente
void perfil(cliente_estr * cliente){
    int elec_perfil;
    do{
        system("cls");
        printf("nombre: %s\n",cliente->nombre);
        printf("direccion: %s\nlocalidad: %s\nprovincia: %s\n",cliente->direccion,cliente->localidad,cliente->provincia);
        printf("correo: %s\n",cliente->correo);
        printf("saldo: %.2f$\n",cliente->dinero);
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
}

///modificar nombre
//cabecera: void mod_nom(cliente_estr *);
//precondicion: estructura cliente ya inicializada
//poscondicion: cambia el nombre en la estructura cliente y llama a la funcion ficheros para guardarlo
void mod_nom(cliente_estr * cliente){
    char nombre_introducido[20];
    char clave_introducida[15];
    system("cls");
    printf("Tu nombre actual es: %s\nintroduce tu nuevo nombre:",cliente->nombre);
    gets(nombre_introducido);
    fflush(stdin);

    printf("introduzca su clave para confirmar:");
    gets(clave_introducida);
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
//cabecera: void mod_dir(cliente_estr *);
//precondicion: estructura cliente ya inicializada
//poscondicion: cambia la direccion/localidad/provincia en la estructura cliente y llama a la funcion ficheros para guardarlas
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
                gets(dir_introducida);
                fflush(stdin);
            }
            break;
        case 2:{
                printf("introduce nueva localidad:");
                gets(localidad_introducida);
                fflush(stdin);
            }
            break;
        case 3:{
                printf("introduce nueva provincia:");
                gets(provincia_introducida);
                fflush(stdin);
            }
            break;
    }

    printf("introduzca su clave para confirmar:");
    gets(clave_introducida);
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
//cabecera: void mod_email(cliente_estr *);
//precondicion: estructura cliente ya inicializada
//poscondicion: cambia el correo en la estructura cliente y llama a la funcion ficheros para guardarlo
void mod_email(cliente_estr * cliente){
    char email_introducido[30];
    char clave_introducida[15];
    system("cls");
    printf("Tu correo actual es: %s\nintroduce tu nuevo correo:",cliente->correo);
    gets(email_introducido);
    fflush(stdin);

    printf("introduzca su clave para confirmar:");
    gets(clave_introducida);
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
//cabecera: void mod_contr(cliente_estr *);
//precondicion: estructura cliente ya inicializada
//poscondicion: cambia la clave en la estructura cliente y llama a la funcion ficheros para guardarla
void mod_contr(cliente_estr * cliente){
    char clave_introducida[15];
    char clave_nueva[15];
    char confirmar[15];
    system("cls");
    printf("introduzca su antigua clave para confirmar:");
    gets(clave_introducida);
    fflush(stdin);
        if(strcmp(cliente->clave,clave_introducida)==0){
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
            strcpy(cliente->clave,clave_nueva);
            ficheros(2,cliente); //guarda las claves
        }
        else{
            printf("Clave incorrecta :(\n");
            system("pause");
        }
}

//cartera
//cabecera: void cartera(cliente_estr *);
//precondicion: estructura cliente ya inicializada
//poscondicion: aumenta el dinero que posee un cliente y llama a la funcion ficheros para guardarlo
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

            gets(clave_introducida);

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
}

///descuentos
//cabecera: descuentos(cliente_estr *);
//precondicion: la estructura cliente ya inicializada
//poscondicion: imprime por pantalla los descuentos disponibles de este usuario

void descuentos(cliente_estr * cliente){                
    int i=0,j=0,k=1,num_guion=0,num_guion2=0;
    FILE *archivo;
    FILE *archivo2;
    char c,c2;
    char importeaux[10];
    char idaux[10];
    descuentos_estr descuentos;
    desclient_estr descliente;
    system("cls");
    
    
    char ruta_actual[1024];
    strcpy(ruta_actual, __FILE__);               
    char *directorio = dirname(ruta_actual);
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Descuentos.txt", directorio);
    archivo = fopen(ruta_relativa, "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        perror("fopen");
    }
    else{
        printf(" _________________________________\n");
        printf("|  |                           |  |\n");
        printf("|  |    $$$  DESCUENTOS  $$$   |  |\n");
        printf(" > |             :)            | <\n");
        printf("|  |    $$$  DISPONIBLES $$$   |  |\n");
        printf("|__|___________________________|__|\n");
        printf("hola %s, tus descuentos disponibles son:\n",cliente->nombre);
        
            memset(descuentos.id_descuento, 0, 10);
            memset(descuentos.descripcion, 0, 50);
            memset(descuentos.tipo, 0, 8);
            memset(descuentos.aplicabilidad, 0, 10);//vacia para no pillar basura en los vectores
            memset(importeaux, 0, 10);
            memset(idaux, 0, 10);
            memset(descliente.id_descuento, 0, 10);
            memset(descliente.fecha_inicial, 0, 12);
            memset(descliente.fecha_limite, 0, 12);

        do{
            c=fgetc(archivo);
            if(num_guion==0 && c!='-' && c!=EOF)
                descuentos.id_descuento[i]=c;//id_descuento
            if(num_guion==1 && c!='-' && c!=EOF)
                descuentos.descripcion[i]=c;//descripcion
            if(num_guion==2 && c!='-' && c!=EOF)
                descuentos.tipo[i]=c;//tipo
            if(num_guion==3 && c!='-' && c!=EOF)
                descuentos.estado=c;//estado
            if(num_guion==4 && c!='-' && c!=EOF)
                importeaux[i]=c;//importe
            if(num_guion==5 && c!='-' && c!=EOF && c!='\n')
                descuentos.aplicabilidad[i]=c;//aplicabilidad
            if(c=='-'){
                num_guion++;
                i=-1;
            }
            i++;
            if((c=='\n' || c==EOF) && descuentos.estado=='S'){//comprueba si esta valido el descuento
                char ruta_actual2[1024];
                strcpy(ruta_actual2, __FILE__);               
                char *directorio2 = dirname(ruta_actual2);
                char ruta_relativa2[1024];
                sprintf(ruta_relativa2, "%s/DATA/DescuentosClientes.txt", directorio2);
                archivo2 = fopen(ruta_relativa2, "r");
                if (archivo2 == NULL) {
                    printf("Error al abrir el archivo.\n");
                    perror("fopen");
                }
                else{
                    do{
                    c2=fgetc(archivo2);
                    if(num_guion2==0 && c2!='-' && c2!=EOF)
                        idaux[j]=c2;//id cliente
                    if(num_guion2==1 && c2!='-' && c2!=EOF)
                        descliente.id_descuento[j]=c2;//id_descuento
                    if(num_guion2==2 && c2!='-' && c2!=EOF)
                        descliente.fecha_inicial[j]=c2;//fecha inicial---------------------------------------------------
                    if(num_guion2==3 && c2!='-' && c2!=EOF)
                        descliente.fecha_limite[j]=c2;//fecha limite
                    if(num_guion2==4 && c2!='-' && c2!=EOF && c2!='\n')
                        descliente.estado=c2;//estado
                    if(c2=='-'){
                        num_guion2++;
                        j=-1;
                    }
                    j++;
                    if(c2=='\n' && cliente->id==atoi(idaux) && (strcmp(descliente.id_descuento,descuentos.id_descuento)==0) && descliente.estado=='S'){
                        descliente.id=atoi(idaux);
                        descuentos.importe=atof(importeaux);
                        printf("\n%i-%s:",k,descuentos.tipo);
                        printf("\ndescripcion: %s",descuentos.descripcion);
                        printf("\ndisponible para: %s",descuentos.aplicabilidad);
                        printf("\nfecha inicial: %s",descliente.fecha_inicial);
                        printf("\nfecha limite: %s",descliente.fecha_limite);
                        printf("\ndescuento: %.2f$\n",descuentos.importe);
                        k++;
                    }
                    if(c2=='\n' || c2==EOF)
                        num_guion2=0;
                    }while(c2!=EOF);
                }
                fclose(archivo2);
            }
            if(c=='\n' || c==EOF)
                num_guion=0;
        }while(c!=EOF);
        system("pause");
    }
    fclose(archivo);
}
//pedidos
void pedidos(){
    printf("modulo pedidos");      ///SALAS----------------------------------
}

//devolucion
void devolucion(){              //SALAS/ANTONIO-----------------------------------------------------                        
    printf("devolucion");
}

///fichero
//cabecera: ficheros(int,cliente_estr *);
//precondicion: se le introduce 1 si se quiere que inicialice la estructura y 2 si quiere que guarde los datos en el fichero
//poscondicion: inicializa la estructura o guarda datos en el fichero
void ficheros(int palanca,cliente_estr * cliente){//------------------------------------------------
    int i=0,num_guion=0;
    FILE *archivo;
    char c;
    char id[8];
    char dinero[10];
    
    system("cls");

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Clientes.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Clientes.txt", directorio);

    if(palanca==1){//abre en modo lectura

        archivo = fopen(ruta_relativa, "r");

        // Verificar si el archivo se abrió correctamente
        if (archivo == NULL) {
            printf("Error al abrir el archivo.\n");
            perror("fopen");
        }
        else{//pilla los datos del fichero
            memset(id, 0, 8);
            memset(cliente->nombre, 0, 20);
            memset(cliente->direccion, 0, 50);
            memset(cliente->localidad, 0, 20);//vacia para no pillar basura en los vectores
            memset(cliente->provincia, 0, 20);
            memset(cliente->correo, 0, 30);
            memset(cliente->clave, 0, 15);
            memset(dinero, 0, 10);
            do{
                c=fgetc(archivo);
                if(num_guion==0 && c!='-' && c!=EOF)
                    id[i]=c;//id
                if(num_guion==1 && c!='-' && c!=EOF)
                    cliente->nombre[i]=c;//nombre
                if(num_guion==2 && c!='-' && c!=EOF)
                    cliente->direccion[i]=c;//direccion
                if(num_guion==3 && c!='-' && c!=EOF)
                    cliente->localidad[i]=c;//localidad
                if(num_guion==4 && c!='-' && c!=EOF)
                    cliente->provincia[i]=c;//provincia
                if(num_guion==5 && c!='-' && c!=EOF)
                    cliente->correo[i]=c;//correo
                if(num_guion==6 && c!='-' && c!=EOF)
                    cliente->clave[i]=c;//clave
                if(num_guion==7 && c!='-' && c!=EOF)
                    dinero[i]=c;//dinero
                if(c=='-'){
                    num_guion++;
                    i=-1;
                }
                i++;
            }while(c!=EOF);
            cliente->id=atoi(id);
            cliente->dinero=atof(dinero);
        }   
    }
    else{
        printf("archivos guardados\n");
        system("pause");
    }
    fclose(archivo);// Cerrar el archivo
}

