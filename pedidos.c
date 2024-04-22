#include <stdio.h>
#include "pedidos.h"
#include "usuarios.h"

int main(int aux,int id){ //si aux=0 el usuario sera un usuario normal, pero si es un transportista aux=1
   pedidos *usuario;
   productos_pedidos *transportista;

   carga_txt(usuario, transportista,id,aux);
   switch_pedidos(*usuario,*transportista,id);

   return 0;
}

void carga_txt(pedidos *usuario, productos_pedidos *transportista,int aux){
    int i=0,num_guion=0;
    FILE *archivo;
    char c;
    char id[8];
    
    system("cls");

    if(aux==0){
        // Obtener la ruta del archivo fuente actual (__FILE__)
        char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
        strcpy(ruta_actual, __FILE__);
        // Obtener el directorio padre de la ruta actual                            ///como el fichero Clientes.txt esta en una carpeta
        char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
        // Construir la ruta del archivo relativa a la ubicación del ejecutable
        char ruta_relativa[1024];
        sprintf(ruta_relativa, "%s/DATA/Productos.txt", directorio);

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
                    c=fgetc(archivo);
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
    else{
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
    sprintf(ruta_relativa, "%s/DATA/ProductosPedido.txt", directorio);

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
                c=fgetc(archivo);
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
    }while();

    if(aux==0){   
        switch (option)
        {
            case 1:
                mostrar_pedidos_usuario(*usuario);
                break;
            case 2:
                devolver(*usuario,aux);
                break;
            case 3:
                exit(1);
                break;
        }
    }
    else{
        switch (option)
        {
            case 1:
                mostrar_pedidos_transportista(*transportista);
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

void devolver(int aux){
    int cont;
    if(aux==0){
        cont=contador_lineas();
    }
    else{

    }

}



void mostrar_pedidos_usuario(){
    if(id==)

    
}

void mostrar_pedidos_transportista()

int contador_lineas(){
    char x;
    int j;
    int i=0,num_guion=0;
    FILE *archivo;
    char c;
    char id[8];
    
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Clientes.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Devoluciones.txt", directorio);
    
    archivo = fopen(ruta_relativa, "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        perror("fopen");
    }
    else{
        do{
            x=fgetc(archivo);
            if(x=='\n'){
                j++;
            }
        }while(x!=EOF)
    }
    return j;
}