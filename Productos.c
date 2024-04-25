#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h> // Para dirname()

#include "Productos.h"

//cabezera: float prod_clien(float);
//precondicion: dinero>=0
//poscondicion: da comienzo a clientes productos
float prod_clien(float dinero){
    int elec_prod_client,elec_prod_categ;
    char descripcion_prod_introducida[50];
    int i;
    int nc,np;
    float *dinero_p;
    dinero_p=&dinero;
    nc=num_categ();
    np=num_prod();
    categ *categorias=(categ*)calloc(nc,sizeof(categ));
    producto *productos=(producto*)calloc(np,sizeof(producto));
    descarga_categ(categorias,nc);
    descarga_prod(productos,np);
    do{
    system("cls");
    printf("Bienvenido al menu de compra de ESIZONE Desea:\nbuscar un producto por su nombre?(1) \nbuscar un producto por su categoria?(2)\no salir(3)\n");

    do{
        scanf("%i",&elec_prod_client);
        if(elec_prod_client<1||elec_prod_client>3)
            printf("Eleccion no valida, intentelo de nuevo:");           //control de entrada
        fflush(stdin);
    }while(elec_prod_client<1||elec_prod_client>3);
    


    if(elec_prod_client==1){//busqueda por nombre
        printf("\nintroduce el nombre del producto en minusculas y sin tildes:");
        gets(descripcion_prod_introducida);
        fflush(stdin);
        busqueda(1,elec_prod_categ,descripcion_prod_introducida,productos,np-1,dinero_p);
        carga_prod(productos,np);
    }


    if(elec_prod_client==2){//busqueda por categoria
        system("cls");
        printf("Seleccione categoria: \n");
        for(i=0;i<nc-1;i++){
            printf("%i-%s\n",(categorias+i)->id_categ,(categorias+i)->descripcion_categ);
        }

        do{
        scanf("%i",&elec_prod_categ);
        if(elec_prod_categ<1||elec_prod_categ>nc)
            printf("Eleccion no valida, intentelo de nuevo:");           //control de entrada
        fflush(stdin);
        }while(elec_prod_categ<1||elec_prod_categ>nc);
        
        busqueda(2,elec_prod_categ,descripcion_prod_introducida,productos,np-1,dinero_p);
        carga_prod(productos,np);
    }
    }while(elec_prod_client!=3);
    return dinero;
}

//cabezera: void busqueda(int ,int ,char [],producto *,int ,float *);
//precondicion: (palanca=1 || palanca=2) && producto ya inicializado && dinero_p>=0
//poscondicion: encuentra el producto que queremos comprar
void busqueda(int palanca,int elec_categ,char elec_descrip[],producto *productos,int np,float *dinero_p){//palanca=1 ->busqueda descripcion    palanca=2  ->categoria
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
        if(k==1)
            printf("\nproducto no encontrado :()");
        else{
        printf("\nseleccione el numero producto que desee comprar(ej:1):\n(seleccione 0 para salir)\n");
        do{
        scanf("%i",&elec_busqueda);
        if(elec_busqueda<0||elec_busqueda>k-1)
            printf("Eleccion no valida, intentelo de nuevo:");           //control de entrada
        fflush(stdin);
        }while(elec_busqueda<0||elec_busqueda>k-1);
        if(elec_busqueda==0)
            printf("operacion cancelada");
        else
            comprar(dinero_p,prod_elegidos,elec_busqueda,productos,np);
        }
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
        if(k==1)
            printf("\nproducto no encontrado :()");
        else{
        printf("\nseleccione el numero producto que desee comprar(ej:1):\n(seleccione 0 para salir)\n");
        do{
        scanf("%i",&elec_busqueda);
        if(elec_busqueda<0||elec_busqueda>k-1)
            printf("Eleccion no valida, intentelo de nuevo:");           //control de entrada
        fflush(stdin);
        }while(elec_busqueda<0||elec_busqueda>k-1);
        if(elec_busqueda==0)
            printf("operacion cancelada");
        else
            comprar(dinero_p,prod_elegidos,elec_busqueda,productos,np);
        }
    }
}

