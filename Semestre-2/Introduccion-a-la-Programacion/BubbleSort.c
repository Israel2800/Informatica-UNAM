// c) Elabora un programa que ordene 20 números 
// almacenados en un arreglo.


#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int temp;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[20];
    int i;
    printf("Ingresa los 20 numeros a ordenar:\n");

    for (i = 0; i < 20; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, 20);

    printf("Arreglo ordenado:\n");
    for (i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}