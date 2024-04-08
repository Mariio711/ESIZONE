#ifndef PRODUCTOS_H
#define PRODUCTOS_H

typedef struct{
    int id_prod;//id propia
    char descripcion_prod[50];
    int id_categ;//id de la categoria
    int id_gestor;//id del provedor
    int stock;
    int entrega;//numero de dias maximo entre que se pide y llega
    int precio;
}producto;

typedef struct{
    int id_categ;//id de la categoria
    char descripcion_categ[50];
}categ;

//void inicio_prod(int);
void prod_client();
void prod_prov();
#endif