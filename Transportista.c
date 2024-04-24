#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include "pedidos.h"
#include "Transportista.h"


#define N_localidad 8

int main(){ //debe recibir id
    int id;
    transportista_estr *transportista;
    carga_transporte(transportista);
    
    menu_transporte(transportista,id);
}

void intro_transportista(transportista_estr *transportista){
    printf("Transportista %s\n",transportista->nombre);
    printf("1.Perfil\n");
    printf("2.Pedidos\n");
    printf("3.Salir del sistema\n");
}

void menu_transporte(transportista_estr *transportista, int id){
    int option;

    intro_transportista(transportista);

    do{                                 //bucle para control de entrada
          scanf("%i",&option);
    }while(0>=option && option>=4); 
     switch(option){
        case 1:
            perfil_transportista(transportista, id);
            break;
        case 2:
            descarga_transporte(transportista);
            principal_pedidos(1,id);
            break;
        case 3:
            descarga_transporte(transportista);
            exit(-1);   
    }
}

void menu_perfil(){
    printf("1. Mostrar informacion\n");
    printf("2. Modificar perfil\n");
    printf("3. Volver atras\n");
    printf("4. Salir\n");
}

void perfil_transportista(transportista_estr *transportista, int id){
    int option;
    system("cls");
    menu_perfil();
    
    do{                                 //bucle para control de entrada
          scanf("%i",&option);
    }while(0>=option && option>=5); 
     switch(option){
        case 1:
            mostrar_info_transportista(transportista, id);
            break;
        case 2:
            mod_transporte(transportista, id);
            break;
        case 3:
            menu_transporte(transportista, id);
            break;
        case 4:
            exit(-1);
            break;
    }
}


void mostrar_info_transportista(transportista_estr *transportista, int id){
    int option;
    system("cls");

    printf("La informacion del usuario es:\n");
    printf("ID: %i\n",(transportista)->id);
    printf("Nombre: %s\n",(transportista)->nombre);
    printf("Email: %s\n",(transportista)->email);
    printf("Empresa: %s\n",(transportista)->nom_empresa);
    printf("Ciudad: %s\n",(transportista)->ciudad);
    printf("\n");

    printf("Desea salir (1) o volver atras (2)?");
    do{                                 //bucle para control de entrada
          scanf("%i",&option);
    }while(option!=1 && option!=2);
    if(option==1){
        exit(-1);
    }
    if(option==2){
        perfil_transportista(transportista,id);
    }
}

int contar_lineas_transportista(){
    FILE *archivo;
    int j=1;
    char c;
    
    //system("cls");

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Clientes.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Transportista.txt", directorio);

    archivo = fopen(ruta_relativa, "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        perror("fopen");
    }
    else{
        do{
            if(fgetc(archivo)=='\n'){
                j++;
            }
        }while(c!=EOF);
    }
    fclose(archivo);// Cerrar el fichero
    return(j);
}

void menu_mod(){
    printf("Seleccione una opcion\n");
    printf("1. Modificar nombre\n");
    printf("2. Modificar ciudad\n");
    printf("3. Modificar email\n");
    printf("4. Modificar contraseña\n");
    printf("5. Volver atras\n");
    printf("6. Salir del sistema\n");
}

void mod_transporte(transportista_estr *transportista, int id){
    int option,i=0,j=contar_lineas_transportista();
    system("cls");
    menu_mod();

    do{
        if(id==transportista->id){
            do{                                 //bucle para control de entrada
                scanf("%i",&option);
            }while(0>=option && option>=5); 
            switch(option){
                case 1:
                    mod_nom(transportista,id);
                    break;
                case 2:
                    mod_ciudad(transportista,id);
                    break;
                case 3:
                    mod_email(transportista,id);
                    break;
                case 4:
                    mod_contr(transportista,id);
                    break;
                case 5:
                    perfil_transportista(transportista,id);
                    break;
                case 6:
                    exit(-1);
                    break;
            }
        }
    }while(i<j);
}

void mod_nom(transportista_estr *transportista, int id){
    int flag=0;
    system("cls");
    printf("Tu nombre actual es: %s\nintroduce tu nuevo nombre:\n",transportista->nombre);
    do{
        if(leer_string(transportista->nombre,N_nombre)==1){
            printf("Error de alamacenamiento");
            flag=1;
        }
    }while (flag==1);
    seleccion_tras_mod(transportista, id);
}

void mod_ciudad(transportista_estr *transportista, int id){
    system("cls");
    mostrar_poblaciones(transportista->ciudad);  
    seleccion_tras_mod(transportista, id);
}

