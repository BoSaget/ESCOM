from machine import Pin, reset
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

#Leds a utilizar
sala = Pin(12, Pin.OUT)
cuarto = Pin(13, Pin.OUT)

#Página Web
def web_page():  
    html = """
<!DOCTYPE html>
<html>
<head>
    <title>Servidor con Micropython</title>
    <link rel="shortcut icon" href="https://raw.githubusercontent.com/jhonatan-lamina/web-images/main/icon-snake.png">
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
                <img src="./Imagenes/Foco.png" width="150" height="150" alt="img">  
                <p class="text-center font-bold text-2xl">Sala</p>
            </div>
            <div class="col-span-2">
                <br>
                <button class="w-full h-12 px-6 text-indigo-100 transition-colors duration-150 bg-green-700 rounded-lg focus:shadow-outline hover:bg-green-800" onclick="window.location.href='/?sala=on'">Encender</button>
                <br><br>
                <button class="w-full h-12 px-6 text-indigo-100 transition-colors duration-150 bg-red-700 rounded-lg focus:shadow-outline hover:bg-red-800" onclick="window.location.href='/?sala=off'">Apagar</button>
                <br>
            </div>
            <div>
                <img src="./Imagenes/Foco.png" width="150" height="150" alt="img">
                <p class="text-center font-bold text-2xl">Cuarto</p>
            </div>
            <div class="col-span-2">
                <br>
                <button class="w-full h-12 px-6 text-indigo-100 transition-colors duration-150 bg-green-700 rounded-lg focus:shadow-outline hover:bg-green-800" onclick="window.location.href='/?cuarto=on'">Encender</button>
                <br><br>
                <button class="w-full h-12 px-6 text-indigo-100 transition-colors duration-150 bg-red-700 rounded-lg focus:shadow-outline hover:bg-red-800" onclick="window.location.href='/?cuarto=off'">Apagar</button>
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
print('Ready...!\n********************************\n')

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

        if request.find('/?sala=on') == 6:
            print('SALA: ON')
            sala.value(1)
        if request.find('/?sala=off') == 6:
            print('SALA: OFF')
            sala.value(0)
        if request.find('/?cuarto=on') == 6:
            print('CUARTO: ON')
            cuarto.value(1)
        if request.find('/?cuarto=off') == 6:
            print('CUARTO: OFF')
            cuarto.value(0)

        conn.send('HTTP/1.1 200 OK\n')
        conn.send('Content-Type: text/html\n')
        conn.send('Connection: close\n\n')
        conn.sendall(web_page())
        conn.close()

    except OSError as e:
        conn.close() #En dado caso de que haya un eror de conexión cierra la comunicación del socket
    time.sleep(0.1)