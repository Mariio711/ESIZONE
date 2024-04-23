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
    int n;
    int id=1;//esta id es la queva a gestionar es lo que se le tiene que añadir
    system("cls");
    n=num_clien();
    cliente_estr *cliente=(cliente_estr*)calloc(n,sizeof(cliente_estr));

    descarga_clientes(cliente,n);
    bienvenida(cliente,id-1); //se le resta 1 porque los vectores se inician en 0
    carga_clientes(cliente,n);
    return 0;  
}

///bienvenida
//cabecera: void bienvenida(cliente_estr *);
//precondicion: recibe la estructura cliente ya inicializada
//postcondicion: llama a la funcion deseada
void bienvenida(cliente_estr *cliente,int id){
    int elec_b;
    do{
        system("cls");

        printf("Bienvenido %s\nQue quieres hacer?\n1. Perfil\n2. Productos\n3. Descuentos\n4. Pedidos\n5. Devoluciones\n6. Salir <-\n",(cliente+id)->nombre);
        do{
            scanf("%i",&elec_b);
            if(elec_b<1||elec_b>6)
                printf("Eleccion no valida, intentelo de nuevo:");           //control de entrada
            fflush(stdin);
        }while(elec_b<1||elec_b>6);

        switch(elec_b){
           case 1:perfil(cliente,id);
               break;
           case 2:printf("hola");//inicio_prod(1);------------------------------------------
                break;
           case 3:descuentos(cliente,id);
               break;
            case 4:printf("hola");//-----------------------------------------
               break;
           case 5:printf("hola");//-------------------------------------
              break;
           case 6:printf("\nadios %s!",cliente[id].nombre);        ///llamar a login
               break;
          }
    }while(elec_b!=6);
}

///perfil
//cabecera: void perfil(cliente_estr *);
//precondicion: estructura cliente ya inicializada
//poscondicion: elige que funcion llamar y muestra los datos del cliente
void perfil(cliente_estr cliente[],int id){
    int elec_perfil;
    do{
        system("cls");
        printf("nombre: %s\n",cliente[id].nombre);
        printf("direccion: %s\nlocalidad: %s\nprovincia: %s\n",cliente[id].direccion,cliente[id].localidad,cliente[id].provincia);
        printf("correo: %s\n",cliente[id].correo);
        printf("saldo: %.2f$\n",cliente[id].dinero);
        printf("-----------------------------------------------------\n");
        printf("Que quieres hacer?\n1. Modificar nombre\n2. Modificar direccion\n3. Modificar email\n4. Modificar clave\n5. Meter dinero\n6. volver <-\n");

        do{
          scanf("%i",&elec_perfil);
          if(elec_perfil<1||elec_perfil>6)
              printf("Eleccion no valida, intentelo de nuevo:");           //control de entrada
           fflush(stdin);
        }while(elec_perfil<1||elec_perfil>6);

        switch(elec_perfil){
          case 1:mod_nom(cliente,id);
              break;
          case 2:mod_dir(cliente,id);
              break;
           case 3:mod_email(cliente,id);
               break;
           case 4:mod_contr(cliente,id);
               break;
           case 5:cartera(cliente,id); 
               break;
        }
    }while(elec_perfil!=6);
}

