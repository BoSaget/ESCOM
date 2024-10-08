# -*- coding: utf-8 -*-
"""Numpy.ipynb

Automatically generated by Colab.

Original file is located at
    https://colab.research.google.com/drive/1KZFzZ5UxQNDgf0mmEHu9EdPu-zwpOSOH

## **Creación Básica de Arrays**
"""

import numpy as np

a = np.array(13)
print("type(a): ", type(a), "\n")
print("a:", a, sep = "\n")
a

b = np.array([1, 2, 3, 4])
print("b:", b, sep = "\n")
b

c = np.array([[1, 2, 3, 4], [5, 6, 7, 8]])
print("c:", c, sep = "\n")
c

d = np.array([[[1, 2, 3, 4], [5, 6, 7, 8]], [[9, 10, 11, 12], [13, 14, 15, 16]]])
print("d:", d, sep = "\n")
d

print(a.ndim)
print(b.ndim)
print(c.ndim)
print(d.ndim)

"""## **Indexación Básica**"""

print("a= ", a)
print("b[2] = ", b[2])
print("c[1] = ", c[1])
print("d[1] = ", d[1])

print("a= ", a)
print("b[2] = ", b[2])
print("c[1, 2] = ", c[1, 2])
print("d[1, 0, 2] = ", d[1, 0, 2])

print(b[1:4])
print(c[1, 1:3])
print(d[1:3, 1:3, 0:2])

"""## **Diferentes tipos de datos en los Arrays**"""

frutas = np.array(['Manzana', 'Naranja', 'Uva'])
print(frutas.dtype)

number_to_string = np.array([6, 1, 2, 4, 623, 8], dtype='str')
print(number_to_string.dtype)
print(number_to_string)

try:
  error_array = np.array(['a', '2', '3'], dtype='int')

except:
  print("Hay un error en su lógica")

float_array = np.array([1.1, 2.1, 3.1])

int_array = float_array.astype(int)
print(int_array)

vector = np.array([127, -127, 32767, -32767], dtype=np.int8) #Entero de un 1byte = 8bits (un bit necesario para almacenar el signo)
print("vector: \t", vector)
print("vector.dtype: \t", vector.dtype)

vector = np.array([127, -127, 32767, -32767], dtype=np.int16) #Entero de un 2bytes = 16bits (un bit necesario para almacenar el signo)
print("vector: \t", vector)
print("vector.dtype: \t", vector.dtype)

"""## **Tamaño de los arrays**


"""

print(a.shape)
print(b.shape)
print(c.shape)
print(d.shape)

"""**Cambio de forma de los arreglos**"""

print("c = ", c, "\n")
c_1D = c.reshape(1, 8)
print("c_1D = ", c_1D, "\n")

c_4D = c.reshape(4, 2)
print("c_4D = ", c_4D, "\n")

print(d)

try:
  d.reshape(3, 5)

except:
  print("Hay un error al intentar cambiar la forma del arreglo")

d.reshape(2,2,2,2)

arr = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9])
arr.reshape(3, -1)

d.reshape(-1)

"""**Transpuesta**"""

print("c = ", c, "\n")
print("c.T = ", c.T)

"""## **Recorrer los valores de un arreglo**"""

for x in b:
  print(x, "\n")

for x in c:
  print(x, "\n")

for x in d:
  print(x, "\n")

for x in d:
  for y in x:
    for z in y:
      print(z)

for x in np.nditer(d):
  print(x)

for i, x in np.ndenumerate(d):
  print("i : ", i, "\t\tx:", x)

"""## **Generacion de arreglos**"""

print(f"np.arrange(0, 1, 0.1) :\n{np.arange(0, 1, 0.1)}")

print(f"np.zeros((2, 3, 5)) :\n{np.zeros((2, 3, 5))}")

print(f"np.ones((2, 3, 5)) :\n{np.ones((2, 3, 5))}")

print(f"np.full((3, 4), 1.23) :\n{np.full((2, 3, 5), 1.23)}")

print(f"np.identity(3) :\n{np.identity(3)}")

print(f"np.eye(3) :\n{np.eye(3)}")

print(f"np.empty((2, 3, 5)) :\n{np.empty((2, 3, 5))}")

"""**Operaciones don arrays**"""

vector = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9])
index = np.where(vector%3 == 0)
print(f"type(indx) :\t{type(index)}")
print(f"indx :\t{index}")

filtrado = vector[index]
print(f"filtrado :\t{filtrado}")

vector_bool = vector%3 == 0
print(f"type(vector_bool) :\t{type(vector_bool)}")
print(f"vector_bool :\t{vector_bool}")
filtrado = vector[vector_bool]
print(f"filtrado :\t{filtrado}")

import math

opt1 = [math.sin(i) for i in [1, 2, 3]]
print(opt1)

import math

opt1 = [math.sin(i) for i in [1, 2, 3]]
print(f"opt1 :\t{opt1}")
print(f"opt1[0] :\t{opt1[0]:.30f}")

opt2 = np.sin(np.array([1, 2, 3], dtype=np.uint8), dtype=np.float64)
print(f"opt2 :\t{opt2}")
print(f"opt2[0] :\t{opt2[0]:.30f}")

x = np.array([1, 2, 3])
y = np.array([0.0, 0.0, 0.0])
np.sin(x, where = x%2==1, out=y)
print(f"y : \t{y}")

x = np.array([1, 2, 3, 4])
y = np.array([4, 5, 6, 7])
z = np.add(x, y)
print(f"z : \t{z}")

z = x + y
print(f"z : \t{z}")

z = np.add(x, y, dtype=float)
print(f"z : \t{z}")

try:
  print(np.array([1, 2, 3, 4]) + np.array([5, 6]))
except:
  print("No se pude realizar la operación")

try:
  print(np.array([1, 2, 3, 4]) + 0.9)
except:
  print("No se pude realizar la operación")

matriz = np.array([[3, 2, 4], [5, 2, 1], [8, 7, 6]])
print(f"matriz :\n{matriz}")
print(f"np.prod(matriz) :\n{np.prod(matriz)}")
print(f"np.prod(matriz, axis=0) :\n{np.prod(matriz, axis=0)}")
print(f"np.prod(matriz, axis=1) :\n{np.prod(matriz, axis=1)}")

print(f"matriz :\n{matriz}")
print(f"np.cumprod(matriz) :\n{np.cumprod(matriz)}")
print(f"np.cumprod(matriz, axis=0) :\n{np.cumprod(matriz, axis=0)}")
print(f"np.cumprod(matriz, axis=1) :\n{np.cumprod(matriz, axis=1)}")

print(f"media: {np.mean(matriz)}")
print(f"desviación estandar muestral: {np.std(matriz, ddof=1)}")

"""**Multiplicación Matricial**"""

arr1 = np.array([[1, 2, 3],
                 [4, 5, 6]])
arr2 = np.array([[6, 5, 4],
                 [3, 2, 1]])

print(arr1 @ arr2.T)

print(np.matmul(arr1, arr2.T))

print(np.dot(arr1, arr2.T))

try:
  print(0.9 @ arr1)
except:
  print("No se puede realizar la operación")

try:
  print(np.array([0.9]) @ arr1)
except:
  print("No se puede realizar la operación")

try:
  print(np.array([200, 100]) @ arr1)
except:
  print("No se puede realizar la operación")

try:
  print(np.matmul(arr1, np.array([10, 20, 30])))
except:
  print("No se puede realizar la operación")