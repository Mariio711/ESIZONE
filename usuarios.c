//en este modulo se encuentra la funcion que se encarga de gestionar los usuarios, cargar los txt en los struct y la autenticacion del usuario

#include <stdio.h>
#include <string.h>
#include "usuarios.h"

//cabecera: void menu_login(usuarios **, int*);
//precondicion: se le pasa un puntero a un puntero de struct usuarios y un puntero a un entero
//postcondicion: se encarga de llamar a la funcion aut_usuarios y si esta devuelve 1 
//llama a menu_usuarios si es cliente lla a a menu_cliente, si es administrador llama a menu_administrador, si es proveedor llama a menu_proveedor, si es trsnsportista llama a menu_transportista

void menu_login(usuarios **vUsuarios, int *nUsuarios){
    int aut;
    aut=aut_usuarios(vUsuarios,nUsuarios);
    if(aut==1){
        menu_usuarios(vUsuarios,*nUsuarios,nUsuarios);
    }
}

//cabecera: void cargarusuarios(usuarios **,int *);
//precondicion: se le pasa un puntero a un puntero de struct usuarios y un puntero a un entero
//postcondicion: se encarga de cargar los datos de los usuarios en un txt Los campos, separados por guiones, son: Id_empresa, Nombre, email, Contrasena y Perfil_usuario.

void cargarusuarios(usuarios **vUsuarios, int *nUsuarios) {
    FILE *f;
    int i = 0;
    f = fopen("usuarios.txt", "r");
    if (f == NULL) {
        return;
    }
    *vUsuarios = NULL;
    while (1) {
        *vUsuarios = realloc(*vUsuarios, (i + 1) * sizeof(usuarios));
        if (fscanf(f, "%s-%s-%s-%s-%s", (*vUsuarios)[i].Id_empresa, (*vUsuarios)[i].Nombre, (*vUsuarios)[i].email, (*vUsuarios)[i].Contrasena, (*vUsuarios)[i].Perfil_usuario) == EOF) {
            break;
        }
        i++;
    }
    *nUsuarios = i;
    fclose(f);
}

//cabecera: int aut_usuarios (usuarios **, int*);
//precondicion: se le pasa un puntero a un puntero de struct usuarios y un puntero a un entero
//postcondicion: se encarga de autenticar al usuario, si el usuario es correcto devuelve 1, si no 0

int aut_usuarios (usuarios **vUsuarios, int *nUsuarios){
    system ("cls");
    system ("COLOR B0");

    int i;
    int existe=0;
    char email[31], contrasena[16];
    printf("Introduzca su email:");
    scanf("%s",email);
    printf("Introduzca su contrasena:");
    scanf("%s",contrasena);

    for(i=0;i<*nUsuarios;i++){
        if(strcmp((*vUsuarios)[i].email,email)==0){
            existe=1;
            if(strcmp((*vUsuarios)[i].Contrasena,contrasena)==0){
                if(strcmp((*vUsuarios)[i].Perfil_usuario,"administrador")==0){
                    menu_admin(vUsuarios, i, nUsuarios);
                }
                if(strcmp((*vUsuarios)[i].Perfil_usuario,"proveedor")==0){
                    int control=1;
                    while (control==1){
                        control=menu_usuarios(vUsuarios, i, nUsuarios);
                    }
                    if (control==2){
                        return 0;
                    }
                }
            } else {
                puts ("\t\tERROR: Contraseña incorrecta, intentalo de nuevo");
                printf("\n\tPulsa ENTER para continuar...\n");
                fflush(stdin);
                getchar();
                system("cls");
                return 0;
            }
        }
    }

    if (existe==0){
        int auxnus;
        do{
            printf("\n\t\tERROR: El usuario no esta registrado, introduce otro usuario valido(1) o registrese(2): ");
            scanf("%d" ,&auxnus);
        }while (auxnus!=1 && auxnus!=2);

        switch(auxnus){
            case 1:
                return 0;
            break;
            case 2:
                while(auxnus==0){
                    auxnus=registro_usuario(vUsuarios, nUsuarios, email);
                }
                return 0;
            break;
        }
    }
    return 1;
}


//cabecera: int registro_usuario (usuarios **, int *, char *);
//precondicion: se le pasa un puntero a un puntero de struct usuarios, un puntero a un entero y un puntero a un char
//postcondicion: se encarga de registrar un usuario, si el usuario ya existe devuelve 0, si no 1

int registro_usuario (usuarios **vUsuarios, int *nUsuarios, char *email){
    int i;
    for(i=0;i<*nUsuarios;i++){
        if(strcmp(vUsuarios[i]->email,email)==0){
            return 0;
        }
    }
    vUsuarios[*nUsuarios]=(usuarios *)malloc(sizeof(usuarios));
    strcpy(vUsuarios[*nUsuarios]->email,email);
    printf("Introduzca su contrasena:");
    scanf("%s",vUsuarios[*nUsuarios]->Contrasena);
    printf("Introduzca su nombre:");
    scanf("%s",vUsuarios[*nUsuarios]->Nombre);
    printf("Introduzca su Id_empresa:");
    scanf("%s",vUsuarios[*nUsuarios]->Id_empresa);
    printf("Introduzca su perfil de usuario:");
    scanf("%s",vUsuarios[*nUsuarios]->Perfil_usuario);
    *nUsuarios=*nUsuarios+1;
    return 1;
}

//cabecera: int guardarusuarios (usuarios *, int);
//precondicion: se le pasa un puntero a un struct usuarios y un entero
//postcondicion: se encarga de guardar los datos de los usuarios en un txt Los campos, separados por guiones, son: Id_empresa, Nombre, email, Contrasena y Perfil_usuario.

int guardarusuarios (usuarios *vUsuarios, int n){
    FILE *f;
    int i;
    f=fopen("usuarios.txt","w");
    if(f==NULL){
        return 0;
    }
    for(i=0;i<n;i++){
        fprintf(f,"%s-%s-%s-%s-%s\n",vUsuarios[i].Id_empresa,vUsuarios[i].Nombre,vUsuarios[i].email,vUsuarios[i].Contrasena,vUsuarios[i].Perfil_usuario);
    }
    fclose(f);
    return 1;
}

