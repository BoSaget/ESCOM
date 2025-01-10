import tkinter as tk
from tkinter import messagebox
import math

# Funciones de cálculo de los modelos de colas (como ya las tenías)
def mm1_queue(lambda_rate, mu_rate):
    rho = lambda_rate / mu_rate
    if rho >= 1:
        return "El sistema no es estable. La tasa de llegada no puede ser mayor o igual a la tasa de servicio."
    Wq = lambda_rate / (mu_rate * (mu_rate - lambda_rate))
    Ws = 1 / (mu_rate - lambda_rate)
    Lq = (lambda_rate ** 2) / (mu_rate * (mu_rate - lambda_rate))
    Ls = lambda_rate / (mu_rate - lambda_rate)
    return f"Utilización: {rho:.2f}\nTiempo promedio de espera en la cola (Wq): {Wq:.2f}\nTiempo total en el sistema (Ws): {Ws:.2f}\nNúmero promedio de clientes en la cola (Lq): {Lq:.2f}\nNúmero promedio de clientes en el sistema (Ls): {Ls:.2f}"

def mmc_queue(lambda_rate, mu_rate, c):
    rho = lambda_rate / (c * mu_rate)
    if rho >= 1:
        return "El sistema no es estable. La tasa de llegada no puede ser mayor o igual a la capacidad total de servicio."
    P0 = (sum([(lambda_rate / mu_rate) ** n / math.factorial(n) for n in range(c)]) +
          (lambda_rate / mu_rate) ** c / (math.factorial(c) * (1 - rho))) ** -1
    Lq = P0 * (lambda_rate / mu_rate) ** c / (math.factorial(c) * (1 - rho))
    Ls = Lq + lambda_rate / mu_rate
    Wq = Lq / lambda_rate
    Ws = Wq + 1 / mu_rate
    return f"Utilización total del sistema: {rho:.2f}\nTiempo promedio de espera en la cola (Wq): {Wq:.2f}\nTiempo total en el sistema (Ws): {Ws:.2f}\nNúmero promedio de clientes en la cola (Lq): {Lq:.2f}\nNúmero promedio de clientes en el sistema (Ls): {Ls:.2f}"

def mg1_queue(lambda_rate, mu_rate, varianza_servicio):
    Wq = (lambda_rate * varianza_servicio + 1 / (mu_rate - lambda_rate))
    Ws = Wq + 1 / mu_rate
    Lq = lambda_rate * Wq
    Ls = Lq + lambda_rate / mu_rate
    return f"Tiempo promedio de espera en la cola (Wq): {Wq:.2f}\nTiempo total en el sistema (Ws): {Ws:.2f}\nNúmero promedio de clientes en la cola (Lq): {Lq:.2f}\nNúmero promedio de clientes en el sistema (Ls): {Ls:.2f}"

def gg1_queue(lambda_rate, mu_rate, varianza_llegada, varianza_servicio):
    Wq = (varianza_llegada + varianza_servicio) / (2 * (mu_rate - lambda_rate))
    Ws = Wq + 1 / mu_rate
    Lq = lambda_rate * Wq
    Ls = Lq + lambda_rate / mu_rate
    return f"Tiempo promedio de espera en la cola (Wq): {Wq:.2f}\nTiempo total en el sistema (Ws): {Ws:.2f}\nNúmero promedio de clientes en la cola (Lq): {Lq:.2f}\nNúmero promedio de clientes en el sistema (Ls): {Ls:.2f}"

# Función que maneja la lógica de la interfaz gráfica
def calcular():
    try:
        lambda_rate = float(entry_lambda.get())
        mu_rate = float(entry_mu.get())

        if modelo_var.get() == "mm1":
            resultado = mm1_queue(lambda_rate, mu_rate)
        elif modelo_var.get() == "mmc":
            c = int(entry_c.get())
            resultado = mmc_queue(lambda_rate, mu_rate, c)
        elif modelo_var.get() == "mg1":
            varianza_servicio = float(entry_varianza_servicio.get())
            resultado = mg1_queue(lambda_rate, mu_rate, varianza_servicio)
        elif modelo_var.get() == "gg1":
            varianza_llegada = float(entry_varianza_llegada.get())
            varianza_servicio = float(entry_varianza_servicio.get())
            resultado = gg1_queue(lambda_rate, mu_rate, varianza_llegada, varianza_servicio)
        else:
            resultado = "Seleccione un modelo de cola."

        messagebox.showinfo("Resultado", resultado)
    except ValueError:
        messagebox.showerror("Error", "Por favor, ingrese valores válidos.")

# Crear la ventana principal
root = tk.Tk()
root.title("Cálculos de Modelos de Colas")

# Crear los campos de entrada
tk.Label(root, text="Tasa de llegada (λ):").grid(row=0, column=0)
entry_lambda = tk.Entry(root)
entry_lambda.grid(row=0, column=1)

tk.Label(root, text="Tasa de servicio (μ):").grid(row=1, column=0)
entry_mu = tk.Entry(root)
entry_mu.grid(row=1, column=1)

tk.Label(root, text="Número de servidores (c):").grid(row=2, column=0)
entry_c = tk.Entry(root)
entry_c.grid(row=2, column=1)

tk.Label(root, text="Varianza del tiempo de servicio:").grid(row=3, column=0)
entry_varianza_servicio = tk.Entry(root)
entry_varianza_servicio.grid(row=3, column=1)

tk.Label(root, text="Varianza del tiempo de llegada:").grid(row=4, column=0)
entry_varianza_llegada = tk.Entry(root)
entry_varianza_llegada.grid(row=4, column=1)

# Crear las opciones del modelo
modelo_var = tk.StringVar(value="mm1")
tk.Radiobutton(root, text="M/M/1", variable=modelo_var, value="mm1").grid(row=5, column=0)
tk.Radiobutton(root, text="M/M/c", variable=modelo_var, value="mmc").grid(row=5, column=1)
tk.Radiobutton(root, text="M/G/1", variable=modelo_var, value="mg1").grid(row=6, column=0)
tk.Radiobutton(root, text="G/G/1", variable=modelo_var, value="gg1").grid(row=6, column=1)

# Crear el botón de cálculo
button_calcular = tk.Button(root, text="Calcular", command=calcular)
button_calcular.grid(row=7, column=0, columnspan=2)

# Ejecutar la interfaz
root.mainloop()
