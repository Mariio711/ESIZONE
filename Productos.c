#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Productos.h"
#include <libgen.h> // Para dirname()

///inicio_prod
//cabecera: void inicio_prod(int);
//precondicion: recibe un entero para saber si entra un cliente o un provedor
//poscondicion:  si entra en el entero (1) da paso a prod_client y si entra (2) a prod_prov
void inicio_prod(int palanca){
    system("cls");
    if(palanca==1)
        prod_client();
    if(palanca==2)
        prod_prov();
    return 0;
}


/*cliente
La plataforma permitirá al cliente realizar consultas de productos tanto por categoría como por
nombre.*/
void prod_client(){
    int elec_prod_client,elec_prod_categ;
    char descripcion_prod_introducida[50];
    char categoria[35];
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
        // Obtener el directorio padre de la ruta actual                            ///como el fichero Clientes.txt esta en una carpeta
        char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
        // Construir la ruta del archivo relativa a la ubicación del ejecutable
        char ruta_relativa[1024];
        sprintf(ruta_relativa, "%s/DATA/Categorias.txt", directorio);

        archivo = fopen(ruta_relativa, "r");

        // Verificar si el archivo se abrió correctamente
        if (archivo == NULL) {
            printf("Error al abrir el archivo.\n");
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
            case 1: strcpy(categoria,"Bricolaje y herramientas");break;
            case 2: strcpy(categoria,"Equipaje y accesorios de viaje");break;
            case 3: strcpy(categoria,"Tecnologia");break;
            case 4: strcpy(categoria,"Deportes y aire libre");break;
            case 5: strcpy(categoria,"Electrodomesticos");break;
            case 6: strcpy(categoria,"Juguetes y juegos");break;
            case 7: strcpy(categoria,"Jardin");break;
            case 8: strcpy(categoria,"Libros");break;
            case 9: strcpy(categoria,"Ropa");break;
            case 10: strcpy(categoria,"Belleza");break;
        }
        printf("\nCategoria seleccionada:%s",categoria);
        }
    }
}

/*-------------------------------------------------------------------
provedor
El usuario proveedor podrá realizar las mismas acciones que el administrador pero sólo sobre
sus propios productos. Es decir, podrá acceder a la información de sus productos que estén
dados de alta en la plataforma. Sobre ellos podrá realizar altas, bajas, búsquedas, listados y
modificaciones de productos.*/
void prod_prov(){

}
