from ntpath import join
import numpy as np
import cv2
import matplotlib.pyplot as plt

img = cv2.imread('1.png')
#print(img.shape)
#print(type(img))
print(img)
lista = []

for i in range(0, len(img)):
    lista.append(img[i])
    
print(lista)