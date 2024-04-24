#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h> // Para dirname()
#include "Productos.h"

//cabecera: void inicio_prod(int);
//precondicion: recibe un entero para saber si entra un cliente o un provedor
//poscondicion:  si entra (1) da paso a prod_client y si entra (2) a prod_prov
/*int main(){//void inicio_prod(int palanca)
    system("cls");
    


    return 0;
}*/

void prod_clien(float dinero){
    int elec_prod_client,elec_prod_categ;
    char descripcion_prod_introducida[50];
    int i,palanca;
    int nc,np;

    nc=num_categ();
    np=num_prod();
    categ *categorias=(categ*)calloc(nc,sizeof(categ));
    producto *productos=(producto*)calloc(np,sizeof(producto));
    descarga_categ(categorias,nc);
    descarga_prod(productos,np);

    system("cls");
    printf("Bienvenido al menu de compra de ESIZONE\nDesea buscar un producto \npor su nombre(1) \no \npor su categoria(2)?\n");

    do{
        scanf("%i",&elec_prod_client);
        if(elec_prod_client<1||elec_prod_client>2)
            printf("Eleccion no valida, intentelo de nuevo:");           //control de entrada
        fflush(stdin);
    }while(elec_prod_client<1||elec_prod_client>2);
    


    if(elec_prod_client==1){//busqueda por nombre
        printf("\nintroduce el nombre del producto en minusculas y sin tildes:");
        gets(descripcion_prod_introducida);
        palanca=1;
    }


    else{//busqueda por categoria
        system("cls");
        printf("Seleccione categoria: \n");
        for(i=0;i<nc;i++){
            printf("%i-%s\n",(categorias+i)->id_categ,(categorias+i)->descripcion_categ);
        }

        do{
        scanf("%i",&elec_prod_categ);
        if(elec_prod_categ<1||elec_prod_categ>nc)
            printf("Eleccion no valida, intentelo de nuevo:");           //control de entrada
        fflush(stdin);
        }while(elec_prod_categ<1||elec_prod_categ>nc);
        
        palanca=2;
    }
    busqueda(palanca,elec_prod_categ,descripcion_prod_introducida,productos,np,dinero);
}

void busqueda(int palanca,int elec_categ,char elec_descrip[],producto *productos,int np,float dinero){//palanca=1 ->busqueda descripcion    palanca=2  ->categoria
    int i,k=1,elec_busqueda;
    producto prod_elegidos[np];
    system("cls");
    if(palanca==1){
        for(i=0;i<np;i++){
            if(strcmp(elec_descrip,(productos+i)->descripcion_prod)==0){
                printf("\n%i-%s",k,(productos+i)->descripcion_prod);
                printf("\n\tprecio:%.2f$",(productos+i)->precio);
                printf("\n\tproductos disponibles:%i",(productos+i)->stock);
                printf("\n\tdias maximo en demora:%i",(productos+i)->entrega);
                prod_elegidos[k].id_prod=(productos+i)->id_prod;
                strcpy(prod_elegidos[k].descripcion_prod,(productos+i)->descripcion_prod);
                prod_elegidos[k].id_categ=(productos+i)->id_categ;
                prod_elegidos[k].id_gestor=(productos+i)->id_gestor;
                prod_elegidos[k].stock=(productos+i)->stock;
                prod_elegidos[k].entrega=(productos+i)->entrega;
                prod_elegidos[k].precio=(productos+i)->precio;
                k++;
            }
        }
        printf("seleccione el numero producto que desee comprar(ej:1):");
        do{
        scanf("%i",&elec_busqueda);
        if(elec_busqueda<1||elec_busqueda>k-1)
            printf("Eleccion no valida, intentelo de nuevo:");           //control de entrada
        fflush(stdin);
        }while(elec_busqueda<1||elec_busqueda>k-1);
        comprar(dinero,prod_elegidos,k,productos,np);
    }

    else{
        for(i=0;i<np;i++){
            if(elec_categ==(productos+i)->id_categ){
                printf("\n%i-%s",k,(productos+i)->descripcion_prod);
                printf("\n\tprecio:%.2f$",(productos+i)->precio);
                printf("\n\tproductos disponibles:%i",(productos+i)->stock);
                printf("\n\tdias maximo en demora:%i",(productos+i)->entrega);
                prod_elegidos[k].id_prod=(productos+i)->id_prod;
                strcpy(prod_elegidos[k].descripcion_prod,(productos+i)->descripcion_prod);
                prod_elegidos[k].id_categ=(productos+i)->id_categ;
                prod_elegidos[k].id_gestor=(productos+i)->id_gestor;
                prod_elegidos[k].stock=(productos+i)->stock;
                prod_elegidos[k].entrega=(productos+i)->entrega;
                prod_elegidos[k].precio=(productos+i)->precio;
                k++;
            }
        }
        printf("seleccione el numero producto que desee comprar(ej:1):");
        do{
        scanf("%i",&elec_busqueda);
        if(elec_busqueda<1||elec_busqueda>k-1)
            printf("Eleccion no valida, intentelo de nuevo:");           //control de entrada
        fflush(stdin);
        }while(elec_busqueda<1||elec_busqueda>k-1);
        comprar(dinero,prod_elegidos,k,productos,np);
    }
}

