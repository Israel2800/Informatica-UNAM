// Realiza el programa completo para la búsqueda de un elemento, 
// con el método de búsqueda en árboles binarios, en donde declares 
// un menú para que el usuario inserte elementos y después haga una 
// búsqueda. Recuerda las reglas para insertar elementos mayores o 
// menores al nodo padre. 

#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int valor;
    struct Nodo* izquierda;
    struct Nodo* derecha;
};

struct Nodo* crearNodo(int valor) {
    struct Nodo* nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nodo->valor = valor;
    nodo->izquierda = nodo->derecha = NULL;
    return nodo;
}

struct Nodo* insertar(struct Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return crearNodo(valor);
    }

    if (valor < raiz->valor) {
        raiz->izquierda = insertar(raiz->izquierda, valor);
    } else if (valor > raiz->valor) {
        raiz->derecha = insertar(raiz->derecha, valor);
    }

    return raiz;
}

struct Nodo* buscar(struct Nodo* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }

    if (valor < raiz->valor) {
        return buscar(raiz->izquierda, valor);
    }

    return buscar(raiz->derecha, valor);
}

void imprimirArbol(struct Nodo* raiz) {
    if (raiz != NULL) {
        imprimirArbol(raiz->izquierda);
        printf("%d ", raiz->valor);
        imprimirArbol(raiz->derecha);
    }
}

int main() {
    struct Nodo* raiz = NULL;
    int opcion, valor;

    do {
        printf("\n1. Insertar elemento\n");
        printf("2. Buscar elemento\n");
        printf("3. Imprimir arbol\n");
        printf("4. Salir\n");

        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un valor para insertar: ");
                scanf("%d", &valor);
                raiz = insertar(raiz, valor);
                break;
            case 2:
                printf("Ingrese el valor a buscar: ");
                scanf("%d", &valor);
                if (buscar(raiz, valor) != NULL) {
                    printf("Elemento %d encontrado en el arbol.\n", valor);
                } else {
                    printf("Elemento %d no encontrado en el arbol.\n", valor);
                }
                break;
            case 3:
                printf("Arbol: ");
                imprimirArbol(raiz);
                printf("\n");
                break;
            case 4:
                break;
            default:
                printf("Opcion no valida. Intentelo de nuevo.\n");
        }
    } while (opcion != 4);

    return 0;
}
