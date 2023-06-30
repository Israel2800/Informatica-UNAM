// Elabora un programa en C que acepte el ingreso de dos números 
// y que, por medio de una función, obtenga la suma de estos.

#include <stdio.h>

// Funcion para obtener la suma de dos numeros:	
int suma(int a, int b){
	return a + b;
}

int main(){
	int num1, num2, resultado;
	
	// Solicitar el ingreso de dos numeros
	printf("Ingrese el primer numero: ");
	scanf("%d", &num1);
	
	printf("Ingrese el segundo numero: ");
	scanf("%d", &num2);

	// Llamar a la funcion `suma` y obtener el resultado
	resultado = suma(num1, num2);
	
	// Imprimir el resultado
	printf("La suma de los dos numeros ingresados es: %d\n", resultado);
	
	return 0;
}