void comprar(float dinero,producto prod_elegidos[],int k,producto *productos,int np){
    int i,encontrado=0;
    if(prod_elegidos[k].stock==0)
        printf("no quedan mas productos de este tipo");
    else{
        for(i=0;i<np && encontrado==0;i++){
            if(prod_elegidos[k].id_prod==(productos+i)->id_prod){
                encontrado=1;//encuentra el producto
                printf("\n%i-%s",k,(productos+i)->descripcion_prod);
                printf("\n\tprecio:%.2f$",(productos+i)->precio);
                printf("\n\tproductos disponibles:%i",(productos+i)->stock);
                printf("\n\tdias maximo en demora:%i",(productos+i)->entrega);
                system("pause");
            }
        }
    }
}
/*-------------------------------------------------------------------
provedor
El usuario proveedor podrá realizar las mismas acciones que el administrador pero sólo sobre
sus propios productos. Es decir, podrá acceder a la información de sus productos que estén
dados de alta en la plataforma. Sobre ellos podrá realizar altas, bajas, búsquedas, listados y
modificaciones de productos.
void prod_prov(){
    int nc,np;
    nc=num_categ();
    np=num_prod();
    categ *categorias=(categ*)calloc(nc,sizeof(categ));
    producto *productos=(producto*)calloc(np,sizeof(producto));
    descarga_categ(categorias,nc);
    descarga_prod(productos,np);
}*/

