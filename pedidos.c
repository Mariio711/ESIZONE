#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include "Lockers.c"
#include "Clientes.h"
#include "pedidos.h"

void principal_pedidos(int aux,int id){ //si aux=0 el usuario sera un usuario normal, pero si es un transportista aux=1
    int x,y,z;
    x=contar_lineas_pedidos();
    y=contar_lineas_pedidos_productos();
    z=contar_lineas_devolucion();
    
    pedidos *pedido_cli=(pedidos*)calloc(x,sizeof(pedidos));
    productos_pedidos *pedido_trans=(productos_pedidos*)calloc(y,sizeof(productos_pedidos)); 
    devolucion *dev=(devolucion*)calloc(z,sizeof(devolucion));

    descarga_txt_pedidos(pedido_cli);
    descarga_txt_productos_pedidos(pedido_trans);
    descarga_txt_devolucion(dev);

    if(aux==0){
        menu_cliente(pedido_cli, pedido_trans,dev ,id);
    }
    else{
        menu_transportista(pedido_cli, pedido_trans,dev, id);
    }      
}

void menu_cliente(pedidos *pedido_cli, productos_pedidos *pedido_trans, devolucion *dev,int id){
    int option;
    
    system("cls");
    opciones_cliente();
    
    do{
        scanf("%i",&option);
    }while(1>option&&option>3);
    
    switch (option)
    {
    case 1:
        mostrar_pedidos_usuario(pedido_cli, id,1);
        break;
    case 2:
        devolver_pedido(pedido_cli,pedido_trans,dev,id);
        break;
    case 3:
        cancelar_pedido(pedido_cli,pedido_trans,dev,id);
        break;
    }
}

void opciones_cliente(){
    printf("Pedidos realizados por el cliente\n");
    printf("1. Mostrar pedidos \n");
    printf("2. Devolver pedido \n");
    printf("3. Cancelar pedido \n");
}

void mostrar_pedidos_usuario(pedidos *pedido_cli, int id, int aux){
    int i,j=contar_lineas_pedidos();
    printf("Estos son sus pedidos\n");

    switch (aux)
    {
    case 1:
        for(i=0;i<j;i++){
            if(id==atoi((pedido_cli+i)->id_cliente)){
                printf("%s-%s-%s-%s-%s-%s\n",(pedido_cli+i)->id_cliente,(pedido_cli+i)->fecha,(pedido_cli+i)->id_pedido,(pedido_cli+i)->estado,(pedido_cli+i)->locker,(pedido_cli+i)->locker);
            }
        }
        break;
    case 2:
        for(i=0;i<j;i++){
            if(id==atoi((pedido_cli+i)->id_cliente)){
                if(strcmp("Entregado",(pedido_cli+i)->estado)==0){
                    printf("%s-%s-%s-%s-%s-%s\n",(pedido_cli+i)->id_cliente,(pedido_cli+i)->fecha,(pedido_cli+i)->id_pedido,(pedido_cli+i)->estado,(pedido_cli+i)->locker,(pedido_cli+i)->locker);
                }
            }
        }
        break;
    case 3:
        for(i=0;i<j;i++){
            if(id==atoi((pedido_cli+i)->id_cliente)){
                if(strcmp("Entregado",(pedido_cli+i)->estado)!=0 && strcmp("Devuelto",(pedido_cli+i)->estado)!=0){
                    printf("%s-%s-%s-%s-%s-%s\n",(pedido_cli+i)->id_cliente,(pedido_cli+i)->fecha,(pedido_cli+i)->id_pedido,(pedido_cli+i)->estado,(pedido_cli+i)->locker,(pedido_cli+i)->locker);
                }
            }
        }
        break;
    }
}

