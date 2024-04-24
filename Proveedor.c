#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h> // Para dirname()

#include "productos.c"
#include "admin.h"
#include "Proveedor.h"

int main(){
    inicio_prov(2);
    return 0;
}
//cabezera: void inicio_prov();
//precondicion: tiene que ser llamado por un usuario y recive su id
//poscondicion: da paso a bienvenido para que comience el modulo
void inicio_prov(int id_prov){
    int n;
    system("cls");
    n=num_prov();
    usuarios *provedor=(usuarios*)calloc(n,sizeof(usuarios));

    descarga_prov(provedor,n);
    bienvenida_prov(provedor,id_prov-1); //se le resta 1 porque los vectores se inician en 0
    carga_prov(provedor,n);
}

//cabecera: void bienvenida_prov(provedor_estr *,int);
//precondicion: recibe la estructura cliente ya inicializada
//postcondicion: llama a la funcion deseada
void bienvenida_prov(usuarios *provedor,int id_prov){
    int elec_b;
    do{
        system("cls");

        printf("Empresa: %s\nQue desea hacer?\n1. Perfil\n2. Productos\n3. Pedidos\n4. Salir <-\n",(provedor+id_prov)->Nombre);
        do{
            scanf("%i",&elec_b);
            if(elec_b<1||elec_b>6)
                printf("Eleccion no valida, intentelo de nuevo:");           //control de entrada
            fflush(stdin);
        }while(elec_b<1||elec_b>4);

        switch(elec_b){
           case 1:perfil_prov(provedor,id_prov);
               break;
           case 2:prod_prov(id_prov+1); //productos
                break;
           case 3:printf("\nhola");   //pedidos
               break;
           case 4:printf("\nadios");  ///llamar a login
               break;
          }
    }while(elec_b!=4);
}

//cabecera: void perfil(provedor_estr *,int);
//precondicion: estructura provedor ya inicializada
//poscondicion: elige que funcion llamar y muestra los datos de la empresa
void perfil_prov(usuarios *provedor,int id_prov){
    int elec_perfil;
    do{
        system("cls");
        printf("empresa: %s\n",(provedor+id_prov)->Nombre);
        printf("correo: %s\n",(provedor+id_prov)->email);
        printf("-----------------------------------------------------\n");
        printf("Que quieres hacer?\n1. Modificar nombre de la empresa\n2. Modificar correo\n3. Modificar clave\n4. volver <-\n");

        do{
          scanf("%i",&elec_perfil);
          if(elec_perfil<1||elec_perfil>4)
              printf("Eleccion no valida, intentelo de nuevo:");           //control de entrada
           fflush(stdin);
        }while(elec_perfil<1||elec_perfil>4);

        switch(elec_perfil){
          case 1:mod_nom_prov(provedor,id_prov);
              break;
           case 2:mod_email_prov(provedor,id_prov);
               break;
           case 3:mod_contr_prov(provedor,id_prov);
               break;
        }
    }while(elec_perfil!=4);
}

//cabecera: void mod_nom_prov(provedor_estr *,int);
//precondicion: estructura provedor ya inicializada
//poscondicion: cambia el nombre en la estructura usuario
void mod_nom_prov(usuarios *provedor,int id_prov){
    char nombre_introducido[20];
    char clave_introducida[15];
    system("cls");
    printf("el nombre de la empresa actual es: %s\nintroduce tu nuevo nombre:",(provedor+id_prov)->Nombre);
    gets(nombre_introducido);
    fflush(stdin);

    printf("introduzca su clave para confirmar:");
    gets(clave_introducida);
    fflush(stdin);
        if(strcmp((provedor+id_prov)->Contrasena,clave_introducida)==0){
            printf("Clave correcta :)\n");                          
            system("pause");
            strcpy((provedor+id_prov)->Nombre,nombre_introducido);
        }
        else{
            printf("Clave incorrecta :(\n");
            system("pause");
        }
}

//cabecera: void mod_email_prov(provedor_estr *,int);
//precondicion: estructura provedor ya inicializada
//poscondicion: cambia el correo en la estructura usuario
void mod_email_prov(usuarios *provedor,int id_prov){
    char email_introducido[30];
    char clave_introducida[15];
    system("cls");
    printf("Tu correo actual es: %s\nintroduce tu nuevo correo:",(provedor+id_prov)->email);
    gets(email_introducido);
    fflush(stdin);

    printf("introduzca su clave para confirmar:");
    gets(clave_introducida);
    fflush(stdin);
        if(strcmp((provedor+id_prov)->Contrasena,clave_introducida)==0){
            printf("Clave correcta :)\n");                          
            system("pause");
            strcpy((provedor+id_prov)->email,email_introducido);
        }
        else{
            printf("Clave incorrecta :(\n");
            system("pause");
        }
}

