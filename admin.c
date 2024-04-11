#include <stdio.h>
#include <stdlib.h>

#include "admin.h"
#include "login.h"
#include "func_aux.h"
#include "clientes.h"
#include "Proveedor.h"
#include "Productos.h"
#include "Pedidos.h"

//definicion de funciones
int perfiladmin(usuarios **vUsuarios, int n);
void verperfiladmin(usuarios **vUsuarios, int n);
void modificarperfiladmin(usuarios **vUsuarios, int n);


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
                provedor_estr *vProveedores;
                int nProveedores;
                cargarproveedores(vProveedores, &nProveedores);
                control = menu_proveedores(vProveedores, nProveedores);
                break;
            case 4:
                //cargo productos
                producto *vProductos;
                int nProductos;
                ficheros_prod( vProductos, &nProductos);
                control = menu_productos(vProdu);
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

//cabecera: int menu_clientes(cliente_estr **vClientes, int nClientes)
//precondicion: vClientes es un puntero a un puntero de estructura de tipo cliente_estr, nClientes es un entero
//postcondicion: muestra el menu de clientes

int menu_clientes(cliente_estr **vClientes, int nClientes){
    int opcion, control = 1;
    do{
        system("cls");
        layer_esizon();
        iguales(("Menu clientes"),'\0');
        printf("Menu clientes\n");
        iguales(("Menu clientes"),'\0');
        printf("1. Ver clientes\n");
        printf("2. Modificar clientes\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 3){
            error_scanf();
        }
        switch(opcion){
            case 1:
                verclientes(vClientes, nClientes);
                break;
            case 2:
                modificarclientes(vClientes, nClientes);
                break;
            case 3:
                control = 0;
                break;
        }
    }while(control != 0);
    return control;
}

//cabecera: void verclientes(cliente_estr **vClientes, int nClientes)
//precondicion: vClientes es un puntero a un puntero de estructura de tipo cliente_estr, nClientes es un entero
//postcondicion: muestra los clientes

