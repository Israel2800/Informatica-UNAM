// Realiza con base en la actividad 2, la representación en Lenguaje C con apuntadores 
// de un grafo con listas de adyacencias. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para un nodo en la lista de adyacencia
struct NodoVecino {
    char estado[50];
    struct NodoVecino* siguiente;
};

// Estructura para un estado y su lista de vecinos
struct Estado {
    char nombre[50];
    struct NodoVecino* vecinos;
};

// Función para crear un nuevo nodo vecino
struct NodoVecino* crearNodoVecino(const char* nombreEstado) {
    struct NodoVecino* nodo = (struct NodoVecino*)malloc(sizeof(struct NodoVecino));
    if (nodo) {
        strcpy(nodo->estado, nombreEstado);
        nodo->siguiente = NULL;
    }
    return nodo;
}

// Función para crear un nuevo estado con su lista de vecinos vacía
struct Estado* crearEstado(const char* nombreEstado) {
    struct Estado* estado = (struct Estado*)malloc(sizeof(struct Estado));
    if (estado) {
        strcpy(estado->nombre, nombreEstado);
        estado->vecinos = NULL;
    }
    return estado;
}

// Función para agregar un vecino a un estado
void agregarVecino(struct Estado* estado, const char* nombreVecino) {
    struct NodoVecino* nuevoNodo = crearNodoVecino(nombreVecino);
    if (nuevoNodo) {
        nuevoNodo->siguiente = estado->vecinos;
        estado->vecinos = nuevoNodo;
    }
}

// Imprimir los vecinos de un estado
void imprimirVecinos(struct Estado* estado) {
    printf("%s:\n", estado->nombre);
    struct NodoVecino* actual = estado->vecinos;
    while (actual) {
        printf("\t%s\n", actual->estado);
        actual = actual->siguiente;
    }
    printf("\n");
}

