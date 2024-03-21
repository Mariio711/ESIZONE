#include <stdio.h>
#include <string.h>

void menu_transporte(FILE *);
void intro_transportista();

int main(/*recibe id del transportista*/){ 
    FILE *fichero_transporte;

    menu_transporte(fichero_transporte);

}

void menu_transporte(FILE *fichero){
    int option;

    if((fichero=fopen("transportistas.txt","w"))==NULL){
        printf("Error de apertura del fichero\n");
    }
    else{
        intro_transportista();

        do{
            scanf("%i",&option);
        }while(0>=option && option>=5);
        switch(option){
            case 1:
                /*funcion que nos permita modificar el fichero con la informacion del transportista*/
                break;
            case 2:
                /*funcion que nos permita ver los estados de los pedidos */
                break;
            case 3:
                /*funcion que gestione un txt con los pedidos en tramite de devolucion*/
                break;
            case 4:
                /*exit*/
                break;
            }


    }

    fclose(fichero);
}

void intro_transportista(){
    printf("Transportista %s\n"/*funcion que obtenga el nombre transportista del txt*/);
    printf("1.Perfil\n");
    printf("2.Pedidos\n");
    printf("3.Retornos\n");
    printf("6.Salir del sistema\n");

}