//cabezera: void comprar(float *,producto [],int,producto *,int);
//precondicion: dinero_p>=0 && producto inicializado
//poscondicion: compra el producto deseado y crea un pedido
void comprar(float *dinero_p,producto prod_elegidos[],int k,producto *productos,int np){
    int i,encontrado=0;
    if(prod_elegidos[k].stock==0)
        printf("no quedan mas productos de este tipo");
    else{
        for(i=0;i<np && encontrado==0;i++){
            if(prod_elegidos[k].id_prod==(productos+i)->id_prod){
                encontrado=1;//encuentra el producto
                if(*dinero_p<(productos+i)->precio)//comprueba si tiene saldo suficiente
                    printf("\nsaldo insuficiente\n");
                else{
                    *dinero_p=*dinero_p-(productos+i)->precio;
                    (productos+i)->stock=(productos+i)->stock-1;
                    printf("\nacabas de comprar %s(%.2f$)\ntu nuevo saldo:%.2f$\n",(productos+i)->descripcion_prod,(productos+i)->precio,*dinero_p);
                    system("pause");
                    hacer_pedido(num_ped,(productos+i)->id_prod,(productos+i)->entrega,(productos+i)->precio);
                }
            }
        }
    }
}
//cabezera: void hacer_pedido(int,int);
//precondicion: existe el fichero productospedido && num_ped>=1
//poscondicion: escribe el pedido en el fichero
hacer_pedido(int n,int id_prod,int entrega,float precio){
    FILE *archivo;
    system("cls");

    char ruta_actual[1024]; 
    strcpy(ruta_actual, __FILE__);                          
    char *directorio = dirname(ruta_actual);                                    
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/ProductosPedido.txt", directorio);
    archivo = fopen(ruta_relativa, "a");


    fprintf(archivo,"%i-",n);
    fprintf(archivo,"%i-",id_prod);
    fprintf(archivo,"%i-",1);
    fprintf(archivo,"%i-",entrega);
    fprintf(archivo,"%.2f-",precio);
    fprintf(archivo,"%s\n","enPreparacion");

}

//cabezera: void prod_prov(int);
//precondicion: id_prov>=1
//poscondicion:da comienzo a provedor productos
void prod_prov(int id_prov){
    int nc,np,elec_prod_prov;
    nc=num_categ();
    np=num_prod();
    categ *categorias=(categ*)calloc(nc,sizeof(categ));
    producto *productos=(producto*)calloc(np,sizeof(producto));
    descarga_categ(categorias,nc);
    descarga_prod(productos,np);
    do{
    system("cls");
    printf("bienvenido al menu de gestion de los productos de tu empresa de ESIZON\nque desea hacer?\n1-ver productos en disposicion\n2-implementar un producto\n3-editar producto actual\n4-salir\n");
    do{
        scanf("%i",&elec_prod_prov);
        if(elec_prod_prov<1||elec_prod_prov>4)
            printf("Eleccion no valida, intentelo de nuevo:");           //control de entrada
        fflush(stdin);
    }while(elec_prod_prov<1||elec_prod_prov>4);
    switch(elec_prod_prov){
        case 1:ver_prod(productos,np-1,id_prov);break;
        case 2:{implementar_prod(productos,np,id_prov);np++;}break;
        case 3:editar_prod(productos,np-1,id_prov);break;
    }
    }while(elec_prod_prov!=4);
    carga_prod(productos,np);
}

//cabezera: void ver_prod(producto *,int,int);
//precondicion: producto ya inicializado && np>=0 && id_prov>=1
//poscondicion: imprime todos los productos de el provedor actual
void ver_prod(producto *productos,int np,int id_prov){
    int i,k=1;
    system("cls");
    for(i=0;i<np;i++){
        if(id_prov==(productos+i)->id_gestor){
            printf("\n%i-%s",k,(productos+i)->descripcion_prod);
            printf("\n\tprecio:%.2f$",(productos+i)->precio);
            printf("\n\tproductos disponibles:%i",(productos+i)->stock);
            printf("\n\tdias maximo en demora:%i",(productos+i)->entrega);
            k++;
        }

    }
    system("pause");
}

//cabezera: void implementar_prod(producto *,int,int);
//precondicion: productos ya inicializado && np>=0 && id_prov>=1
//poscondicion: crea un producto nuevo
void implementar_prod(producto *productos,int np,int id_prov){
    int pd,ddd;
    char descrip[50];
    char money[12];
    FILE *archivo;
    producto extra;
    memset(descrip,0,50);
    memset(money,0,12);
    system("cls");

    char ruta_actual[1024]; 
    strcpy(ruta_actual, __FILE__);                          
    char *directorio = dirname(ruta_actual);                                    
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Productos.txt", directorio);

    archivo = fopen(ruta_relativa, "a");

    printf("usted va a agregar un producto nuevo...\n");

    extra.id_prod=(productos+np-2)->id_prod+1;
    printf("descripcion:");gets(descrip);fflush(stdin);
    strcpy(extra.descripcion_prod,descrip);
    extra.id_categ=id_prov-1;
    extra.id_gestor=id_prov;
    printf("precio (ej:50.30[con punto]) :");gets(money);fflush(stdin);
    extra.precio=atof(money);
    printf("productos disponibles:");scanf("%i",&pd);fflush(stdin);
    extra.stock=pd;
    printf("dias maximos de demora:");scanf("%i",&ddd);fflush(stdin);
    extra.entrega=ddd;

    fprintf(archivo,"%i-",extra.id_prod);
    fprintf(archivo,"%s-",extra.descripcion_prod);
    fprintf(archivo,"%i-",extra.id_categ);
    fprintf(archivo,"%i-",extra.id_gestor);
    fprintf(archivo,"%i-",extra.stock);
    fprintf(archivo,"%i-",extra.entrega);
    fprintf(archivo,"%.2f\n",extra.precio);

}

