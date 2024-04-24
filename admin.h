#ifndef ADMIN_H
#define ADMIN_H

#define N_id_empresa 5
#define N_Nombre 21
#define N_email 31
#define N_Contrasena 16
#define N_Perfil_usuario 13

#include "pedidos.h"
#include "Productos.h"
#include "Proveedor.h"
#include "Transportista.h"
#include "Clientes.h"


void menu_admin(usuarios **vUsuarios, int n);
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
int menu_trans(transportista_estr *vTransportista, int nTransportista);
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


#endif // ADMIN_H