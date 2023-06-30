// En este programa, se solicitan dos numeros del tipo entero
// al usuario y se almacenan en las variables `numero1` y `numero2`.
// Luego, se utiliza una estructura `if` para comparar si ambos
// numeros son iguales usando el operador de igualdad (`==`). 
// Por lo tanto, dependiendo del resultado de la comparacion, se 
// imprime un mensaje indicando si los numeros son iguales o no.

#include <stdio.h>

int main() {
    int numero1, numero2;

    printf("Ingrese el primer numero: ");
    scanf("%d", &numero1);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &numero2);

    if (numero1 == numero2) {
        printf("Los numeros son iguales.\n");
    } else {
        printf("Los numeros no son iguales.\n");
    }

    return 0;
}