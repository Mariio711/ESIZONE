#ifndef USUARIOS_H
#define USUARIOS_H

#include "Proveedor.h"
#include "Clientes.h"
#include "Transportista.h"

void menu_login();
void cargarusuarios(usuarios **,int *);
int aut_usuarios (usuarios **, int *, cliente_estr **, int *, transportista_estr **, int *);
int registro_usuario (cliente_estr **, int *);
int registro_admin_o_prov (usuarios **, int *, char perfil[20]);
int guardarusuarios(usuarios *, int);
void control_guardado_user(int, int *, usuarios **);


#endif