void devolver_pedido(pedidos *pedido_cli, productos_pedidos *pedido_trans, devolucion *dev ,int id){
    char pedido[7];
    int i=-1,j=contar_lineas_pedidos();
    int aux=0,intentos=0, x=0;
    int y=contar_lineas_pedidos_productos();
    int option;
    mostrar_pedidos_usuario(pedido_cli, id,2);
    printf("Seleccione el pedido a devolver(numero de pedido)\n");
    do{
        if(intentos>0){
            printf("Error, quedan %i intentos\n",3-i);
        }
        if (intentos==3){
            carga_txt_devolucion(dev);
            carga_txt_pedidos(pedido_cli);
            carga_txt_productos_pedidos(pedido_trans);
            exit(1);
        }
        fgets(pedido,7,stdin);
        do{
            i++;
            if(strcmp((pedido_cli+i)->id_pedido,pedido)==0){
                if (strcmp((pedido_cli+i)->estado,"Entregado")!=0){
                    strcpy((pedido_cli+i)->estado,"EnLocker");
                    do{
                        if(strcmp(pedido,(pedido_trans+x)->id_pedido)==0){
                            strcpy((pedido_trans+x)->estado,"EnLocker");
                            //strcpy(dev->id_pedido,);
                        }
                        x++;
                    }while(x<y);
                    aux=1;
                }   
            }
        }while(aux==0 && i<j);
    }while(aux==0);
    system("cls");
    printf("Desea hacer algun cambio mas(1), volver atras(2) o salir(3)\n");
    do{
        scanf("%i",&option);
    }while(1<option&&option>3);
    switch (option)
    {
    case 1:
        devolver_pedido(pedido_cli,pedido_trans,dev,id);
        break;
    case 2:
        menu_cliente(pedido_cli,pedido_trans,dev,id);
        break;
    case 3:
        carga_txt_devolucion(dev);
        carga_txt_pedidos(pedido_cli);
        carga_txt_productos_pedidos(pedido_trans);
        exit(1);
    } 
}

void cancelar_pedido(pedidos *pedido_cli, productos_pedidos *pedido_trans, devolucion *dev,int id){
    char pedido[7];
    int i=-1,j=contar_lineas_pedidos();
    int aux=0,intentos=0;
    int x=0,y=contar_lineas_pedidos_productos();
    int intento=0,option;
    mostrar_pedidos_usuario(pedido_cli, id,3);

    printf("Seleccione el pedido a cancelar(numero de pedido)\n");
    do{
        if(intentos>0){
            printf("Error, quedan %i intentos\n",3-i);
        }
        if (intentos==3){
            exit(1);
        }
        fgets(pedido,7,stdin);
        do{
            i++;
            if(strcmp((pedido_cli+i)->id_pedido,pedido)==0){
                if (strcmp((pedido_cli+i)->estado,"EnPreparacion")!=0 || strcmp((pedido_cli+i)->estado,"Enviado")==0){
                    strcpy((pedido_cli+i)->estado,"Cancelado");
                    do{
                        if(strcmp(pedido,(pedido_trans+x)->id_pedido)==0){
                            strcpy((pedido_trans+x)->estado,"Cancelado");
                        }
                    }while(x<y);
                    aux=1;
                }   
            }
        }while(aux==0 && i<j);
        intento++;
    }while(aux==0);   
    system("cls");
    printf("Desea hacer algun cambio mas(1), volver atras(2) o salir(3)\n");
    do{
        scanf("%i",&option);
    }while(1<option&&option>3);
    switch (option)
    {
    case 1:
        cancelar_pedido(pedido_cli,pedido_trans,dev,id);
        break;
    case 2:
        menu_cliente(pedido_cli,pedido_trans,dev,id);
        break;
    case 3:
        carga_txt_devolucion(dev);
        carga_txt_pedidos(pedido_cli);
        carga_txt_productos_pedidos(pedido_trans);
        exit(1);
    }   
}

int contar_lineas_pedidos(){
    FILE *archivo;
    int j=1;
    char c;
    
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
        c=fgetc(archivo);
        do{
            if('\n'==c){
                j++;
            }
        }while(c!=EOF);
    }
    fclose(archivo);// Cerrar el fichero
    return(j);
}

