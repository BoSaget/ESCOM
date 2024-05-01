# Escribe tu código aquí :-)
import machine
import time

# Entrada y salida digital
# pines de entrada
boton1 = machine.Pin(33, machine.Pin.IN, machine.Pin.PULL_UP)
boton2 = machine.Pin(32, machine.Pin.IN, machine.Pin.PULL_UP)

# pines de salida
led_verde = machine.Pin(14, machine.Pin.OUT)
led_naranja = machine.Pin(26, machine.Pin.OUT)

contador = 0

while True:

    #Cuando es 0 el booton esta presionado
    if (boton1.value() == 0):
        contador = contador + 1
        led_naranja.value(1)()
        time.sleep(1)
        led_naranja.value(0)

    elif (boton2.value() == 0):
        if (contador != 0):
            for i in range(0, contador):
                led_naranja.value(1)()
                time.sleep(1)
                led_naranja.value(0)
                time.sleep(1)
            contador = 0
        else:
            led_naranja.value(1)()
            led_verde.value(1)()
            time.sleep(1)
            led_naranja.value(0)
            led_verde.value(0)


    else:
        led_verde.value(1)()
        time.sleep(1)
        led_verde.value(0)
        time.sleep(1)
