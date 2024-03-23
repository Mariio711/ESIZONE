/* Identificador de la empresa administradora o proveedora (Id_empresa), 4 dígitos.
o Nombre de la empresa (Nombre), sería ESIZON si es administrador, 20 caracteres máximo.
o Email (email), 30 caracteres máximo, será usado como nombre de usuario para el acceso a la plataforma.
o Contraseña para acceder al sistema (Contraseña), con 15 caracteres máximo. o Perfil del usuario (Perfil_usuario): «administrador» o «proveedor».*/

#ifndef USUARIOS_H
#define USUARIOS_H

#include "Clientes.h"
#include "admin.h"


void menu_login(usuarios **, int*, cliente_estr **, int*);

#endif