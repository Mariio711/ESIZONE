#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


#include "login.h"
#include "admin.h"
#include "Clientes.h"


int main (){
    // Establecer el idioma a español
    setlocale(LC_ALL, "es_ES.UTF-8"); // Cambiar locale - Suficiente para m�quinas Linux

    int nUsuarios=0;
    usuarios *vUsuarios;
    int nClientes=0;
    cliente_estr *vClientes;

    menu_login(&vUsuarios, &nUsuarios, &vClientes, &nClientes);
    //test_control_modif();
    //test_control_mat();       


    system("pause");
    return 0;
}