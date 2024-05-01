from machine import Pin, reset
from hcsr04 import HCSR04
import network
import socket
import time

#Se descativa la salida debug
import esp
esp.osdebug(None)

#Obtiene la memoria ocupada por objetos que no son necesarios para el programa
import gc
gc.collect()

#Conexión a wifi
ssid = 'TV!' #Nombre de la red wifi
key = '5553690373' #Contraseña

indicador = Pin(2, Pin.OUT)
wlan = network.WLAN(network.STA_IF)
if not wlan.isconnected():
    wlan.active(True)
    wlan.connect(ssid, key) #Checa que se conecte a la red
    print('Conectandose a: %s' % ssid)

    timeout = time.ticks_ms()
    while not wlan.isconnected(): #Mientras no se conecte, el led de la ESP parpadeará
        indicador.on()
        time.sleep(0.15)
        indicador.off()
        time.sleep(0.15)
        if (time.ticks_diff (time.ticks_ms(), timeout) > 10000):
            break

    if wlan.isconnected(): #Conectado el led se mantendrá encendido
        indicador.on()
        print('Successful connection to: %s' % ssid)
        print('IP: %s\nSUBNET: %s\nGATEWAY: %s\nDNS: %s' % wlan.ifconfig()[0:4])

    else: #En el caso en el que no se contecte, se apagará
        indicador.off()
        wlan.active(False)
        print('Failed to connect to: %s' % ssid)
else: #En el caso en el que se conecte a la primera vez, el led se prenderá
    indicador.on()
    print('Connected\nIP: %s\nSUBNET: %s\nGATEWAY: %s\nDNS: %s' % wlan.ifconfig()[0:4])

#Luces
comedor = Pin(16, Pin.OUT)
cocina = Pin(17, Pin.OUT)
cuarto2 = Pin(5, Pin.OUT)
cuarto1 = Pin(13, Pin.OUT)
banio = Pin(23, Pin.OUT)
alarma = Pin(22, Pin.OUT)
entrada = Pin(33, Pin.OUT)
puerta = Pin(32, Pin.OUT)

#Sensor de proximidad
#sensor = HCSR04(trigger_pin=18, echo_pin=17, echo_timeout_us=10000)