//cabecera: void mod_contr_prov(provedor_estr *,int);
//precondicion: estructura provedor ya inicializada
//poscondicion: cambia la clave en la estructura usuario
void mod_contr_prov(usuarios *provedor,int id_prov){
    char clave_introducida[15];
    char clave_nueva[15];
    char confirmar[15];
    system("cls");
    printf("introduzca su antigua clave para confirmar:");
    gets(clave_introducida);
    fflush(stdin);
        if(strcmp((provedor+id_prov)->Contrasena,clave_introducida)==0){
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
            strcpy((provedor+id_prov)->Contrasena,clave_nueva);
        }
        else{
            printf("Clave incorrecta :(\n");
            system("pause");
        }
}

//cabecera: num_prov();
//precondicion: existe fichero "AdminProv.txt"
//poscondicion: cuenta cuantos provedores existen
int num_prov(){
    int num_prov=0;
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
    sprintf(ruta_relativa, "%s/DATA/AdminProv.txt", directorio);

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
                num_prov++;
        }while(c!=EOF);
    }
    fclose(archivo);// Cerrar el fichero
    return num_prov;
}

//cabecera: num_prov(provedor_estr *,int);
//precondicion: existe fichero "AdminProv.txt"
//poscondicion: inicia la estructura usuarios
void descarga_prov(usuarios *provedor,int n){
    FILE *archivo;
    int i,j=0,num_guion=0;
    char c;
    char id_prov[8];
    char nombre_empresa[20];
    char correo[30];
    char clave[15];
    char perfil_usuario[13];

    //system("cls");

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero AdminProv.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/AdminProv.txt", directorio);

    archivo = fopen(ruta_relativa, "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        perror("fopen");
    }
    else{
        for(i=0;i<n;i++){
        memset(id_prov, 0, 8);
        memset(nombre_empresa, 0, 20);//vacia para no pillar basura en los vectores
        memset(correo, 0, 30);
        memset(clave, 0, 15);
        memset(perfil_usuario, 0, 13);
        do{
            c=fgetc(archivo);
            if(num_guion==0 && c!='-' && c!=EOF)
                id_prov[j]=c;//id
            if(num_guion==1 && c!='-' && c!=EOF)
                nombre_empresa[j]=c;//nombre
            if(num_guion==2 && c!='-' && c!=EOF)
                correo[j]=c;//correo
            if(num_guion==3 && c!='-' && c!=EOF)
                clave[j]=c;//clave
            if(num_guion==4 && c!='-' && c!=EOF &&c!='\n')
                perfil_usuario[j]=c;//provedor/admin
            if(c=='-'){
                num_guion++;
                j=-1;
            }
            if(c=='\n'){
                strcpy((provedor+i)->Nombre,nombre_empresa);
                strcpy((provedor+i)->email,correo);
                strcpy((provedor+i)->Contrasena,clave);
                strcpy((provedor+i)->Perfil_usuario,perfil_usuario);
                strcpy((provedor+i)->Id_empresa,id_prov);
                num_guion=0;
                j=-1;
            }
            j++;
        }while(c!='\n'&&c!=EOF);
        }
    }
    fclose(archivo);// Cerrar el fichero
}

//cabecera: carga_prov(provedor_estr *,int);
//precondicion: existe fichero "AdminProv.txt"
//poscondicion: guarda la estructura en el fichero "AdminProv.txt"
void carga_prov(usuarios *provedor,int n){
    FILE *archivo;
    int i=0;
    //system("cls");

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero AdminProv.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/AdminProv.txt", directorio);

    archivo = fopen(ruta_relativa, "w");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        perror("fopen");
    }
    else{
        do{
            fprintf(archivo,"%s-",(provedor+i)->Id_empresa);
            fprintf(archivo,"%s-",(provedor+i)->Nombre);
            fprintf(archivo,"%s-",(provedor+i)->email);
            fprintf(archivo,"%s-",(provedor+i)->Contrasena);
            fprintf(archivo,"%s\n",(provedor+i)->Perfil_usuario);
            i++;
        }while(i!=n-1);
    }
    fclose(archivo);// Cerrar el fichero
}