import socket
import json
from GeneradorSubneteo import get_info_basico,get_info_basico_tabla

mi_socket = socket.socket()
mi_socket.bind(("localhost",8000))
mi_socket.listen(5)

while True:
    conexion, addr = mi_socket.accept()
    print("Nueva conexión establecida!")
    print(addr)
    peticion = conexion.recv(500000)
    request_pet = json.loads(peticion.decode('utf-8'))
    print(request_pet,type(request_pet))
    if request_pet["op"] == 1:
        jsonsend = get_info_basico(request_pet["ip"],request_pet["redes"])
    elif request_pet["op"] == 2:
        jsonsend = get_info_basico_tabla(request_pet["ip"],request_pet["redes"])
    conexion.send(bytes(json.dumps(jsonsend), 'utf-8'))
    conexion.close()