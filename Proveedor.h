#ifndef CLIENTES_H
#define CLIENTES_H

typedef struct{
    int id_empresa;
    char nombre_empresa[20];
    char correo[30];
    char clave[15];
    char perfil_usuario[13];
}provedor_estr;

//void inicio_prov();
void bienvenida_prov(provedor_estr *);
void perfil_prov(provedor_estr *);
void mod_nom_prov(provedor_estr *);
void mod_email_prov(provedor_estr *);
void mod_contr_prov(provedor_estr *);
void pedidos_prov();
void productos_prov();
void ficheros_prov(int,provedor_estr *);
#endif
