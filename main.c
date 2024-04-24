#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

#include "func_aux.h"
#include "login.h"


int main (){
    // Establecer el idioma a español
    setlocale(LC_ALL, "es_ES.UTF-8"); // Cambiar locale - Suficiente para m�quinas Linux
    SetConsoleCP(CP_UTF8); // Cambiar STDIN -  Para maquinas Windows
    SetConsoleOutputCP(CP_UTF8); // Cambiar STDOUT - Para maquinas Windows

    menu_login();
    //test_control_modif();
    //test_control_mat();       


    system("pause");
    return 0;
}