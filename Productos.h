#ifndef PRODUCTOS_H
#define PRODUCTOS_H

typedef struct{
    int id_prod;//id propia
    char descripcion_prod[50];
    int id_categ;//id de la categoria
    int id_gestor;//id del provedor
    int stock;
    int entrega;//numero de dias maximo entre que se pide y llega
    float precio;
}producto;

typedef struct{
    int id_categ;
    char descripcion_categ[50];
}categ;

//void inicio_prod(int);
float prod_clien(float);
void prod_prov(int);

void busqueda(int,int,char[],producto *,int,float *);
void comprar(float *,producto [],int,producto *,int);
void hacer_pedido(int,int,int,float);

void ver_prod(producto *,int,int);
void implementar_prod(producto *,int,int);
void editar_prod(producto *,int,int);

void descarga_categ(categ *,int);
void descarga_prod(producto *,int);
void carga_prod(producto *,int);
int num_categ();
int num_prod();
int num_ped();
#endif