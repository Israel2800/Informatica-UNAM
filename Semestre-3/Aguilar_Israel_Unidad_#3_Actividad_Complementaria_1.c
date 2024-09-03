// Desarrolla en Lenguaje C el programa de un grafo que almacene los estados de 
// la república mexicana y sus estados vecinos; es decir, el programa debe 
// imprimir el nombre de todos los estados y una lista de los estados vecinos 
// para cada estado en particular. El grafo puede representarse a través de una 
// matriz o una lista ligada. Recuerda utilizar por lo menos las operaciones 
// de Init(), addNodo(), addEdge().

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Estructura de un nodo que representa un estado
struct StateNode {
    char name[50];
    struct StateNode* next;
    struct NeighbourNode* neighbours;
};

// Estructura de un nodo que representa un estado vecino
struct NeighbourNode {
    char name[50];
    struct NeighbourNode* next;
};

// Función para inicializar un grafo vacío
struct StateNode* Init() {
    return NULL;
}

// Función para agregar un nuevo estado al grafo
struct StateNode* addNode(struct StateNode* graph, const char* name) {
    struct StateNode* newNode = (struct StateNode*)malloc(sizeof(struct StateNode));
    strcpy(newNode->name, name);
    newNode->next = graph;
    newNode->neighbours = NULL;
    return newNode;
}

// Función para agregar una relación entre dos estados (estado -> vecino)
void addEdge(struct StateNode* graph, const char* state, const char* neighbour) {
    struct StateNode* currentState = graph;

    while (currentState != NULL) {
        if (strcmp(currentState->name, state) == 0) {
            struct NeighbourNode* newNeighbour = (struct NeighbourNode*)malloc(sizeof(struct NeighbourNode));
            strcpy(newNeighbour->name, neighbour);
            newNeighbour->next = currentState->neighbours;
            currentState->neighbours = newNeighbour;
        }
        currentState = currentState->next;
    }
}

// Función para imprimir los estados y sus vecinos
void printGraph(struct StateNode* graph) {
    struct StateNode* currentState = graph;

    while (currentState != NULL) {
        printf("%s\n", currentState->name);

        struct NeighbourNode* currentNeighbour = currentState->neighbours;
        while (currentNeighbour != NULL) {
            printf("  - %s\n", currentNeighbour->name);
            currentNeighbour = currentNeighbour->next;
        }

        currentState = currentState->next;
    }
}

// Función para liberar la memoria utilizada por el grafo
void deleteGraph(struct StateNode* graph) {
    struct StateNode* currentState = graph;
    while (currentState != NULL) {
        struct StateNode* temp = currentState;
        currentState = currentState->next;

        struct NeighbourNode* currentNeighbour = temp->neighbours;
        while (currentNeighbour != NULL) {
            struct NeighbourNode* tempNeighbour = currentNeighbour;
            currentNeighbour = currentNeighbour->next;
            free(tempNeighbour);
        }

        free(temp);
    }
}