//cabezera: void editar_prod(producto *,int,int);
//precondicion: productos ya inicializado && np>=0 && id_prov>=1
//poscondicion: edita los productos existentes
void editar_prod(producto *productos,int np,int id_prov){
    int i,k=1,elec_prod,pd,ddd;//pd->productos disponibles   ddd->dias de demora
    char descrip[50];
    char money[12];
    for(i=0;i<np;i++){
        if(id_prov==(productos+i)->id_gestor){
            system("cls");
            printf("\n%i-%s",k,(productos+i)->descripcion_prod);
            printf("\n\tprecio:%.2f$",(productos+i)->precio);
            printf("\n\tproductos disponibles:%i",(productos+i)->stock);
            printf("\n\tdias maximo en demora:%i",(productos+i)->entrega);
            printf("\n\nquiere editar este articulo(1=si)?\n");
            scanf("%i",&elec_prod);
            fflush(stdin);
            if(elec_prod==1){
                memset(descrip,0,50);
                memset(money,0,12);
                printf("descripcion:");gets(descrip);fflush(stdin);
                printf("precio (ej:50.30[con punto]) :");gets(money);fflush(stdin);
                printf("productos disponibles:");scanf("%i",&pd);fflush(stdin);
                printf("dias maximos de demora:");scanf("%i",&ddd);fflush(stdin);
                strcpy((productos+i)->descripcion_prod,descrip);
                (productos+i)->precio=atof(money);
                (productos+i)->stock=pd;
                (productos+i)->entrega=ddd;
            }
            k++;
        }
    }
    system("pause");
}

//cabecera: void descarga_categ(categ *,int);
//precondicion: categ iniciada && n>=0
//poscondicion: pilla los datos de el txt para guardarlos en la estructura
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

//cabecera: void descarga_prod(producto *,int);
//precondicion: producto iniciado && n>=0
//poscondicion: pilla los datos de el txt para guardarlos en la estructura
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

//cabecera: void carga_prod(producto *,int);
//precondicion: producto iniciado && n>=0
//poscondicion: guarda la estructura en el txt
void carga_prod(producto *productos,int n){
    FILE *archivo;
    int i=0;
    //system("cls");

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Productos.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Productos.txt", directorio);

    archivo = fopen(ruta_relativa, "w");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir Productos.txt\n");
        perror("fopen");
    }
    else{
        do{
            fprintf(archivo,"%i-",(productos+i)->id_prod);
            fprintf(archivo,"%s-",(productos+i)->descripcion_prod);
            fprintf(archivo,"%i-",(productos+i)->id_categ);
            fprintf(archivo,"%i-",(productos+i)->id_gestor);
            fprintf(archivo,"%i-",(productos+i)->stock);
            fprintf(archivo,"%i-",(productos+i)->entrega);
            fprintf(archivo,"%.2f\n",(productos+i)->precio);
            i++;
        }while(i!=n-1);
    }
    fclose(archivo);// Cerrar el fichero
}

//cabecera: int num_categ();
//precondicion: 
//poscondicion: devuelve el numero de categorias que existen
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

//cabecera: int num_prod();
//precondicion: 
//poscondicion: devuelve el numero de productos que existen
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

//cabecera: int num_ped();
//precondicion: 
//poscondicion: devuelve el numero de productos que existen
int num_ped(){
    int num_pedidos=0;
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
    sprintf(ruta_relativa, "%s/DATA/ProductosPedido.txt", directorio);

    archivo = fopen(ruta_relativa, "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir ProductosPedido.txt.\n");
        perror("fopen");
    }
    else{
        do{
            c=fgetc(archivo);
            if(c=='\n'||c==EOF)
                num_pedidos++;
        }while(c!=EOF);
    }
    fclose(archivo);// Cerrar el fichero
    return num_pedidos;
}
