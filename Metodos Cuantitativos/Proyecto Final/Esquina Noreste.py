def esquina_noroeste(oferta, demanda):
    filas = len(oferta)
    columnas = len(demanda)

    # Crear tabla vacía
    solucion = [[0 for _ in range(columnas)] for _ in range(filas)]

    i, j = 0, 0

    while i < filas and j < columnas:
        # Asignar la cantidad máxima posible
        asignacion = min(oferta[i], demanda[j])
        solucion[i][j] = asignacion

        # Reducir oferta y demanda según la asignación
        oferta[i] -= asignacion
        demanda[j] -= asignacion

        # Mover a la siguiente celda
        if oferta[i] == 0:
            i += 1  # Pasar a la siguiente fila
        elif demanda[j] == 0:
            j += 1  # Pasar a la siguiente columna

    return solucion

# Solicitar datos al usuario
print("Ingrese las ofertas separadas por espacios:")
oferta = list(map(int, input().split()))
print("Ingrese las demandas separadas por espacios:")
demanda = list(map(int, input().split()))

solucion = esquina_noroeste(oferta[:], demanda[:])  # Usar copias para no modificar las listas originales

# Imprimir la solución
print("Solución inicial (Método de la Esquina Noroeste):")
for fila in solucion:
    print(fila)
