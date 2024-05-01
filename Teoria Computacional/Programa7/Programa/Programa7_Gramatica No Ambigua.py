import random

def archivo(simbolo, produccion, cadena_evaluada, cadena_resultante, estado, indice):

    if estado == 'e':
        if indice == 0:
            ##Abre el archivo por primera vez
            archivo = open("Programa7_Evaluacion.txt", "w")
            cadena = "Simbolo que se esta evaluando: " + simbolo + "\tProduccion aplicada: " + produccion + "\nCadena Evaluada: " + cadena_evaluada + "\t\t\tCadena Resultante: " + cadena_resultante + "\n" 
            archivo.write(cadena)
            print(cadena)

        else:
            ##Segunda o mas veces que abre el archivo
            archivo = open("Programa7_Evaluacion.txt", "a")
            cadena = "Simbolo que se esta evaluando: " + simbolo + "\tProduccion aplicada: " + produccion + "\nCadena Evaluada: " + cadena_evaluada + "\t\t\tCadena Resultante: " + cadena_resultante + "\n"
            archivo.write(cadena)
            print(cadena)
            
    elif estado == 'a':
        archivo = open("Programa7_Evaluacion.txt", "a")
        cadena = "Simbolo que se esta evaluando: " + simbolo + "\tProduccion aplicada: " + produccion + "\nCadena Evaluada: " + "\t\t\tCadena Resultante: " + cadena_resultante + "\n"
        archivo.write(cadena)
        print(cadena)
        
        archivo.write("--Cadena Aceptada--")
        print("--Cadena Aceptada--")
            
    else:
        if indice == 0:
            ##Abre el archivo por primera vez
            archivo = open("Programa7_Evaluacion.txt", "w")
            cadena = "Simbolo que se esta evaluando: " + simbolo + "\tProduccion aplicada: " + produccion + "\nCadena Evaluada: " + cadena_evaluada + "\t\t\tCadena Resultante: " + cadena_resultante + "\n" 
            archivo.write(cadena)
            print(cadena)
                        
            archivo.write("--Cadena Rechazada--")
            print("--Cadena Rechazada--")
            
        else:
            archivo = open("Programa7_Evaluacion.txt", "a")
            archivo.write("--Cadena Rechazada--")
            print("--Cadena Rechazada--")
        
        
        
        
    archivo.close()

def proceso (cadena):
    expandir = 'B'
    cadena_aux = expandir
    
    if cadena[0] != ')':
        for i in range (0, len(cadena)):
            nueva_cadena= "e"
            simbolo = cadena[i]
            
            if expandir == 'B' and simbolo == '(':
                eleccion = "(RB"
                cadena_aux = cadena_aux.replace("B", eleccion)
            
            elif expandir == 'R' and simbolo == ')':
                eleccion = ")"
                cadena_aux = cadena_aux.replace("R", eleccion)
                
            elif expandir == 'R' and simbolo == '(':
                eleccion = "(RR"
                cadena_aux = cadena_aux.replace("R", eleccion)
            
            for j in range (0, len(cadena_aux)):
                if cadena_aux[j] == 'R':
                    expandir = 'R'
                    break
                    
                elif cadena_aux[j] == 'B':
                    expandir = 'B'
                    break
                
            for k in range(i, len(cadena)):
                if nueva_cadena == 'e':
                    nueva_cadena = cadena[k]
                    
                else:
                    nueva_cadena = nueva_cadena + cadena[k]
                    
            archivo(simbolo, eleccion, nueva_cadena, cadena_aux, 'e',i)
            
            if i == len(cadena)-1:
                if cadena_aux == cadena + 'B':
                    archivo(simbolo, eleccion, nueva_cadena, cadena, 'a', i)
                    return
            
        archivo(simbolo, eleccion, nueva_cadena, cadena_aux, 'r', i)
        
    else:
        archivo(')', 'NULL', cadena, 'NULL', 'r', 0)

ciclo = True

while ciclo == True:
    print ("Seleccione una Opcion (Se tomara en cuenta que se desea expandir B desde el inicio)")
    print ("1. Ingresar la cadena manualmente")
    print ("2. Generarla aleatoriamente")
    
    opcion = int(input(""))
    
    if opcion == 1:
        print("Por favor ingrese la cadena, EJ: (()())")
        cadena = input("")
        proceso(cadena)
        
    
    elif opcion == 2:
        print("Modo aleatorio")
        n = random.randint(1, 10)
        cadena = 'e'
        
        for i in range(0, n*2):
            digito = random.randint(0, 1)
            
            if digito == 0:
                digito = '('
                
            else:
                digito = ')'    
            
            if cadena == 'e':
                cadena = digito
                
            else:
                cadena = cadena + digito
                
        proceso(cadena)
        
    else:
        print("Ingrese una opcion valida")
        
    print("¿Desea volver a correr el programa?")
    print("Presione (y) si lo desea volver a correr, de lo contrario presione cualquier tecla")
    repetir = input("")
    
    if repetir != 'y' and repetir != 'Y':
        ciclo = False 