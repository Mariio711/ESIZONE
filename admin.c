#include <stdio.h>
#include <stdlib.h>

#include "clientes.h"
#include "admin.h"
#include "login.h"
#include "func_aux.h"
#include "Proveedor.h"
#include "Productos.h"
#include "pedidos.h"
#include "Transportista.h"

//definicion de funciones
//admin
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
void mod_nom_prov(usuarios *vProveedores, int n);
void mod_email_prov(usuarios *vProveedores, int n);
void mod_contr_prov(usuarios *vProveedores, int n);

//productos
int menu_productos(producto *vProductos, int nProductos, categ *vCategorias, int nCategorias);
void verproductos(producto *vProductos, int nProductos, categ *vCategorias, int nCategorias);
void modificarproductos(producto *vProductos, int nProductos);
void mod_desc(producto *vProductos, int n);
void mod_precio(producto *vProductos, int n);
void mod_stock(producto *vProductos, int n);
void mod_categ(producto *vProductos, int n);

//categorias
int menu_categorias(categ *vCategorias, int nCategorias);
void vercategorias(categ *vCategorias, int nCategorias);
void modificarcategorias(categ *vCategorias, int nCategorias);
void mod_desc_categ(categ *vCategorias, int n);

//pedidos
int menu_pedidos(pedidos *vPedidos, int nPedidos);
void verpedidos(pedidos *vPedidos, int nPedidos);
void modificarpedidos(pedidos *vPedidos, int nPedidos);
void mod_id_cliente(pedidos *vPedidos, int n);
void mod_fecha(pedidos *vPedidos, int n);

//transportista
int menu_transportista(transportista_estr *vTransportista, int nTransportista);
void vertransportista(transportista_estr *vTransportista, int nTransportista);
void modificartransportista(transportista_estr *vTransportista, int nTransportista);
void mod_nom_emp(transportista_estr *vTransportista, int n);

//descuentos
int menu_descuentos(descuentos_estr *vDescuentos, int nDescuentos);
void verdescuentos(descuentos_estr *vDescuentos, int nDescuentos);
void modificardescuentos(descuentos_estr *vDescuentos, int nDescuentos);
void mod_desc_desc(descuentos_estr *vDescuentos, int n);
void mod_tipo(descuentos_estr *vDescuentos, int n);
void mod_estado(descuentos_estr *vDescuentos, int n);

