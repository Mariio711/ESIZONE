#ifndef ADMIN_H
#define ADMIN_H

#define N_id_empresa 5
#define N_Nombre 21
#define N_email 31
#define N_Contrasena 16
#define N_Perfil_usuario 13

typedef struct {
    char Id_empresa[5];
    char Nombre[21];
    char email[31];
    char Contrasena[16];
    char Perfil_usuario[13];
}usuarios;

int menu_admin(usuarios **vUsuarios, int n);


#endif // ADMIN_H