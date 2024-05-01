import machine
import time

#Las GPIO son del 36 al 26

while True:
    ## 1110 0001 Temperatura ambiente
    uno = machine.Pin(34, machine.Pin.IN)
    dos = machine.Pin(35, machine.Pin.IN)
    cuatro = machine.Pin(32, machine.Pin.IN)
    ocho = machine.Pin(33, machine.Pin.IN)
    
    diezSeis = machine.Pin(25, machine.Pin.IN)
    treintaDos = machine.Pin(26, machine.Pin.IN)
    sesentaCuatro = machine.Pin(27, machine.Pin.IN)
    cientoVeinteOcho = machine.Pin(14, machine.Pin.IN)
    
    if (uno.value() == 1 and dos.value() == 0 and cuatro.value() == 1 and ocho.value() == 0 and diezSeis.value() == 1 and treintaDos.value() == 0):
        print("No hay humedad, humedad ambiente")
        machine.Pin(2, machine.Pin.OUT).value(0)
        
    elif (uno.value() == 1 and dos.value() == 1 and cuatro.value() == 1 and ocho .value() == 1 and diezSeis.value() == 1):
        print("Humedo")
        machine.Pin(2, machine.Pin.OUT).value(1)