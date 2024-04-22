#ifndef pedidos_h
#define pedidos_h

typedef struct {
    char id_pedido;
    char fecha[10];
    char id_cliente;
    char ciudad[50];
    int locker;
    char descuento[10];
}pedidos;

typedef struct {
    char id_pedido[7];
    char id_producto[7];
    int unidades;
    char fecha_prevista[10];
    float importe;
    char estado;
    char id_tran[4];
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
};


void carga_txt(FILE *, pedidos *, productos_pedidos *, int , int);
int numero_pedidos(FILE *, int , int);
void recopilacion_pedidos(pedidos *, productos_pedidos *, int, int, int);
void menu_pedidos(int);
void switch_pedidos(int);
void mostrar_pedidos(int aux);

#endif