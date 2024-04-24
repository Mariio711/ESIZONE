#ifndef PROVEEDOR_H
#define PROVEEDOR_H

typedef struct {
    char Id_empresa[5];
    char Nombre[21];
    char email[31];
    char Contrasena[16];
    char Perfil_usuario[13];
}usuarios;

void inicio_prov(int);
void bienvenida_prov(usuarios *,int);
void perfil_prov(usuarios *,int);

void mod_nom_prov(usuarios *,int);
void mod_email_prov(usuarios *,int);
void mod_contr_prov(usuarios *,int);

void carga_prov(usuarios *,int);
void descarga_prov(usuarios *,int);
int num_prov();

#endif
