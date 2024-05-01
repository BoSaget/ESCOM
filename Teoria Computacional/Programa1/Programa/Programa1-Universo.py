import random
import os
import math
import cmath
from matplotlib import pyplot

#Primera Grafica
def pasar_coordenadas1(x, y):
    archivo = open("Programa1_Coordenadas1.txt", "a")
    archivo.write(str(x))
    archivo.write(",")
    archivo.write(str(y))
    archivo.write("\n")
    archivo.close()
    

#Segunda Grafica (32 bits)
def pasar_coordenadas2(x,y):
    archivo = open("Programa1_Coordenadas2.txt", "a")
    archivo.write(str(x))
    archivo.write(",")
    archivo.write(str(y))
    archivo.write("\n")
    archivo.close()
    

def grafica1(k):
     
    archivo = open("Programa1_Coordenadas1.txt", "r")
    for coordenada in archivo:
        x = False
        y = False
        separacion = False
        
        for dato in coordenada:
            if dato != "," and dato !=" " and separacion == False:
                if x == False:
                    x = dato
                
                else:
                    x = x + dato
            
            elif dato != "," and dato !=" " and separacion == True:
                if y == False:
                    y = dato
                
                else:
                    y = y + dato
            else:
                separacion = True
                
        pyplot.plot(int(x), int(y), marker=".", color="blue")
        
        # Logaritmo base 2
        if int(y) != 0:
            y2 = math.log2(int(y))
        else:
            y2=0
            
        pyplot.plot(int(x), y2, marker=".", color="red")

        # Logaritmo base 10
        if int(y) != 0:
            y10 = math.log10(int(y))
        else:
            y10=0
            
        pyplot.plot(int(x), y10, marker=".", color="green")
                
                
    # Establecer el color de los ejes.
    pyplot.axhline(0, color="black")
    pyplot.axvline(0, color="black")
    
    # Limitar los valores de los ejes.
    pyplot.xlim(0, 2**k)
    pyplot.ylim(0, k)
    
    #Salva la Grafica
    pyplot.savefig("Programa1_Grafica1.png")
    
    # Mostrarlo.
    #pyplot.show()

            
    archivo.close()
    
    
    
def grafica2(k):
    #print("Aqui va la grafica2")
    archivo = open("Programa1_Coordenadas2.txt", "r")
    for coordenada in archivo:
        x = False
        y = False
        separacion = False
        
        for dato in coordenada:
            if dato != "," and dato !=" " and separacion == False:
                if x == False:
                    x = dato
                
                else:
                    x = x + dato
            
            elif dato != "," and dato !=" " and separacion == True:
                if y == False:
                    y = dato
                
                else:
                    y = y + dato
            else:
                separacion = True
                
        pyplot.plot(int(x), int(y), marker=".", color="blue")
        
        # Logaritmo base 2
        if int(y) != 0:
            y2 = math.log2(int(y))
        else:
            y2=0
            
        pyplot.plot(int(x), y2, marker=".", color="red")

        # Logaritmo base 10
        if int(y) != 0:
            y10 = math.log10(int(y))
        else:
            y10=0
            
        pyplot.plot(int(x), y10, marker=".", color="green")
                
    
    # Establecer el color de los ejes.
    pyplot.axhline(0, color="black")
    pyplot.axvline(0, color="black")
    
    # Limitar los valores de los ejes.
    pyplot.xlim(0, 2**k)
    pyplot.ylim(0, 32)
    
    #Salva la Grafica
    pyplot.savefig("Programa1_Grafica2.png")
    
    # Mostrarlo.
    #pyplot.show()
    archivo.close()
    

#cuenta cuantos 1s hay en el numero binario
def unos(numero):

    unos = 0
    if numero >= 1:
        while numero > 1:
                
            residuo = numero % 2
            numero = numero // 2
                
            if residuo == 1:
                unos = unos + 1
        
        unos = unos + 1
                            
    return unos

#Transformador (Binario-Decimal)
def trans_decimal(cadena):
    numero = 0
    posicion = len(cadena)-1

    while posicion > -1:
        aux = (len(cadena)-1) - posicion
        if cadena[posicion] == "1" and numero == 0:
            numero = 2 ** aux
        elif cadena[posicion] == "1":
            numero = numero + (2**aux)
            
        posicion = posicion - 1
    return numero


