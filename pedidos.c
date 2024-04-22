#include <stdio.h>
#include "pedidos.h"
#include "clientes.h"

int main(int aux,int id){ //si aux=0 el usuario sera un usuario normal, pero si es un transportista aux=1
    pedidos *pedido_cli;
    productos_pedidos *pedido_trans; 

    if(aux==1){
        carga_txt_pedidos(*pedido_cli);
        menu_cliente();
    }
    else{
        carga_txt_productos_pedidos(*pedido_trans);
        menu_transportista();
    }
            
    return 0;
}

void carga_txt_pedidos(pedidos *pedido_cli){
    FILE *archivo;
    int i,j=0,num_guion=0;
    char c;
    char id[7];
    char fecha[10];
    char id_cliente[7];
    float importe;

    //system("cls");

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Clientes.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/ProductosPedidos.txt", directorio);

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
                fecha[j]=c;//nombre
            if(num_guion==2 && c!='-' && c!=EOF)
                direccion[j]=c;//direccion
            if(num_guion==3 && c!='-' && c!=EOF)
                id_cliente[j]=c;//localidad
            if(num_guion==4 && c!='-' && c!=EOF &&c!='\n')
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


void carga_txt_productos_pedidos(productos_pedidos *pedido_trans){
    FILE *archivo;
    int i,j=0,num_guion=0;
    char c;
    char id[7];
    char id_producto[7];
    char unidades;
    char estado;
    char id_trans[4];
    char id_locker[10];
    char codigo_locker[4];
    char fecha_entrega[10];

    system("cls");

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Clientes.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Pedidos.txt", directorio);

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
                strcpy(pedido_trans[i].nombre,nombre);
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

void descarga_txt_pedidos(pedidos *pedido_cli){
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
    sprintf(ruta_relativa, "%s/DATA/Productos.txt", directorio);

    archivo = fopen(ruta_relativa, "w");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        perror("fopen");
    }
    else{
        do{
            fprintf(archivo,"%i-",(pedido_cli+i)->id_cliente);
            fprintf(archivo,"%s-",(pedido_cli+i)->fecha);
            fprintf(archivo,"%i-",(pedido_cli+i)->id_pedido);
            fprintf(archivo,"%i-",(pedido_cli+i)->locker);
            fprintf(archivo,"%.2f-",(pedido_cli+i)->importe);
            i++;
        }while(i!=n-1);
    }
    fclose(archivo);// Cerrar el fichero
    printf("\ncarga completada\n");
}

void carga_txt_productos_pedidos(productos_pedidos *pedido_trans){
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
    sprintf(ruta_relativa, "%s/DATA/Productos.txt", directorio);

    archivo = fopen(ruta_relativa, "w");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        perror("fopen");
    }
    else{
        do{
            fprintf(archivo,"%i-",(pedido_cli+i)->id_cliente);
            fprintf(archivo,"%s-",(pedido_cli+i)->fecha);
            fprintf(archivo,"%i-",(pedido_cli+i)->id_pedido);
            fprintf(archivo,"%i-",(pedido_cli+i)->locker);
            fprintf(archivo,"%.2f-",(pedido_cli+i)->importe);
            i++;
        }while(i!=n-1);
    }
    fclose(archivo);// Cerrar el fichero
    printf("\ncarga completada\n");
}