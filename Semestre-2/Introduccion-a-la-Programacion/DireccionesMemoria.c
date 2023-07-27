// Elabora un programa en C que acepte el ingreso de cinco 
// números, y que posteriormente imprima las direcciones de 
// memoria de los valores correspondientes

#include <stdio.h>

int main() {
    int numeros[5];
    int i;

    printf("Ingresa cinco numeros:\n");

    for (i = 0; i < 5; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("\nDirecciones de memoria de los valores ingresados:\n");
    for (i = 0; i < 5; i++) {
        printf("Numero %d: %p\n", i + 1, (void *)&numeros[i]);
    }

    return 0;
}
