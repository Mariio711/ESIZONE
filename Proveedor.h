#ifndef PROVEEDOR_H
#define PROVEEDOR_H

typedef struct{
    int id_empresa;
    char nombre_empresa[20];
    char correo[30];
    char clave[15];
    char perfil_usuario[13];
}usuarios;

//void inicio_prov();
void bienvenida_prov(usuarios *,int);
void perfil_prov(usuarios *,int);

void mod_nom_prov(usuarios *,int);
void mod_email_prov(usuarios *,int);
void mod_contr_prov(usuarios *,int);

void carga_prov(usuarios *,int);
void descarga_prov(usuarios *,int);
int num_prov();

#endif
