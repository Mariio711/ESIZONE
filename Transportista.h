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

void intro_transportista(transportista_estr *transportista); //funcion dedicada a mostrar graficamente las opciones del menu
void menu_transporte(transportista_estr *transportista);//funcion para seleccionar la opcion del menu que querramos
void menu_perfil();
void perfil_transportista(transportista_estr *transportista);
void mostrar_info_transportista(transportista_estr *transportista);
void menu_mod();
void mod_transporte(transportista_estr *transportista);
void mod_nom(transportista_estr *transportista);
void mod_ciudad(transportista_estr *transportista);
void mod_email(transportista_estr *transportista);
void mod_contr(transportista_estr *transportista);
void ficheros(int aux,transportista_estr *transportista);

#endif