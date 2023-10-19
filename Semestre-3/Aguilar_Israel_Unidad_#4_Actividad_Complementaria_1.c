#include <stdio.h>
#include <string.h>

// Función para intercambiar dos elementos en el arreglo
void swap(char* arr[], int a, int b) {
    char* temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// Función para encontrar el pivote y realizar la partición del arreglo
int partition(char* arr[], int low, int high) {
    char* pivot = arr[high]; // Elegimos el último elemento como pivote
    int i = (low - 1);       // Índice del elemento más pequeño

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) <= 0) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return (i + 1);
}

// Función principal del algoritmo Quick Sort
void quickSort(char* arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Índice del pivote

        // Ordenamos los elementos antes y después del pivote recursivamente
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    char* songs[] = {
        "Turning page",
        "Fugaz",
        "Let it be",
        "Yesterday",
        "Just the way you are",
        "Chachacha",
        "Chupetazos",
        "Mi ultimo deseo",
        "El de la codeina",
        "Bailar",
        "Volar",
        "Coincidir",
        "Algo contigo",
        "Muerte en Hawaii",
        "Rene",
        "Tengo tu love",
        "Bajo el agua",
        "Que lloro",
        "Mar y tierra",
        "Amorfoda",
        "I know",
        "Makes me happy"
    };

    int num_songs = sizeof(songs) / sizeof(songs[0]);

    printf("Canciones en orden ascendente:\n");
    quickSort(songs, 0, num_songs - 1);

    for (int i = 0; i < num_songs; i++) {
        printf("%s\n", songs[i]);
    }

    printf("\nCanciones en orden descendente:\n");
    for (int i = num_songs - 1; i >= 0; i--) {
        printf("%s\n", songs[i]);
    }

    return 0;
}
