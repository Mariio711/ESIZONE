//en este modulo se encuentra la funcion que se encarga de gestionar los usuarios, cargar los txt en los struct y la autenticacion del usuario

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <libgen.h>

#include "func_aux.h"
#include "Proveedor.h"
#include "Transportista.h"
#include "Clientes.h"
#include "admin.h"
#include "login.h"


void cargarusuarios(usuarios **,int *);
int aut_usuarios (usuarios **, int *, cliente_estr **, int *, transportista_estr **, int *);
int registro_usuario (cliente_estr **, int *);
int registro_admin_o_prov (usuarios **, int *, char perfil[20]);
int guardarusuarios(usuarios *, int);
void control_guardado_user(int, int *, usuarios **);



#define N_direccion 50
#define N_provincia 20

//definicion de funciones



//cabecera: void menu_login(usuarios vUsuarios, int nUsuarios)
//precondicion: recibe un puntero doble a estructuras de usuarios (usuarios) y un puntero a entero (int) que representa el número de usuarios.
//postcondicion: muestra un menú de inicio de sesión y registro de usuarios, y según la opción elegida, realiza las acciones correspondientes.

void menu_login(){

    usuarios *vUsuarios;
    int nUsuarios=0;
    cliente_estr *vClientes;
    int nClientes=num_clien();
    transportista_estr *vTransportistas;
    int nTransportistas=contar_lineas_transportista();
    

    cargarusuarios(&vUsuarios, &nUsuarios);
    descarga_clientes(vClientes, nClientes);
    descarga_transporte(vTransportistas);

    int resp=0;
    int aux;
    int control=0;
    while (control==0){
        system ("cls"); //limpia la terminal
        system ("COLOR B0"); //cambia color terminal a fondo celeste y letras negras
        layer_esizon();
        printf ("\tSeleccione una opción:\n\n\t1.Iniciar sesión\n\t2.Registrarse\n\t3.Salir\n\n\tOpción: ");
        if (scanf("%i", &resp) != 1 || (resp!=1 && resp!=2 && resp!=3)) {                      // Si scanf no pudo leer un número entero
            error_scanf();
        }
        
        switch (resp)
            {
            case 1:

                while(control==0){
                    control = aut_usuarios (&vUsuarios, &nUsuarios, &vClientes, &nClientes, &vTransportistas, &nTransportistas);
                }
                if(control==1){
                    control_guardado_user(control, &nUsuarios, &vUsuarios);
                }
                control = 0;
            break;
            case 2:
                aux=registro_usuario(&vClientes, &nClientes);
                system ("cls");                                                                                         
                printf ("\n\n\tUsuario registrado correctamente! Pulse cualquier tecla para ir a iniciar sesion");      
                fflush (stdin);                                                                                         
                getchar ();
                while(control==0){
                    control = aut_usuarios (&vUsuarios, &nUsuarios, &vClientes, &nClientes, &vTransportistas, &nTransportistas);
                }
                if(control==1){
                    control_guardado_user(control, &nUsuarios, &vUsuarios);
                }
                control = 0;
                break;
    case 3:
        control = 1;
        break;
    }
    }
        
}

//cabecera: void cargarusuarios(usuarios **,int *);
//precondicion: se le pasa un puntero a un puntero de struct usuarios y un puntero a un entero
//postcondicion: se encarga de cargar los datos de los usuarios en un txt Los campos, separados por guiones, son: Id_empresa, Nombre, email, Contrasena y Perfil_usuario.

