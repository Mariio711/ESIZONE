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

typedef struct{
    int dia;
    int mes;
    int ano;
}fecha;

typedef struct{
    int id;
    char id_descuento[10];
    fecha fecha_inicial;
    fecha fecha_limite;
    char estado_dc;
}desclient_estr;

typedef struct{
    char id_descuento[10];
    char descripcion[50];
    char tipo[8];
    char estado_d;
    float importe;
    char aplicabilidad[10];
}descuentos_estr;

void inicio_cliente(int);
int num_clien();
int num_descuentos();
int num_desclientes();

void descarga_clientes(cliente_estr *,int);
void carga_clientes(cliente_estr *,int);
void iniciar_descuentos(descuentos_estr [],int);
void iniciar_desclientes(desclient_estr [],int);

void bienvenida_clien(cliente_estr *,int);
void perfil(cliente_estr *,int);

void descuentos(cliente_estr *,int);

void mod_nom_clien(cliente_estr *,int);
void mod_dir_clien(cliente_estr *,int);
void mod_email_clien(cliente_estr *,int);
void mod_contr_clien(cliente_estr *,int);
void cartera(cliente_estr *,int);

#endif