void mod_email(transportista_estr *transportista, int id){
    int flag=0;
    system("cls");
    printf("Tu email actual es: %s\nintroduce tu nuevo nombre:\n",transportista->email);
    do{
        if(leer_string(transportista->email,N_nombre)==1){
            printf("Error de alamacenamiento");
            flag=1;
        }
    }while (flag==1);
    seleccion_tras_mod(transportista, id);
}

void mod_contr(transportista_estr *transportista, int id){
    int flag=0;
    system("cls");
    printf("Tu contraseña actual es: %s\nintroduce tu nuevo nombre:\n",transportista->contra);
    do{
        if(leer_string(transportista->contra,N_nombre)==1){
            printf("Error de alamacenamiento");
            flag=1;
        }
    }while (flag==1);
    seleccion_tras_mod(transportista, id);
}

void seleccion_tras_mod(transportista_estr *transportista, int id){
    int option;
    printf("Cambio realizado correctamente\n Desea salir (1), volver atras (2) o volver al menu principal (3)?\n");
    do{                                 //bucle para control de entrada
          scanf("%i",&option);
    }while(option!=1 && option!=2 && option!=3);
    switch (option)
    {
    case 1:
        exit(-1);
        break;
    case 2:
        mod_transporte(transportista, id);
        break;
    case 3:
        menu_transporte(transportista, id);
        break;
    }
}

void carga_transporte(transportista_estr *transportista){
    int i=0,num_guion=0;
    FILE *archivo;
    char c;
    char id[7];
    
    system("cls");

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Clientes.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Transportista.txt", directorio);

    archivo = fopen(ruta_relativa, "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        perror("fopen");
    }
    else{//pilla los datos del fichero
        memset(id, 0, 8);
        memset(transportista->nombre, 0, 21);
        memset(transportista->email, 0, 31);
        memset(transportista->contra, 0, 16);//vacia para no pillar basura en los vectores
        memset(transportista->nom_empresa, 0, 21);
        memset(transportista->ciudad, 0, 21);
        do{
            c=fgetc(archivo);
            if(num_guion==0 && c!='-' && c!=EOF)
                id[i]=c;//id
            if(num_guion==1 && c!='-' && c!=EOF)
                transportista->nombre[i]=c;//nombre
            if(num_guion==2 && c!='-' && c!=EOF)
                transportista->email[i]=c;//direccion
            if(num_guion==3 && c!='-' && c!=EOF)
                transportista->contra[i]=c;//localidad
            if(num_guion==4 && c!='-' && c!=EOF)
                transportista->nom_empresa[i]=c;//provincia
            if(num_guion==5 && c!='-' && c!=EOF)
                transportista->ciudad[i]=c;//correo
            if(c=='-'){
                num_guion++;
                i=-1;
            }
            i++;
        }while(c!=EOF);
        transportista->id=atoi(id);
    }
    printf("\nid: %i\nnombre: %s\nemail: %s\ncontra: %s\nnom_empresa: %s\nciudad: %s\n", transportista->id, transportista->nombre, transportista->email, transportista->contra, transportista->nom_empresa, transportista->ciudad);
    fclose(archivo);// Cerrar el archivo
}

char poblacion[N_localidad][50] = {
    "Sanlucar de Bda",
    "Jerez de la Fra",
    "Cadiz",
    "Puerto real",
    "San Fernando",
    "Chiclana de la Fra",
    "El Pto de Santa Maria", 
    "Chipiona",
};

//cabecera: void mostrar_poblaciones(char* seleccionado)
//precondicion: recibe un puntero a caracteres (char*) que representa la población seleccionada
//postcondicion: muestra por pantalla las poblaciones disponibles y permite seleccionar una de ellas.
void mostrar_poblaciones(char* seleccionado) {

    int i,opcion=0;
     do {
    printf("\n\n\tSeleccione una población:\n\n");
    for (i = 0; i < N_localidad; i++){
        printf("\t\t%d. %s\n", i+1, poblacion[i]);
    }
    printf("\n\n\tOpcion: ");

    opcion = 0;
        if (scanf("%d", &opcion) != 1 || ( opcion < 1 || opcion > N_localidad)) {
            error_scanf();
        }
    } while (opcion < 1 || opcion > N_localidad);

    strcpy(seleccionado, poblacion[opcion-1]);
}


