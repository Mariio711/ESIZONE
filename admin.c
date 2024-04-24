#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Clientes.h"
#include "func_aux.h"
#include "Proveedor.h"
#include "Productos.h"
#include "pedidos.h"
#include "Transportista.h"
#include "login.h"
#include "admin.h"

//definicion de funciones
//administrador
int perfiladmin(usuarios **vUsuarios, int n);
void verperfiladmin(usuarios **vUsuarios, int n);
void modificarperfiladmin(usuarios **vUsuarios, int n);

//clientes
int menu_clientes(cliente_estr **vClientes, int nClientes);
void verclientes(cliente_estr **vClientes, int nClientes);
void modificarclientes(cliente_estr **vClientes, int nClientes);
void mod_cartera(cliente_estr *vClientes, int n);

//proveedores
int menu_proveedores(usuarios *vProveedores, int nProveedores);
void verproveedores(usuarios *vProveedores, int nProveedores);
void modificarproveedores(usuarios *vProveedores, int nProveedores);

//productos
int menu_productos(producto *vProductos, int nProductos, categ *vCategorias, int nCategorias);
void verproductos(producto *vProductos, int nProductos, categ *vCategorias, int nCategorias);
void modificarproductos(producto *vProductos, int nProductos);
void mod_precio(producto *vProductos, int n);
void mod_stock(producto *vProductos, int n);
void mod_categ(producto *vProductos, int n);

//categorias
int menu_categorias(categ *vCategorias, int nCategorias);
void vercategorias(categ *vCategorias, int nCategorias);
void modificarcategorias(categ *vCategorias, int nCategorias);

//pedidos
int menu_pedidos(pedidos *vPedidos, int nPedidos);
void verpedidos(pedidos *vPedidos, int nPedidos);
void modificarpedidos(pedidos *vPedidos, int nPedidos);
void mod_id_cliente(pedidos *vPedidos, int n);
void mod_id_pedido(pedidos *vPedidos, int n);
void mod_fecha(pedidos *vPedidos, int n);
void mod_locker(pedidos *vPedidos, int n);

//transportista
int menu_transportista(transportista_estr *vTransportista, int nTransportista);
void vertransportista(transportista_estr *vTransportista, int nTransportista);
void modificartransportista(transportista_estr *vTransportista, int nTransportista);

//descuentos
int menu_descuentos(descuentos_estr *vDescuentos, int nDescuentos);
void verdescuentos(descuentos_estr *vDescuentos, int nDescuentos);
void modificardescuentos(descuentos_estr *vDescuentos, int nDescuentos);
void mod_tipo(descuentos_estr *vDescuentos, int n);
void mod_estado(char *);
void mod_aplicabilidad(descuentos_estr *vDescuentos, int n);
void mod_tipo(descuentos_estr *vDescuentos, int n);
void mod_importe(descuentos_estr *vDescuentos, int n);

//devoluciones
int menu_devoluciones(devolucion *vDevoluciones, int nDevoluciones);
void verdevoluciones(devolucion *vDevoluciones, int nDevoluciones);
void modificardevoluciones(devolucion *vDevoluciones, int nDevoluciones);
void mod_id_producto(devolucion *vDevoluciones, int nDevoluciones, int n);
void mod_fecha_devolucion(devolucion *vDevoluciones, int n);


