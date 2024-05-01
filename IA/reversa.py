#Modulo HCSR04 es el sensor sonico exdi
# Complete project details at https://RandomNerdTutorials.com/micropython-hc-sr04-ultrasonic-esp32-esp8266/
from hcsr04 import HCSR04
from time import sleep
import machine

#Led de salida
led_der = machine.Pin(15, machine.Pin.OUT)
led_cen = machine.Pin(21, machine.Pin.OUT)
led_izq = machine.Pin(13, machine.Pin.OUT)

#Motores 1 es adelante, 2 es atras
motor_der1 = machine.Pin(4, machine.Pin.OUT)
motor_der2 = machine.Pin(19, machine.Pin.OUT)

motor_izq1 = machine.Pin(12, machine.Pin.OUT)
motor_izq2 = machine.Pin(14, machine.Pin.OUT)

# ESP8266
#sensor = HCSR04(trigger_pin=12, echo_pin=14, echo_timeout_us=10000)

while True:

    #Movimiento hacia atras
    motor_der1.value(0)
    motor_der2.value(1)

    motor_izq1.value(0)
    motor_izq2.value(1)# Escribe tu código aquí :-)