//cabecera: int leer_string(char aux, int MAX)
//precondicion: recibe un puntero a caracteres (char) y un entero MAX que indica la longitud máxima de caracteres que se pueden leer
//postcondicion: lee una cadena de caracteres de la entrada del usuario y la almacena en aux. Devuelve 1 si la entrada supera MAX caracteres y 0 en caso contrario.
int leer_string(char *aux, int MAX) {
    // Leer la entrada del usuario
    fflush(stdin);
    if (fgets(aux, MAX+2, stdin) == NULL) {
        // Si fgets() falla, establecer aux[0] en '\0'
        aux[0] = '\0';
        return 1;
    }

    // Verificar si la entrada excede el tamaño máximo del buffer
    if (strlen(aux) == MAX+1 && aux[MAX] != '\n') {
        // Si la entrada es demasiado larga, descartar el resto de la entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // Eliminar el salto de línea final, si existe
    aux[strcspn(aux, "\n")] = '\0';
}

//cabecera: void error_scanf()
//precondicion: no recibe nada
//postcondicion: muestra por pantalla un mensaje de error por una entrada no compatible con scanf.
void error_scanf(){

    printf("\n\tError: Entrada no compatible, introduzca de nuevo\n");
    printf("\n\tPulsa ENTER para continuar...\n");
    fflush(stdin);  // Limpia el búfer de entrada       
    getchar();      //pausa
    system("cls");
}

//cabecera: int modif(char *modificador, int N)
//precondicion: modificador es un puntero a una cadena de caracteres y N es un entero que indica la longitud máxima de la cadena. modificador debe tener al menos N+1 elementos.
//postcondicion: La función lee una cadena de caracteres desde el teclado y la almacena en modificador, siempre y cuando la cadena no supere la longitud máxima indicada por N.
// La función retorna 1 si la cadena se pudo modificar y 0 en caso contrario.
int modif(char *modificador, int N){

    char aux[50];
    int auxi, control=0;;

    do{
        leer_string(aux, 50);
        
        if(strlen(aux)>N){
            control=1;
            printf("\n\tLa cadena no puede tener mas de %i caracteres", N);
            printf("\n\tIntroduce de nuevo (max %i caracteres): ", N);
        }else{
            control=0;
        }
        
    }while(control==1);

    control_modif(modificador, aux, N);
}

//cabecera: int control_modif(char *modificador, char aux)
//precondicion: recibe dos punteros a caracteres (char): modificador, que representa el valor original, y aux, que representa el nuevo valor propuesto
//postcondicion: muestra por pantalla una confirmación para cambiar de modificador a aux y devuelve un entero indicando si se realizó o no la modificación
int control_modif(char *modificador, char *aux, int MAX){

    int auxi;
    printf("\n\tEstas seguro de cambiar de %s a %s, si(1) o no (0): ",modificador, aux);
    if (scanf("%i", &auxi) != 1 || (auxi!=1 && auxi!=0)) {                      // Si scanf no pudo leer un número entero
        error_scanf();
        return 0;
    }
    if (auxi==0){
        return 0;
    }
    fflush(stdin);
    if(strcmp(strcpy(modificador,aux),aux) == 0 && strlen(aux) <= MAX){
        printf("\n\n\tLA MODIFIACION SE REALIZO CON EXITO");
        return 1;
    }else{
        printf("\n\n\tLA MODIFIACION NO SE REALIZO CORRECTAMENTE, VUELVA A INTENTARLO");
        return 0;
    }
}

void descarga_transporte(transportista_estr *transportista){
    FILE *archivo;
    int i=0;
    int n=contar_lineas_transportista();
    //system("cls");

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);
    // Obtener el directorio padre de la ruta actual                            ///como el fichero Clientes.txt esta en una carpeta
    char *directorio = dirname(ruta_actual);                                    ///hacemos una ruta relativa para que lo lea sin problemas
    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Transportista.txt", directorio);

    archivo = fopen(ruta_relativa, "w");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        perror("fopen");
    }
    else{
        do{
            fprintf(archivo,"%s-",(transportista+i)->id);
            fprintf(archivo,"%s-",(transportista+i)->nombre);
            fprintf(archivo,"%s-",(transportista+i)->email);
            fprintf(archivo,"%s-",(transportista+i)->contra);
            fprintf(archivo,"%.2f-",(transportista+i)->nom_empresa);
            fprintf(archivo,"%s\n",(transportista+i)->ciudad);
            i++;
        }while(i!=n-1);
    }
    fclose(archivo);// Cerrar el fichero
    printf("\ncarga completada\n");
}