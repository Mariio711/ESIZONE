#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


#include "usuarios.h"


int main (){
    // Establecer el idioma a español
    setlocale(LC_ALL, "es_ES.UTF-8"); // Cambiar locale - Suficiente para m�quinas Linux

    int nUsuarios=0;
    usuarios *vUsuarios;

    menu_login(&vUsuarios, &nUsuarios);
    //test_control_modif();
    //test_control_mat();       //activar viajes.h

    system("pause");
    return 0;
}