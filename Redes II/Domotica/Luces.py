# Escribe tu código aquí :-)
import machine
import time

# pines de salida
led_sala = machine.Pin(12, machine.Pin.OUT)
led_cuarto = machine.Pin(13, machine.Pin.OUT)

while True:

    led_sala.value(1)
    led_cuarto.value(1)
    time.sleep(1)

    led_sala.value(0)
    time.sleep(1)

    led_cuarto.value(0)
    time.sleep(1)
