// Instrucciones
// Desarrolla en Lenguaje C el programa de una pila utilizando un arreglo, recuerda incluir por lo menos las operaciones push() y pop(), así como otras operaciones que sean necesarias. Para esta actividad, elige 4 nombres propios de personas pues la pila los almacenará. El programa principal realizará las siguientes operaciones: 
// 2. Extraer un nombre 
// 3. Insertar 4 nombres 
// 4. Extraer 2 nombres 
// 5. Extraer 3 nombres 


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_TAMANO_PILA 5

// Definición de la estructura de la pila y el tamaño que tendrá
typedef struct {
    char nombres[MAX_TAMANO_PILA][30];
    int tope;
} Pila;

// Función para inicializar la pila
void inicializarPila(Pila *pila) {
    pila->tope = -1;
}

// Función para verificar si la pila está vacía
bool estaVacia(Pila *pila) {
    return pila->tope == -1;
}

// Función para verificar si la pila está llena
bool estaLlena(Pila *pila) {
    return pila->tope == MAX_TAMANO_PILA - 1;
}

// Función para agregar un nombre a la pila utlilizando (push)
void push(Pila *pila, char nombre[]) {
    if (estaLlena(pila)) {
        printf("La pila esta llena. No se puede agregar el nombre: %s\n", nombre);
    } else {
        pila->tope++;
        strcpy(pila->nombres[pila->tope], nombre);
        printf("Nombre \"%s\" agregado a la pila.\n", nombre);
    }
}

// Función para eliminar un nombre de la pila utilizando (pop)
void pop(Pila *pila) {
    if (estaVacia(pila)) {
        printf("La pila esta vacia. No se puede extraer un nombre.\n");
    } else {
        printf("Nombre \"%s\" extraido de la pila.\n", pila->nombres[pila->tope]);
        pila->tope--;
    }
}

int main() {
    Pila pila;
    inicializarPila(&pila);

    int opcion;
    char nombre[30];

    do {
        printf("\nOperaciones disponibles:\n");
        printf("1. Insertar un nombre\n");
        printf("2. Extraer un nombre\n");
        printf("3. Insertar 4 nombres\n");
        printf("4. Extraer 2 nombres\n");
        printf("5. Extraer 3 nombres\n");
        printf("0. Salir\n");
        printf("Elija una opcion: ");
        
        // Leer la opción del usuario
        if (scanf("%d", &opcion) != 1) {
            // Si la entrada no es un número válido, limpiar el búfer de entrada
            while (getchar() != '\n');
            printf("Opcion no valida. Por favor, elija una de las opciones disponibles.\n");
            continue;
        }

        switch (opcion) {
            case 1:
                printf("Ingrese el nombre: ");
                scanf("%s", nombre);
                push(&pila, nombre);
                break;
            case 2:
                pop(&pila);
                break;
            case 3:
                push(&pila, "Paola");
                push(&pila, "Paulette");
                push(&pila, "Romeo");
                push(&pila, "Israel");
                break;
            case 4:
                pop(&pila);
                pop(&pila);
                break;
            case 5:
                pop(&pila);
                pop(&pila);
                pop(&pila);
                break;
            case 0:
                printf("Hasta luego, muchas gracias!\n");
                break;
            default:
                printf("Opcion no valida. Por favor, elija una de las opciones disponibles.\n");
        }
    } while (opcion != 0);

    return 0;
}