int contar_lineas_devolucion(){
    FILE *archivo;
    int j=1;
    char c;
    
    //system("cls");

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Clientes.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Devolucion.txt", directorio);

    archivo = fopen(ruta_relativa, "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        perror("fopen");
    }
    else{
        do{
            c=fgetc(archivo);
            if('\n'==c){
                j++;
            }
        }while(c!=EOF);
    }
    fclose(archivo);// Cerrar el fichero
    return(j);
}

int contar_lineas_pedidos_productos(){
    FILE *archivo;
    int j=1;
    char c;
    
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
        do{
            c=fgetc(archivo);
            if('\n'==c){
                j++;
            }
        }while(c!=EOF);
    }
    fclose(archivo);// Cerrar el fichero
    return(j);
}

void menu_transportista(pedidos *pedido_cli, productos_pedidos *pedido_trans,devolucion *dev ,int id){
    int option;

    system("cls");
    opciones_transportista();

    do{
        scanf("%i",&option);
    }while(1>option&&option>3);
    
    switch (option)
    {
    case 1:
        mostrar_pedidos_transportista(pedido_cli,pedido_trans,dev,id);
        break;
    case 2:
        gestionar_devoluciones(pedido_cli,pedido_trans, dev,id);
        break;
    case 3:
        carga_txt_devolucion(dev);
        carga_txt_pedidos(pedido_cli);
        carga_txt_productos_pedidos(pedido_trans);
        exit(1);
    }
}

void mostrar_pedidos_transportista(pedidos *pedido_cli, productos_pedidos *pedido_trans,devolucion *dev, int id){
    int i,j=contar_lineas_pedidos();
    int aux;
    printf("Seleccione los pedidos que quiere ver\n Ya entregados(1)\n No entregados (2)");

    do{
        scanf("%i",&aux);
    }while(aux!=1 && aux!=2);
    
    if(aux==1){
        printf("Estos son sus pedidos\n");
        for(i=0;i<j;i++){
            if(id==atoi((pedido_cli+i)->id_cliente)){
                printf("%s-%s-%s-%s-%s-%s\n",(pedido_cli+i)->id_cliente,(pedido_cli+i)->fecha,(pedido_cli+i)->id_pedido,(pedido_cli+i)->estado,(pedido_cli+i)->locker,(pedido_cli+i)->locker);
            }
        }
    }
    if(aux==2){
        printf("Estos son sus pedidos\n");
        for(i=0;i<j;i++){
            if(id==atoi((pedido_cli+i)->id_cliente)){
                if(strcmp("Entregado",(pedido_cli+i)->estado)==0){
                    printf("%s-%s-%s-%s-%s-%s\n",(pedido_cli+i)->id_cliente,(pedido_cli+i)->fecha,(pedido_cli+i)->id_pedido,(pedido_cli+i)->estado,(pedido_cli+i)->locker,(pedido_cli+i)->locker);
                }
            }
        } 
        printf("Desea salir (1) o volver atras(2)\n");
        do{
            scanf("%i",&aux);
        }while(aux!=1 && aux!=2);
        if(aux==1){
            carga_txt_devolucion(dev);
            carga_txt_pedidos(pedido_cli);
            carga_txt_productos_pedidos(pedido_trans);
            exit(1);
        }
        if(aux==2){
            menu_transportista(pedido_cli, pedido_trans, dev, id);
        }
    }
}

