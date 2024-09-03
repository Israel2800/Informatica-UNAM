// Realiza el programa completo para la búsqueda de un elemento, con 
// el método de búsqueda lineal, en donde declares un menú para que 
// el usuario inserte elementos y después haga una búsqueda. Envía un 
// archivo PDF con el código fuente del programa, así como las pantallas 
// de la salida que haya generado tu programa en un archivo.


#include <stdio.h>
#include <string.h>

int main() {
    int n, elemento, continuar, cambiarCantidad;
    
    do {
        printf("Ingrese la cantidad de elementos que desea tener en el arreglo: ");
        scanf("%d", &n);
        
        int arreglo[n];
        
        printf("Ingrese los elementos del arreglo:\n");
        for (int i = 0; i < n; i++) {
            printf("Elemento %d: ", i + 1);
            scanf("%d", &arreglo[i]);
        }
        
        do {
            printf("Ingrese el elemento que desea buscar: ");
            scanf("%d", &elemento);
            
            // Búsqueda lineal
            int encontrado = 0;
            printf("El elemento %d se encuentra en las siguientes posiciones del arreglo:\n", elemento);
            for (int i = 0; i < n; i++) {
                if (arreglo[i] == elemento) {
                    encontrado = 1;
                    printf("Posicion %d\n", i);
                }
            }
            
            if (!encontrado) {
                printf("El elemento %d no se encuentra en el arreglo.\n", elemento);
            }
            
            printf("¿Desea buscar otro elemento? (1 para si, 0 para no): ");
            scanf("%d", &continuar);
        } while (continuar == 1);
        
        printf("¿Desea introducir una nueva cantidad de elementos en el arreglo? (1 para si, 0 para no): ");
        scanf("%d", &cambiarCantidad);
    } while (cambiarCantidad == 1);
    
    return 0;
}