//cabecera: void perfiladmin(usuarios **vUsuarios, int *nUsuarios)
//precondicion: vUsuarios es un puntero a un puntero de estructura de tipo usuarios, nUsuarios es un puntero a entero
//postcondicion: muestra el perfil del administrador
void menu_admin(usuarios **vUsuarios, int n){
    int opcion, control = 1;

    do{
        system("cls");
        layer_esizon();
        iguales(("Menu administrador"), NULL);
        printf("Menu administrador\n");
        iguales(("Menu administrador"), NULL);
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
            {
                cliente_estr *vClientes;
                int nClientes;
                descarga_clientes(vClientes, nClientes);
                control = menu_clientes(&vClientes, nClientes);
            break;
            }
            case 3:
            {
                usuarios *vProveedores;
                int nProveedores;
                carga_prov(vProveedores, nProveedores);
                control = menu_proveedores(vProveedores, nProveedores);
                break;
            }
            case 4:
            {
                producto *vProductos;
                int nProductos;
                categ *vCategorias;
                int nCategorias;
                descarga_prod( vProductos, &nProductos);
                ficheros_categ(vCategorias, &nCategorias);
                control = menu_productos(vProductos, nProductos, vCategorias, nCategorias);
                break;
            }
            case 5:
            {
                categ *vCategorias;
                int nCategorias;
                ficheros_categ(vCategorias, &nCategorias);
                control = menu_categorias(vCategorias, nCategorias);
                break;
            }
            case 6:
            {
                pedidos *vPedidos;
                int nPedidos;
                carga_txt_pedidos(vPedidos);
                control = menu_pedidos(vPedidos, nPedidos);
                break;
            }
            case 7:
            {
                transportista_estr *vTransportista;
                int nTransportista;
                ficheros_transp(vTransportista, &nTransportista);
                control = menu_transportista(vTransportista, nTransportista);
                break;
            }
            case 8:{
                descuentos_estr *vDescuentos;
                int nDescuentos;
                ficheros_descuentos(vDescuentos, &nDescuentos);

                control = menu_descuentos(vDescuentos, nDescuentos);
                break;}
            case 9:{
                devolucion *vDevoluciones;
                int nDevoluciones;
                ficheros_devoluciones(vDevoluciones, &nDevoluciones);
                control = menu_devoluciones(vDevoluciones, nDevoluciones);
            break;}
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
        iguales(("Perfil administrador"), NULL);
        printf("Perfil administrador\n");
        iguales(("Perfil administrador"), NULL);
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
    iguales(("Perfil administrador"), NULL);
    printf("Perfil administrador\n", NULL);
    iguales(("Perfil administrador"), NULL);
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
    iguales(("Modificar perfil administrador"), NULL);
    printf("Modificar perfil administrador\n");
    iguales(("Modificar perfil administrador"), NULL);
    printf("1 - Id empresa: %s\n", vUsuarios[n]->Id_empresa);
    printf("2 - Nombre: %s\n", vUsuarios[n]->Nombre);
    printf("3 - Email: %s\n", vUsuarios[n]->email);
    printf("4 - Contrasena: %s\n", vUsuarios[n]->Contrasena);
    printf("5 - Perfil usuario: %s\n", vUsuarios[n]->Perfil_usuario);
    printf("6 - Salir\n");
    printf("\n ¿Que campo desea modificar? 3, 4 o 6: ");
    if(scanf("%d", &opcion) != 1 || opcion == 3 || opcion == 4 || opcion == 6){
        error_scanf();
    }
    switch(opcion){
        case 3:
            printf("Introduce el nuevo Email: ");
            modif(vUsuarios[n]->email, N_email);
            break;
        case 4:
            printf("Introduce la nueva Contrasena: ");
            modif(vUsuarios[n]->Contrasena, N_Contrasena);
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
        iguales(("Menu clientes"), NULL);
        printf("Menu clientes\n");
        iguales(("Menu clientes"), NULL);
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
    iguales(("Clientes"), NULL);
    printf("Clientes\n");
    iguales(("Clientes"), NULL);
    for(i = 0; i < nClientes; i++){
        printf("Id cliente: %d\n", vClientes[i]->id);
        printf("Nombre: %s\n", vClientes[i]->nombre);
        printf("Direccion: %s\n", vClientes[i]->direccion);
        printf("Correo: %s\n", vClientes[i]->correo);
        printf("Clave: %s\n", vClientes[i]->clave);
        printf("Cartera: %f\n", vClientes[i]->dinero);
        printf("\n");
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
    iguales(("Modificar clientes"), NULL);
    printf("Modificar clientes\n");
    iguales(("Modificar clientes"), NULL);
    printf("Introduce el Id del cliente a modificar: ");
    if(scanf("%d", &opcion) != 1){
        error_scanf();
    }
    for(i = 0; i < nClientes; i++){
        if(opcion == vClientes[i]->id){
            printf("1 - Nombre: %s\n", vClientes[i]->nombre);
            printf("2 - Direccion: %s\n", vClientes[i]->direccion);
            printf("5 - Correo: %s\n", vClientes[i]->correo);
            printf("6 - Clave: %s\n", vClientes[i]->clave);
            printf("7 - Cartera: %f\n", vClientes[i]->dinero);
            printf("8 - Salir\n");
            printf("\n ¿Que campo desea modificar? 1, 2, 5, 6 u 8 (salir): ");
            if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 8){
                error_scanf();
            }
            switch(opcion){
                case 1:
                    modif(vClientes[i]->nombre, N_nombre);
                    break;
                case 2:
                    modif(vClientes[i]->direccion, 50);
                    break;
                case 5:
                    modif(vClientes[i]->correo, N_email);
                    break;
                case 6:
                    modif(vClientes[i]->clave, N_Contrasena);
                    break;
                case 7:
                    mod_cartera(*vClientes, i);
                    break;
                case 8:
                    break;
            }
        }
    }
    printf("\n");
    printf("Pulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada
    getchar();      //pausa
}
            
//cabecera: mod_cartera(cliente_estr *vClientes)
//precondicion: vClientes es un puntero a estructura de tipo cliente_estr
//postcondicion: modifica la cartera del cliente

void mod_cartera(cliente_estr *vClientes, int n){
    float dinero;
    printf("Introduce el nuevo dinero: ");
    if(scanf("%f", &dinero) != 1){
        error_scanf();
    }
    vClientes->dinero = dinero;
}

//cabecera: menu_proveedores(usuarios **vProveedores, int nProveedores)
//precondicion: vProveedores es un puntero a un puntero de estructura de tipo usuarios, nProveedores es un entero
//postcondicion: muestra el menu de proveedores

int menu_proveedores(usuarios *vProveedores, int nProveedores){
    int opcion, control = 1;
    do{
        system("cls");
        layer_esizon();
        iguales(("Menu proveedores"), NULL);
        printf("Menu proveedores\n");
        iguales(("Menu proveedores"), NULL);
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

//cabecera: void verproveedores(usuarios **vProveedores, int nProveedores)
//precondicion: vProveedores es un puntero a un puntero de estructura de tipo usuarios, nProveedores es un entero
//postcondicion: muestra los proveedores

void verproveedores(usuarios *vProveedores, int nProveedores){
    int i;
    system("cls");
    layer_esizon();
    iguales(("Proveedores"), NULL);
    printf("Proveedores\n");
    iguales(("Proveedores"), NULL);
    for(i = 0; i < nProveedores; i++){
        if (strcmp(vProveedores[i].Perfil_usuario, "proveedor") == 0){
            printf("Id empresa: %s\n", vProveedores[i].Id_empresa);
            printf("Nombre empresa: %s\n", vProveedores[i].Nombre);
            printf("Correo: %s\n", vProveedores[i].email);
            printf("Clave: %s\n", vProveedores[i].Contrasena);
            printf("Perfil usuario: %s\n", vProveedores[i].Perfil_usuario);
            printf("\n");
        }
        vProveedores++;
    }
    printf("Pulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada       
    getchar();      //pausa
}

//cabecera: void modificarproveedores(usuarios **vProveedores, int nProveedores)
//precondicion: vProveedores es un puntero a un puntero de estructura de tipo usuarios, nProveedores es un entero
//postcondicion: modifica los proveedores

void modificarproveedores(usuarios *vProveedores, int nProveedores){
    int i, opcion;
    char aux[100];
    system("cls");
    layer_esizon();
    iguales(("Modificar proveedores"), NULL);
    printf("Modificar proveedores\n");
    iguales(("Modificar proveedores"), NULL);
    printf("Introduce el Id del proveedor a modificar: ");
    if(scanf("%d", &opcion) != 1){
        error_scanf();
    }
    for(i = 0; i < nProveedores; i++){
        if(opcion == atoi(vProveedores[i].Id_empresa) && strcmp(vProveedores[i].Perfil_usuario, "proveedor") == 0){
            printf("1 - Nombre empresa: %s\n", vProveedores[i].Nombre);
            printf("2 - Correo: %s\n", vProveedores[i].email);
            printf("3 - Clave: %s\n", vProveedores[i].Contrasena);
            printf("4 - Salir\n");
            printf("\n ¿Que campo desea modificar? 1, 2, 3, 4:  ");
            if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 4){
                error_scanf();
            }
            switch(opcion){
                case 1:
                    modif(vProveedores[i].Nombre, N_Nombre);
                    break;
                case 2:
                    modif(vProveedores[i].email, N_email);
                    break;
                case 3:
                    modif(vProveedores[i].Contrasena, N_Contrasena);
                    break;
                case 4:
                    break;
            }
        }
    }
    printf("\n");
    printf("Pulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada
    getchar();      //pausa
}

//cabecera: menu_productos(producto *vProductos, int nProductos)
//precondicion: vProductos es un puntero a estructura de tipo producto, nProductos es un entero
//postcondicion: muestra el menu de productos

int menu_productos(producto *vProductos, int nProductos, categ *vCategorias, int nCategorias){
    int opcion, control = 1;
    do{
        system("cls");
        layer_esizon();
        iguales(("Menu productos"), NULL);
        printf("Menu productos\n");
        iguales(("Menu productos"), NULL);
        printf("1. Ver productos\n");
        printf("2. Modificar productos\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 3){
            error_scanf();
        }
        switch(opcion){
            case 1:
                verproductos(vProductos, nProductos, vCategorias, nCategorias);
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

//cabecera: void verproductos(producto *vProductos, int nProductos)
//precondicion: vProductos es un puntero a estructura de tipo producto, nProductos es un entero
//postcondicion: muestra los productos

void verproductos(producto *vProductos, int nProductos, categ *vCategorias, int nCategorias){
    int i;
    system("cls");
    layer_esizon();
    iguales(("Productos"), NULL);
    printf("Productos\n");
    iguales(("Productos"), NULL);
    for(i = 0; i < nProductos; i++){
        printf("Id producto: %d\n", (*vProductos).id_prod);
        printf("Descripcion: %s\n", (*vProductos).descripcion_prod);
        printf("Precio: %f\n", (*vProductos).precio);
        printf("Stock: %d\n", (*vProductos).stock);
        printf("Categoria: %s\n", vCategorias[(*vProductos).id_categ].descripcion_categ);
        printf("\n");
        vProductos++;
    }
    printf("Pulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada       
    getchar();      //pausa
}

//cabecera: void modificarproductos(producto *vProductos, int nProductos)
//precondicion: vProductos es un puntero a estructura de tipo producto, nProductos es un entero
//postcondicion: modifica los productos

void modificarproductos(producto *vProductos, int nProductos){
    int i, opcion;
    char aux[100];
    system("cls");
    layer_esizon();
    iguales(("Modificar productos"), NULL);
    printf("Modificar productos\n");
    iguales(("Modificar productos"), NULL);
    printf("Introduce el Id del producto a modificar: ");
    if(scanf("%d", &opcion) != 1){
        error_scanf();
    }
    for(i = 0; i < nProductos; i++){
        if(opcion != (*vProductos).id_prod){
        vProductos++;
        }
        else{
            if(opcion == vProductos[i].id_prod){
            printf("1 - Descripcion: %s\n", vProductos[i].descripcion_prod);
            printf("2 - Precio: %f\n", vProductos[i].precio);
            printf("3 - Stock: %d\n", vProductos[i].stock);
            printf("4 - Categoria: %d\n", vProductos[i].id_categ);
            printf("5 - Salir\n");
            printf("\n ¿Que campo desea modificar? 1, 2, 3, 4 o 5: ");
            if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 5){
                error_scanf();
            }
            switch(opcion){
                case 1:
                    modif(vProductos[i].descripcion_prod, 50);
                    break;
                case 2:
                    mod_precio(vProductos, i);
                    break;
                case 3:
                    mod_stock(vProductos, i);
                    break;
                case 4:
                    mod_categ(vProductos, i);
                    break;
                case 5:
                    break;
            }
        }
        }
    } 
        
    printf("\n");
    printf("Pulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada
    getchar();      //pausa
}

//cabecera: mod_precio(producto *vProductos)
//precondicion: vProductos es un puntero a estructura de tipo producto
//postcondicion: modifica el precio del producto

void mod_precio(producto *vProductos, int n){
    float precio;
    printf("Introduce el nuevo precio: ");
    if(scanf("%f", &precio) != 1){
        error_scanf();
    }
    vProductos[n].precio = precio;
}

//cabecera: mod_stock(producto *vProductos)
//precondicion: vProductos es un puntero a estructura de tipo producto
//postcondicion: modifica el stock del producto

void mod_stock(producto *vProductos, int n){
    int stock;
    printf("Introduce el nuevo stock: ");
    if(scanf("%d", &stock) != 1){
        error_scanf();
    }
    vProductos[n].stock = stock;
}

//cabecera: mod_categ(producto *vProductos)
//precondicion: vProductos es un puntero a estructura de tipo producto
//postcondicion: modifica la categoria del producto

void mod_categ(producto *vProductos, int n){
    int categ;
    printf("Introduce la nueva categoria (ID): ");
    if(scanf("%d", &categ) != 1){
        error_scanf();
    }
    vProductos[n].id_categ = categ;
}

//cabecera: menu_categorias(categ *vCategorias, int nCategorias)
//precondicion: vCategorias es un puntero a estructura de tipo categ, nCategorias es un entero
//postcondicion: muestra el menu de categorias

int menu_categorias(categ *vCategorias, int nCategorias){
    int opcion, control = 1;
    do{
        system("cls");
        layer_esizon();
        iguales(("Menu categorias"), NULL);
        printf("Menu categorias\n");
        iguales(("Menu categorias"), NULL);
        printf("1. Ver categorias\n");
        printf("2. Modificar categorias\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 3){
            error_scanf();
        }
        switch(opcion){
            case 1:
                vercategorias(vCategorias, nCategorias);
                break;
            case 2:
                modificarcategorias(vCategorias, nCategorias);
                break;
            case 3:
                control = 0;
                break;
        }
    }while(control != 0);
    return control;
}

//cabecera: void vercategorias(categ *vCategorias, int nCategorias)
//precondicion: vCategorias es un puntero a estructura de tipo categ, nCategorias es un entero
//postcondicion: muestra las categorias

void vercategorias(categ *vCategorias, int nCategorias){
    int i;
    system("cls");
    layer_esizon();
    iguales(("Categorias"), NULL);
    printf("Categorias\n");
    iguales(("Categorias"), NULL);
    for(i = 0; i < nCategorias; i++){
        printf("Id categoria: %d\n", (*vCategorias).id_categ);
        printf("Descripcion: %s\n", (*vCategorias).descripcion_categ);
        printf("\n");
        vCategorias++;
    }
    printf("Pulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada       
    getchar();      //pausa
}

//cabecera: void modificarcategorias(categ *vCategorias, int nCategorias)
//precondicion: vCategorias es un puntero a estructura de tipo categ, nCategorias es un entero
//postcondicion: modifica las categorias

void modificarcategorias(categ *vCategorias, int nCategorias){
    int i, opcion;
    char aux[100];
    system("cls");
    layer_esizon();
    iguales(("Modificar categorias"), NULL);
    printf("Modificar categorias\n");
    iguales(("Modificar categorias"), NULL); ;
    printf("Introduce el Id de la categoria a modificar: ");
    if(scanf("%d", &opcion) != 1){
        error_scanf();
    }
    for(i = 0; i < nCategorias; i++){
        if(opcion == vCategorias[i].id_categ){
            printf("1 - Descripcion: %s\n", vCategorias[i].descripcion_categ);
            printf("2 - Salir\n");
            printf("\n ¿Que campo desea modificar? 1 o 2: ");
            if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 2){
                error_scanf();
            }
            switch(opcion){
                case 1:
                    modif((*vCategorias).descripcion_categ, 50);
                    break;
                case 2:
                    break;
            }
        }
    }
    printf("\n");
    printf("Pulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada
    getchar();      //pausa
}

//cabecera: menu_pedidos(pedido *vPedidos, int nPedidos)
//precondicion: vPedidos es un puntero a estructura de tipo pedido, nPedidos es un entero
//postcondicion: muestra el menu de pedidos

int menu_pedidos(pedidos *vPedidos, int nPedidos){
    int opcion, control = 1;
    do{
        system("cls");
        layer_esizon();
        iguales(("Menu pedidos"), NULL);
        printf("Menu pedidos\n");
        iguales(("Menu pedidos") , NULL);
        printf("1. Ver pedidos\n");
        printf("2. Modificar pedidos\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 3){
            error_scanf();
        }
        switch(opcion){
            case 1:
                verpedidos(vPedidos, nPedidos);
                break;
            case 2:
                modificarpedidos(vPedidos, nPedidos);
                break;
            case 3:
                control = 0;
                break;
        }
    }while(control != 0);
    return control;
}

//cabecera: void verpedidos(pedido *vPedidos, int nPedidos)
//precondicion: vPedidos es un puntero a estructura de tipo pedido, nPedidos es un entero
//postcondicion: muestra los pedidos

void verpedidos(pedidos *vPedidos, int nPedidos){
    int i;
    system("cls");
    layer_esizon();
    iguales(("Pedidos"), NULL);
    printf("Pedidos\n");
    iguales(("Pedidos"), NULL);
    for(i = 0; i < nPedidos; i++){
        printf("Id pedido: %s\n", (*vPedidos).id_pedido);
        printf("Id cliente: %s\n", (*vPedidos).id_cliente);
        printf("Locker: %s\n", (*vPedidos).locker);
        printf("Fecha: %s\n", (*vPedidos).fecha);
        printf("\n");
        vPedidos++;
    }
    printf("Pulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada       
    getchar();      //pausa
}

//cabecera: void modificarpedidos(pedido *vPedidos, int nPedidos)
//precondicion: vPedidos es un puntero a estructura de tipo pedido, nPedidos es un entero
//postcondicion: modifica los pedidos

void modificarpedidos(pedidos *vPedidos, int nPedidos){
    int i, opcion;
    char aux[100];
    system("cls");
    layer_esizon();
    iguales(("Modificar pedidos"), NULL);
    printf("Modificar pedidos\n");
    iguales(("Modificar pedidos"),  NULL);
    printf("Introduce el Id del pedido a modificar: ");
    if(scanf("%d", &opcion) != 1){
        error_scanf();
    }
    for(i = 0; i < nPedidos; i++){
        if(opcion == atoi(vPedidos[i].id_pedido)){
            printf("1 - Id Pedido: %s\n", vPedidos[i].id_pedido);
            printf("2 - Id Cliente: %s\n", vPedidos[i].id_cliente);
            printf("3 - Locker: %s\n", vPedidos[i].locker);
            printf("4 - Estado: %s\n", vPedidos[i].estado);
            printf("5 - Fecha: %s\n", vPedidos[i].fecha);
            printf("6 - Salir\n");
            printf("\n ¿Que campo desea modificar? 1, 2, 3, 4, 5 o 6: ");
            if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 6){
                error_scanf();
            }
            switch(opcion){
                case 1:
                    mod_id_cliente(vPedidos, i);
                    break;
                case 2:
                    mod_id_pedido(vPedidos, i);
                    break;
                case 3:
                    mod_locker(vPedidos, i);
                    break;
                case 4:
                    modif(vPedidos[i].estado, 2);
                    break;
                case 5:
                    mod_fecha(vPedidos, i);
                    break;
                case 6:
                    break;
            }
        }
        vPedidos++;
    }
    printf("\n");
    printf("Pulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada
    getchar();      //pausa
}

//cabecera: mod_id_cliente(pedidos *vPedidos, int n)
//precondicion: vPedidos es un puntero a estructura de tipo pedidos
//postcondicion: modifica el id del cliente del pedido

void mod_id_cliente(pedidos *vPedidos, int n){
    char id_cliente[7];
    printf("Introduce el nuevo id del cliente: ");
    if(scanf("%s", id_cliente) != 1){
        error_scanf();
    }
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(strcmp(vPedidos[i].id_cliente, id_cliente) == 0){
            flag = 1;
        }
    }
    if(flag == 0){
        strcpy(vPedidos[n].id_cliente, id_cliente);
    }
    else{
        printf("El id del cliente ya existe\n");
    }
    
}

//cabecera: mod_id_pedido(pedidos *vPedidos, int n)
//precondicion: vPedidos es un puntero a estructura de tipo pedidos
//postcondicion: modifica el id del cliente del pedido

void mod_id_pedido(pedidos *vPedidos, int n){
    char id_pedido[7];
    printf("Introduce el nuevo id del pedido: ");
    if(scanf("%s", id_pedido) != 1){
        error_scanf();
    }
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(strcmp(vPedidos[i].id_pedido, id_pedido) == 0){
            flag = 1;
        }
    }
    if(flag == 0){
        strcpy(vPedidos[n].id_pedido, id_pedido);
    }
    else{
        printf("El id del pedido ya existe\n");
    }
}

//cabecera: mod_locker(pedidos *vPedidos)
//precondicion: vPedidos es un puntero a estructura de tipo pedidos
//postcondicion: modifica el locker del pedido

void mod_locker(pedidos *vPedidos, int n){
    char locker[50];
    printf("Introduce el nuevo locker: ");
    if(scanf("%s", locker) != 1){
        error_scanf();
    }
    strcpy(vPedidos[n].locker, locker);
}

//cabecera: mod_fecha(pedidos *vPedidos)
//precondicion: vPedidos es un puntero a estructura de tipo pedidos
//postcondicion: modifica la fecha del pedido

void mod_fecha(pedidos *vPedidos, int n){
    char fecha[50];
    printf("Introduce la nueva fecha: ");
    if(scanf("%s", fecha) != 1){
        error_scanf();
    }
    //comporbar que la fecha es el formato DD/MM/AAAA
    if (fecha[2] == '/' && fecha[5] == '/' && fecha[10] == '\0')
    {
        strcpy(vPedidos[n].fecha, fecha);
    }
    else
    {
        printf("Formato de fecha incorrecto\n");
    }
    
    
}

//cabecera: menu_transportista(transportista *vTransportista, int nTransportista)
//precondicion: vTransportista es un puntero a estructura de tipo transportista, nTransportista es un entero
//postcondicion: muestra el menu de transportista

int menu_transportista(transportista_estr *vTransportista, int nTransportista){
    int opcion, control = 1;
    do{
        system("cls");
        layer_esizon();
        iguales(("Menu transportista"), NULL);
        printf("Menu transportista\n");
        iguales(("Menu transportista"), NULL);
        printf("1. Ver transportista\n");
        printf("2. Modificar transportista\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 3){
            error_scanf();
        }
        switch(opcion){
            case 1:
                vertransportista(vTransportista, nTransportista);
                break;
            case 2:
                modificartransportista(vTransportista, nTransportista);
                break;
            case 3:
                control = 0;
                break;
        }
    }while(control != 0);
    return control;
}

//cabecera: void vertransportista(transportista *vTransportista, int nTransportista)
//precondicion: vTransportista es un puntero a estructura de tipo transportista, nTransportista es un entero
//postcondicion: muestra el transportista

void vertransportista(transportista_estr *vTransportista, int nTransportista){
    int i;
    system("cls");
    layer_esizon();
    iguales(("Transportista"), NULL);
    printf("Transportista\n");
    iguales(("Transportista"), NULL);
    for(i = 0; i < nTransportista; i++){
        printf("Id empresa: %d\n", (*vTransportista).id);
        printf("Nombre empresa: %s\n", (*vTransportista).nom_empresa);
        printf("Correo: %s\n", (*vTransportista).email);
        printf("Clave: %s\n", (*vTransportista).contra);
        printf("Perfil usuario: %s\n", (*vTransportista).nombre);
        printf("\n");
        vTransportista++;
    }
    printf("Pulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada       
    getchar();      //pausa
}

//cabecera: void modificartransportista(transportista *vTransportista, int nTransportista)
//precondicion: vTransportista es un puntero a estructura de tipo transportista, nTransportista es un entero
//postcondicion: modifica el transportista


void modificartransportista(transportista_estr *vTransportista, int nTransportista){
    int i, opcion;
    char aux[100];
    system("cls");
    layer_esizon();
    iguales(("Modificar transportista"), NULL);
    printf("Modificar transportista\n");
    iguales(("Modificar transportista"), NULL);
    printf("Introduce el Id del transportista a modificar: ");
    if(scanf("%d", &opcion) != 1){
        error_scanf();
    }
    for(i = 0; i < nTransportista; i++){
        if(opcion == vTransportista[i].id){
            printf("1 - Nombre empresa: %s\n", vTransportista[i].nom_empresa);
            printf("2 - Correo: %s\n", vTransportista[i].email);
            printf("3 - Clave: %s\n", vTransportista[i].contra);
            printf("4 - Perfil usuario: %s\n", vTransportista[i].nombre);
            printf("5 - Salir\n");
            printf("\n ¿Que campo desea modificar? 1, 2, 3, 4 o 5: ");
            if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 5){
                error_scanf();
            }
            switch(opcion){
                case 1:
                modif((*vTransportista).nom_empresa, 50);
                break;
                case 2:
                modif((*vTransportista).email, N_email);
                break;
                case 3:
                modif((*vTransportista).contra, N_Contrasena);
                break;
                case 4:
                modif((*vTransportista).nombre, N_nombre);
                break;
                case 5:
                break;
            }
        }
    }
    printf("\n");
    printf("Pulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada
    getchar();      //pausa
}

//cabecera: mod_nom_emp(transportista *vTransportista)
//precondicion: vTransportista es un puntero a estructura de tipo transportista
//postcondicion: modifica el nombre de la empresa del transportista

int menu_descuentos(descuentos_estr *vDescuentos, int nDescuentos){
    int opcion, control = 1;
    do{
        system("cls");
        layer_esizon();
        iguales(("Menu descuentos"), NULL);
        printf("Menu descuentos\n");
        iguales(("Menu descuentos"), NULL);
        printf("1. Ver descuentos\n");
        printf("2. Modificar descuentos\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 3){
            error_scanf();
        }
        switch(opcion){
            case 1:
                verdescuentos(vDescuentos, nDescuentos);
                break;
            case 2:
                modificardescuentos(vDescuentos, nDescuentos);
                break;
            case 3:
                control = 0;
                break;
        }
    }while(control != 0);
    return control;
}

//cabecera: void verdescuentos(descuento *vDescuentos, int nDescuentos)
//precondicion: vDescuentos es un puntero a estructura de tipo descuento, nDescuentos es un entero
//postcondicion: muestra los descuentos

void verdescuentos(descuentos_estr *vDescuentos, int nDescuentos){
    int i;
    system("cls");
    layer_esizon();
    iguales(("Descuentos"), NULL);
    printf("Descuentos\n");
    iguales(("Descuentos"), NULL);
    for(i = 0; i < nDescuentos; i++){
        printf("Id descuento: %s\n", (*vDescuentos).id_descuento);
        printf("Descripcion: %s\n", (*vDescuentos).descripcion);
        printf("Aplicabilidad: %s\n", (*vDescuentos).aplicabilidad);
        printf("Tipo: %s\n", (*vDescuentos).tipo);
        printf("Importe: %f\n", (*vDescuentos).importe);
        printf("Estado: %c\n", (*vDescuentos).estado_d);
        printf("\n");
        vDescuentos++;
    }
    printf("Pulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada       
    getchar();      //pausa
}

//cabecera: void modificardescuentos(descuento *vDescuentos, int nDescuentos)
//precondicion: vDescuentos es un puntero a estructura de tipo descuento, nDescuentos es un entero
//postcondicion: modifica los descuentos

void modificardescuentos(descuentos_estr *vDescuentos, int nDescuentos){
    int i, opcion;
    char aux[100];
    system("cls");
    layer_esizon();
    iguales(("Modificar descuentos"), NULL);
    printf("Modificar descuentos\n");
    iguales(("Modificar descuentos"), NULL);
    printf("Introduce el Id del descuento a modificar: ");
    if(scanf("%d", &opcion) != 1){
        error_scanf();
    }
    for(i = 0; i < nDescuentos; i++){
        if(opcion == atoi(vDescuentos[i].id_descuento)){
            printf("1 - Descripcion: %s\n", vDescuentos[i].descripcion);
            printf("2 - Aplicabilidad: %s\n", vDescuentos[i].aplicabilidad);
            printf("3 - Tipo: %s\n", vDescuentos[i].tipo);
            printf("4 - Importe: %f\n", vDescuentos[i].importe);
            printf("5 - Estado: %c\n", vDescuentos[i].estado_d);
            printf("6 - Salir\n");
            printf("\n ¿Que campo desea modificar? 1, 2, 3, 4, 5 o 6: ");
            if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 6){
                error_scanf();
            }
            switch(opcion){
                case 1:
                    modif(vDescuentos[i].descripcion, 50);
                    break;
                case 2:
                    mod_aplicabilidad(vDescuentos, i);
                    break;
                case 3:
                    mod_tipo(vDescuentos, i);
                    break;
                case 4:
                    mod_importe(vDescuentos, i);
                    break;
                case 5:
                    mod_estado(&vDescuentos[i].estado_d);
                    break;
                case 6:
                    break;
            }
        }
    }
}

//cabecera: mod_aplicabilidad(descuento *vDescuentos)
//precondicion: vDescuentos es un puntero a estructura de tipo descuento
//postcondicion: modifica la aplicabilidad del descuento

void mod_aplicabilidad(descuentos_estr *vDescuentos, int n){
    char* aplicabilidad;
    printf("Introduce la nueva aplicabilidad 'todos' o 'esizon': ");
    if(scanf("%c", aplicabilidad) != 1){
        error_scanf();
    }
    if (strcmp(aplicabilidad, "todos") == 0 || strcmp(aplicabilidad, "esizon") == 0){
        strcpy(vDescuentos[n].aplicabilidad, aplicabilidad);
    }else{
        printf("Error, introduce 'todos' o 'esizon'\n");
    }
}

//cabecera: mod_tipo(descuento *vDescuentos)
//precondicion: vDescuentos es un puntero a estructura de tipo descuento
//postcondicion: modifica el tipo del descuento

void mod_tipo(descuentos_estr *vDescuentos, int n){
    char tipo[50];
    printf("Introduce el nuevo tipo: ");
    if(scanf("%s", tipo) != 1){
        error_scanf();
    }
    strcpy(vDescuentos[n].tipo, tipo);
}

//cabecera: mod_importe(descuento *vDescuentos)
//precondicion: vDescuentos es un puntero a estructura de tipo descuento
//postcondicion: modifica el importe del descuento

void mod_importe(descuentos_estr *vDescuentos, int n){
    float importe;
    printf("Introduce el nuevo importe: ");
    if(scanf("%f", &importe) != 1){
        error_scanf();
    }
    vDescuentos[n].importe = importe;
}

//cabecera: mod_estado(descuento *vDescuentos)
//precondicion: vDescuentos es un puntero a estructura de tipo descuento
//postcondicion: modifica el estado del descuento

void mod_estado(char *estado_ini){
    char estado;
    printf("Introduce el nuevo estado S o N: ");
    if(scanf("%c", &estado) != 1){
        error_scanf();
    }
    if(estado == 'S' || estado == 'N'){
    *estado_ini = estado;
    }else{
        printf("Error, introduce S o N\n");
    }
}

//cabecera: menu_devoluciones(devolucion *vDevoluciones, int nDevoluciones)
//precondicion: vDevoluciones es un puntero a estructura de tipo devolucion, nDevoluciones es un entero
//postcondicion: muestra el menu de devoluciones

int menu_devoluciones(devolucion *vDevoluciones, int nDevoluciones){
    int opcion, control = 1;
    do{
        system("cls");
        layer_esizon();
        iguales(("Menu devoluciones"), NULL);
        printf("Menu devoluciones\n");
        iguales(("Menu devoluciones"), NULL);
        printf("1. Ver devoluciones\n");
        printf("2. Modificar devoluciones\n");
        printf("3. Salir\n");
        printf("Opcion: ");
        if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 3){
            error_scanf();
        }
        switch(opcion){
            case 1:
                verdevoluciones(vDevoluciones, nDevoluciones);
                break;
            case 2:
                modificardevoluciones(vDevoluciones, nDevoluciones);
                break;
            case 3:
                control = 0;
                break;
        }
    }while(control != 0);
    return control;
}

//cabecera: void verdevoluciones(devolucion *vDevoluciones, int nDevoluciones)
//precondicion: vDevoluciones es un puntero a estructura de tipo devolucion, nDevoluciones es un entero
//postcondicion: muestra las devoluciones
void verdevoluciones(devolucion *vDevoluciones, int nDevoluciones){
    int i;
    system("cls");
    layer_esizon();
    iguales(("Devoluciones"), NULL);
    printf("Devoluciones\n");
    iguales(("Devoluciones"), NULL);
    for(i = 0; i < nDevoluciones; i++){
        printf("Id pedido: %s\n", (*vDevoluciones).id_pedido);
        printf("Id producto: %s\n", (*vDevoluciones).id_producto);
        printf("Fecha: %s\n", (*vDevoluciones).fecha_devolucion);
        printf("Motivo: %s\n", (*vDevoluciones).motivo);
        printf("Estado: %c\n", (*vDevoluciones).estado);
        printf("\n");
        vDevoluciones++;
    }
    printf("Pulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada       
    getchar();      //pausa
}

//cabecera: void modificardevoluciones(devolucion *vDevoluciones, int nDevoluciones)
//precondicion: vDevoluciones es un puntero a estructura de tipo devolucion, nDevoluciones es un entero
//postcondicion: modifica las devoluciones
void modificardevoluciones(devolucion *vDevoluciones, int nDevoluciones){
    int i, opcion;
    char aux[100];
    system("cls");
    layer_esizon();
    iguales(("Modificar devoluciones"), NULL);
    printf("Modificar devoluciones\n");
    iguales(("Modificar devoluciones"), NULL);
    printf("Introduce el Id de la devolucion a modificar: ");
    if(scanf("%d", &opcion) != 1){
        error_scanf();
    }
    for(i = 0; i < nDevoluciones; i++){
        if(opcion == atoi((*vDevoluciones).id_pedido)){
            printf("1 - Id producto: %s\n", (*vDevoluciones).id_producto);
            printf("2 - Fecha: %s\n", (*vDevoluciones).fecha_devolucion);
            printf("3 - Motivo: %s\n", (*vDevoluciones).motivo);
            printf("4 - Estado: %c\n", (*vDevoluciones).estado);
            printf("5 - Salir\n");
            printf("\n ¿Que campo desea modificar? 1, 2, 3, 4 o 5: ");
            if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 5){
                error_scanf();
            }
            switch(opcion){
                case 1:
                    mod_id_producto(vDevoluciones, nDevoluciones, i);
                    break;
                case 2:
                    mod_fecha_devolucion(vDevoluciones, i);
                    break;
                case 3:
                    modif((*vDevoluciones).motivo, 50);
                    break;
                case 4:
                    mod_estado(&vDevoluciones[i].estado);
                    break;
                case 5:
                    break;
            }
        }
        vDevoluciones++;
    }
    printf("\n");
    printf("Pulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada
    getchar();      //pausa
}

//cabecera: mod_id_producto(devolucion *vDevoluciones)
//precondicion: vDevoluciones es un puntero a estructura de tipo devolucion
//postcondicion: modifica el id del producto de la devolucion

void mod_id_producto(devolucion *vDevoluciones,int nDevoluciones, int n){
    char id_producto[7];
    printf("\nIntroduce el nuevo id del producto: ");
    if(scanf("%s", id_producto) != 1){
        error_scanf();
    }
    //comprobamos que el id del producto sea un entero y no sea repetido
    for (int i = 0; i < nDevoluciones; i++){
        if(id_producto == vDevoluciones[i].id_producto){
            printf("Error, el id del producto ya existe\n");
        }else{
            strcpy(vDevoluciones[n].id_producto, id_producto);
        }
    }

}

//cabecera: mod_fecha_devolucion(devolucion *vDevoluciones)
//precondicion: vDevoluciones es un puntero a estructura de tipo devolucion
//postcondicion: modifica la fecha de la devolucion

void mod_fecha_devolucion(devolucion *vDevoluciones, int n){
    char fecha_devolucion[50];
    printf("\nIntroduce la nueva fecha de devolucion: ");
    if(scanf("%s", fecha_devolucion) != 1){
        error_scanf();
    }
    //comprobamos formato de fecha DD/MM/AAAA
    if(fecha_devolucion[2] == '/' && fecha_devolucion[5] == '/'){
        strcpy((*vDevoluciones).fecha_devolucion, fecha_devolucion);
    }else{
        printf("Error, introduce la fecha en formato DD/MM/AAAA\n");
    }
}