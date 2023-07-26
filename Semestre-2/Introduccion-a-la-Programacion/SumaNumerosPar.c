// a) Escribe un programa en C que determine la suma de 
// los números de posición par de la cifra 1257851.

#include <stdio.h>

int main() {
    int num = 1257851;
    int suma = 0;
    int posicion = 0;

    while (num > 0) {
        int digito = num % 10;
        if (posicion % 2 == 0) {
            suma += digito;
        }
        num /= 10;
        posicion++;
    }

    printf("La suma de los numeros de posicion par es: %d\n", suma);

    return 0;
}
