#Modulo HCSR04 es el sensor sonico exdi
# Complete project details at https://RandomNerdTutorials.com/micropython-hc-sr04-ultrasonic-esp32-esp8266/
from hcsr04 import HCSR04
from time import sleep
import machine

#Funciones
def stop(m1der, m2der, m1izq, m2izq):
    m1der.value(0)
    m2der.value(0)

    m1izq.value(0)
    m2izq.value(0)

def girarDerecha(m1der, m2der, m1izq, m2izq, led):
    led.value(1)
    
    m1der.value(0)
    m2der.value(1)

    m1izq.value(1)
    m2izq.value(0)
    
    sleep(0.3)
    stop(m1der, m2der, m1izq, m2izq)
    led.value(0)

#Led de salida
led_der = machine.Pin(15, machine.Pin.OUT)
led_cen = machine.Pin(21, machine.Pin.OUT)
led_izq = machine.Pin(13, machine.Pin.OUT)

#Motores 1 es adelante, 2 es atras
motor_der1 = machine.Pin(4, machine.Pin.OUT)
motor_der2 = machine.Pin(19, machine.Pin.OUT)

motor_izq1 = machine.Pin(12, machine.Pin.OUT)
motor_izq2 = machine.Pin(14, machine.Pin.OUT)

# ESP32
sensor_der = HCSR04(trigger_pin=5, echo_pin=18, echo_timeout_us=10000)
sensor_cen = HCSR04(trigger_pin=22, echo_pin=23, echo_timeout_us=10000)
sensor_izq = HCSR04(trigger_pin=25, echo_pin=26, echo_timeout_us=10000)

while True:
  
    girarDerecha(motor_der1, motor_der2, motor_izq1, motor_izq2, led_der)
    sleep(2)


