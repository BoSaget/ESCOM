import numpy as np
from fractions import Fraction

def gauss_jordan(A, B):
    n = len(B)
    M = np.hstack([A, B.reshape(-1, 1)])  # Combina A y B en una sola matriz
    
    # Realizam la eliminación de Gauss-Jordan
    for i in range(n):
        # Hace el pivote en la posición (i, i)
        M[i] = M[i] / M[i, i]
        
        # Hace ceros en la columna i para las otras filas
        for j in range(n):
            if j != i:
                M[j] = M[j] - M[j, i] * M[i]
    
    # El resultado se encuentra en la última columna de la matriz M
    return M[:, -1]

def print_solution(solution):
    print("Solución en fracciones:")
    for val in solution:
        frac_val = Fraction(val).limit_denominator()  # Convierte a fracción
        print(f"{frac_val}")
    
    print("\nSolución en decimales:")
    for val in solution:
        print(f"{val:.4f}")

def main():
    # Solicita al usuario el tamaño de la matriz A y el vector B
    n = int(input("Ingrese el tamaño de la matriz (n x n): "))
    
    # Inicializa la matriz A y el vector B
    A = np.zeros((n, n))
    B = np.zeros(n)
    
    print("Ingrese los elementos de la matriz A:")
    for i in range(n):
        for j in range(n):
            A[i, j] = float(input(f"A[{i+1},{j+1}] = "))
    
    print("Ingrese los elementos del vector B:")
    for i in range(n):
        B[i] = float(input(f"B[{i+1}] = "))
    
    # Resuelve el sistema original A * X = B
    print("\nSolución del sistema original A * X = B:")
    X_original = gauss_jordan(A, B)
    print_solution(X_original)
    
    # Cambia el vector B
    print("\nAhora, ingrese los nuevos valores para el vector B:")
    for i in range(n):
        B[i] = float(input(f"B[{i+1}] = "))
    
    # Resuelve el sistema con el nuevo vector B
    print("\nSolución con el nuevo vector B:")
    X_new = gauss_jordan(A, B)
    print_solution(X_new)

# Ejecuta el programa
main()