//cabecera: descarga_clientes();
//precondicion: existe fichero "Clientes.txt"
//poscondicion: carga la estructura cliente
void descarga_categ(categ *categorias,int n){
    FILE *archivo;
    int i,j=0,num_guion=0;
    char c;
    char id_categ[8];
    char descripcion_categ[50];

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Categorias.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Categorias.txt", directorio);

    archivo = fopen(ruta_relativa, "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir categorias.txt.\n");
        perror("fopen");
    }
    else{
        for(i=0;i<n;i++){
        memset(id_categ, 0, 8);
        memset(descripcion_categ, 0, 50);//vacia para no pillar basura en los vectores

        do{
            c=fgetc(archivo);
            if(num_guion==0 && c!='-' && c!=EOF)
                id_categ[j]=c;//id
            if(num_guion==1 && c!='-' && c!=EOF &&c!='\n')
                descripcion_categ[j]=c;//categoria
            if(c=='-'){
                num_guion++;
                j=-1;
            }
            if(c=='\n'){
                strcpy((categorias+i)->descripcion_categ,descripcion_categ);
                (categorias+i)->id_categ=atoi(id_categ);
                num_guion=0;
                j=-1;
            }
            j++;
        }while(c!='\n'&&c!=EOF);
        }
    }
    fclose(archivo);// Cerrar el fichero
}
//cabecera: descarga_clientes();
//precondicion: existe fichero "Clientes.txt"
//poscondicion: carga la estructura cliente
void descarga_prod(producto *productos,int n){
    FILE *archivo;
    int i,j=0,num_guion=0;
    char c;
    char id_prod[8];
    char descripcion_prod[50];
    char id_categ[8];
    char id_prov[8];
    char stock[8];
    char entrega[8];
    char precio[12];

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Productos.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Productos.txt", directorio);

    archivo = fopen(ruta_relativa, "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir Productos.txt.\n");
        perror("fopen");
    }
    else{
        for(i=0;i<n;i++){
        memset(id_prod, 0, 8);
        memset(id_categ, 0, 8);
        memset(id_prov, 0, 8);
        memset(stock, 0, 8);
        memset(entrega, 0, 8);
        memset(precio, 0, 12);
        memset(descripcion_prod, 0, 50);//vacia para no pillar basura en los vectores

        do{
            c=fgetc(archivo);
            if(num_guion==0 && c!='-' && c!=EOF)
                id_prod[j]=c;
            if(num_guion==1 && c!='-' && c!=EOF)
                descripcion_prod[j]=c;
            if(num_guion==2 && c!='-' && c!=EOF)
                id_categ[j]=c;
            if(num_guion==3 && c!='-' && c!=EOF)
                id_prov[j]=c;
            if(num_guion==4 && c!='-' && c!=EOF)
                stock[j]=c;
            if(num_guion==5 && c!='-' && c!=EOF)
                entrega[j]=c;
            if(num_guion==6 && c!='-' && c!=EOF &&c!='\n')
                precio[j]=c;
            if(c=='-'){
                num_guion++;
                j=-1;
            }
            if(c=='\n'){
                strcpy((productos+i)->descripcion_prod,descripcion_prod);
                (productos+i)->id_prod=atoi(id_prod);
                (productos+i)->id_categ=atoi(id_categ);
                (productos+i)->id_gestor=atoi(id_prov);
                (productos+i)->stock=atoi(stock);
                (productos+i)->entrega=atoi(entrega);
                (productos+i)->precio=atof(precio);
                num_guion=0;
                j=-1;
            }
            j++;
        }while(c!='\n'&&c!=EOF);
        }
    }
    fclose(archivo);// Cerrar el fichero
}
//cabecera: num_clien();
//precondicion: existe el fichero "Clientes.txt"
//poscondicion: cuenta cuantos clientes existen
int num_categ(){
    int num_categorias=0;
    FILE *archivo;
    char c;
    
    //system("cls");

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Categorias.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Categorias.txt", directorio);

    archivo = fopen(ruta_relativa, "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir Categorias.txt.\n");
        perror("fopen");
    }
    else{
        do{
            c=fgetc(archivo);
            if(c=='\n'||c==EOF)
                num_categorias++;
        }while(c!=EOF);
    }
    fclose(archivo);// Cerrar el fichero
    return num_categorias;
}
//cabecera: num_clien();
//precondicion: existe el fichero "Clientes.txt"
//poscondicion: cuenta cuantos clientes existen
int num_prod(){
    int num_productos=0;
    FILE *archivo;
    char c;
    
    //system("cls");

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Categorias.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Productos.txt", directorio);

    archivo = fopen(ruta_relativa, "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir Productos.txt.\n");
        perror("fopen");
    }
    else{
        do{
            c=fgetc(archivo);
            if(c=='\n'||c==EOF)
                num_productos++;
        }while(c!=EOF);
    }
    fclose(archivo);// Cerrar el fichero
    return num_productos;
}