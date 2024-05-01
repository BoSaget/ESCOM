#!/usr/bin/python3.8
#Autor: Ismael Lopez Larumbe
#Redes 2
import threading as th
import skimage.io as io
import os
from os import getcwd
from copy import deepcopy

#En python no hay return convencional en los threads, se usan variables globales
global canalesG
canalesG=list()

def filtroRG(str_imagen,indice):

    imagen = io.imread("ESCOM/Redes II/Primer Parcial/Practica1/imagenes/"+str_imagen)
    canal_rojo = deepcopy(imagen)

    canal_rojo[:,:,1]=0 #quita el verde
    canal_rojo[:,:,2]=0 #quita el azul
    #necesita numero entero, no acepta fracciones las coordenadas de las matrices
    if imagen.shape[0]%2 == 0:
        mitad=int(imagen.shape[0]/2)
    else:
        mitad=int((imagen.shape[0]+1)/2)

    global canalesG #Accede a global de la mitad inferior
    canalesG[indice][:mitad,:,0]=0 #quita el rojo
    canalesG[indice][:mitad,:,2]=0 #quita el azul

    nombre=str_imagen.split('.')[0] #obtiene nombre y quita la extension
    io.imsave("ESCOM/Redes II/Primer Parcial/Practica1/resultados/"+nombre+"_rojo.png",canal_rojo)#Nombra y guarda la nueva imagen en la carpeta "resultados"

def filtroBG(str_imagen,indice):

    imagen = io.imread("ESCOM/Redes II/Primer Parcial/Practica1/imagenes/"+str_imagen)
    canal_azul = deepcopy(imagen)

    canal_azul[:,:,0]=0 #quita el rojo
    canal_azul[:,:,1]=0 #quita el verde

    if imagen.shape[0]%2 == 0:
        mitad=int(imagen.shape[0]/2)
    else:
        mitad=int((imagen.shape[0]-1)/2)

    global canalesG#Accede a global de la mitad superior
    canalesG[indice][mitad:,:,0]=0 #quita el rojo
    canalesG[indice][mitad:,:,2]=0 #quita el azul

    nombre=str_imagen.split('.')[0] #obtiene nombre y quita la extension
    io.imsave("ESCOM/Redes II/Primer Parcial/Practica1/resultados/"+nombre+"_azul.png",canal_azul)

#obtiene los nombres de la carpeta "origen" como una lista
def ls(ruta = getcwd()+"/ESCOM/Redes II/Primer Parcial/Practica1/imagenes"):
    return [arch.name for arch in os.scandir(ruta) if arch.is_file()]


nombres = ls()
hilosR=list()
hilosA=list()

#prepara lista global,tendran acceso compartido
for i in range(len(nombres)):
    imagen = io.imread("ESCOM/Redes II/Primer Parcial/Practica1/imagenes/"+nombres[i])
    canal_verde = deepcopy(imagen)
    canalesG.append(canal_verde)

#Inicia los hilos y los mete a una lista
for i in range(len(nombres)):
    t1=th.Thread(name=(nombres[i].split('.')[0])+"_Rojo",target=filtroRG,args=(nombres[i],i, )) #Crea el hilo de filtro rojo y mitad verde
    hilosR.append(t1)
    t1.start()#Corre el hilo
    t2=th.Thread(name=(nombres[i].split('.')[0])+"_Azul",target=filtroBG,args=(nombres[i],i, )) #crea el hilo de filtro azul y mitad verde
    hilosA.append(t2)
    t2.start()

#Junta los hilos y espera a que todos acaben
for i in range(len(nombres)):
    hilosA[i].join()
    hilosR[i].join()

#Guarda como archivo los resultados de ambos hilos
for i in range(len(nombres)):
    io.imsave("ESCOM/Redes II/Primer Parcial/Practica1/resultados/"+nombres[i].split('.')[0]+"_verde.png",canalesG[i])
