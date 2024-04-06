#ifndef CLIENTES_H
#define CLIENTES_H

typedef struct{
    int id_empresa;
    char nombre_empresa[20];
    char correo[30];
    char clave[15];
    char perfil_usuario[13];
}provedor_estr;

void bienvenida(provedor_estr *);
void pedidos();
void productos();
#endif