void gestionar_devoluciones(pedidos *pedido_cli, productos_pedidos *pedido_trans, devolucion *dev,int id){
    char pedido[7];
    int option;
    char nuevo_estado[14];
    int intentos=0,i=0,x=0,aux=0,intento=0;
    int j=contar_lineas_pedidos_productos();
    int y=contar_lineas_pedidos();
    mostrar_pedidos_transportista(pedido_cli,pedido_trans,dev,id);
    printf("Seleccione un pedido\n");
    do{
        if(intentos>0){
            printf("Error, quedan %i intentos\n",3-intentos);
        }
        if (intentos==3){
            carga_txt_devolucion(dev);
            carga_txt_pedidos(pedido_cli);
            carga_txt_productos_pedidos(pedido_trans);
            exit(1);
        }
        fgets(pedido,7,stdin);
        do{
            i++;
            if(strcmp((pedido_trans+i)->id_pedido,pedido)==0){
                if (strcmp((pedido_cli+i)->estado,"EnPeparacion")==0 || strcmp((pedido_cli+i)->estado,"Enviado")==0){
                    
                    opciones_gestionar_devoluciones();
                    switch (option)
                    {
                    case 1:
                        strcpy(nuevo_estado,"EnLocker");
                        do{
                            if(strcmp(pedido,(pedido_cli+x)->id_pedido)==0){
                                strcpy((pedido_cli+x)->estado,nuevo_estado);
                            }
                            x++;
                        }while(x<y);
                        aux=1;
                        break;
                    case 2:
                        strcpy(nuevo_estado,"Enviado");
                        do{
                            if(strcmp(pedido,(pedido_cli+x)->id_pedido)==0){
                                strcpy((pedido_cli+x)->estado,nuevo_estado);
                            }
                            x++;
                        }while(x<y);
                        aux=1;
                        break;
                    case 3:
                        strcpy(nuevo_estado,"EnPreparacion");
                        do{
                            if(strcmp(pedido,(pedido_cli+x)->id_pedido)==0){
                                strcpy((pedido_cli+x)->estado,nuevo_estado);
                            }
                            x++;
                        }while(x<y);
                        aux=1;
                        break;
                    case 4:
                        menu_transportista(pedido_cli,pedido_trans,dev,id);
                        break;
                    case 5:
                        carga_txt_devolucion(dev);
                        carga_txt_pedidos(pedido_cli);
                        carga_txt_productos_pedidos(pedido_trans);
                        exit(1);
                    }
                }   
            }
        }while(aux==0 && i<j);
        intento++;
    }while(aux==0);  
    system("cls");
    printf("Desea hacer algun cambio mas(1), volver atras(2) o salir(3)\n");
    do{
        scanf("%i",&option);
    }while(1<option&&option>3);
    switch (option)
    {
    case 1:
        gestionar_devoluciones(pedido_cli,pedido_trans,dev,id);
        break;
    case 2:
        menu_transportista(pedido_cli,pedido_trans,dev,id);
        break;
    case 3:
        carga_txt_devolucion(dev);
        carga_txt_pedidos(pedido_cli);
        carga_txt_productos_pedidos(pedido_trans);
        exit(1);
    }   
}

void opciones_gestionar_devoluciones(){
    printf("Seleccione el nuevo estado del pedido o una opcion \n");
    printf("1. EnLocker\n");
    printf("2. Enviado\n");
    printf("3. EnPreparacion\n");
    printf("4. Volver atras\n");
    printf("5. Salir\n");
}

void opciones_transportista(){
    printf("Pedidos a cargo del transportista\n");
    printf("1. Gestionar pedidos \n");
    printf("2. Gestionar devoluciones \n");
}


