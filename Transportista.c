#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include "Transportista.h"
#include "func_aux.h"


int main(){ 
    transportista_estr *transportista;
    transportista_estr x;
    transportista=&x;
    ficheros(1,transportista);
    menu_transporte(transportista);
}

void intro_transportista(transportista_estr *transportista){
    printf("Transportista %s\n",transportista->nombre);
    printf("1.Perfil\n");
    printf("2.Pedidos\n");
    printf("3.Salir del sistema\n");
}

void menu_transporte(transportista_estr *transportista){
    int option;

    intro_transportista(transportista);

    do{                                 //bucle para control de entrada
          scanf("%i",&option);
     }while(0>=option && option>=4); 
     switch(option){
        case 1:
            perfil_transportista(transportista);
            break;
        case 2:
            /*funcion que nos permitita ver los estados de los pedidos */
            break;
        case 3:
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
            mostrar_info_transportista(transportista);
            break;
        case 2:
            mod_transporte(transportista);
            break;
        case 3:
            menu_transporte(transportista);
            break;
        case 4:
            exit(-1);
            break;
    }
}


void mostrar_info_transportista(transportista_estr *transportista){
    int option;

    system("cls");
    printf("La informacion del usuario es:\n");
    printf("ID: %i\n",transportista->id);
    printf("Nombre: %s\n",transportista->nombre);
    printf("Email: %s\n",transportista->email);
    printf("Empresa: %s\n",transportista->nom_empresa);
    printf("Ciudad: %s\n",transportista->ciudad);
    printf("\n");
    printf("Desea salir (1) o volver atras (2)?");
    do{                                 //bucle para control de entrada
          scanf("%i",&option);
    }while(option!=1 || option!=2);
    if(option==1){
        exit(-1);
    }
    if(option==2){
        perfil_transportista(transportista);
    }
}

void menu_mod(){
    printf("Seleccione una opción\n");
    printf("1. Modificar nombre\n");
    printf("2. Modificar ciudad\n");
    printf("3. Modificar email\n");
    printf("4. Modificar contraseña\n");
    printf("5. Volver atras\n");
    printf("6. Salir del sistema\n");
}

void mod_transporte(transportista_estr *transportista){
    int option;
    menu_mod();

     do{                                 //bucle para control de entrada
          scanf("%i",&option);
     }while(0>=option && option>=5); 
     switch(option){
        case 1:
            mod_nom(transportista);
            break;
        case 2:
            mod_ciudad(transportista);
            break;
        case 3:
            mod_email(transportista);
            break;
        case 4:
            mod_contr(transportista);
            break;
        case 5:
            perfil_transportista(transportista);
            break;
        case 6:
            exit(-1);
            break;
    }
}

void mod_nom(transportista_estr *transportista){
    char nombre_introducido[20];
    system("cls");
    printf("Tu nombre actual es: %s\nintroduce tu nuevo nombre:",transportista->nombre);
    fgets(nombre_introducido,20,stdin);
    do{
        if(leer_string(transportista->nombre,N_nombre)==1){
            printf("Error de alamacenamiento");
        }
    }while (leer_string(transportista->nombre,N_nombre)==1);
}

void mod_ciudad(transportista_estr *transportista){
    system("cls");
    mostrar_poblaciones(transportista->ciudad);  
}

void mod_email(transportista_estr *transportista){
    system("cls");
    do{
        if(leer_string(transportista->email,N_nombre)==1){
            printf("Error de alamacenamiento");
        }
    }while (leer_string(transportista->email,N_nombre)==1);
}

void mod_contr(transportista_estr *transportista){
    system("cls");
    do{
        if(leer_string(transportista->contra,N_nombre)==1){
            printf("Error de alamacenamiento");
        }
    }while (leer_string(transportista->contra,N_nombre)==1);
}

void ficheros(int aux,transportista_estr *transportista){
    int i=0,num_guion=0;
    FILE *archivo;
    char c;
    char id[8];
    
    system("cls");

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Clientes.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Transportista.txt", directorio);

    if(aux==1){//abre en modo lectura
        archivo = fopen(ruta_relativa, "r");

        // Verificar si el archivo se abrió correctamente
        if (archivo == NULL) {
            printf("Error al abrir el archivo.\n");
            perror("fopen");
        }
        else{//pilla los datos del fichero
            memset(id, 0, 8);
            memset(transportista->nombre, 0, 21);
            memset(transportista->email, 0, 31);
            memset(transportista->contra, 0, 16);//vacia para no pillar basura en los vectores
            memset(transportista->nom_empresa, 0, 21);
            memset(transportista->ciudad, 0, 21);
            do{
                c=getc(archivo);
                if(num_guion==0 && c!='-' && c!=EOF)
                    id[i]=c;//id
                if(num_guion==1 && c!='-' && c!=EOF)
                    transportista->nombre[i]=c;//nombre
                if(num_guion==2 && c!='-' && c!=EOF)
                    transportista->email[i]=c;//direccion
                if(num_guion==3 && c!='-' && c!=EOF)
                    transportista->contra[i]=c;//localidad
                if(num_guion==4 && c!='-' && c!=EOF)
                    transportista->nom_empresa[i]=c;//provincia
                if(num_guion==5 && c!='-' && c!=EOF)
                    transportista->ciudad[i]=c;//correo
                if(c=='-'){
                    num_guion++;
                    i=-1;
                }
                i++;
            }while(c!=EOF);
            transportista->id=atoi(id);
                    
        }
            printf("\nid: %i\nnombre: %s\nemail: %s\ncontra: %s\nnom_empresa: %s\nciudad: %s\n", transportista->id, transportista->nombre, transportista->email, transportista->contra, transportista->nom_empresa, transportista->ciudad);
    }
    else{
        printf("archivos guardados\n");
        system("pause");
    }
    fclose(archivo);// Cerrar el archivo
}