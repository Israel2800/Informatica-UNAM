# Instrucciones
# Desarrolla un programa en lenguaje Python en donde diseñes una función 
# para resolver un problema de tu elección. La función debe de ser llamada 
# desde el cuerpo del programa principal. 

# Para este ejemplo, voy a crear una función en Python que calcule la suma de 
# los elementos de una lista que cumplan cierta condición. La función será llamada 
# desde el cuerpo del programa principal, que creará una lista y llamará a la función 
# para obtener la suma de los elementos que sean múltiplos de 3.


def suma_multiplos_3(lista):
    """
    Función que calcula la suma de los elementos de una lista que sean múltiplos de 3.
    """
    suma = 0
    for elemento in lista:
        if elemento % 3 == 0:
            suma += elemento
    return suma

entrada = input("Introduzca la lista de números separados por comas: ")
mi_lista = [int(elemento) for elemento in entrada.split(",")]
suma = suma_multiplos_3(mi_lista)
print(f"La suma de los múltiplos de 3 en la lista otorgada es: {suma}")