#ifndef ADMIN_H
#define ADMIN_H

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

void menu_admin(usuarios **, int);


#endif // ADMIN_H