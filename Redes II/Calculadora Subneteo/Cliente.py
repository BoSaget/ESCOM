import socket
import json


def enviar_peticion(jsoninfo):

    mi_socket = socket.socket()
    mi_socket.connect(("localhost",8000))
    mi_socket.send(bytes(json.dumps(jsoninfo), 'utf-8'))
    respuesta = mi_socket.recv(500000)
    request_res = json.loads(respuesta.decode('utf-8'))
    #print(request_res,type(request_res))
    mi_socket.close()
    return request_res

if __name__ == '__main__':  
    print("Ingresa la ip: ")
    ip = input()
    print("Ingresa numero redes: ")
    redes = input()

    print("Menu")
    print("1.- Obtener la clase de la ip, mascaras y rango de host")
    print("2.- Obtener la clase de la ip, mascaras, rango de host y la tabla de subneteo")
    opcion = input()

    if opcion == "1":
        jsonrec = enviar_peticion({"ip":ip,"redes":redes,"op":1})
        for clave in jsonrec:
            print(clave+": "+str(jsonrec[clave]))
    elif opcion == "2":
        jsonrec = enviar_peticion({"ip":ip,"redes":redes,"op":2})
        for clave in jsonrec:
            if type(jsonrec[clave]) != type([]): 
                print(clave+": "+str(jsonrec[clave]))
            else:
                for datostabla in jsonrec[clave]:
                    #print(datostabla)
                    if jsonrec["ClaseIP"] =="C":
                        print(str(datostabla[0])+"."+str(datostabla[1])+"."+str(datostabla[2])+"."+str(datostabla[3])+" ["+str(datostabla[4])+"-"+str(datostabla[5])+"] ")
                    elif jsonrec["ClaseIP"] =="B":
                        print(str(datostabla[0])+"."+str(datostabla[1])+"."+str(datostabla[2])+" ["+str(datostabla[3])+"-"+str(datostabla[4])+"] ")
                    elif jsonrec["ClaseIP"] =="A":
                        print(str(datostabla[0])+"."+str(datostabla[1])+" ["+str(datostabla[2])+"-"+str(datostabla[3])+"] ")