int main() {
    // Estados
    struct Estado* estados[31];
   	estados[0] = crearEstado("Aguascalientes");
	estados[1] = crearEstado("Baja California");
	estados[2] = crearEstado("Baja California Sur");
	estados[3] = crearEstado("Campeche");
	estados[4] = crearEstado("Chiapas");
	estados[5] = crearEstado("Chihuahua");
	estados[6] = crearEstado("Coahuila");
	estados[7] = crearEstado("Colima");
	estados[8] = crearEstado("Durango");
	estados[9] = crearEstado("Guanajuato");
	estados[10] = crearEstado("Guerrero");
	estados[11] = crearEstado("Hidalgo");
	estados[12] = crearEstado("Jalisco");
	estados[13] = crearEstado("Estado de Mexico");
	estados[14] = crearEstado("Ciudad de Mexico");
	estados[15] = crearEstado("Michoacan");
	estados[16] = crearEstado("Morelos");
	estados[17] = crearEstado("Nayarit");
	estados[18] = crearEstado("Nuevo Leon");
	estados[19] = crearEstado("Oaxaca");
	estados[20] = crearEstado("Puebla");
	estados[21] = crearEstado("Queretaro");
	estados[22] = crearEstado("Quintana Roo");
	estados[23] = crearEstado("San Luis Potosi");
	estados[24] = crearEstado("Sinaloa");
	estados[25] = crearEstado("Sonora");
	estados[26] = crearEstado("Tabasco");
	estados[27] = crearEstado("Tamaulipas");
	estados[28] = crearEstado("Tlaxcala");
	estados[29] = crearEstado("Veracruz");
	estados[30] = crearEstado("Yucatan");
	estados[31] = crearEstado("Zacatecas");

    // Estados Vecinos
	agregarVecino(estados[0], "Zacatecas");
	agregarVecino(estados[0], "Jalisco");
	agregarVecino(estados[0], "San Luis Potosi");
	
	agregarVecino(estados[1], "Baja California Sur");
	agregarVecino(estados[1], "Sonora");
	
	agregarVecino(estados[2], "Sinaloa");
	agregarVecino(estados[2], "Baja California");
	
	agregarVecino(estados[3], "Yucatan");
	agregarVecino(estados[3], "Quintana Roo");
	agregarVecino(estados[3], "Tabasco");
	
	agregarVecino(estados[4], "Oaxaca");
	agregarVecino(estados[4], "Tabasco");
	agregarVecino(estados[4], "Veracruz");

	agregarVecino(estados[5], "Sonora");
	agregarVecino(estados[5], "Sinaloa");
	agregarVecino(estados[5], "Durango");
	agregarVecino(estados[5], "Coahuila");
	
	agregarVecino(estados[6], "Nuevo Leon");
	agregarVecino(estados[6], "Tamaulipas");
	agregarVecino(estados[6], "Durango");
	agregarVecino(estados[6], "Zacatecas");
	agregarVecino(estados[6], "Chihuahua");
	
	agregarVecino(estados[7], "Jalisco");
	agregarVecino(estados[7], "Michoacan");
	
	agregarVecino(estados[8], "Sinaloa");
	agregarVecino(estados[8], "Chihuahua");
	agregarVecino(estados[8], "Coahuila");
	agregarVecino(estados[8], "Nayarit");
	agregarVecino(estados[8], "Zacatecas");
	
	agregarVecino(estados[9], "San Luis Potosi");
	agregarVecino(estados[9], "Queretaro");
	agregarVecino(estados[9], "Michoacan");
	agregarVecino(estados[9], "Jalisco");
	
	agregarVecino(estados[10], "Oaxaca");
	agregarVecino(estados[10], "Puebla");
	agregarVecino(estados[10], "Morelos");
	agregarVecino(estados[10], "Michoacan");
	
	agregarVecino(estados[11], "San Luis Potosi");
	agregarVecino(estados[11], "Queretaro");
	agregarVecino(estados[11], "Veracruz");
	agregarVecino(estados[11], "Puebla");
	
	agregarVecino(estados[12], "Nayarit");
	agregarVecino(estados[12], "Zacatecas");
	agregarVecino(estados[12], "Aguascalientes");
	agregarVecino(estados[12], "San Luis Potosi");
	agregarVecino(estados[12], "Guanajuato");
	agregarVecino(estados[12], "Colima");
	
	agregarVecino(estados[13], "Queretaro");
	agregarVecino(estados[13], "Hidalgo");
	agregarVecino(estados[13], "Tlaxcala");
	agregarVecino(estados[13], "Morelos");
	agregarVecino(estados[13], "Puebla");
	agregarVecino(estados[13], "Guerrero");
	agregarVecino(estados[13], "Michoacan");
	
	agregarVecino(estados[15], "Colima");
	agregarVecino(estados[15], "Guanajuato");
	agregarVecino(estados[15], "Estado de Mexico");
	agregarVecino(estados[15], "Guerrero");
	agregarVecino(estados[15], "Jalisco");
	
	agregarVecino(estados[16], "Estado de Mexico");
	agregarVecino(estados[16], "Guerrero");
	agregarVecino(estados[16], "Puebla");
	
	agregarVecino(estados[17], "Sinaloa");
	agregarVecino(estados[17], "Durango");
	agregarVecino(estados[17], "Jalisco");
	agregarVecino(estados[17], "Zacatecas");
	
	agregarVecino(estados[18], "Tamaulipas");
	agregarVecino(estados[18], "Coahuila");
	
	agregarVecino(estados[19], "Chiapas");
	agregarVecino(estados[19], "Guerrero");
	agregarVecino(estados[19], "Puebla");
	
	agregarVecino(estados[20], "Tlaxcala");
	agregarVecino(estados[20], "Hidalgo");
	agregarVecino(estados[20], "Veracruz");
	agregarVecino(estados[20], "Oaxaca");
	agregarVecino(estados[20], "Guerrero");
	agregarVecino(estados[20], "Morelos");
	
	agregarVecino(estados[21], "San Luis Potosi");
	agregarVecino(estados[21], "Hidalgo");
	agregarVecino(estados[21], "Estado de Mexico");
	agregarVecino(estados[21], "Guanajuato");
	
	agregarVecino(estados[22], "Yucatan");
	agregarVecino(estados[22], "Campeche");
	
	agregarVecino(estados[23], "Zacatecas");
	agregarVecino(estados[23], "Nuevo Leon");
	agregarVecino(estados[23], "Tamaulipas");
	agregarVecino(estados[23], "Veracruz");
	agregarVecino(estados[23], "Hidalgo");
	agregarVecino(estados[23], "Queretaro");
	agregarVecino(estados[23], "Guanajuato");
	agregarVecino(estados[23], "Jalisco");
	
	agregarVecino(estados[24], "Sonora");
	agregarVecino(estados[24], "Chihuahua");
	agregarVecino(estados[24], "Durango");
	agregarVecino(estados[24], "Nayarit");
	
	agregarVecino(estados[25], "Chihuahua");
	agregarVecino(estados[25], "Sinaloa");
	agregarVecino(estados[25], "Baja California");
	
	agregarVecino(estados[26], "Campeche");
	agregarVecino(estados[26], "Chiapas");
	agregarVecino(estados[26], "Veracruz");
	
	agregarVecino(estados[27], "Nuevo Leon");
	agregarVecino(estados[27], "Coahuila");
	agregarVecino(estados[27], "San Luis Potosi");
	
	agregarVecino(estados[28], "Estado de Mexico");
	agregarVecino(estados[28], "Puebla");
	
	agregarVecino(estados[29], "Tamaulipas");
	agregarVecino(estados[29], "San Luis Potosi");
	agregarVecino(estados[29], "Hidalgo");
	agregarVecino(estados[29], "Puebla");
	agregarVecino(estados[29], "Oaxaca");
	agregarVecino(estados[29], "Tabasco");
	
	agregarVecino(estados[30], "Campeche");
	agregarVecino(estados[30], "Quintana Roo");
	
	agregarVecino(estados[31], "Durango");
	agregarVecino(estados[31], "Nayarit");
	agregarVecino(estados[31], "Jalisco");
	agregarVecino(estados[31], "Aguascalientes");
	agregarVecino(estados[31], "San Luis Potosi");
	
	agregarVecino(estados[14], "Estado de Mexico");
	agregarVecino(estados[14], "Morelos");
    
	printf("Estados de la Republica Mexicana y sus estados vecinos:\n");
	for (int i = 0; i < 32; i++) {
        imprimirVecinos(estados[i]);
    }

    // Liberar memoria
    for (int i = 0; i < 32; i++) {
        struct NodoVecino* actual = estados[i]->vecinos;
        while (actual) {
            struct NodoVecino* siguiente = actual->siguiente;
            free(actual);
            actual = siguiente;
        }
        free(estados[i]);
    }

    return 0;
}