//devoluciones
int menu_devoluciones(devolucion *vDevoluciones, int nDevoluciones);
void verdevoluciones(devolucion *vDevoluciones, int nDevoluciones);
void modificardevoluciones(devolucion *vDevoluciones, int nDevoluciones);
void mod_id_prod(devolucion *vDevoluciones, int n);
void mod_fecha_dev(devolucion *vDevoluciones, int n);
void mod_motivo(devolucion *vDevoluciones, int n);







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
                ficheros_prov(vProveedores, &nProveedores);
                control = menu_proveedores(vProveedores, nProveedores);
                break;
            }
            case 4:
            {
                producto *vProductos;
                int nProductos;
                categ *vCategorias;
                int nCategorias;
                ficheros_prod( vProductos, &nProductos);
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
                ficheros_pedidos(vPedidos, &nPedidos);
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
            case 8:
                //cargo descuentos
                control = menu_descuentos( /*falta*/);
                
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
    iguales(("Modificar clientes"),'\0');
    printf("Modificar clientes\n");
    iguales(("Modificar clientes"),'\0');
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
                    mod_nom_cli(*vClientes, i);
                    break;
                case 2:
                    mod_dir_cli(*vClientes, i);
                    break;
                case 5:
                    mod_email_cli(*vClientes, i);
                    break;
                case 6:
                    mod_contr_cli(*vClientes);
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

//cabecera: void verproveedores(usuarios **vProveedores, int nProveedores)
//precondicion: vProveedores es un puntero a un puntero de estructura de tipo usuarios, nProveedores es un entero
//postcondicion: muestra los proveedores

void verproveedores(usuarios *vProveedores, int nProveedores){
    int i;
    system("cls");
    layer_esizon();
    iguales(("Proveedores"),'\0');
    printf("Proveedores\n");
    iguales(("Proveedores"),'\0');
    for(i = 0; i < nProveedores; i++){
        if (strcmp(vProveedores[i].perfil_usuario, "proveedor") == 0){
            printf("Id empresa: %d\n", vProveedores[i].id_empresa);
            printf("Nombre empresa: %s\n", vProveedores[i].nombre_empresa);
            printf("Correo: %s\n", vProveedores[i].correo);
            printf("Clave: %s\n", vProveedores[i].clave);
            printf("Perfil usuario: %s\n", vProveedores[i].perfil_usuario);
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
    iguales(("Modificar proveedores"),'\0');
    printf("Modificar proveedores\n");
    iguales(("Modificar proveedores"),'\0');
    printf("Introduce el Id del proveedor a modificar: ");
    if(scanf("%d", &opcion) != 1){
        error_scanf();
    }
    for(i = 0; i < nProveedores; i++){
        if(opcion == vProveedores[i].id_empresa){
            printf("1 - Nombre empresa: %s\n", vProveedores[i].nombre_empresa);
            printf("2 - Correo: %s\n", vProveedores[i].correo);
            printf("3 - Clave: %s\n", vProveedores[i].clave);
            printf("4 - Salir\n");
            printf("\n ¿Que campo desea modificar? 1, 2, 3, 4:  ");
            if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 4){
                error_scanf();
            }
            switch(opcion){
                case 1:
                    mod_nom_prov(vProveedores, i);
                    break;
                case 2:
                    mod_email_prov(vProveedores, i);
                    break;
                case 3:
                    mod_contr_prov(vProveedores, i);
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
    iguales(("Productos"),'\0');
    printf("Productos\n");
    iguales(("Productos"),'\0');
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
    iguales(("Modificar productos"),'\0');
    printf("Modificar productos\n");
    iguales(("Modificar productos"),'\0');
    printf("Introduce el Id del producto a modificar: ");
    if(scanf("%d", &opcion) != 1){
        error_scanf();
    }
    for(i = 0; i < nProductos; i++){
        if(opcion != (*vProductos).id_prod){
        vProductos++;
        }
        else{
            if(opcion == (*vProductos).id_prod){
            printf("1 - Descripcion: %s\n", (*vProductos).descripcion_prod);
            printf("2 - Precio: %f\n", (*vProductos).precio);
            printf("3 - Stock: %d\n", (*vProductos).stock);
            printf("4 - Categoria: %d\n", (*vProductos).id_categ);
            printf("5 - Salir\n");
            printf("\n ¿Que campo desea modificar? 1, 2, 3, 4 o 5: ");
            if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 5){
                error_scanf();
            }
            switch(opcion){
                case 1:
                    mod_desc(vProductos, i);
                    break;
                case 2:
                    mod_precio(vProductos);
                    break;
                case 3:
                    mod_stock(vProductos);
                    break;
                case 4:
                    mod_categ(vProductos);
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

//cabecera: mod_desc(producto *vProductos, int nProductos)
//precondicion: vProductos es un puntero a estructura de tipo producto
//postcondicion: modifica la descripcion del producto

void mod_desc(producto *vProductos){
    char descripcion[50];
    printf("Introduce la nueva descripcion: ");
    if(scanf("%s", descripcion) != 1){
        error_scanf();
    }
    strcpy((*vProductos).descripcion_prod, descripcion);
}

//cabecera: mod_precio(producto *vProductos)
//precondicion: vProductos es un puntero a estructura de tipo producto
//postcondicion: modifica el precio del producto

void mod_precio(producto *vProductos){
    float precio;
    printf("Introduce el nuevo precio: ");
    if(scanf("%f", &precio) != 1){
        error_scanf();
    }
    (*vProductos).precio = precio;
}

//cabecera: mod_stock(producto *vProductos)
//precondicion: vProductos es un puntero a estructura de tipo producto
//postcondicion: modifica el stock del producto

void mod_stock(producto *vProductos){
    int stock;
    printf("Introduce el nuevo stock: ");
    if(scanf("%d", &stock) != 1){
        error_scanf();
    }
    (*vProductos).stock = stock;
}

//cabecera: mod_categ(producto *vProductos)
//precondicion: vProductos es un puntero a estructura de tipo producto
//postcondicion: modifica la categoria del producto

void mod_categ(producto *vProductos){
    int categ;
    printf("Introduce la nueva categoria (ID): ");
    if(scanf("%d", &categ) != 1){
        error_scanf();
    }
    (*vProductos).id_categ = categ;
}

//cabecera: menu_categorias(categ *vCategorias, int nCategorias)
//precondicion: vCategorias es un puntero a estructura de tipo categ, nCategorias es un entero
//postcondicion: muestra el menu de categorias

int menu_categorias(categ *vCategorias, int nCategorias){
    int opcion, control = 1;
    do{
        system("cls");
        layer_esizon();
        iguales(("Menu categorias"),'\0');
        printf("Menu categorias\n");
        iguales(("Menu categorias"),'\0');
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
    iguales(("Categorias"),'\0');
    printf("Categorias\n");
    iguales(("Categorias"),'\0');
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
    iguales(("Modificar categorias"),'\0');
    printf("Modificar categorias\n");
    iguales(("Modificar categorias"),'\0');
    printf("Introduce el Id de la categoria a modificar: ");
    if(scanf("%d", &opcion) != 1){
        error_scanf();
    }
    for(i = 0; i < nCategorias; i++){
        if(opcion == (*vCategorias).id_categ){
            printf("1 - Descripcion: %s\n", (*vCategorias).descripcion_categ);
            printf("2 - Salir\n");
            printf("\n ¿Que campo desea modificar? 1 o 2: ");
            if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 2){
                error_scanf();
            }
            switch(opcion){
                case 1:
                    mod_desc_categ(vCategorias);
                    break;
                case 2:
                    break;
            }
        }
        vCategorias++;
    }
    printf("\n");
    printf("Pulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada
    getchar();      //pausa
}

//cabecera: mod_desc_categ(categ *vCategorias)
//precondicion: vCategorias es un puntero a estructura de tipo categ
//postcondicion: modifica la descripcion de la categoria

void mod_desc_categ(categ *vCategorias){
    char descripcion[50];
    printf("Introduce la nueva descripcion: ");
    if(scanf("%s", descripcion) != 1){
        error_scanf();
    }
    strcpy((*vCategorias).descripcion_categ, descripcion);
}

//cabecera: menu_pedidos(pedido *vPedidos, int nPedidos)
//precondicion: vPedidos es un puntero a estructura de tipo pedido, nPedidos es un entero
//postcondicion: muestra el menu de pedidos

int menu_pedidos(pedidos *vPedidos, int nPedidos){
    int opcion, control = 1;
    do{
        system("cls");
        layer_esizon();
        iguales(("Menu pedidos"),'\0');
        printf("Menu pedidos\n");
        iguales(("Menu pedidos"),'\0');
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
    iguales(("Pedidos"),'\0');
    printf("Pedidos\n");
    iguales(("Pedidos"),'\0');
    for(i = 0; i < nPedidos; i++){
        printf("Id pedido: %d\n", (*vPedidos).id_pedido);
        printf("Id cliente: %d\n", (*vPedidos).id_cliente);
        printf("Ciudad: %s\n", (*vPedidos).ciudad);
        printf("Locker: %d\n", (*vPedidos).locker);
        printf("Descuento: %s\n", (*vPedidos).descuento);
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
    iguales(("Modificar pedidos"),'\0');
    printf("Modificar pedidos\n");
    iguales(("Modificar pedidos"),'\0');
    printf("Introduce el Id del pedido a modificar: ");
    if(scanf("%d", &opcion) != 1){
        error_scanf();
    }
    for(i = 0; i < nPedidos; i++){
        if(opcion == (*vPedidos).id_pedido){
            printf("1 - Id cliente: %d\n", (*vPedidos).id_cliente);
            printf("2 - Ciudad: %s\n", (*vPedidos).ciudad);
            printf("3 - Locker: %d\n", (*vPedidos).locker);
            printf("4 - Descuento: %s\n", (*vPedidos).descuento);
            printf("5 - Fecha: %s\n", (*vPedidos).fecha);
            printf("6 - Salir\n");
            printf("\n ¿Que campo desea modificar? 1, 2, 3, 4, 5 o 6: ");
            if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 6){
                error_scanf();
            }
            switch(opcion){
                case 1:
                    mod_id_cliente(vPedidos);
                    break;
                case 2:
                    mod_ciudad(vPedidos);
                    break;
                case 3:
                    mod_locker(vPedidos);
                    break;
                case 4:
                    mod_descuento(vPedidos);
                    break;
                case 5:
                    mod_fecha(vPedidos);
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

//cabecera: mod_id_cliente(pedidos *vPedidos)
//precondicion: vPedidos es un puntero a estructura de tipo pedidos
//postcondicion: modifica el id del cliente del pedido

void mod_id_cliente(pedidos *vPedidos){
    int id_cliente;
    printf("Introduce el nuevo id del cliente: ");
    if(scanf("%d", &id_cliente) != 1){
        error_scanf();
    }
    (*vPedidos).id_cliente = id_cliente;
}

//cabecera: mod_ciudad(pedidos *vPedidos)
//precondicion: vPedidos es un puntero a estructura de tipo pedidos
//postcondicion: modifica la ciudad del pedido

void mod_ciudad(pedidos *vPedidos){
    char ciudad[50];
    printf("Introduce la nueva ciudad: ");
    if(scanf("%s", ciudad) != 1){
        error_scanf();
    }
    strcpy((*vPedidos).ciudad, ciudad);
}

//cabecera: mod_locker(pedidos *vPedidos)
//precondicion: vPedidos es un puntero a estructura de tipo pedidos
//postcondicion: modifica el locker del pedido

void mod_locker(pedidos *vPedidos){
    int locker;
    printf("Introduce el nuevo locker: ");
    if(scanf("%d", &locker) != 1){
        error_scanf();
    }
    (*vPedidos).locker = locker;
}

//cabecera: mod_descuento(pedidos *vPedidos)
//precondicion: vPedidos es un puntero a estructura de tipo pedidos
//postcondicion: modifica el descuento del pedido

void mod_descuento(pedidos *vPedidos){
    char descuento[50];
    printf("Introduce el nuevo descuento: ");
    if(scanf("%s", descuento) != 1){
        error_scanf();
    }
    strcpy((*vPedidos).descuento, descuento);
}

//cabecera: mod_fecha(pedidos *vPedidos)
//precondicion: vPedidos es un puntero a estructura de tipo pedidos
//postcondicion: modifica la fecha del pedido

void mod_fecha(pedidos *vPedidos){
    char fecha[50];
    printf("Introduce la nueva fecha: ");
    if(scanf("%s", fecha) != 1){
        error_scanf();
    }
    strcpy((*vPedidos).fecha, fecha);
}

//cabecera: menu_transportista(transportista *vTransportista, int nTransportista)
//precondicion: vTransportista es un puntero a estructura de tipo transportista, nTransportista es un entero
//postcondicion: muestra el menu de transportista

int menu_transportista(transportista_estr *vTransportista, int nTransportista){
    int opcion, control = 1;
    do{
        system("cls");
        layer_esizon();
        iguales(("Menu transportista"),'\0');
        printf("Menu transportista\n");
        iguales(("Menu transportista"),'\0');
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
    iguales(("Transportista"),'\0');
    printf("Transportista\n");
    iguales(("Transportista"),'\0');
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
    iguales(("Modificar transportista"),'\0');
    printf("Modificar transportista\n");
    iguales(("Modificar transportista"),'\0');
    printf("Introduce el Id del transportista a modificar: ");
    if(scanf("%d", &opcion) != 1){
        error_scanf();
    }
    for(i = 0; i < nTransportista; i++){
        if(opcion == (*vTransportista).id){
            printf("1 - Nombre empresa: %s\n", (*vTransportista).nom_empresa);
            printf("2 - Correo: %s\n", (*vTransportista).email);
            printf("3 - Clave: %s\n", (*vTransportista).contra);
            printf("4 - Perfil usuario: %s\n", (*vTransportista).nombre);
            printf("5 - Salir\n");
            printf("\n ¿Que campo desea modificar? 1, 2, 3, 4 o 5: ");
            if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 5){
                error_scanf();
            }
            switch(opcion){
                case 1:
                mod_nom_emp(vTransportista);
                break;
                case 2:
                mod_email(vTransportista);
                break;
                case 3:
                mod_contr(vTransportista);
                break;
                case 4:
                mod_nom(vTransportista);
                break;
                case 5:
                break;
            }
        }
        vTransportista++;
    }
    printf("\n");
    printf("Pulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada
    getchar();      //pausa
}

//cabecera: mod_nom_emp(transportista *vTransportista)
//precondicion: vTransportista es un puntero a estructura de tipo transportista
//postcondicion: modifica el nombre de la empresa del transportista

void mod_nom_emp(transportista_estr *vTransportista){
    char nom_empresa[50];
    printf("Introduce el nuevo nombre de la empresa: ");
    if(scanf("%s", nom_empresa) != 1){
        error_scanf();
    }
    strcpy((*vTransportista).nom_empresa, nom_empresa);
}

//cabecera: menu_descuentos(descuento *vDescuentos, int nDescuentos)
//precondicion: vDescuentos es un puntero a estructura de tipo descuento, nDescuentos es un entero
//postcondicion: muestra el menu de descuentos

int menu_descuentos(descuentos_estr *vDescuentos, int nDescuentos){
    int opcion, control = 1;
    do{
        system("cls");
        layer_esizon();
        iguales(("Menu descuentos"),'\0');
        printf("Menu descuentos\n");
        iguales(("Menu descuentos"),'\0');
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
    iguales(("Descuentos"),'\0');
    printf("Descuentos\n");
    iguales(("Descuentos"),'\0');
    for(i = 0; i < nDescuentos; i++){
        printf("Id descuento: %d\n", (*vDescuentos).id_descuento);
        printf("Descripcion: %s\n", (*vDescuentos).descripcion);
        printf("Aplicabilidad: %f\n", (*vDescuentos).aplicabilidad);
        printf("Tipo: %s\n", (*vDescuentos).tipo);
        printf("Importe: %f\n", (*vDescuentos).importe);
        printf("Estado: %s\n", (*vDescuentos).estado);
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
    iguales(("Modificar descuentos"),'\0');
    printf("Modificar descuentos\n");
    iguales(("Modificar descuentos"),'\0');
    printf("Introduce el Id del descuento a modificar: ");
    if(scanf("%d", &opcion) != 1){
        error_scanf();
    }
    for(i = 0; i < nDescuentos; i++){
        if(opcion == (*vDescuentos).id_descuento){
            printf("1 - Descripcion: %s\n", (*vDescuentos).descripcion);
            printf("2 - Aplicabilidad: %f\n", (*vDescuentos).aplicabilidad);
            printf("3 - Tipo: %s\n", (*vDescuentos).tipo);
            printf("4 - Importe: %f\n", (*vDescuentos).importe);
            printf("5 - Estado: %s\n", (*vDescuentos).estado);
            printf("6 - Salir\n");
            printf("\n ¿Que campo desea modificar? 1, 2, 3, 4, 5 o 6: ");
            if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 6){
                error_scanf();
            }
            switch(opcion){
                case 1:
                    mod_desc_desc(vDescuentos);
                    break;
                case 2:
                    mod_aplicabilidad(vDescuentos);
                    break;
                case 3:
                    mod_tipo(vDescuentos);
                    break;
                case 4:
                    mod_importe(vDescuentos);
                    break;
                case 5:
                    mod_estado(vDescuentos);
                    break;
                case 6:
                    break;
            }
        }
        vDescuentos++;
    }
}

//cabecera: mod_desc_desc(descuento *vDescuentos)
//precondicion: vDescuentos es un puntero a estructura de tipo descuento
//postcondicion: modifica la descripcion del descuento

void mod_desc_desc(descuentos_estr *vDescuentos){
    char descripcion[50];
    printf("Introduce la nueva descripcion: ");
    if(scanf("%s", descripcion) != 1){
        error_scanf();
    }
    strcpy((*vDescuentos).descripcion, descripcion);
}

//cabecera: mod_aplicabilidad(descuento *vDescuentos)
//precondicion: vDescuentos es un puntero a estructura de tipo descuento
//postcondicion: modifica la aplicabilidad del descuento

void mod_aplicabilidad(descuentos_estr *vDescuentos){
    float aplicabilidad;
    printf("Introduce la nueva aplicabilidad: ");
    if(scanf("%f", &aplicabilidad) != 1){
        error_scanf();
    }
    strcpy((*vDescuentos).aplicabilidad, aplicabilidad);
}

//cabecera: mod_tipo(descuento *vDescuentos)
//precondicion: vDescuentos es un puntero a estructura de tipo descuento
//postcondicion: modifica el tipo del descuento

void mod_tipo(descuentos_estr *vDescuentos){
    char tipo[50];
    printf("Introduce el nuevo tipo: ");
    if(scanf("%s", tipo) != 1){
        error_scanf();
    }
    strcpy((*vDescuentos).tipo, tipo);
}

//cabecera: mod_importe(descuento *vDescuentos)
//precondicion: vDescuentos es un puntero a estructura de tipo descuento
//postcondicion: modifica el importe del descuento

void mod_importe(descuentos_estr *vDescuentos){
    float importe;
    printf("Introduce el nuevo importe: ");
    if(scanf("%f", &importe) != 1){
        error_scanf();
    }
    strcpy((*vDescuentos).importe, importe);
}

//cabecera: mod_estado(descuento *vDescuentos)
//precondicion: vDescuentos es un puntero a estructura de tipo descuento
//postcondicion: modifica el estado del descuento

void mod_estado(descuentos_estr *vDescuentos){
    char estado;
    printf("Introduce el nuevo estado S o N: ");
    if(scanf("%s", estado) != 1){
        error_scanf();
    }
    if(estado == 'S' || estado == 'N'){
    (*vDescuentos).estado_d = estado;
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
        iguales(("Menu devoluciones"),'\0');
        printf("Menu devoluciones\n");
        iguales(("Menu devoluciones"),'\0');
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
    iguales(("Devoluciones"),'\0');
    printf("Devoluciones\n");
    iguales(("Devoluciones"),'\0');
    for(i = 0; i < nDevoluciones; i++){
        printf("Id pedido: %d\n", (*vDevoluciones).id_pedido);
        printf("Id producto: %d\n", (*vDevoluciones).id_producto);
        printf("Fecha: %d\n", (*vDevoluciones).fecha_devolucion);
        printf("Motivo: %s\n", (*vDevoluciones).motivo);
        printf("Estado: %s\n", (*vDevoluciones).estado);
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
    iguales(("Modificar devoluciones"),'\0');
    printf("Modificar devoluciones\n");
    iguales(("Modificar devoluciones"),'\0');
    printf("Introduce el Id de la devolucion a modificar: ");
    if(scanf("%d", &opcion) != 1){
        error_scanf();
    }
    for(i = 0; i < nDevoluciones; i++){
        if(opcion == (*vDevoluciones).id_pedido){
            printf("1 - Id producto: %d\n", (*vDevoluciones).id_producto);
            printf("2 - Fecha: %d\n", (*vDevoluciones).fecha_devolucion);
            printf("3 - Motivo: %s\n", (*vDevoluciones).motivo);
            printf("4 - Estado: %s\n", (*vDevoluciones).estado);
            printf("5 - Salir\n");
            printf("\n ¿Que campo desea modificar? 1, 2, 3, 4 o 5: ");
            if(scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 5){
                error_scanf();
            }
            switch(opcion){
                case 1:
                    mod_id_producto(vDevoluciones, nDevoluciones);
                    break;
                case 2:
                    mod_fecha_devolucion(vDevoluciones);
                    break;
                case 3:
                    mod_motivo(vDevoluciones);
                    break;
                case 4:
                    mod_estado(vDevoluciones);
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

void mod_id_producto(devolucion *vDevoluciones, int nDevoluciones){
    char id_producto;
    printf("\nIntroduce el nuevo id del producto: ");
    if(scanf("%d", &id_producto) != 1){
        error_scanf();
    }
    //comprobamos que el id del producto sea un entero y no sea repetido
    for (int i = 0; i < nDevoluciones; i++){
        if(id_producto == (*vDevoluciones).id_producto){
            printf("Error, el id del producto ya existe\n");
        }else{
            (*vDevoluciones).id_producto = id_producto;
        }
    }

}

//cabecera: mod_fecha_devolucion(devolucion *vDevoluciones)
//precondicion: vDevoluciones es un puntero a estructura de tipo devolucion
//postcondicion: modifica la fecha de la devolucion

void mod_fecha_devolucion(devolucion *vDevoluciones){
    char fecha_devolucion[50];
    printf("\nIntroduce la nueva fecha de devolucion: ");
    if(scanf("%d", &fecha_devolucion) != 1){
        error_scanf();
    }
    //comprobamos formato de fecha DD/MM/AAAA
    if(fecha_devolucion[2] == '/' && fecha_devolucion[5] == '/'){
        strcpy((*vDevoluciones).fecha_devolucion, fecha_devolucion);
    }else{
        printf("Error, introduce la fecha en formato DD/MM/AAAA\n");
    }
}

//cabecera: mod_motivo(devolucion *vDevoluciones)
//precondicion: vDevoluciones es un puntero a estructura de tipo devolucion
//postcondicion: modifica el motivo de la devolucion

void mod_motivo(devolucion *vDevoluciones){
    char motivo[50];
    printf("\nIntroduce el nuevo motivo: ");
    if(scanf("%s", motivo) != 1){
        error_scanf();
    }
    strcpy((*vDevoluciones).motivo, motivo);
}

//cabecera: mod_estado(devolucion *vDevoluciones)
//precondicion: vDevoluciones es un puntero a estructura de tipo devolucion
//postcondicion: modifica el estado de la devolucion

void mod_estado(devolucion *vDevoluciones){
    char estado;
    printf("\nIntroduce el nuevo estado S o N: ");
    if(scanf("%s", estado) != 1){
        error_scanf();
    }
    if(estado == 'S' || estado == 'N'){
        strcpy((*vDevoluciones).estado, estado);
    }else{
        printf("Error, introduce S o N\n");
    }
}


