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

def mg1_queue(lambda_rate, mu_rate, service_variance):
    Wq = (lambda_rate * service_variance + 1 / (mu_rate - lambda_rate))
    Ws = Wq + 1 / mu_rate
    Lq = lambda_rate * Wq
    Ls = Lq + lambda_rate / mu_rate
    
    print(f"Modelo M/G/1:")
    print(f"Tiempo promedio de espera en la cola (Wq): {Wq:.2f}")
    print(f"Tiempo total en el sistema (Ws): {Ws:.2f}")
    print(f"Número promedio de clientes en la cola (Lq): {Lq:.2f}")
    print(f"Número promedio de clientes en el sistema (Ls): {Ls:.2f}\n")

def gg1_queue(lambda_rate, mu_rate, arrival_variance, service_variance):
    # G/G/1 es más complejo, lo abordamos usando aproximaciones
    # Suponemos que la tasa de llegada y el tiempo de servicio son distribuciones con varianzas conocidas.
    Wq = (arrival_variance + service_variance) / (2 * (mu_rate - lambda_rate))
    Ws = Wq + 1 / mu_rate
    Lq = lambda_rate * Wq
    Ls = Lq + lambda_rate / mu_rate
    
    print(f"Modelo G/G/1 (aproximado):")
    print(f"Tiempo promedio de espera en la cola (Wq): {Wq:.2f}")
    print(f"Tiempo total en el sistema (Ws): {Ws:.2f}")
    print(f"Número promedio de clientes en la cola (Lq): {Lq:.2f}")
    print(f"Número promedio de clientes en el sistema (Ls): {Ls:.2f}\n")

# Parámetros de ejemplo
lambda_rate = 30  # tasa de llegada
mu_rate = 15      # tasa de servicio
c = 3            # número de servidores (para M/M/c)
service_variance = 1  # varianza del tiempo de servicio (para M/G/1 y G/G/1)
arrival_variance = 1   # varianza del tiempo de llegada (para G/G/1)

# Llamadas a los modelos
mm1_queue(lambda_rate, mu_rate)
mmc_queue(lambda_rate, mu_rate, c)
mg1_queue(lambda_rate, mu_rate, service_variance)
gg1_queue(lambda_rate, mu_rate, arrival_variance, service_variance)