#Página Web
def web_page():  
    html = """
<!DOCTYPE html>
<html>
<head>
    <title>Servidor con Micropython</title>
    <meta http-equiv="Content-Type" content="text/html;charset=UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <script src="https://cdn.tailwindcss.com"></script>
</head>

<body>
    <div class="border-2">
        <div class="bg-indigo-500 bg">
            <div class="font-mono text-center text-4xl font-semibold text-indigo-100">
                <h1>Proyecto Domotica</h1>
            </div>"
        </div>
    </div>
	<div class="container flex">
        <div class="grid grid-cols-6 gap-1 grid-rows-6">
            <div>
                <img src="https://imagenpng.com/wp-content/uploads/2015/04/foco_amarillo.png" width="150" height="150" alt="img">  
                <p class="text-center font-bold text-2xl">Comedor</p>
            </div>
            <div class="col-span-2">
                <br>
                <button class="w-full h-12 px-6 text-indigo-100 transition-colors duration-150 bg-green-700 rounded-lg focus:shadow-outline hover:bg-green-800" onclick="window.location.href='/?comedor=on'">Encender</button>
                <br><br>
                <button class="w-full h-12 px-6 text-indigo-100 transition-colors duration-150 bg-red-700 rounded-lg focus:shadow-outline hover:bg-red-800" onclick="window.location.href='/?comedor=off'">Apagar</button>
                <br>
            </div>

            <div>
                <img src="https://imagenpng.com/wp-content/uploads/2015/04/foco_amarillo.png" width="150" height="150" alt="img">
                <p class="text-center font-bold text-2xl">Cocina</p>
            </div>
            <div class="col-span-2">
                <br>
                <button class="w-full h-12 px-6 text-indigo-100 transition-colors duration-150 bg-green-700 rounded-lg focus:shadow-outline hover:bg-green-800" onclick="window.location.href='/?cocina=on'">Encender</button>
                <br><br>
                <button class="w-full h-12 px-6 text-indigo-100 transition-colors duration-150 bg-red-700 rounded-lg focus:shadow-outline hover:bg-red-800" onclick="window.location.href='/?cocina=off'">Apagar</button>
                <br>
            </div>

            <div>
                <img src="https://imagenpng.com/wp-content/uploads/2015/04/foco_amarillo.png" width="150" height="150" alt="img">
                <p class="text-center font-bold text-2xl">Cuarto de Visitas</p>
            </div>
            <div class="col-span-2">
                <br>
                <button class="w-full h-12 px-6 text-indigo-100 transition-colors duration-150 bg-green-700 rounded-lg focus:shadow-outline hover:bg-green-800" onclick="window.location.href='/?cuarto2=on'">Encender</button>
                <br><br>
                <button class="w-full h-12 px-6 text-indigo-100 transition-colors duration-150 bg-red-700 rounded-lg focus:shadow-outline hover:bg-red-800" onclick="window.location.href='/?cuarto2=off'">Apagar</button>
                <br>
            </div>

            <div>
                <img src="https://imagenpng.com/wp-content/uploads/2015/04/foco_amarillo.png" width="150" height="150" alt="img">
                <p class="text-center font-bold text-2xl">Cuarto Principal</p>
            </div>
            <div class="col-span-2">
                <br>
                <button class="w-full h-12 px-6 text-indigo-100 transition-colors duration-150 bg-green-700 rounded-lg focus:shadow-outline hover:bg-green-800" onclick="window.location.href='/?cuarto1=on'">Encender</button>
                <br><br>
                <button class="w-full h-12 px-6 text-indigo-100 transition-colors duration-150 bg-red-700 rounded-lg focus:shadow-outline hover:bg-red-800" onclick="window.location.href='/?cuarto1=off'">Apagar</button>
                <br>
            </div>
            
            <div>
                <img src="https://imagenpng.com/wp-content/uploads/2015/04/foco_amarillo.png" width="150" height="150" alt="img">
                <p class="text-center font-bold text-2xl">Baño</p>
            </div>
            <div class="col-span-2">
                <br>
                <button class="w-full h-12 px-6 text-indigo-100 transition-colors duration-150 bg-green-700 rounded-lg focus:shadow-outline hover:bg-green-800" onclick="window.location.href='/?banio=on'">Encender</button>
                <br><br>
                <button class="w-full h-12 px-6 text-indigo-100 transition-colors duration-150 bg-red-700 rounded-lg focus:shadow-outline hover:bg-red-800" onclick="window.location.href='/?banio=off'">Apagar</button>
                <br>
            </div>

            <div>
                <img src="https://imagenpng.com/wp-content/uploads/2015/04/foco_amarillo.png" width="150" height="150" alt="img">
                <p class="text-center font-bold text-2xl">Entrada</p>
            </div>
            <div class="col-span-2">
                <br>
                <button class="w-full h-12 px-6 text-indigo-100 transition-colors duration-150 bg-green-700 rounded-lg focus:shadow-outline hover:bg-green-800" onclick="window.location.href='/?entrada=on'">Encender</button>
                <br><br>
                <button class="w-full h-12 px-6 text-indigo-100 transition-colors duration-150 bg-red-700 rounded-lg focus:shadow-outline hover:bg-red-800" onclick="window.location.href='/?entrada=off'">Apagar</button>
                <br>
            </div>

            <div>
                <img src="https://imagenpng.com/wp-content/uploads/2015/04/foco_amarillo.png" width="150" height="150" alt="img">
                <p class="text-center font-bold text-2xl">Puerta</p>
            </div>
            <div class="col-span-2">
                <br>
                <button class="w-full h-12 px-6 text-indigo-100 transition-colors duration-150 bg-green-700 rounded-lg focus:shadow-outline hover:bg-green-800" onclick="window.location.href='/?puerta=on'">Encender</button>
                <br><br>
                <button class="w-full h-12 px-6 text-indigo-100 transition-colors duration-150 bg-red-700 rounded-lg focus:shadow-outline hover:bg-red-800" onclick="window.location.href='/?puerta=off'">Apagar</button>
                <br>
            </div>
            
            <div class="col-span-6">
                <br>
                <button class="w-full h-12 px-6 text-indigo-100 transition-colors duration-150 bg-blue-700 rounded-lg focus:shadow-outline hover:bg-blue-800" onclick="window.location.href='/?luces=on'">Encender todas las luces</button>
                <br><br>
                <button class="w-full h-12 px-6 text-indigo-100 transition-colors duration-150 bg-yellow-700 rounded-lg focus:shadow-outline hover:bg-yellow-800" onclick="window.location.href='/?luces=off'">Apagar todas las luces</button>
                <br>
            </div>
            
        </div>
	</div>
</body>
</html>
"""
    return html

