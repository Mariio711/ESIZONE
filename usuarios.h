/* Identificador de la empresa administradora o proveedora (Id_empresa), 4 dígitos.
o Nombre de la empresa (Nombre), sería ESIZON si es administrador, 20 caracteres máximo.
o Email (email), 30 caracteres máximo, será usado como nombre de usuario para el acceso a la plataforma.
o Contraseña para acceder al sistema (Contraseña), con 15 caracteres máximo. o Perfil del usuario (Perfil_usuario): «administrador» o «proveedor».*/

#ifndef USUARIOS_H
#define USUARIOS_H

#include "Clientes.h"

#define N_id_empresa 5
#define N_Nombre 21
#define N_email 31
#define N_Contrasena 16
#define N_Perfil_usuario 13


typedef struct usuarios{
    char Id_empresa[5];
    char Nombre[21];
    char email[31];
    char Contrasena[16];
    char Perfil_usuario[13];
}usuarios;


void menu_login(usuarios **, int*, cliente_estr **, int*);
int aut_usuarios (usuarios **, int*, cliente_estr **, int*);
void cargarusuarios(usuarios **,int *);
void cargarclientes(cliente_estr **, int *);
int registro_usuario (cliente_estr **, int *);
int guardarusuarios (usuarios *, int);
int modif(char*, int);
void control_guardado_user(int control, int *nUsuarios, usuarios **vUsuarios);
#endif