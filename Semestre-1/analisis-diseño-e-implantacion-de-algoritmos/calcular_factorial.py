# Instrucciones:
# Elabora un programa en lenguaje "Python" de forma libre, en 
# donde emplees alguna de las tres estructuras de control que menciona 
# el teorema de la estructura.

# Para mostrar el uso de la estructura de control "while" del teorema 
# de la estructura, voy a crear un programa en Python que solicite al 
# usuario un número entero positivo y calcule su factorial utilizando 
# un bucle while.

num = int(input("Introduce un número entero positivo: "))

if num < 0:
    print("El número debe ser entero y positivo.")
else: 
    factorial = 1

    while num > 0:
        factorial *= num
        num -= 1

        print(f"El factorial es: {factorial}")