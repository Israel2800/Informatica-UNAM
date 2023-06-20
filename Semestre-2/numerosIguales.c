// En este programa, se solicitan dos números del tipo entero
// al usuario y se almacenan en las variables `numero1` y `numero2`.
// Luego, se utiliza una estructura `if` para comparar si ambos
// números son iguales usando el operador de igualdad (`==`). Por lo tanto,
// dependiendo del resultado de la comparación, se imprime un  
// mensaje indicando si los números son iguales o no.

#include <stdio.h>

int main() {
    int numero1, numero2;

    printf("Ingrese el primer número: ");
    scanf("%d", &numero1);

    printf("Ingrese el segundo número: ");
    scanf("%d", &numero2);

    if (numero1 == numero2) {
        printf("Los números son iguales.\n");
    } else {
        printf("Los números no son iguales.\n");
    }

    return 0;
}
