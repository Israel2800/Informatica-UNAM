// Elabora un programa en C que acepte el ingreso de dos números 
// y que, por medio de una función, obtenga la suma de estos.
// Utilizando valores de tipo flotante.

#include <stdio.h>

// Funcion para obtener la suma de dos numeros:	
float suma(float a, float b){
	return a + b;
}

int main(){
	float num1, num2, resultado;
	
	// Solicitar el ingreso de dos numeros
	printf("Ingrese el primer numero: ");
	scanf("%f", &num1);
	
	printf("Ingrese el segundo numero: ");
	scanf("%f", &num2);
	

	// Llamar a la funcion `suma` y obtener el resultado
	resultado = suma(num1, num2);
	
	// Imprimir el resultado
	printf("La suma de los dos numeros ingresados es: %f\n", resultado);
	
	return 0;
}