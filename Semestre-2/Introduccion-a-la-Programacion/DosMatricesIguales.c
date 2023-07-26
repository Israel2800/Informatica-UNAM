// b) Elabora un programa en C que determine si el 
// contenido de dos matrices de 2x2, son iguales.

#include <stdio.h>

int matricesIguales(int matriz1[2][2], int matriz2[2][2]) {
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            if (matriz1[i][j] != matriz2[i][j]) {
                return 0; // Matrices no iguales
            }
        }
    }
    return 1; // Matrices son iguales
}

int main() {
    int matriz1[2][2] = {{1, 2}, {3, 4}};
    int matriz2[2][2] = {{1, 2}, {3, 4}};

    if (matricesIguales(matriz1, matriz2)) {
        printf("Las matrices son iguales.\n");
    } else {
        printf("Las matrices no son iguales.\n");
    }

    return 0;
}