int main() {
    struct StateNode* graph = Init();

    graph = addNode(graph, "Aguascalientes");
    graph = addNode(graph, "Baja California");
    graph = addNode(graph, "Baja California Sur");
    graph = addNode(graph, "Campeche");
    graph = addNode(graph, "Chiapas");
    graph = addNode(graph, "Chihuahua");
    graph = addNode(graph, "Coahuila");
    graph = addNode(graph, "Colima");
    graph = addNode(graph, "Durango");
    graph = addNode(graph, "Guanajuato");
    graph = addNode(graph, "Guerrero");
    graph = addNode(graph, "Hidalgo");
    graph = addNode(graph, "Jalisco");
    graph = addNode(graph, "Estado de Mexico");
    graph = addNode(graph, "Ciudad de Mexico");
    graph = addNode(graph, "Michoacan");
    graph = addNode(graph, "Morelos");
    graph = addNode(graph, "Nayarit");
    graph = addNode(graph, "Nuevo Leon");
    graph = addNode(graph, "Oaxaca");
    graph = addNode(graph, "Puebla");
    graph = addNode(graph, "Queretaro");
    graph = addNode(graph, "Quintana Roo");
    graph = addNode(graph, "San Luis Potosi");
    graph = addNode(graph, "Sinaloa");
    graph = addNode(graph, "Sonora");
    graph = addNode(graph, "Tabasco");
    graph = addNode(graph, "Tamaulipas");
    graph = addNode(graph, "Tlaxcala");
    graph = addNode(graph, "Veracruz");
    graph = addNode(graph, "Yucatan");
    graph = addNode(graph, "Zacatecas");

	// Estados vecinos
	addEdge(graph, "Aguascalientes", "Zacatecas");
	addEdge(graph, "Aguascalientes", "Jalisco");
	addEdge(graph, "Aguascalientes", "San Luis Potosi");
	addEdge(graph, "Baja California", "Baja California Sur");
	addEdge(graph, "Baja California", "Sonora");
	addEdge(graph, "Baja California Sur", "Sinaloa");
	addEdge(graph, "Baja California Sur", "Baja California");
	addEdge(graph, "Campeche", "Yucatan");
	addEdge(graph, "Campeche", "Quintana Roo");
	addEdge(graph, "Campeche", "Tabasco");
	addEdge(graph, "Chiapas", "Oaxaca");
	addEdge(graph, "Chiapas", "Tabasco");
	addEdge(graph, "Chiapas", "Veracruz");
	addEdge(graph, "Chihuahua", "Sonora");
	addEdge(graph, "Chihuahua", "Sinaloa");
	addEdge(graph, "Chihuahua", "Durango");
	addEdge(graph, "Chihuahua", "Coahuila");
	addEdge(graph, "Coahuila", "Nuevo Leon");
	addEdge(graph, "Coahuila", "Tamaulipas");
	addEdge(graph, "Coahuila", "Durango");
	addEdge(graph, "Coahuila", "Zacatecas");
	addEdge(graph, "Coahuila", "Chihuahua");
	addEdge(graph, "Colima", "Jalisco");
	addEdge(graph, "Colima", "Michoacan");
	addEdge(graph, "Durango", "Sinaloa");
	addEdge(graph, "Durango", "Chihuahua");
	addEdge(graph, "Durango", "Coahuila");
	addEdge(graph, "Durango", "Nayarit");
	addEdge(graph, "Durango", "Zacatecas");
	addEdge(graph, "Guanajuato", "San Luis Potosi");
	addEdge(graph, "Guanajuato", "Queretaro");
	addEdge(graph, "Guanajuato", "Michoacan");
	addEdge(graph, "Guanajuato", "Jalisco");
	addEdge(graph, "Guerrero", "Oaxaca");
	addEdge(graph, "Guerrero", "Puebla");
	addEdge(graph, "Guerrero", "Morelos");
	addEdge(graph, "Guerrero", "Michoacan");
	addEdge(graph, "Hidalgo", "San Luis Potosi");
	addEdge(graph, "Hidalgo", "Queretaro");
	addEdge(graph, "Hidalgo", "Veracruz");
	addEdge(graph, "Hidalgo", "Puebla");
	addEdge(graph, "Jalisco", "Nayarit");
	addEdge(graph, "Jalisco", "Zacatecas");
	addEdge(graph, "Jalisco", "Aguascalientes");
	addEdge(graph, "Jalisco", "San Luis Potosi");
	addEdge(graph, "Jalisco", "Guanajuato");
	addEdge(graph, "Jalisco", "Colima");
	addEdge(graph, "Estado de Mexico", "Queretaro");
	addEdge(graph, "Estado de Mexico", "Hidalgo");
	addEdge(graph, "Estado de Mexico", "Tlaxcala");
	addEdge(graph, "Estado de Mexico", "Morelos");
	addEdge(graph, "Estado de Mexico", "Puebla");
	addEdge(graph, "Estado de Mexico", "Guerrero");
	addEdge(graph, "Estado de Mexico", "Michoacan");
	addEdge(graph, "Michoacan", "Colima");
	addEdge(graph, "Michoacan", "Guanajuato");
	addEdge(graph, "Michoacan", "Estado de Mexico");
	addEdge(graph, "Michoacan", "Guerrero");
	addEdge(graph, "Michoacan", "Jalisco");
	addEdge(graph, "Morelos", "Estado de Mexico");
	addEdge(graph, "Morelos", "Guerrero");
	addEdge(graph, "Morelos", "Puebla");
	addEdge(graph, "Nayarit", "Sinaloa");
	addEdge(graph, "Nayarit", "Durango");
	addEdge(graph, "Nayarit", "Jalisco");
	addEdge(graph, "Nayarit", "Zacatecas");
	addEdge(graph, "Nuevo Leon", "Tamaulipas");
	addEdge(graph, "Nuevo Leon", "Coahuila");
	addEdge(graph, "Oaxaca", "Chiapas");
	addEdge(graph, "Oaxaca", "Guerrero");
	addEdge(graph, "Oaxaca", "Puebla");
	addEdge(graph, "Puebla", "Tlaxcala");
	addEdge(graph, "Puebla", "Hidalgo");
	addEdge(graph, "Puebla", "Veracruz");
	addEdge(graph, "Puebla", "Oaxaca");
	addEdge(graph, "Puebla", "Guerrero");
	addEdge(graph, "Puebla", "Morelos");
	addEdge(graph, "Queretaro", "San Luis Potosi");
	addEdge(graph, "Queretaro", "Hidalgo");
	addEdge(graph, "Queretaro", "Estado de Mexico");
	addEdge(graph, "Queretaro", "Guanajuato");
	addEdge(graph, "Quintana Roo", "Yucatan");
	addEdge(graph, "Quintana Roo", "Campeche");
	addEdge(graph, "San Luis Potosi", "Zacatecas");
	addEdge(graph, "San Luis Potosi", "Nuevo Leon");
	addEdge(graph, "San Luis Potosi", "Tamaulipas");
	addEdge(graph, "San Luis Potosi", "Veracruz");
	addEdge(graph, "San Luis Potosi", "Hidalgo");
	addEdge(graph, "San Luis Potosi", "Queretaro");
	addEdge(graph, "San Luis Potosi", "Guanajuato");
	addEdge(graph, "San Luis Potosi", "Jalisco");
	addEdge(graph, "Sinaloa", "Sonora");
	addEdge(graph, "Sinaloa", "Chihuahua");
	addEdge(graph, "Sinaloa", "Durango");
	addEdge(graph, "Sinaloa", "Nayarit");
	addEdge(graph, "Sonora", "Chihuahua");
	addEdge(graph, "Sonora", "Sinaloa");
	addEdge(graph, "Sonora", "Baja California");
	addEdge(graph, "Tabasco", "Campeche");
	addEdge(graph, "Tabasco", "Chiapas");
	addEdge(graph, "Tabasco", "Veracruz");
	addEdge(graph, "Tamaulipas", "Nuevo Leon");
	addEdge(graph, "Tamaulipas", "Coahuila");
	addEdge(graph, "Tamaulipas", "San Luis Potosi");
	addEdge(graph, "Tlaxcala", "Estado de Mexico");
	addEdge(graph, "Tlaxcala", "Puebla");
	addEdge(graph, "Veracruz", "Tamaulipas");
	addEdge(graph, "Veracruz", "San Luis Potosi");
	addEdge(graph, "Veracruz", "Hidalgo");
	addEdge(graph, "Veracruz", "Puebla");
	addEdge(graph, "Veracruz", "Oaxaca");
	addEdge(graph, "Veracruz", "Tabasco");
	addEdge(graph, "Yucatan", "Campeche");
	addEdge(graph, "Yucatan", "Quintana Roo");
	addEdge(graph, "Zacatecas", "Durango");
	addEdge(graph, "Zacatecas", "Nayarit");
	addEdge(graph, "Zacatecas", "Jalisco");
	addEdge(graph, "Zacatecas", "Aguascalientes");
	addEdge(graph, "Zacatecas", "San Luis Potosi");
	addEdge(graph, "Ciudad de Mexico", "Estado de Mexico");
	addEdge(graph, "Ciudad de Mexico", "Morelos");
    // Imprimir los estados y sus vecinos
    printf("Estados de la Republica Mexicana y sus estados vecinos:\n");
    printGraph(graph);

    // Liberar la memoria del grafo
    deleteGraph(graph);

    return 0;
}
