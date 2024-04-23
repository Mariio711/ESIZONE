#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h> // Para dirname()
#include "Productos.h"

//cabecera: void inicio_prod(int);
//precondicion: recibe un entero para saber si entra un cliente o un provedor
//poscondicion:  si entra (1) da paso a prod_client y si entra (2) a prod_prov
int main(){//void inicio_prod(int palanca)
    system("cls");
    int palanca=1;//------
    int nc;
    nc=num_categ();
    categ *categoria=(categ*)calloc(nc,sizeof(categ));
    descarga_categ(categoria,nc);
    
    if(palanca==1)
        prod_client();
    if(palanca==2)
        prod_prov();
    return 0;
}

void prod_clien(){
    int elec_prod_client,elec_prod_categ;
    char descripcion_prod_introducida[50];
    char categoria_selec[35];
    FILE *archivo;
    char c;
    int i;
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
    }

    else{//busqueda por categoria
        system("cls");
        // Obtener la ruta del archivo fuente actual (__FILE__)
        char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
        strcpy(ruta_actual, __FILE__);
        // Obtener el directorio padre de la ruta actual                            ///como el fichero categorias.txt esta en una carpeta
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
        else{//imprimir el fichero
            for(i=0;(c = fgetc(archivo)) != EOF;i++){
                printf("%c",c);
            }

        printf("\n\nSeleccione categoria: ");
        do{
            scanf("%i",&elec_prod_categ);
            if(elec_prod_categ<1||elec_prod_categ>10)
                printf("Categoria no valida, intentelo de nuevo:");           //control de entrada
            fflush(stdin);
        }while(elec_prod_categ<1||elec_prod_categ>10);

        switch(elec_prod_categ){
            case 1: strcpy(categoria_selec,"Bricolaje y herramientas");break;
            case 2: strcpy(categoria_selec,"Equipaje y accesorios de viaje");break;
            case 3: strcpy(categoria_selec,"Tecnologia");break;
            case 4: strcpy(categoria_selec,"Deportes y aire libre");break;
            case 5: strcpy(categoria_selec,"Electrodomesticos");break;
            case 6: strcpy(categoria_selec,"Juguetes y juegos");break;
            case 7: strcpy(categoria_selec,"Jardin");break;
            case 8: strcpy(categoria_selec,"Libros");break;
            case 9: strcpy(categoria_selec,"Ropa");break;
            case 10: strcpy(categoria_selec,"Belleza");break;
        }
        printf("\nCategoria seleccionada:%s",categoria_selec);
        }
    }
}

busqueda(int palanca){//palanca=1 ->busqueda descripcion    palanca=2  ->categoria

}

/*-------------------------------------------------------------------
provedor
El usuario proveedor podrá realizar las mismas acciones que el administrador pero sólo sobre
sus propios productos. Es decir, podrá acceder a la información de sus productos que estén
dados de alta en la plataforma. Sobre ellos podrá realizar altas, bajas, búsquedas, listados y
modificaciones de productos.*/
void prod_prov(){

}

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
