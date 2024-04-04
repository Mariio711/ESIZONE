#ifndef pedidos.h
#define pedidos.h

typedef struct {
    int id_pedido;
    char fecha[10];
    int id_cliente;
    char ciudad[];
    int locker;
    char descuento[10];
}pedidos;

void menu_pedidos(int);
void switch_pedidos(int);

#endif