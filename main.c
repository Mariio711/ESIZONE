#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


#include "admin.h"
#include "Clientes.h"
#include "login.h"


int main (){
    // Establecer el idioma a español
    setlocale(LC_ALL, "es_ES.UTF-8"); // Cambiar locale - Suficiente para m�quinas Linux

    menu_login();
    //test_control_modif();
    //test_control_mat();       


    system("pause");
    return 0;
}