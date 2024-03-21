#ifndef TRANSPORTISTA_H
#define TRANSPORTISTA_H

//LA ESTRUCTURA DE TRANSPORTISTA
typedef struct{
    int id;
    char nombre[20];
    char email[30];
    char contra[15];
    char nom_empresa[20];
    char ciudad[20]
}transportista_estr;

void intro_transportista(); //funcion dedicada a mostrar graficamente las opciones del menu
void menu_transporte(FILE *); //funcion para seleccionar la opcion del menu que querramos

#endif