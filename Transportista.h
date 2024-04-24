#ifndef TRANSPORTISTA_H
#define TRANSPORTISTA_H


#define N_id 5
#define N_nombre 21
#define N_email 31
#define N_contra 16
#define N_nom_empresa 21
#define N_ciudad 21

typedef struct{
    int id;
    char nombre[N_nombre];
    char email[N_email];
    char contra[N_contra];
    char nom_empresa[N_nom_empresa];
    char ciudad[N_ciudad];
} transportista_estr;

void intro_transportista(transportista_estr *);
void menu_transporte(transportista_estr *, int );
void menu_perfil();
void perfil_transportista(transportista_estr *, int );
void mostrar_info_transportista(transportista_estr *, int );
int contar_lineas_transportista();
void menu_mod();
void mod_transporte(transportista_estr *, int );
void mod_nom(transportista_estr *, int );
void mod_ciudad(transportista_estr *, int );
void mod_email(transportista_estr *, int );
void mod_contr(transportista_estr *, int );
void seleccion_tras_mod(transportista_estr *, int );
void carga_transporte(transportista_estr *);
void mostrar_poblaciones(char* );
void descarga_transporte(transportista_estr *);

#endif