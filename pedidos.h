#ifndef pedidos_h
#define pedidos_h


typedef struct {
    char id_pedido[7];
    char fecha[10];
    char id_cliente[7];
    char estado[13];
    char locker[10];
    float importe;
}pedidos;

typedef struct {
    char id_pedido[7];
    char id_producto[7];
    char unidades;
    char fecha_prevista[10];
    float importe;
    char estado[13];
    char id_trans[4];
    char id_locker[10];
    char codigo_locker[4];
    char fecha_entrega[10];
}productos_pedidos;

typedef struct devoluciones
{
    char id_pedido[7];
    char id_producto[7];
    char fecha_devolucion[10];
    char motivo[50];
    char estado;
}devolucion;

void principal_pedidos(int aux,int id);
void menu_cliente(pedidos *pedido_cli, productos_pedidos *pedido_trans, int id);
void opciones_cliente();
void mostrar_pedidos_usuario(pedidos *pedido_cli, int id, int aux);
void devolver_pedido(pedidos *pedido_cli, productos_pedidos *pedido_trans, int id);
void cancelar_pedido(pedidos *pedido_cli, productos_pedidos *pedido_trans, int id);
int contar_lineas_pedidos();
int contar_lineas_pedidos_productos();
void menu_transportista(pedidos *pedido_cli, productos_pedidos *pedido_trans, int id);
void mostrar_pedidos_transportista(pedidos *pedido_cli, productos_pedidos *pedido_trans, int id);
void gestionar_devoluciones(pedidos *pedido_cli, productos_pedidos *pedido_trans, int id);
void opciones_gestionar_devoluciones();
void opciones_transportista();
void carga_txt_pedidos(pedidos *pedido_cli);
void carga_txt_productos_pedidos(productos_pedidos *pedido_trans);
void descarga_txt_pedidos(pedidos *pedido_cli);
void carga_txt_productos_pedidos(productos_pedidos *pedido_trans);


#endif