void cargarusuarios(usuarios **vUsuarios, int *n) {
    
    FILE *fichero;
	int len;
    char linea[100];             // Guardar cada linea que leamos del fichero.
    char *token=NULL;

    *vUsuarios=NULL;
    *n=0;


    fichero = fopen("./DATA/AdminProv.txt" , "r");
    if (fichero == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
    }
    else {    	
		do{ 
            if (((fgets(linea,100,fichero) ) != (NULL) )){     
            
                *vUsuarios=realloc((usuarios *)(*vUsuarios),((*n)+1)*sizeof(usuarios));
				
				len=strlen(linea);

                    if (linea[len - 1] == '\n') {
                    linea[len - 1] = '\0';
                    } else {
                    linea[len] = '\n';
                    linea[len + 1] = '\0';
                    }// Eliminamos el retorno de la cadena del fichero de texto
              
               
			    token=strtok(linea,"-");
			    if (token==NULL) break;
				
        
                if (token!= NULL ) {
                	strcpy((*vUsuarios)[*n].Id_empresa,token);
				}
				
				token=strtok(NULL,"-");
				if (token==NULL) break;
 				
                if (token!= NULL ) {
                	strcpy((*vUsuarios)[*n].Nombre,token);
				}
				
				token=strtok(NULL,"-");
				if (token==NULL) break;
 
				if (token!= NULL) {
                	strcpy((*vUsuarios)[*n].email,token);
				}

				token=strtok(NULL,"-");
				if (token==NULL) break;
				
				if (token!= NULL ) {
                	strcpy((*vUsuarios)[*n].Contrasena,token);
				}

			    token=strtok(NULL,"-");
			    if (token==NULL) break;
			
			    if (token!= NULL ) {
                	strcpy((*vUsuarios)[*n].Perfil_usuario,token);
                }
		  
		        (*n)++;  
            }
        }while(!feof(fichero));
    }
    fclose(fichero);
}

//cabecera: int aut_usuarios (usuarios **, int*);
//precondicion: se le pasa un puntero a un puntero de struct usuarios y un puntero a un entero
//postcondicion: se encarga de autenticar al usuario, si el usuario es correcto devuelve 1, si no 0

int aut_usuarios (usuarios **vUsuarios, int *nUsuarios, cliente_estr **vClientes, int *nClientes, transportista_estr **vTransportistas, int *nTransportistas){
    system ("cls");
    system ("COLOR B0");

    int i;
    int existe=0;
    char email[31], contrasena[16];
    int control=0;
    do{
        layer_esizon();
        printf("\tIntroduzca su email: ");
        if (scanf("%s", email) != 1) {                      // Si scanf no pudo leer un número entero
            error_scanf();
            control=1;
        }
        printf("Introduzca su contrasena:");  
        if (scanf("%s",contrasena) != 1) {                      // Si scanf no pudo leer un número entero
            error_scanf();
            control=1;
        }
    }while(control==1);

    for(i=0;i<*nUsuarios;i++){
        if(strcmp((*vUsuarios)[i].email,email)==0){
            existe=1;
            if(existe == 1 && strcmp((*vUsuarios)[i].Contrasena,contrasena)==0){
                if(strcmp((*vUsuarios)[i].Perfil_usuario,"admin")==0){
                    menu_admin(vUsuarios, i);
                    return 1;
                }
                if(strcmp((*vUsuarios)[i].Perfil_usuario,"proveedor")==0){
                    inicio_prov(i);
                    return 1;
                }
            } else {
                puts ("\t\tERROR: Contraseña incorrecta, intentalo de nuevo");
                printf("\n\tPulsa ENTER para continuar...\n");
                fflush(stdin);
                getchar();
                system("cls");
                return 0;
            }
            if(existe==0){
                for (i=0; i<*nClientes; i++){
                    if(strcmp((*vClientes)[i].correo,email)==0 ){
                        existe=1;
                        if(strcmp((*vClientes)[i].clave,contrasena)==0 && existe==1){
                            inicio_cliente(i);
                            return 1;
                        } else {
                            puts ("\t\tERROR: Contraseña incorrecta, intentalo de nuevo");
                            printf("\n\tPulsa ENTER para continuar...\n");
                            fflush(stdin);
                            getchar();
                            system("cls");
                            return 0;
                        }
                    }
                }
            }

            if (existe == 0){
                for (i=0; i<*nTransportistas; i++){
                    if(strcmp((*vTransportistas)[i].email,email)==0 ){
                        existe=1;
                        if(strcmp((*vTransportistas)[i].contra,contrasena)==0 && existe==1){
                            menu_transporte(*vTransportistas, i);
                            return 1;
                        } else {
                            puts ("\t\tERROR: Contraseña incorrecta, intentalo de nuevo");
                            printf("\n\tPulsa ENTER para continuar...\n");
                            fflush(stdin);
                            getchar();
                            system("cls");
                            return 0;
                        }
                    }
                }
            }
            {
                
            }
            
        }
    }
    

    if (existe==0){
        int auxnus;
        do{
            printf("\n\t\tERROR: El usuario no esta registrado, introduce otro usuario valido(1) o registrese(2): ");
            scanf("%d" ,&auxnus);
        }while (auxnus!=1 && auxnus!=2);

        switch(auxnus){
            case 1:
                return 0;
            break;
            case 2:
                while(auxnus==0){
                    auxnus=registro_usuario(vClientes, nClientes);
                }
                return 1;
            break;
        }
    }
    return 1;
}

