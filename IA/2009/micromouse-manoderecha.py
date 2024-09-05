from hcsr04 import HCSR04
from time import sleep
import machine

#Funciones para ver si existe alguna paredDelante
def paredDerecha(sensor):
  if (sensor.distance_cm() < 15):
    return True
 
  return False
  
def paredDelante(sensor):
  if (sensor.distance_cm() < 15):
    return True
    
  return False

#Funciones para el movimiento, coomo avanzar recto, detenerse y girar
def recto(der_frente, der_reversa, izq_frente, izq_reversa, led):
    led.value(1)
    
    der_frente.value(1)
    der_reversa.value(0)

    izq_frente.value(1)
    izq_reversa.value(0)

def stop(der_frente, der_reversa, izq_frente, izq_reversa, led):
    led.value(0)
    
    der_frente.value(0)
    der_reversa.value(0)

    izq_frente.value(0)
    izq_reversa.value(0)
  
def giraDerecha(der_frente, der_reversa, izq_frente, izq_reversa, led):
    led.value(1)
   
    der_frente.value(0)
    der_reversa.value(0)

    izq_frente.value(1)
    izq_reversa.value(0)
    
    sleep(0.1)
    
    stop(der_frente, der_reversa, izq_frente, izq_reversa, led)

def giraIzquierda(der_frente, der_reversa, izq_frente, izq_reversa, led):
    led.value(1)
    
    der_frente.value(1)
    der_reversa.value(0)

    izq_frente.value(0)
    izq_reversa.value(0)
    
    sleep(0.1)
    
    stop(der_frente, der_reversa, izq_frente, izq_reversa, led)
    

#Led de salida
led_der = machine.Pin(15, machine.Pin.OUT)
led_cen = machine.Pin(21, machine.Pin.OUT)
led_izq = machine.Pin(13, machine.Pin.OUT)

#Motores 1 es adelante, 2 es atras
motor_der_frente = machine.Pin(4, machine.Pin.OUT)
motor_der_reversa = machine.Pin(19, machine.Pin.OUT)

motor_izq_frente = machine.Pin(12, machine.Pin.OUT)
motor_izq_reversa = machine.Pin(14, machine.Pin.OUT)

# ESP32
sensor_der = HCSR04(trigger_pin=5, echo_pin=18, echo_timeout_us=10000)
sensor_cen = HCSR04(trigger_pin=22, echo_pin=23, echo_timeout_us=10000)
sensor_izq = HCSR04(trigger_pin=25, echo_pin=26, echo_timeout_us=10000)

while True:
  
  if (paredDerecha(sensor_der) == False):
    stop(motor_der_frente, motor_der_reversa, motor_izq_frente, motor_izq_reversa, led_cen)
    sleep(1)
    
    giraDerecha(motor_der_frente, motor_der_reversa, motor_izq_frente, motor_izq_reversa, led_der)
    print("Giro a la derecha...Completado")
   
  while (paredDelante(sensor_cen) == True):
    stop(motor_der_frente, motor_der_reversa, motor_izq_frente, motor_izq_reversa, led_cen)
    sleep(1)
    
    giraIzquierda(motor_der_frente, motor_der_reversa, motor_izq_frente, motor_izq_reversa, led_izq)
    print("Giro a la izquierda...Completado")
    
  print(sensor_cen.distance_cm())
  recto(motor_der_frente, motor_der_reversa, motor_izq_frente, motor_izq_reversa, led_cen)
