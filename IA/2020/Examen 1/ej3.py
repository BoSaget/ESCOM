import numpy as np

# Lista de productos
productos = ["Producto 1", "Producto 2", "Producto 3", "Producto 4"]

# Diccionario que mapea usuarios con sus calificaciones (1-5)
calificaciones = {
    "usuario1": {"Producto 1": 5, "Producto 2": 3, "Producto 3": 4},
    "usuario2": {"Producto 1": 2, "Producto 2": 5, "Producto 3": 3},
    "usuario3": {"Producto 1": 4, "Producto 2": 4, "Producto 3": 5, "Producto 4": 3},
}

# Crear una función para calcular la similitud entre usuarios usando la distancia coseno
from sklearn.metrics.pairwise import cosine_similarity

def crear_matriz_usuarios_productos(usuarios, productos):
    # Crear una matriz con ceros de tamaño (usuarios x productos)
    matriz = np.zeros((len(usuarios), len(productos)))
    usuarios_lista = list(usuarios.keys())
    
    # Llenar la matriz con las calificaciones de los usuarios
    for i, usuario in enumerate(usuarios_lista):
        for j, producto in enumerate(productos):
            matriz[i][j] = usuarios[usuario].get(producto, 0)
    return matriz, usuarios_lista

# Crear la matriz de usuarios-productos
matriz_calificaciones, usuarios_lista = crear_matriz_usuarios_productos(calificaciones, productos)

# Calcular la similitud entre usuarios
similitud_usuarios = cosine_similarity(matriz_calificaciones)

def recomendar_productos(usuario, usuarios_lista, similitud_usuarios, calificaciones, productos, n_recomendaciones=2):
    indice_usuario = usuarios_lista.index(usuario)
    
    # Obtener las similitudes del usuario con otros usuarios
    similitudes = similitud_usuarios[indice_usuario]
    
    # Ordenar los usuarios por su similitud
    usuarios_similares = np.argsort(similitudes)[::-1][1:]  # Ignorar al mismo usuario
    
    recomendaciones = {}
    
    # Buscar recomendaciones de los usuarios más similares
    for similar in usuarios_similares:
        similar_usuario = usuarios_lista[similar]
        for producto, calificacion in calificaciones[similar_usuario].items():
            if producto not in calificaciones[usuario]:  # Solo recomendar productos no calificados por el usuario
                if producto not in recomendaciones:
                    recomendaciones[producto] = calificacion
                else:
                    recomendaciones[producto] += calificacion
    
    # Ordenar las recomendaciones por calificación y devolver las mejores n recomendaciones
    recomendaciones_ordenadas = sorted(recomendaciones.items(), key=lambda x: x[1], reverse=True)
    return [producto for producto, calificacion in recomendaciones_ordenadas[:n_recomendaciones]]

# Ejemplo de recomendación para usuario1
recomendaciones_usuario1 = recomendar_productos("usuario1", usuarios_lista, similitud_usuarios, calificaciones, productos)
print(f"Recomendaciones para usuario1: {recomendaciones_usuario1}")