#Transformador (Deccimal-Binario)
def trans_binario(numero):
    binario = 0

    #print ("Transformando a binario....")

    if numero > 1:
        while numero > 1:
                
            residuo = numero % 2
            numero = numero // 2
                
            if binario == 0:
                binario = str(residuo)
                    
            else:
                binario = str(residuo) + binario
        
        binario = str(numero) + binario
                
    else:
        binario = str(numero)
        
    return binario

def relleno(cadena, largo):
    
    if(largo == len(cadena)):
        return cadena
    else:
        for x in range (0, largo - len(cadena)):
            cadena = "0" + cadena
            
    return cadena


#Archivo 1 (Forma de Conjunto)
def pasarlo_archivo1(binario, k):
    archivo = open("Programa1_Archivo1.txt", "a")
    
    if k == 0:
        archivo.write("{")
        archivo.write("e")
        
    else:
        archivo.write(" ,")
        archivo.write(binario)
        
    archivo.close()
        

#Archivo2 (Forma de cadena)
def pasarlo_archivo2(binario, k):
    archivo = open("Programa1_Archivo2.txt", "a")
    
    if k != 0:
        archivo.write(binario)    
    
    archivo.close()

#Archivo2 (Separacion de 32 bits)
def separador_de_32_bits_archivo2():
    contador = 0
    binario = 0
    archivo = open("Programa1_Archivo2.txt", "r")
    
    for linea in archivo:
        for caracter in linea:
            if contador < 31 and binario == 0:
                binario = caracter
                contador = contador + 1
                
            elif contador < 31:
                binario = binario + caracter
                contador = contador + 1
            
            else:
                contador = 0
                binario = binario + ","
                binario = binario + caracter
    archivo.close()
    binario = binario + ","
    return binario


def borrar_archivo_existente():
    archivo = open("Programa1_Archivo1.txt", "w")
    archivo.close()
    
    archivo = open("Programa1_Coordenadas1.txt", "w")
    archivo.close()
    
    archivo = open("Programa1_Archivo2.txt", "w")
    archivo.close()
    
    archivo = open("Programa1_Coordenadas2.txt", "w")
    archivo.close()
    

def universo(k):
    
    coordenada_x = 0
    coordenada_x1 = 1
    coordenada_y1 = 0
    
    for i in range (0, k+1):
        largo = 2 ** i
        
        for j in range(0, largo):
            #Trancformaiocn a binario y Relleno de 0
            binario = trans_binario(j)
            binario = relleno(binario, i)
            
            #Escritura Archivo1
            pasarlo_archivo1(binario, i)
            
            #Coordenadas de la Primera Grafica
            coordenada_y = unos(j)
            pasar_coordenadas1(coordenada_x, coordenada_y)
            coordenada_x = coordenada_x + 1
            
            #Escritura Archivo2
            pasarlo_archivo2(binario, i)
            
    archivo = open("Programa1_Archivo1.txt", "a")
    archivo.write("}")
    archivo.close()
    
    aux=separador_de_32_bits_archivo2()
    archivo = open("Programa1_Archivo2.txt", "w")
    archivo.write(aux)
    archivo.close()
    
    #Coordenadas de la Segunda Grafica
    archivo = open("Programa1_Coordenadas2.txt", "w")
    for caracter in aux:
        if caracter == ",":
            coordenada_y1 = trans_decimal(coordenada_y1)
            coordenada_y1 = unos(int(coordenada_y1))
            
            pasar_coordenadas2(coordenada_x1, coordenada_y1)
            coordenada_x1 = coordenada_x1 + 1
            coordenada_y1 = 0
        
        elif coordenada_y1 == 0:
            coordenada_y1 = caracter
            
        else:
            coordenada_y1 = coordenada_y1 + caracter
                
    archivo.close()
    
    grafica1(k)
    grafica2(k)


def menu():
    print("Seleccione una opcion")
    print("1. Ingresar un numero entre 0-1000")
    print("2. Generar un numero aleatorio entre 0-1000")

    op = int(input(""))

    if op == 1:
        print("Ingrese un numero entre 0-1000")
        k = int(input(""))
        universo(k)
        
    elif op == 2:
        k = random.randint(0, 1000)
        print("El numero aleatorio es igual a: " + str(k))
        universo(k)
        
    else:
        print("Ingrese un numero valido")


repetir = 1

while repetir == 1:
    borrar_archivo_existente()
    menu()
    print("Si desea ingresar otro numero presione (y)")
    respuesta = input("")
    os.system("cls")
    
    if respuesta != 'y' and respuesta != 'Y':
        repetir = 0