//cabecera: int registro_usuario (usuarios **, int *);
//precondicion: se le pasa un puntero a un puntero de struct usuarios y un puntero al numerop de clientes
//postcondicion: se encarga de registrar a un usuario, si el usuario es correcto devuelve 1, si no 0

int registro_usuario (cliente_estr **vClientes, int *nClientes){
    int aux1=(*nClientes);
    char aux[50];
    *vClientes=realloc((cliente_estr *)(*vClientes),((*nClientes)+1)*sizeof(cliente_estr));
    //comprobacion realloc ok
    if (*vClientes == NULL) {
        printf("Error: no se pudo asignar memoria se borraran todos los datos sin guardar\n");
        exit(1);
    }
    (*nClientes)++;

    do{

        system("cls");
        layer_esizon();
        iguales(("REGISTRO DE USUARIO"));
        printf ("REGISTRO DE USUARIO\n");
        iguales(("REGISTRO DE USUARIO"));

        printf("\t\n\nIntroduzca email: ");
        leer_string(aux, N_email);
    }while(strlen(aux)>N_email);
    strcpy((*vClientes)[(*nClientes)-1].correo,aux);

    do{

        system("cls");
        layer_esizon();
        iguales(("REGISTRO DE USUARIO"));
        printf ("REGISTRO DE USUARIO\n");
        iguales(("REGISTRO DE USUARIO"));

        printf("\n\tIntroduzca contraseña (max 8 caracteres): ");
        leer_string(aux, N_Contrasena);
    }while(strlen(aux)>N_Contrasena);
    strcpy((*vClientes)[(*nClientes)-1].clave,aux);

        system("cls");
        layer_esizon();
        iguales(("REGISTRO DE USUARIO"));
        printf ("REGISTRO DE USUARIO\n");
        iguales(("REGISTRO DE USUARIO"));

        mostrar_poblaciones(aux);
        strcpy((*vClientes)[(*nClientes)-1].localidad,aux);

    do{

        system("cls");
        layer_esizon();
        iguales(("REGISTRO DE USUARIO"));
        printf ("REGISTRO DE USUARIO\n");
        iguales(("REGISTRO DE USUARIO"));

        printf("\n\tIntroduzca nombre: ");
        leer_string(aux, N_Nombre);
    }while(strlen(aux)>N_Nombre);
    strcpy((*vClientes)[(*nClientes)-1].nombre,aux);

    do{

        system("cls");
        layer_esizon();
        iguales(("REGISTRO DE USUARIO"));
        printf ("REGISTRO DE USUARIO\n");
        iguales(("REGISTRO DE USUARIO"));

        printf("\n\tIntroduzca direccion: ");
        leer_string(aux, N_direccion);
    }while(strlen(aux)>N_direccion);
    strcpy((*vClientes)[(*nClientes)-1].direccion,aux);

    do{

        system("cls");
        layer_esizon();
        iguales(("REGISTRO DE USUARIO"));
        printf ("REGISTRO DE USUARIO\n");
        iguales(("REGISTRO DE USUARIO"));

        printf("\n\tIntroduzca provincia: ");
        leer_string(aux, N_provincia);
    }while(strlen(aux)>N_provincia);
    strcpy((*vClientes)[(*nClientes)-1].provincia,aux);

    if (*nClientes > 1) {
        ((*vClientes)[*nClientes-1].id)=((*vClientes)[(*nClientes)-2].id)+1;
    } else {
        ((*vClientes)[*nClientes-1].id) = 1;
    }


    carga_clientes((*vClientes), (*nClientes));

    if(aux1>=(*nClientes)){
        return 1;
    }else{
        return 0;
    }
}


//cabecera: int registro_admin_o_prov (usuarios **vUsuarios, int *n, char perfil[20])
//precondicion: recibir un puntero a un array dinámico de estructuras usuarios, y un puntero al número de usuarios totales (n)
//postcondicion: retorna el índice del nuevo usuario añadido al array dinámico de estructuras usuarios