///modificar nombre
//cabecera: void mod_nom(cliente_estr *);
//precondicion: estructura cliente ya inicializada
//poscondicion: cambia el nombre en la estructura cliente y llama a la funcion ficheros para guardarlo
void mod_nom(cliente_estr cliente[],int id){
    char nombre_introducido[20];
    char clave_introducida[15];
    system("cls");
    printf("Tu nombre actual es: %s\nintroduce tu nuevo nombre:",cliente[id].nombre);
    gets(nombre_introducido);
    fflush(stdin);

    printf("introduzca su clave para confirmar:");
    gets(clave_introducida);
    fflush(stdin);
        if(strcmp(cliente[id].clave,clave_introducida)==0){
            printf("Clave correcta :)\n");                          
            system("pause");
            strcpy(cliente[id].nombre,nombre_introducido);
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
void mod_dir(cliente_estr cliente[],int id){
    char dir_introducida[50];
    char localidad_introducida[20];
    char provincia_introducida[20];
    char clave_introducida[15];
    int elec_mod_dir;
    system("cls");
    printf("Tu direccion actual es: %s\n",cliente[id].direccion);
    printf("Tu localidad actual es: %s\n",cliente[id].localidad);
    printf("Tu provincia actual es: %s\n",cliente[id].provincia); 
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
        if(strcmp(cliente[id].clave,clave_introducida)==0){
            printf("Clave correcta :)\n");                          
            system("pause");
            
            switch(elec_mod_dir){
                case 1:strcpy(cliente[id].direccion,dir_introducida);
                    break;
                case 2:strcpy(cliente[id].localidad,localidad_introducida);
                    break;
               case 3:strcpy(cliente[id].provincia,provincia_introducida);
                    break;
            }
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
void mod_email(cliente_estr cliente[],int id){
    char email_introducido[30];
    char clave_introducida[15];
    system("cls");
    printf("Tu correo actual es: %s\nintroduce tu nuevo correo:",cliente[id].correo);
    gets(email_introducido);
    fflush(stdin);

    printf("introduzca su clave para confirmar:");
    gets(clave_introducida);
    fflush(stdin);
        if(strcmp(cliente[id].clave,clave_introducida)==0){
            printf("Clave correcta :)\n");                          
            system("pause");
            strcpy(cliente[id].correo,email_introducido);
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
void mod_contr(cliente_estr cliente[],int id){
    char clave_introducida[15];
    char clave_nueva[15];
    char confirmar[15];
    system("cls");
    printf("introduzca su antigua clave para confirmar:");
    gets(clave_introducida);
    fflush(stdin);
        if(strcmp(cliente[id].clave,clave_introducida)==0){
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
            strcpy(cliente[id].clave,clave_nueva);
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
void cartera(cliente_estr cliente[],int id){
    int elec_cartera;
    char clave_introducida[15];
    do{
        system("cls");
        printf("saldo actual:%.2f$\n",cliente[id].dinero);
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

            if(strcmp(cliente[id].clave,clave_introducida)==0){
                printf("Clave correcta :)\n");                          //introduce la clave del usuario para poder ingresar dinero
                system("pause");
                switch(elec_cartera){
                    case 1:cliente[id].dinero=cliente[id].dinero+5;
                        break;
                    case 2:cliente[id].dinero=cliente[id].dinero+10;
                        break;
                    case 3:cliente[id].dinero=cliente[id].dinero+25;
                        break;
                    case 4:cliente[id].dinero=cliente[id].dinero+50;
                        break;
                    case 5:cliente[id].dinero=cliente[id].dinero+100;
                        break;
                }
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

void descuentos(cliente_estr cliente[],int id){                
    int i,j,k=1;
    int td,tdc;//tamaños de descuento y descliente


    system("cls");
    
    td=num_descuentos();
    tdc=num_desclientes();

    descuentos_estr descuentos[td];
    desclient_estr descliente[tdc];

    iniciar_descuentos(descuentos,td);
    iniciar_desclientes(descliente,tdc);

    printf(" _________________________________\n");
    printf("|  |                           |  |\n");
    printf("|  |    $$$  DESCUENTOS  $$$   |  |\n");
    printf(" > |             :)            | <\n");
    printf("|  |    $$$  DISPONIBLES $$$   |  |\n");
    printf("|__|___________________________|__|\n");
    printf("hola %s, tus descuentos disponibles son:\n",cliente[id].nombre);

    for(i=0;i<td-1;i++){
        for(j=0;j<tdc-1;j++){
            if(strcmp(descliente[j].id_descuento,descuentos[i].id_descuento)==0){
                if(descliente[j].id==cliente[id].id){
                    if(descuentos[i].estado_d=='S' && descliente[j].estado_dc=='S'){
                        printf("\n%i-%s:",k,descuentos[i].tipo);
                        printf("\ndescripcion: %s",descuentos[i].descripcion);
                        printf("\ndisponible para: %s",descuentos[i].aplicabilidad);
                        printf("\nfecha inicial: %i/%i/%i",descliente[j].fecha_inicial.dia,descliente[j].fecha_inicial.mes,descliente[j].fecha_inicial.ano);
                        printf("\nfecha limite: %i/%i/%i",descliente[j].fecha_limite.dia,descliente[j].fecha_limite.mes,descliente[j].fecha_limite.ano);
                        printf("\ndescuento: %.2f$\n",descuentos[i].importe);
                        k++;
                    }
                }  
            }
        }
    }

    system("pause");
}

///num_clien
//cabecera: num_clien();
//precondicion: existe fichero "Clientes.txt"
//poscondicion: cuenta cuantos clientes existen
int num_clien(){
    int num_clientes=0;
    FILE *archivo;
    char c;
    
    //system("cls");

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Clientes.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Clientes.txt", directorio);

    archivo = fopen(ruta_relativa, "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        perror("fopen");
    }
    else{
        do{
            c=fgetc(archivo);
            if(c=='\n'||c==EOF)
                num_clientes++;
        }while(c!=EOF);
    }
    fclose(archivo);// Cerrar el fichero
    return num_clientes;
}
///num_clien
//cabecera: num_clien();
//precondicion: existe fichero "Clientes.txt"
//poscondicion: cuenta cuantos clientes existen
int num_descuentos(){//------------------------------------------------
    int num_descuentos=0;
    FILE *archivo;
    char c;
    
    //system("cls");

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Clientes.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Descuentos.txt", directorio);

    archivo = fopen(ruta_relativa, "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        perror("fopen");
    }
    else{
        do{
            c=fgetc(archivo);
            if(c=='\n'||c==EOF)
                num_descuentos++;
        }while(c!=EOF);
    }
    fclose(archivo);// Cerrar el fichero
    return num_descuentos;
}
///num_clien
//cabecera: num_clien();
//precondicion: existe fichero "Clientes.txt"
//poscondicion: cuenta cuantos clientes existen
int num_desclientes(){//------------------------------------------------
    int num_desclientes=0;
    FILE *archivo;
    char c;
    
    //system("cls");

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Clientes.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/DescuentosClientes.txt", directorio);

    archivo = fopen(ruta_relativa, "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        perror("fopen");
    }
    else{
        do{
            c=fgetc(archivo);
            if(c=='\n'||c==EOF)
                num_desclientes++;
        }while(c!=EOF);
    }
    fclose(archivo);// Cerrar el fichero
    return num_desclientes;
}
void descarga_clientes(cliente_estr cliente[],int n){
    FILE *archivo;
    int i,j=0,num_guion=0;
    char c;
    char id[8];
    char nombre[20];
    char direccion[50];
    char localidad[20];
    char provincia[20];
    char correo[30];
    char clave[15];
    char dinero[10];

    //system("cls");

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Clientes.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Clientes.txt", directorio);

    archivo = fopen(ruta_relativa, "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        perror("fopen");
    }
    else{
        for(i=0;i<n;i++){
        memset(id, 0, 8);
        memset(nombre, 0, 20);
        memset(direccion, 0, 50);
        memset(localidad, 0, 20);//vacia para no pillar basura en los vectores
        memset(provincia, 0, 20);
        memset(correo, 0, 30);
        memset(clave, 0, 15);
        memset(dinero, 0, 10);
        do{
            c=fgetc(archivo);
            if(num_guion==0 && c!='-' && c!=EOF)
                id[j]=c;//id
            if(num_guion==1 && c!='-' && c!=EOF)
                nombre[j]=c;//nombre
            if(num_guion==2 && c!='-' && c!=EOF)
                direccion[j]=c;//direccion
            if(num_guion==3 && c!='-' && c!=EOF)
                localidad[j]=c;//localidad
            if(num_guion==4 && c!='-' && c!=EOF)
                provincia[j]=c;//provincia
            if(num_guion==5 && c!='-' && c!=EOF)
                correo[j]=c;//correo
            if(num_guion==6 && c!='-' && c!=EOF)
                clave[j]=c;//clave
            if(num_guion==7 && c!='-' && c!=EOF &&c!='\n')
                dinero[j]=c;//dinero
            if(c=='-'){
                num_guion++;
                j=-1;
            }
            if(c=='\n'){
                strcpy(cliente[i].nombre,nombre);
                strcpy(cliente[i].direccion,direccion);
                strcpy(cliente[i].localidad,localidad);
                strcpy(cliente[i].provincia,provincia);
                strcpy(cliente[i].correo,correo);
                strcpy(cliente[i].clave,clave);
                cliente[i].id=atoi(id);
                cliente[i].dinero=atof(dinero);
                num_guion=0;
                j=-1;
            }
            j++;
        }while(c!='\n'&&c!=EOF);
        }
    }
    fclose(archivo);// Cerrar el fichero
}

void carga_clientes(cliente_estr cliente[],int n){
    FILE *archivo;
    int i=0;
    //system("cls");

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Clientes.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Clientes.txt", directorio);

    archivo = fopen(ruta_relativa, "w");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        perror("fopen");
    }
    else{
        do{
            fprintf(archivo,"%i-",cliente[i].id);
            fprintf(archivo,"%s-",cliente[i].nombre);
            fprintf(archivo,"%s-",cliente[i].direccion);
            fprintf(archivo,"%s-",cliente[i].localidad);
            fprintf(archivo,"%s-",cliente[i].provincia);
            fprintf(archivo,"%s-",cliente[i].correo);
            fprintf(archivo,"%s-",cliente[i].clave);
            fprintf(archivo,"%.2f\n",cliente[i].dinero);
            i++;
        }while(i!=n-1);
    }
    fclose(archivo);// Cerrar el fichero
}

void iniciar_descuentos(descuentos_estr descuentos [],int td){
    FILE *archivo;
    char c;
    int i,num_guion=0,j=0;
    char id_descuento[10];
    char descripcion[50];
    char tipo[8];
    char importe[10];
    char aplicabilidad[10];

    char ruta_actual[1024];
    strcpy(ruta_actual, __FILE__);               
    char *directorio = dirname(ruta_actual);
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Descuentos.txt", directorio);
    archivo = fopen(ruta_relativa, "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir Descuentos.txt\n");
        perror("fopen");
    }
    else{
        for(i=0;i<td;i++){
        memset(id_descuento, 0, 10);
        memset(descripcion, 0, 50);
        memset(tipo, 0, 8);
        memset(importe, 0, 10);//vacia para no pillar basura en los vectores
        memset(aplicabilidad, 0, 10);
        
        do{
            c=fgetc(archivo);
            if(num_guion==0 && c!='-' && c!=EOF)
                id_descuento[j]=c;
            if(num_guion==1 && c!='-' && c!=EOF)
                descripcion[j]=c;
            if(num_guion==2 && c!='-' && c!=EOF)
                tipo[j]=c;
            if(num_guion==3 && c!='-' && c!=EOF)
                descuentos[i].estado_d=c;
            if(num_guion==4 && c!='-' && c!=EOF)
                importe[j]=c;
            if(num_guion==5 && c!='-' && c!=EOF && c!='\n')
                aplicabilidad[j]=c;
            if(c=='-'){
                num_guion++;
                j=-1;
            }
            if(c=='\n'){
                strcpy(descuentos[i].id_descuento,id_descuento);
                strcpy(descuentos[i].descripcion,descripcion);
                strcpy(descuentos[i].tipo,tipo);
                strcpy(descuentos[i].aplicabilidad,aplicabilidad);
                descuentos[i].importe=atof(importe);
                num_guion=0;
                j=-1;
            }
            j++;
        }while(c!='\n'&& c!=EOF);
        }
    }
    fclose(archivo);
}

void iniciar_desclientes(desclient_estr descliente [],int tdc){
    FILE *archivo;
    char c;
    int i,num_guion=0,num_barras=0,j=0;
    char id[10];
    char id_descuento[10];
    char diai[3],mesi[3],anoi[5],diaf[3],mesf[3],anof[5];

    char ruta_actual[1024];
    strcpy(ruta_actual, __FILE__);               
    char *directorio = dirname(ruta_actual);
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/DescuentosClientes.txt", directorio);
    archivo = fopen(ruta_relativa, "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir DescuentosClientes.txt\n");
        perror("fopen");
    }
    else{
        for(i=0;i<tdc;i++){
        memset(id, 0, 10);
        memset(id_descuento, 0, 10);//vacia para no pillar basura en los vectores
        memset(diai,0,3);
        memset(mesi,0,3);
        memset(anoi,0,5);
        memset(diaf,0,3);
        memset(mesf,0,3);
        memset(anof,0,5);
        do{
            c=fgetc(archivo);
            if(num_guion==0 && c!='-' && c!=EOF)
                id[j]=c;
            if(num_guion==1 && c!='-' && c!=EOF)
                id_descuento[j]=c;
            if(num_guion==2 && c!='-' && c!=EOF && c!='/'){
                switch(num_barras){
                    case 0:diai[j]=c;break;
                    case 1:mesi[j]=c;break;
                    case 2:anoi[j]=c;break;
                }
            }
            if(num_guion==3 && c!='-' && c!=EOF && c!='/'){
                switch(num_barras){
                    case 2:diaf[j]=c;break;
                    case 3:mesf[j]=c;break;
                    case 4:anof[j]=c;break;
                }
            }
            if(num_guion==4 && c!='-' && c!=EOF && c!='\n')
                descliente[i].estado_dc=c;
            if(c=='-'){
                num_guion++;
                j=-1;
            }
            if(c=='/'){
                num_barras++;
                j=-1;
            }
            if(c=='\n'){
                strcpy(descliente[i].id_descuento,id_descuento);
                descliente[i].id=atoi(id);
                descliente[i].fecha_inicial.dia=atoi(diai);
                descliente[i].fecha_inicial.mes=atoi(mesi);
                descliente[i].fecha_inicial.ano=atoi(anoi);
                descliente[i].fecha_limite.dia=atoi(diaf);
                descliente[i].fecha_limite.mes=atoi(mesf);
                descliente[i].fecha_limite.ano=atoi(anof);
                num_guion=0;
                num_barras=0;
                j=-1;
            }
            j++;
        }while(c!='\n'&& c!=EOF);
        }
    }
    fclose(archivo);
}