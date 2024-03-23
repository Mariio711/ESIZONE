#include <stdio.h>
#include <stdlib.h>

#include "admin.h"
#include "login.h"
#include "func_aux.h"

//cabecera: void perfiladmin(usuarios **vUsuarios, int *nUsuarios)
//precondicion: vUsuarios es un puntero a un puntero de estructura de tipo usuarios, nUsuarios es un puntero a entero
//postcondicion: muestra el perfil del administrador
void menu_admin(usuarios **vUsuarios, int n){
    int opcion, control = 1;

    do{
        system("cls");
        layer_esizon();
        iguales(("Menu administrador"),'\0');
        printf("Menu administrador\n");
        iguales(("Menu administrador"),'\0');
        printf("1. Perfil\n");
        printf("2. Clientes\n");
        printf("3. Proveedores\n");
        printf("4. Productos\n");
        printf("5. Categorias\n");
        printf("6. Pedidos\n");
        printf("7. Transportista\n");
        printf("8. Descuentos\n");
        printf("9. devoluciones\n");
        printf("10. Salir\n");
        printf("Opcion: ");
        if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 10){
            error_scanf();
        }
        switch(opcion){
            case 1:
                control = perfiladmin(vUsuarios, n);
                break;
            case 2:
                cliente_estr **vClientes;
                int nClientes;
                cargarclientes(vClientes, &nClientes);
                control = menu_clientes(vClientes, nClientes);
                break;
            case 3:
                //cargo proveedores
                control = menu_proveedores(/*falta*/);
                break;
            case 4:
                //cargo productos
                control = menu_productos(/*falta*/);
                break;
            case 5:
                //cargo categorias
                control = menu_categorias( /*falta*/);
                break;
            case 6:
                //cargo pedidos
                control = menu_pedidos( /*falta*/);
                break;
            case 7:
                //cargo transportista
                control = menu_transportista( /*falta*/);
                break;
            case 8:
                //cargo descuentos
                control = menu_descuentos( /*falta*/);
                break;
            case 9:
                //cargo devoluciones
                control = menu_devoluciones( /*falta*/);
                break;
            case 10:
                control = 0;
                break;
        }
    }while(control != 0);
}

//cabecera: int perfiladmin(usuarios **vUsuarios, int *nUsuarios)
//precondicion: vUsuarios es un puntero a un puntero de estructura de tipo usuarios, nUsuarios es un puntero a entero
//postcondicion: muestra el perfil del administrador dando opcion a modificarlo
int perfiladmin(usuarios **vUsuarios, int n){
    int opcion, control = 1;
    do{
        system("cls");
        layer_esizon();
        iguales(("Perfil administrador"),'\0');
        printf("Perfil administrador\n");
        iguales(("Perfil administrador"),'\0');
        printf("1. Ver perfil\n");
        printf("2. Modificar perfil\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 3){
            error_scanf();
        }
        switch(opcion){
            case 1:
                verperfiladmin(vUsuarios, n);
                break;
            case 2:
                modificarperfiladmin(vUsuarios, n);
                break;
            case 3:
                control = 0;
                break;
        }
    }while(control != 0);
    return control;
}

//cabecera: void verperfiladmin(usuarios **vUsuarios, int *nUsuarios)
//precondicion: vUsuarios es un puntero a un puntero de estructura de tipo usuarios, nUsuarios es un puntero a entero
//postcondicion: muestra el perfil del administrador
void verperfiladmin(usuarios **vUsuarios, int n){
    system("cls");
    layer_esizon();
    iguales(("Perfil administrador"),'\0');
    printf("Perfil administrador\n");
    iguales(("Perfil administrador"),'\0');
    printf("Id empresa: %s\n", (*vUsuarios)->Id_empresa);
    printf("Nombre: %s\n", (*vUsuarios)->Nombre);
    printf("Email: %s\n", (*vUsuarios)->email);
    printf("Contrasena: %s\n", (*vUsuarios)->Contrasena);
    printf("Perfil usuario: %s\n", (*vUsuarios)->Perfil_usuario);
    printf("\n");
    printf("Pulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada       
    getchar();      //pausa
}

//cabecera: void modificarperfiladmin(usuarios **vUsuarios, int *nUsuarios)
//precondicion: vUsuarios es un puntero a un puntero de estructura de tipo usuarios, nUsuarios es un puntero a entero
//postcondicion: modifica el perfil del administrador
void modificarperfiladmin(usuarios **vUsuarios, int n){
    char aux[100];
    int opcion;
    system("cls");
    layer_esizon();
    iguales(("Modificar perfil administrador"),'\0');
    printf("Modificar perfil administrador\n");
    iguales(("Modificar perfil administrador"),'\0');
    printf("1 - Id empresa: %s\n", (*vUsuarios)->Id_empresa);
    printf("2 - Nombre: %s\n", (*vUsuarios)->Nombre);
    printf("3 - Email: %s\n", (*vUsuarios)->email);
    printf("4 - Contrasena: %s\n", (*vUsuarios)->Contrasena);
    printf("5 - Perfil usuario: %s\n", (*vUsuarios)->Perfil_usuario);
    printf("6 - Salir\n");
    printf("\n ¿Que campo desea modificar? 3, 4 o 6: ");
    if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 5){
        error_scanf();
    }
    switch(opcion){
        case 3:
            printf("Introduce el nuevo Email: ");
            modif(&(*vUsuarios)->email, N_email);
            break;
        case 4:
            printf("Introduce la nueva Contrasena: ");
            modif(&(*vUsuarios)->Contrasena, N_Contrasena);
            break;
        case 6:
            break;
    }
    printf("\n");
    printf("Pulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada       
    getchar();      //pausa
}