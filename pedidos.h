#ifndef pedidos_h
#define pedidos_h


typedef struct {
    char id_pedido[7];
    char fecha[10];
    char id_cliente[7];
    char locker[10];
    float importe;
}pedidos;

typedef struct {
    char id_pedido[7];
    char id_producto[7];
    int unidades;
    char fecha_prevista[10];
    float importe;
    char estado;
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

#endif