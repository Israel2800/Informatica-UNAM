from pulp import *

# Crear el problema
prob = LpProblem("AsignacionTrabajos", LpMinimize)

# Crear las variables de decisión
empresas = [1, 2, 3, 4]
trabajos = ['A', 'B', 'C', 'D']
x = LpVariable.dicts("x", (trabajos, empresas), cat='Binary')

# Definir la función objetivo
costos = {
    'A': [48, 44, 46, 43],
    'B': [72, 67, 69, 73],
    'C': [36, 41, 40, 37],
    'D': [52, 53, 55, 51]
}

prob += lpSum(costos[trabajo][empresa-1] * x[trabajo][empresa] for trabajo in trabajos for empresa in empresas)

# Agregar las restricciones
for trabajo in trabajos:
    prob += lpSum(x[trabajo][empresa] for empresa in empresas) == 1

for empresa in empresas:
    prob += lpSum(x[trabajo][empresa] for trabajo in trabajos) == 1

# Resolver el problema
prob.solve()

# Imprimir la solución óptima
print("Solución Óptima:")
for trabajo in trabajos:
    for empresa in empresas:
        if value(x[trabajo][empresa]) == 1:
            print(f"Asignar Trabajo {trabajo} a la Empresa {empresa}")