void verclientes(cliente_estr **vClientes, int nClientes){
    int i;
    system("cls");
    layer_esizon();
    iguales(("Clientes"),'\0');
    printf("Clientes\n");
    iguales(("Clientes"),'\0');
    for(i = 0; i < nClientes; i++){
        printf("Id: %d\n", (*vClientes)->id);
        printf("Nombre: %s\n", (*vClientes)->nombre);
        printf("Direccion: %s\n", (*vClientes)->direccion);
        printf("Localidad: %s\n", (*vClientes)->localidad);
        printf("Provincia: %s\n", (*vClientes)->provincia);
        printf("Correo: %s\n", (*vClientes)->correo);
        printf("Clave: %s\n", (*vClientes)->clave);
        printf("Dinero: %f\n", (*vClientes)->dinero);
        printf("\n");
        vClientes++;
    }
    printf("Pulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada       
    getchar();      //pausa
}

//cabecera: void modificarclientes(cliente_estr **vClientes, int nClientes)
//precondicion: vClientes es un puntero a un puntero de estructura de tipo cliente_estr, nClientes es un entero
//postcondicion: modifica los clientes

void modificarclientes(cliente_estr **vClientes, int nClientes){
    int i, opcion;
    char aux[100];
    system("cls");
    layer_esizon();
    iguales(("Modificar clientes"),'\0');
    printf("Modificar clientes\n");
    iguales(("Modificar clientes"),'\0');
    printf("Introduce el Id del cliente a modificar: ");
    if(scanf("%d", &opcion) != 1){
        error_scanf();
    }
    for(i = 0; i < nClientes; i++){
        if(opcion == (*vClientes)->id){
            printf("1 - Nombre: %s\n", (*vClientes)->nombre);
            printf("2 - Direccion: %s\n", (*vClientes)->direccion);
            printf("3 - Localidad: %s\n", (*vClientes)->localidad);
            printf("4 - Provincia: %s\n", (*vClientes)->provincia);
            printf("5 - Correo: %s\n", (*vClientes)->correo);
            printf("6 - Clave: %s\n", (*vClientes)->clave);
            printf("7 - Dinero: %f\n", (*vClientes)->dinero);
            printf("8 - Salir\n");
            printf("\n ¿Que campo desea modificar? 1, 2, 5, 6 u 8 (salir): ");
            if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 8){
                error_scanf();
            }
            switch(opcion){
                case 1:
                    mod_nom(*vClientes);
                    break;
                case 2:
                    mod_dir(*vClientes);
                    break;
                case 5:
                    mod_email(*vClientes);
                    break;
                case 6:
                    mod_contr(*vClientes);
                    break;
                case 7:
                    mod_cartera(*vClientes);
                    break;
                case 8:
                    break;
            }
        }
        vClientes++;
    }
    printf("\n");
    printf("Pulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada
    getchar();      //pausa
}
            
//cabecera: mod_cartera(cliente_estr *vClientes)
//precondicion: vClientes es un puntero a estructura de tipo cliente_estr
//postcondicion: modifica la cartera del cliente

void mod_cartera(cliente_estr *vClientes){
    float dinero;
    printf("Introduce el nuevo dinero: ");
    if(scanf("%f", &dinero) != 1){
        error_scanf();
    }
    vClientes->dinero = dinero;
}

//cabecera: menu_proveedores(provedor_estr **vProveedores, int nProveedores)
//precondicion: vProveedores es un puntero a un puntero de estructura de tipo provedor_estr, nProveedores es un entero
//postcondicion: muestra el menu de proveedores

int menu_proveedores(provedor_estr *vProveedores, int nProveedores){
    int opcion, control = 1;
    do{
        system("cls");
        layer_esizon();
        iguales(("Menu proveedores"),'\0');
        printf("Menu proveedores\n");
        iguales(("Menu proveedores"),'\0');
        printf("1. Ver proveedores\n");
        printf("2. Modificar proveedores\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 3){
            error_scanf();
        }
        switch(opcion){
            case 1:
                verproveedores(vProveedores, nProveedores);
                break;
            case 2:
                modificarproveedores(vProveedores, nProveedores);
                break;
            case 3:
                control = 0;
                break;
        }
    }while(control != 0);
    return control;
}

//cabecera: void verproveedores(provedor_estr **vProveedores, int nProveedores)
//precondicion: vProveedores es un puntero a un puntero de estructura de tipo provedor_estr, nProveedores es un entero
//postcondicion: muestra los proveedores

void verproveedores(provedor_estr *vProveedores, int nProveedores){
    int i;
    system("cls");
    layer_esizon();
    iguales(("Proveedores"),'\0');
    printf("Proveedores\n");
    iguales(("Proveedores"),'\0');
    for(i = 0; i < nProveedores; i++){
        printf("Id empresa: %d\n", (*vProveedores).id_empresa);
        printf("Nombre empresa: %s\n", (*vProveedores).nombre_empresa);
        printf("Correo: %s\n", (*vProveedores).correo);
        printf("Clave: %s\n", (*vProveedores).clave);
        printf("Perfil usuario: %s\n", (*vProveedores).perfil_usuario);
        printf("\n");
        vProveedores++;
    }
    printf("Pulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada       
    getchar();      //pausa
}

//cabecera: void modificarproveedores(provedor_estr **vProveedores, int nProveedores)
//precondicion: vProveedores es un puntero a un puntero de estructura de tipo provedor_estr, nProveedores es un entero
//postcondicion: modifica los proveedores

void modificarproveedores(provedor_estr *vProveedores, int nProveedores){
    int i, opcion;
    char aux[100];
    system("cls");
    layer_esizon();
    iguales(("Modificar proveedores"),'\0');
    printf("Modificar proveedores\n");
    iguales(("Modificar proveedores"),'\0');
    printf("Introduce el Id del proveedor a modificar: ");
    if(scanf("%d", &opcion) != 1){
        error_scanf();
    }
    for(i = 0; i < nProveedores; i++){
        if(opcion == (*vProveedores).id_empresa){
            printf("1 - Nombre empresa: %s\n", (*vProveedores).nombre_empresa);
            printf("2 - Correo: %s\n", (*vProveedores).correo);
            printf("3 - Clave: %s\n", (*vProveedores).clave);
            printf("4 - Perfil usuario: %s\n", (*vProveedores).perfil_usuario);
            printf("5 - Salir\n");
            printf("\n ¿Que campo desea modificar? 1, 2, 3, 4 o 5: ");
            if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 5){
                error_scanf();
            }
            switch(opcion){
                case 1:
                    mod_nom_prov(vProveedores);
                    break;
                case 2:
                    mod_email_prov(vProveedores);
                    break;
                case 3:
                    mod_contr_prov(vProveedores);
                    break;
                case 5:
                    break;
            }
        }
        vProveedores++;
    }
    printf("\n");
    printf("Pulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada
    getchar();      //pausa
}

//cabecera: menu_productos(producto *vProductos, int nProductos)
//precondicion: vProductos es un puntero a estructura de tipo producto, nProductos es un entero
//postcondicion: muestra el menu de productos

int menu_productos(producto *vProductos, int nProductos){
    int opcion, control = 1;
    do{
        system("cls");
        layer_esizon();
        iguales(("Menu productos"),'\0');
        printf("Menu productos\n");
        iguales(("Menu productos"),'\0');
        printf("1. Ver productos\n");
        printf("2. Modificar productos\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 3){
            error_scanf();
        }
        switch(opcion){
            case 1:
                verproductos(vProductos, nProductos);
                break;
            case 2:
                modificarproductos(vProductos, nProductos);
                break;
            case 3:
                control = 0;
                break;
        }
    }while(control != 0);
    return control;
}