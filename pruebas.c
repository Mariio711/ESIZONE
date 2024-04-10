#include <stdio.h>
#include <libgen.h> // Para dirname()
#include <string.h>
void abrirArchivo() {
    FILE *archivo;
    char caracter;

    // Obtener la ruta del archivo fuente actual (__FILE__)
    char ruta_actual[1024]; // Tamaño suficientemente grande para la ruta
    strcpy(ruta_actual, __FILE__);

    // Obtener el directorio padre de la ruta actual
    char *directorio = dirname(ruta_actual);

    // Construir la ruta del archivo relativa a la ubicación del ejecutable
    char ruta_relativa[1024];
    sprintf(ruta_relativa, "%s/DATA/Clientes.txt", directorio);///<------------------AQUI SELECCIONAR EL FICHERO QUE QUIERAS METER

    // Abrir el archivo en modo lectura ("r")
    archivo = fopen(ruta_relativa, "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        perror("fopen");
        return;
    }

    // Leer y mostrar el contenido del archivo
    printf("Contenido del archivo:\n");
    while ((caracter = fgetc(archivo)) != EOF) {
        printf("%c", caracter);
    }

    // Cerrar el archivo
    fclose(archivo);
}

int main() {
    // Llamar a la función para abrir el archivo
    abrirArchivo();
    return 0;
}
