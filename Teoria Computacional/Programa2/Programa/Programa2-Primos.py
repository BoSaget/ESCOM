import random
import os
import math
import cmath
from matplotlib import pyplot

#Coordenadas de la Grafica
def pasar_coordenadas1(x, y):
    archivo = open("Programa2_Coordenadas1.txt", "a")
    archivo.write(str(x))
    archivo.write(",")
    archivo.write(str(y))
    archivo.write("\n")
    archivo.close()
    
    
def grafica(k, limite_y):
     
    archivo = open("Programa2_Coordenadas1.txt", "r")
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
    pyplot.xlim(0, k)
    pyplot.ylim(0, limite_y)
    
    #Salva la Grafica
    pyplot.savefig("Programa2_Grafica1.png")
    
    # Mostrarlo.
    pyplot.show()

            
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

#Archivo 1 (Forma de Conjunto)
def pasarlo_archivo1(binario, actual, final):
    archivo = open("Programa2_Archivo1.txt", "a")
    if actual == 1:
        archivo.write("{")
        archivo.write(binario)
        archivo.write(",")
        
    elif actual != final:
        archivo.write(binario)
        archivo.write(",")
    
    else:
        archivo.write(binario)
        archivo.write("}")
    archivo.close()

#Checa si es Numero Primo
def es_primo(numero):
    for i in range (2,numero):   
        aux = numero // i
        if aux * i == numero:
            return 0
    return numero

#Programa Central
def primos(n):
    numero = 2
    cantidad = 1
    limite_y = 0
    while cantidad <= n:
        primo = es_primo(numero)
        if primo != 0:
            primo_binario = trans_binario(primo)
            pasarlo_archivo1(primo_binario, cantidad, n)
            coordenada_y = unos(primo)
            pasar_coordenadas1(cantidad, coordenada_y)  
            cantidad = cantidad + 1
            
            if limite_y < coordenada_y:
                limite_y = coordenada_y
        
        numero = numero + 1
        
    grafica(n, limite_y)
            
#Resetea los arhicov y los formatea
def borrar_archivo_existente():
    archivo = open("Programa2_Archivo1.txt", "w")
    archivo.close()
    
    archivo = open("Programa2_Coordenadas1.txt", "w")
    archivo.close()
        

def menu():
    print("Seleccione una opcion")
    print("1. Ingresar un numero entre 2-1000000")
    print("2. Generar un numero aleatorio entre 2-1000000")

    op = int(input(""))

    if op == 1:
        print("Ingrese un numero entre 2-1000000")
        n = int(input(""))
        primos(n)
        
    elif op == 2:
        n = random.randint(2, 1000000)
        print("El numero aleatorio es igual a: " + str(n))
        primos(n)
        
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