#ifndef pedidos_h
#define pedidos_h

typedef struct {
    int id_pedido;
    char fecha[10];
    int id_cliente;
    char ciudad[50];
    int locker;
    char descuento[10];
}pedidos;

void menu_pedidos(int);
void switch_pedidos(int);

#endif