#ifndef CLIENTES_H
#define CLIENTES_H

typedef struct{
    int id;
    char nombre[20];
    char direccion[50];
    char localidad[20];
    char provincia[20];
    char correo[30];
    char clave[15];
    float dinero;
}cliente_estr;

void ficheros(int,cliente_estr *);
void bienvenida(cliente_estr *);

void perfil(cliente_estr *);
void productos();
void descuentos();
void pedidos();
void devolucion();

void mod_nom(cliente_estr *);
void mod_dir(cliente_estr *);
void mod_email(cliente_estr *);
void mod_contr(cliente_estr *);
void cartera(cliente_estr *);

#endif
