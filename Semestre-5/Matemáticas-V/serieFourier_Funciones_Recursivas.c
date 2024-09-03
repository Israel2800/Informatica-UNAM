// 1) Empleando funciones recursivas, elabora un algoritmo donde representes el desarrollo de la serie de Fourier.


#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define NUM_POINTS 1000  // Número de puntos para integración numérica

// Definición de la función periódica f(x) a aproximar
double f(double x) {
    return (x < 0) ? -1 : 1;  // Ejemplo: una onda cuadrada simple
}

// Aproximación de la integración numérica usando la regla del trapecio
double integrate(double (*func)(double), double start, double end, int n) {
    double step = (end - start) / n;
    double sum = 0.5 * (func(start) + func(end));
    for (int i = 1; i < n; i++) {
        sum += func(start + i * step);
    }
    return sum * step;
}

// Cálculo del coeficiente a0
double a0() {
    return integrate(f, -PI, PI, NUM_POINTS) / (2 * PI);
}

// Cálculo recursivo de an (coeficientes de coseno)
double an(int n) {
    if (n == 0) {
        return a0();  // Base de la recursión para a0
    } else {
        double func_cos(double x) {
            return f(x) * cos(n * x);
        }
        return integrate(func_cos, -PI, PI, NUM_POINTS) / PI;
    }
}

// Cálculo recursivo de bn (coeficientes de seno)
double bn(int n) {
    if (n == 0) {
        return 0;  // b0 es siempre 0
    } else {
        double func_sin(double x) {
            return f(x) * sin(n * x);
        }
        return integrate(func_sin, -PI, PI, NUM_POINTS) / PI;
    }
}

// Función recursiva para la serie de Fourier
double fourier_series(double x, int N) {
    if (N == 0) {
        return a0();  // Término base de la recursión
    } else {
        return fourier_series(x, N - 1) + an(N) * cos(N * x) + bn(N) * sin(N * x);
    }
}

int main() {
    int N = 10;  // Número de términos de la serie
    double x_values[NUM_POINTS];
    double fourier_values[NUM_POINTS];
    double step = (2 * PI) / NUM_POINTS;

    // Calcula los valores de x y la serie de Fourier para esos valores
    for (int i = 0; i < NUM_POINTS; i++) {
        x_values[i] = -PI + i * step;
        fourier_values[i] = fourier_series(x_values[i], N);
    }

    // Imprime los resultados
    for (int i = 0; i < NUM_POINTS; i++) {
        printf("x: %.3f, Fourier: %.3f\n", x_values[i], fourier_values[i]);
    }

    return 0;
}