void descarga_txt_devolucion(devolucion *dev){
    FILE *archivo;
    int i,j=0,num_guion=0;
    int n=contar_lineas_devolucion();
    char c;
    char id_pedido[7];
    char id_producto[7];
    char fecha_devolucion[10];
    char motivo[50];
    char estado[13];

    //system("cls");

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Clientes.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Devolucion.txt", directorio);

    archivo = fopen(ruta_relativa, "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        perror("fopen");
    }
    else{
        for(i=0;i<n;i++){
        memset(id_pedido, 0, 7);
        memset(id_producto, 0, 7);
        memset(fecha_devolucion, 0, 10);
        memset(estado, 0, 13);//vacia para no pillar basura en los vectores
        memset(motivo, 0, 50);
        do{
            c=fgetc(archivo);
            if(num_guion==0 && c!='-' && c!=EOF)
                id_pedido[j]=c;//id
            if(num_guion==1 && c!='-' && c!=EOF)
                id_producto[j]=c;//nombre
            if(num_guion==2 && c!='-' && c!=EOF)
                fecha_devolucion[j]=c;//direccion
            if(num_guion==3 && c!='-' && c!=EOF)
                estado[j]=c;//localidad
            if(num_guion==3 && c!='-' && c!=EOF)
                motivo[j]=c;//localidad
            if(c=='-'){
                num_guion++;
                j=-1;
            }
            if(c=='\n'){
                strcpy((dev+i)->id_pedido,id_pedido);
                strcpy((dev+i)->id_producto,id_producto);
                strcpy((dev+i)->fecha_devolucion,fecha_devolucion);
                strcpy((dev+i)->estado,estado);
                strcpy((dev+i)->motivo,motivo);
                
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
    int i,j=0,num_guion=0;
    int n=contar_lineas_pedidos();
    char c;
    char id_pedido[7];
    char fecha[10];
    char id_cliente[7];
    char estado[13];
    char locker[10];
    char importe[10];

    //system("cls");

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
        memset(id_pedido, 0, 7);
        memset(fecha, 0, 10);
        memset(id_cliente, 0, 7);
        memset(estado, 0, 13);//vacia para no pillar basura en los vectores
        memset(locker, 0, 10);
        memset(importe, 0, 10);
        do{
            c=fgetc(archivo);
            if(num_guion==0 && c!='-' && c!=EOF)
                id_pedido[j]=c;//id
            if(num_guion==1 && c!='-' && c!=EOF)
                fecha[j]=c;//nombre
            if(num_guion==2 && c!='-' && c!=EOF)
                id_cliente[j]=c;//direccion
            if(num_guion==3 && c!='-' && c!=EOF)
                estado[j]=c;//localidad
            if(num_guion==3 && c!='-' && c!=EOF)
                locker[j]=c;//localidad
            if(num_guion==4 && c!='-' && c!=EOF &&c!='\n')
                importe[j]=c;//dinero
            if(c=='-'){
                num_guion++;
                j=-1;
            }
            if(c=='\n'){
                strcpy((pedido_cli+i)->id_pedido,id_pedido);
                strcpy((pedido_cli+i)->fecha,fecha);
                strcpy((pedido_cli+i)->id_cliente,id_cliente);
                strcpy((pedido_cli+i)->estado,estado);
                strcpy((pedido_cli+i)->locker,locker);
                (pedido_cli+i)->importe=atof(importe);
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
    int i=0;
    int n=contar_lineas_pedidos_productos();
    //system("cls");

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Clientes.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/ProductosPedido.txt", directorio);

    archivo = fopen(ruta_relativa, "w");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        perror("fopen");
    }
    else{
        do{
            fprintf(archivo,"%s-",(pedido_trans+i)->id_pedido);
            fprintf(archivo,"%s-",(pedido_trans+i)->id_producto);
            fprintf(archivo,"%i-",(pedido_trans+i)->unidades);
            fprintf(archivo,"%s-",(pedido_trans+i)->fecha_prevista);
            fprintf(archivo,"%.2f-",(pedido_trans+i)->importe);
            fprintf(archivo,"%s-",(pedido_trans+i)->id_trans);
            fprintf(archivo,"%s-",(pedido_trans+i)->id_locker);
            fprintf(archivo,"%s-",(pedido_trans+i)->codigo_locker);
            fprintf(archivo,"%s-\n",(pedido_trans+i)->fecha_entrega);
            i++;
        }while(i!=n-1);
    }
    fclose(archivo);// Cerrar el fichero
    printf("\ncarga completada\n");
}

void carga_txt_devolucion(devolucion *dev){
    FILE *archivo;
    int i=0;
    int n=contar_lineas_devolucion();
    //system("cls");

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Clientes.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Devolucion.txt", directorio);

    archivo = fopen(ruta_relativa, "w");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        perror("fopen");
    }
    else{
        do{
            fprintf(archivo,"%s-",(dev+i)->id_pedido);
            fprintf(archivo,"%s-",(dev+i)->id_producto);
            fprintf(archivo,"%s-",(dev+i)->fecha_devolucion);
            fprintf(archivo,"%s-",(dev+i)->motivo);
            fprintf(archivo,"%s-",(dev+i)->estado);

            i++;
        }while(i!=n-1);
    }
    fclose(archivo);// Cerrar el fichero
    printf("\ncarga completada\n");
}

void descarga_txt_productos_pedidos(productos_pedidos *pedido_trans){
        FILE *archivo;
    int i,j=0,num_guion=0;
    char c;
    int n=contar_lineas_pedidos_productos();
    char id_producto[7];
    char id_pedido[7];
    char unidades[5];
    char fecha_prevista[10];
    char importe[10];
    char estado[13];
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
    sprintf(ruta_relativa, "%s/DATA/ProductosPedido.txt", directorio);

    archivo = fopen(ruta_relativa, "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        perror("fopen");
    }
    else{
        for(i=0;i<n;i++){
        memset(id_producto, 0, 7);
        memset(id_pedido, 0, 7);
        memset(estado, 0, 13);
        memset(fecha_entrega, 0, 10);
        memset(id_trans, 0, 4);//vacia para no pillar basura en los vectores
        memset(id_locker, 0, 10);
        memset(codigo_locker, 0, 4);
        memset(fecha_entrega, 0, 10);
        do{
            c=fgetc(archivo);
            if(num_guion==0 && c!='-' && c!=EOF)
                id_pedido[j]=c;
            if(num_guion==1 && c!='-' && c!=EOF)
                id_producto[j]=c;
            if(num_guion==2 && c!='-' && c!=EOF)
                unidades[j]=c;
            if(num_guion==3 && c!='-' && c!=EOF)
                fecha_prevista[j]=c;
            if(num_guion==4 && c!='-' && c!=EOF)
                importe[j]=c;
            if(num_guion==5 && c!='-' && c!=EOF)
                estado[j]=c;
            if(num_guion==6 && c!='-' && c!=EOF)
                id_trans[j]=c;
            if(num_guion==7 && c!='-' && c!=EOF)
                id_locker[j]=c;
            if(num_guion==8 && c!='-' && c!=EOF)
                codigo_locker[j]=c;
            if(num_guion==9 && c!='-' && c!=EOF &&c!='\n')
                fecha_entrega[j]=c;
            if(c=='-'){
                num_guion++;
                j=-1;
            }
            if(c=='\n'){
                strcpy((pedido_trans+i)->id_pedido,id_pedido);
                strcpy((pedido_trans+i)->id_producto,id_producto);
                (pedido_trans+i)->unidades=atoi(unidades);
                strcpy((pedido_trans+i)->fecha_prevista,fecha_prevista);
                (pedido_trans+i)->importe=atof(importe);
                strcpy((pedido_trans+i)->estado,estado);
                strcpy((pedido_trans+i)->id_trans,id_trans);
                strcpy((pedido_trans+i)->id_locker,id_locker);
                strcpy((pedido_trans+i)->codigo_locker,codigo_locker);
                strcpy((pedido_trans+i)->fecha_entrega,fecha_entrega);
                num_guion=0;
                j=-1;
            }
            j++;
        }while(c!='\n'&&c!=EOF);
        }
    }
    fclose(archivo);// Cerrar el fichero
}

void carga_txt_pedidos(pedidos *pedido_cli){
    FILE *archivo;
    int i=0;
    int n=contar_lineas_pedidos();
    //system("cls");

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Clientes.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Pedidos.txt", directorio);

    archivo = fopen(ruta_relativa, "w");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        perror("fopen");
    }
    else{
        do{
            fprintf(archivo,"%s-",(pedido_cli+i)->id_cliente);
            fprintf(archivo,"%s-",(pedido_cli+i)->fecha);
            fprintf(archivo,"%s-",(pedido_cli+i)->id_pedido);
            fprintf(archivo,"%s-",(pedido_cli+i)->estado);
            fprintf(archivo,"%s-",(pedido_cli+i)->locker);
            fprintf(archivo,"%.2f\n",(pedido_cli+i)->importe);
            i++;
        }while(i!=n-1);
    }
    fclose(archivo);// Cerrar el fichero
    printf("\ncarga completada\n");
}