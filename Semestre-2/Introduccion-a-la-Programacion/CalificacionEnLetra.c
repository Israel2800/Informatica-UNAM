// b) Escribe un programa en lenguaje C que transforme una calificación 
// numérica a su equivalente en letra, con la siguiente regla.
// •	Calificación menor a 6 equivale a ‘NA’
// •	Calificación mayor o igual a 6 y menor a 7 equivale a ‘S’
// •	Calificación entre 7 y 8 equivale a ‘B’
// •	Calificación entre 9 y 10 equivale a ‘E’


#include <stdio.h>

int main() {
    float calificacion;

    printf("Introduce la calificacion numerica: ");
    scanf("%f", &calificacion);

    if (calificacion < 6) {
        printf("Calificacion en letra: NA\n");
    }
    else if (calificacion >= 6 && calificacion < 7) {
        printf("Calificacion en letra: S\n");
    }
    else if (calificacion >= 7 && calificacion <= 8) {
        printf("Calificacion en letra: B\n");
    }
    else if (calificacion >= 9 && calificacion <= 10) {
        printf("Calificacion en letra: E\n");
    }
    else {
        printf("Calificacion no valida\n");
    }

    return 0;
}