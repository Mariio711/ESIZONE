//en este modulo se encuentra la funcion que se encarga de gestionar los usuarios, cargar los txt en los struct y la autenticacion del usuario

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>


#include "usuarios.h"
#include "func_aux.h"
#include "clientes.h"

//cabecera: void menu_login(usuarios vUsuarios, int nUsuarios)
//precondicion: recibe un puntero doble a estructuras de usuarios (usuarios) y un puntero a entero (int) que representa el número de usuarios.
//postcondicion: muestra un menú de inicio de sesión y registro de usuarios, y según la opción elegida, realiza las acciones correspondientes.

void menu_login(usuarios **vUsuarios, int *nUsuarios, cliente_estr **vClientes, int *nClientes){

    cargarusuarios(vUsuarios, nUsuarios);
    ficheros(vClientes, nClientes);

    system ("cls"); //limpia la terminal
    system ("COLOR B0"); //cambia color terminal a fondo celeste y letras negras
    int aux;

    int resp=0;
    while (resp!=1 && resp!=2 && resp!=3){
        printf("\n\n");
        printf("%40s", "███████╗░██████╗██╗███████╗░█████╗░███╗░░██╗\n");
        printf("%40s", "██╔════╝██╔════╝██║╚════██║██╔══██╗████╗░██║\n");
        printf("%40s", "█████╗░░╚█████╗░██║░░███╔═╝██║░░██║██╔██╗██║\n");
        printf("%40s", "██╔══╝░░░╚═══██╗██║██╔══╝░░██║░░██║██║╚████║\n");
        printf("%40s", "███████╗██████╔╝██║███████╗╚█████╔╝██║░╚███║\n");
        printf("%40s", "╚══════╝╚═════╝░╚═╝╚══════╝░╚════╝░╚═╝░░╚══╝\n");
        printf ("\n\n");
        printf ("\tSeleccione una opción:\n\n\t1.Iniciar sesión\n\t2.Registrarse\n\t3.Salir\n\n\tOpción: ");
        if (scanf("%i", &resp) != 1 || (resp!=1 && resp!=2 && resp!=3)) {                      // Si scanf no pudo leer un número entero
            error_scanf();
        }

    }
        int control=0;
    switch (resp)
    {
    case 1:

        while(control==0){
            control = aut_usuarios (vUsuarios, nUsuarios, vClientes, nClientes);
        }
    break;
    case 2:
        aux=0;
        aux=registro_usuario(vClientes, nClientes);
        system ("cls");                                                                                         //Raya: de  aux=registro_usuario(vUsuarios, nUsuarios, "usuario");
        printf ("\n\n\tUsuario registrado correctamente! Pulse cualquier tecla para ir a iniciar sesion");      //a control=aut_usuarios (vUsuarios, nUsuarios); lo he añadido
        fflush (stdin);                                                                                         // para que funcione bien pero no es perfecto
        getchar ();
        control=aut_usuarios (vUsuarios, nUsuarios, vClientes, nClientes);
    break;
    case 3:
    break;
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

int aut_usuarios (usuarios **vUsuarios, int *nUsuarios, cliente_estr **vClientes, int *nClientes){
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
    
    for (i=0; i<*nClientes; i++){
        if(strcmp((*vClientes)[i].correo,email)==0){
            existe=1;
            if(strcmp((*vClientes)[i].clave,contrasena)==0){
                bienvenida((*vClientes)[i]);
                return 1;
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


//cabecera: int registro_usuario(usuarios **vUsuarios, int *n)
//precondicion: recibir un puntero a un array dinámico de estructuras usuarios, y un puntero al número de usuarios totales (n)
//postcondicion: retorna el índice del nuevo usuario añadido al array dinámico de estructuras usuarios

int registro_usuario(usuarios **vUsuarios, int *n){
    *vUsuarios = realloc(*vUsuarios, (*n + 1) * sizeof(usuarios));
    printf("\n\tIntroduce el Id de la empresa: ");
    modif((*vUsuarios)[*n].Id_empresa, 4);
    printf("\n\tIntroduce el nombre de la empresa: ");
    modif((*vUsuarios)[*n].Nombre, 20);
    printf("\n\tIntroduce el email: ");
    modif((*vUsuarios)[*n].email, 30);
    printf("\n\tIntroduce la contraseña: ");
    modif((*vUsuarios)[*n].Contrasena, 15);
    printf("\n\tIntroduce el perfil de usuario: ");
    modif((*vUsuarios)[*n].Perfil_usuario, 12);
    (*n)++;
    guardarusuarios(*vUsuarios, *n);
    return 1;
}

//cabecera: int guardarusuarios(usuarios *u, int tam)
//precondicion: recibir un puntero a un array de estructuras usuarios y un entero con el número de usuarios del array
//postcondicion: escribe en un fichero la lista completa de usuarios con sus datos. Si no se puede acceder al fichero, se imprime un mensaje de error y se sale del programa.
// de los usuarios en un txt Los campos, separados por guiones, son: Id_empresa, Nombre, email, Contrasena y Perfil_usuario.

int guardarusuarios(usuarios *u, int tam){
    FILE *f;
    int i;
    f = fopen("usuarios.txt", "w");
    if (f == NULL) {
        printf("Error al abrir el fichero\n");
        exit(1);
    }
    for (i = 0; i < tam; i++) {
        fprintf(f, "%s-%s-%s-%s-%s\n", u[i].Id_empresa, u[i].Nombre, u[i].email, u[i].Contrasena, u[i].Perfil_usuario);
    }
    fclose(f);
    return 1;
}

//cabecera: int modif(char *modificador, int N)
//precondicion: modificador es un puntero a una cadena de caracteres y N es un entero que indica la longitud máxima de la cadena. modificador debe tener al menos N+1 elementos.
//postcondicion: La función lee una cadena de caracteres desde el teclado y la almacena en modificador, siempre y cuando la cadena no supere la longitud máxima indicada por N.
// La función retorna 1 si la cadena se pudo modificar y 0 en caso contrario.
int modif(char *modificador, int N){

    char aux[50];
    int auxi, control=0;;

    do{
        leer_string(aux, 50);
        
        if(strlen(aux)>N){
            control=1;
            printf("\n\tLa cadena no puede tener mas de %i caracteres", N);
            printf("\n\tIntroduce de nuevo (max %i caracteres): ", N);
        }else{
            control=0;
        }
        
    }while(control==1);

    control_modif(modificador, aux, N);
}

//cabecera: void control_guardado_user(int control, int *nUsuarios, usuarios **vUsuarios)
//precondicion: control es un entero que indica si se realizaron cambios en el perfil del usuario,
// nUsuarios es un puntero al número total de usuarios almacenados y vUsuarios es un puntero a un vector de estructuras de tipo usuarios.
// El vector vUsuarios debe tener al menos *nUsuarios elementos.
//postcondicion: La función guarda los cambios realizados en el perfil del usuario en el archivo "usuario.txt" si se detectaron cambios 
//(es decir, si control es igual a 1) y muestra un mensaje en caso contrario.
void control_guardado_user(int control, int *nUsuarios, usuarios **vUsuarios){
    if (control==1)
    guardarusuarios((*vUsuarios), (*nUsuarios));
    else
    printf("\n\tNo se han guardado los datos");
}