int registro_admin_o_prov (usuarios **vUsuarios, int *n, char perfil[20]){

    int aux1=(*n);
    char aux[50];
    *vUsuarios=realloc((usuarios *)(*vUsuarios),((*n)+1)*sizeof(usuarios));
    //comprobacion realloc ok
    if (*vUsuarios == NULL) {
        printf("Error: no se pudo asignar memoria se borraran todos los datos sin guardar\n");
        exit(1);
    }
    (*n)++;

    do{

        system("cls");
        layer_esizon();
        iguales(("REGISTRO DE USUARIO"));
        printf ("REGISTRO DE USUARIO\n");
        iguales(("REGISTRO DE USUARIO"));

        printf("\t\n\nIntroduzca email: ");
        leer_string(aux, N_email);
    }while(strlen(aux)>N_email);

    if(strcmp(perfil,"administrador")==0){
        strcpy((*vUsuarios)[(*n)-1].Id_empresa,"0001");
        strcpy((*vUsuarios)[(*n)-1].Nombre,"ESIZON");
    }else{
    do{
    strcpy((*vUsuarios)[(*n)-1].email,aux);


        system("cls");
        layer_esizon();
        iguales(("REGISTRO DE USUARIO"));
        printf ("REGISTRO DE USUARIO\n");
        iguales(("REGISTRO DE USUARIO"));

        printf("\n\tIntroduzca empresa: ");
        leer_string(aux, N_Nombre);
        for(int i=0; i<(*n)-1; i++){
            if(strcmp((*vUsuarios)[i].Nombre,aux)==0){

                strcpy((*vUsuarios)[(*n)-1].Id_empresa,(*vUsuarios)[i].Id_empresa);
                break;
            }
        }
    strcpy((*vUsuarios)[(*n)-1].Nombre,aux);
    }while(strlen(aux)>N_Nombre);
    }


    do{

        system("cls");
        layer_esizon();
        iguales(("REGISTRO DE USUARIO"));
        printf ("REGISTRO DE USUARIO\n");
        iguales(("REGISTRO DE USUARIO"));

        printf("\n\tIntroduzca contraseña (max 8 caracteres): ");
        leer_string(aux, N_Contrasena);
    }while(strlen(aux)>N_Contrasena);
    strcpy((*vUsuarios)[(*n)-1].Contrasena,aux);

    //copia el perfil del usuario
    strcpy((*vUsuarios)[(*n)-1].Perfil_usuario, perfil);

    guardarusuarios((*vUsuarios), (*n));

    if(aux1>=(*n)){
        return 1;
    }else{
        return 0;
    }
}

//cabecera: int guardarusuarios(usuarios *u, int tam)
//precondicion: recibir un puntero a un array de estructuras usuarios y un entero con el número de usuarios del array
//postcondicion: escribe en un fichero la lista completa de usuarios con sus datos. Si no se puede acceder al fichero, se imprime un mensaje de error y se sale del programa.
// de los usuarios en un txt Los campos, separados por guiones, son: Id_empresa, Nombre, email, Contrasena y Perfil_usuario.

int guardarusuarios(usuarios *u, int tam){
    FILE *f;
    int i;
    f = fopen("./DATA/AdminProv.txt", "w");
    if (f == NULL) {
        printf("Error al abrir el fichero 2\n");
        exit(1);
    }
    for (i = 0; i < tam; i++) {
        fprintf(f, "%s-%s-%s-%s-%s\n", u[i].Id_empresa, u[i].Nombre, u[i].email, u[i].Contrasena, u[i].Perfil_usuario);
    }
    fclose(f);
    return 1;
}

//cabecera: void control_guardado_user(int control, int *nUsuarios, usuarios **vUsuarios)
//precondicion: control es un entero que indica si se realizaron cambios en el perfil del usuario,
// nUsuarios es un puntero al número total de usuarios almacenados y vUsuarios es un puntero a un vector de estructuras de tipo usuarios.
// El vector vUsuarios debe tener al menos *nUsuarios elementos.
//postcondicion: La función guarda los cambios realizados en el perfil del usuario en el archivo "usuario.txt" si se detectaron cambios 
//(es decir, si control es igual a 1) y muestra un mensaje en caso contrario.
void control_guardado_user(int control, int *nUsuarios, usuarios **vUsuarios){
    if (control==1)
    guardarusuarios((*vUsuarios), (*nUsuarios));
    else
    printf("\n\tNo se han guardado los datos");
}

