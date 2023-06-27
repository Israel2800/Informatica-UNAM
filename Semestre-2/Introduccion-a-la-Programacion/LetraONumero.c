// a) Elabora un programa que determine si un carácter introducido 
// por el usuario es una letra o un número.

#include <stdio.h>

int main() {
    char caracter;

    printf("Introduce un caracter: ");
    scanf("%c", &caracter);

    if ((caracter >= 'A' && caracter <= 'Z') || (caracter >= 'a' && caracter <= 'z')) {
        printf("El caracter introducido es una letra.\n");
    }
    else if (caracter >= '0' && caracter <= '9') {
        printf("El caracter introducido es un numero.\n");
    }
    else {
        printf("El caracter introducido no es ni una letra ni un numero.\n");
    }

    return 0;
}