import math

def mm1_queue(lambda_rate, mu_rate):
    rho = lambda_rate / mu_rate
    if rho >= 1:
        print("El sistema no es estable. La tasa de llegada no puede ser mayor o igual a la tasa de servicio.")
        return
    Wq = lambda_rate / (mu_rate * (mu_rate - lambda_rate))
    Ws = 1 / (mu_rate - lambda_rate)
    Lq = (lambda_rate ** 2) / (mu_rate * (mu_rate - lambda_rate))
    Ls = lambda_rate / (mu_rate - lambda_rate)
    
    print(f"Modelo M/M/1:")
    print(f"Utilización: {rho:.2f}")
    print(f"Tiempo promedio de espera en la cola (Wq): {Wq:.2f}")
    print(f"Tiempo total en el sistema (Ws): {Ws:.2f}")
    print(f"Número promedio de clientes en la cola (Lq): {Lq:.2f}")
    print(f"Número promedio de clientes en el sistema (Ls): {Ls:.2f}\n")

def mmc_queue(lambda_rate, mu_rate, c):
    rho = lambda_rate / (c * mu_rate)
    if rho >= 1:
        print("El sistema no es estable. La tasa de llegada no puede ser mayor o igual a la capacidad total de servicio.")
        return
    P0 = (sum([(lambda_rate / mu_rate) ** n / math.factorial(n) for n in range(c)]) +
          (lambda_rate / mu_rate) ** c / (math.factorial(c) * (1 - rho))) ** -1
    Lq = P0 * (lambda_rate / mu_rate) ** c / (math.factorial(c) * (1 - rho))
    Ls = Lq + lambda_rate / mu_rate
    Wq = Lq / lambda_rate
    Ws = Wq + 1 / mu_rate
    
    print(f"Modelo M/M/c ({c} servidores):")
    print(f"Utilización total del sistema: {rho:.2f}")
    print(f"Tiempo promedio de espera en la cola (Wq): {Wq:.2f}")
    print(f"Tiempo total en el sistema (Ws): {Ws:.2f}")
    print(f"Número promedio de clientes en la cola (Lq): {Lq:.2f}")
    print(f"Número promedio de clientes en el sistema (Ls): {Ls:.2f}\n")

def mg1_queue(lambda_rate, mu_rate, varianza_servicio):
    Wq = (lambda_rate * varianza_servicio + 1 / (mu_rate - lambda_rate))
    Ws = Wq + 1 / mu_rate
    Lq = lambda_rate * Wq
    Ls = Lq + lambda_rate / mu_rate
    
    print(f"Modelo M/G/1:")
    print(f"Tiempo promedio de espera en la cola (Wq): {Wq:.2f}")
    print(f"Tiempo total en el sistema (Ws): {Ws:.2f}")
    print(f"Número promedio de clientes en la cola (Lq): {Lq:.2f}")
    print(f"Número promedio de clientes en el sistema (Ls): {Ls:.2f}\n")

def gg1_queue(lambda_rate, mu_rate, varianza_llegada, varianza_servicio):
    # G/G/1 es más complejo, lo abordamos usando aproximaciones
    # Suponemos que la tasa de llegada y el tiempo de servicio son distribuciones con varianzas conocidas.
    Wq = (varianza_llegada + varianza_servicio) / (2 * (mu_rate - lambda_rate))
    Ws = Wq + 1 / mu_rate
    Lq = lambda_rate * Wq
    Ls = Lq + lambda_rate / mu_rate
    
    print(f"Modelo G/G/1 (aproximado):")
    print(f"Tiempo promedio de espera en la cola (Wq): {Wq:.2f}")
    print(f"Tiempo total en el sistema (Ws): {Ws:.2f}")
    print(f"Número promedio de clientes en la cola (Lq): {Lq:.2f}")
    print(f"Número promedio de clientes en el sistema (Ls): {Ls:.2f}\n")

# Menú de selección
while True:
    print("\nSeleccione el modelo de colas que desea calcular:")
    print("1. M/M/1")
    print("2. M/M/c")
    print("3. M/G/1")
    print("4. G/G/1")
    print("5. Salir")

    opcion = input("Ingrese el número de la opción deseada: ")

    if opcion == '1':
        lambda_rate = float(input("Ingrese la tasa de llegada (\u03bb): "))
        mu_rate = float(input("Ingrese la tasa de servicio (\u03bc): "))
        mm1_queue(lambda_rate, mu_rate)

    elif opcion == '2':
        lambda_rate = float(input("Ingrese la tasa de llegada (\u03bb): "))
        mu_rate = float(input("Ingrese la tasa de servicio (\u03bc): "))
        c = int(input("Ingrese el número de servidores (c): "))
        mmc_queue(lambda_rate, mu_rate, c)

    elif opcion == '3':
        lambda_rate = float(input("Ingrese la tasa de llegada (\u03bb): "))
        mu_rate = float(input("Ingrese la tasa de servicio (\u03bc): "))
        varianza_servicio = float(input("Ingrese la varianza del tiempo de servicio: "))
        mg1_queue(lambda_rate, mu_rate, varianza_servicio)

    elif opcion == '4':
        lambda_rate = float(input("Ingrese la tasa de llegada (\u03bb): "))
        mu_rate = float(input("Ingrese la tasa de servicio (\u03bc): "))
        varianza_llegada = float(input("Ingrese la varianza del tiempo de llegada: "))
        varianza_servicio = float(input("Ingrese la varianza del tiempo de servicio: "))
        gg1_queue(lambda_rate, mu_rate, varianza_llegada, varianza_servicio)

    elif opcion == '5':
        print("Saliendo del programa. ¡Hasta luego!")
        break

    else:
        print("Opción no válida. Intente nuevamente.")
