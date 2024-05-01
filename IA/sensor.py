#Modulo HCSR04 es el sensor sonico exdi
# Complete project details at https://RandomNerdTutorials.com/micropython-hc-sr04-ultrasonic-esp32-esp8266/
from hcsr04 import HCSR04
from time import sleep
import machine

#Led de salida
led_der = machine.Pin(15, machine.Pin.OUT)
led_cen = machine.Pin(21, machine.Pin.OUT)
led_izq = machine.Pin(13, machine.Pin.OUT)

# ESP32
sensor_der = HCSR04(trigger_pin=5, echo_pin=18, echo_timeout_us=10000)
sensor_cen = HCSR04(trigger_pin=22, echo_pin=23, echo_timeout_us=10000)
sensor_izq = HCSR04(trigger_pin=25, echo_pin=26, echo_timeout_us=10000)

# ESP8266
#sensor = HCSR04(trigger_pin=12, echo_pin=14, echo_timeout_us=10000)

while True:
    distance_der = sensor_der.distance_cm()
    distance_cen = sensor_cen.distance_cm()
    distance_izq = sensor_izq.distance_cm()

    if(distance_der < 10 or distance_izq < 10 or distance_cen < 10 ):
        if (distance_der < 8):
            led_der.value(1)

        else:
            led_der.value(0)

        if (distance_cen < 8):
            led_cen.value(1)

        else:
            led_cen.value(0)

        if (distance_izq < 8):
            led_izq.value(1)

        else:
            led_izq.value(0)

    else:
        led_der.value(0)
        led_cen.value(0)
        led_izq.value(0)
    #print('Distance:', distance, 'cm')
    #sleep(1)