#Configuración dle Socket
try:
    tcp_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    tcp_socket.bind(('', 80))
    tcp_socket.listen(3)
    time.sleep(1)
    print('Configuracion del socket exitosa\n')
    
except OSError as e:
    print('La configuaración falló, reiniciando...\n')
    time.sleep(3)
    reset()
print('Conexión Lista...!\n********************************\n')

while True:
    try:
        if gc.mem_free() < 102000: #OBtiene memoria y la libera
            gc.collect()
            
        conn, addr = tcp_socket.accept()
        conn.settimeout(3.0)

        print('Nueva conexión desde: %s' % str(addr[0]))
        request = conn.recv(1024)
        conn.settimeout(None)
        request = str(request)

        if request.find('/?comedor=on') == 6:
            print('COMEDOR: ENCENDIDO')
            comedor.value(1)
        elif request.find('/?comedor=off') == 6:
            print('COMEDOR: APAGADO')
            comedor.value(0)

        if request.find('/?cocina=on') == 6:
            print('COCINA: ENCENDIDO')
            cocina.value(1)
        elif request.find('/?cocina=off') == 6:
            print('COCINA: APAGADO')
            cocina.value(0)

        if request.find('/?cuarto2=on') == 6:
            print('CUARTO2: ENCENDIDO')
            cuarto2.value(1)
        elif request.find('/?cuarto2=off') == 6:
            print('CUARTO2: APAGADO')
            cuarto2.value(0)

        if request.find('/?cuarto1=on') == 6:
            print('CUARTO1: ENCENDIDO')
            cuarto1.value(1)
        elif request.find('/?cuarto1=off') == 6:
            print('CUARTO1: APAGADO')
            cuarto1.value(0)

        if request.find('/?banio=on') == 6:
            print('BANIO: ENCENDIDO')
            banio.value(1)
        elif request.find('/?banio=off') == 6:
            print('BANIO: APAGADO')
            banio.value(0)

        if request.find('/?entrada=on') == 6:
            print('ENTRADA: ENCENDIDO')
            entrada.value(1)
        elif request.find('/?entrada=off') == 6:
            print('ENTRADA: APAGADO')
            entrada.value(0)

        if request.find('/?puerta=on') == 6:
            print('PUERTA: ENCENDIDO')
            puerta.value(1)

        elif request.find('/?puerta=off') == 6:
            print('PUERTA: APAGADO')
            puerta.value(0)
            
        if request.find('/?luces=on') == 6:
            print('LUCES: ENCENDIDAS')
            comedor.value(1)
            cocina.value(1)
            cuarto2.value(1)
            cuarto1.value(1)
            banio.value(1)
            alarma.value(1)
            entrada.value(1)
            puerta.value(1)

        elif request.find('/?luces=off') == 6:
            print('LUCES: APAGADAS')
            comedor.value(0)
            cocina.value(0)
            cuarto2.value(0)
            cuarto1.value(0)
            banio.value(0)
            alarma.value(0)
            entrada.value(0)
            puerta.value(0)        
        
        conn.send('HTTP/1.1 200 OK\n')
        conn.send('Content-Type: text/html\n')
        conn.send('Connection: close\n\n')
        conn.sendall(web_page())
        conn.close()

    except OSError as e:
        conn.close() #En dado caso de que haya un eror de conexión cierra la comunicación del socket
    time.sleep(0.1)