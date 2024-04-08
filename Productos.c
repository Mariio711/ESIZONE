#include <stdio.h>
#include <stdlib.h>
#include "Productos.h"

///inicio_prod
//cabecera: void inicio_prod(int);
//precondicion: recibe un entero para saber si entra un cliente o un provedor
//poscondicion:  si entra en el entero (1) da paso a prod_client y si entra (2) a prod_prov
int main(){//void inicio_prod(int palanca)
    int palanca=1;
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
    char categoria[38];
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

        FILE*f;
        if((f=fopen("Categorias.txt","r"))!=NULL){//-----------------------
            do{
                fscanf(f,"%s",categoria);
                printf("\n%s",categoria);
            }while(feof(f)==0);
            
            fclose(f);
        }
        else
            printf("el fichero Categorias no se pudo abrir");

        printf("Seleccione categoria: ");
        do{
            scanf("%i",&elec_prod_categ);
            if(elec_prod_categ<1||elec_prod_categ>10)
                printf("Categoria no valida, intentelo de nuevo:");           //control de entrada
            fflush(stdin);
        }while(elec_prod_categ<1||elec_prod_categ>10);

        //switch(elec_prod_categ)--------------------------
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
