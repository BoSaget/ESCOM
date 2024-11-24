import numpy as np
from collections import Counter

# Cargar el dataset Iris desde la URL y procesarlo
def load_iris():
    """
    Carga el dataset Iris desde el repositorio UCI, procesa las características
    y las etiquetas y devuelve los arrays X (características) y y (etiquetas).
    """
    from urllib.request import urlopen
    import csv
    url = "https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data"
    response = urlopen(url)  # Abrir la URL del dataset
    data = list(csv.reader(response.read().decode('utf-8').splitlines()))  # Leer CSV línea por línea
    # Extraer características (X) y etiquetas (y) del dataset
    X = np.array([list(map(float, row[:4])) for row in data if row])  # Las primeras 4 columnas
    y = np.array([0 if row[4] == "Iris-setosa" else 1 if row[4] == "Iris-versicolor" else 2 
                  for row in data if row])  # Mapear nombres de especies a números
    return X, y

# Implementación de métricas manuales
def accuracy_score(y_true, y_pred):
    """
    Calcula la precisión como la proporción de predicciones correctas.
    """
    return np.sum(y_true == y_pred) / len(y_true)

def recall_score(y_true, y_pred, average='macro'):
    """
    Calcula el recall para cada clase y devuelve el promedio (macro).
    """
    unique_classes = np.unique(y_true)  # Clases únicas en el dataset
    recalls = []
    for cls in unique_classes:
        tp = np.sum((y_pred == cls) & (y_true == cls))  # Verdaderos positivos
        fn = np.sum((y_pred != cls) & (y_true == cls))  # Falsos negativos
        recalls.append(tp / (tp + fn) if (tp + fn) > 0 else 0)  # Evitar división por 0
    return np.mean(recalls)  # Promedio de recall por clase

def f1_score(y_true, y_pred, average='macro'):
    """
    Calcula el F1 Score para cada clase y devuelve el promedio (macro).
    """
    unique_classes = np.unique(y_true)  # Clases únicas en el dataset
    f1s = []
    for cls in unique_classes:
        tp = np.sum((y_pred == cls) & (y_true == cls))  # Verdaderos positivos
        fp = np.sum((y_pred == cls) & (y_true != cls))  # Falsos positivos
        fn = np.sum((y_pred != cls) & (y_true == cls))  # Falsos negativos
        precision = tp / (tp + fp) if (tp + fp) > 0 else 0  # Precisión
        recall = tp / (tp + fn) if (tp + fn) > 0 else 0  # Recall
        f1s.append(2 * precision * recall / (precision + recall) if (precision + recall) > 0 else 0)
    return np.mean(f1s)  # Promedio de F1 Score por clase

# Implementación del clasificador KNN
def knn_classifier(X_train, y_train, X_test, k=3):
    """
    Implementa un clasificador K-Vecinos Cercanos desde cero.
    """
    predictions = []  # Lista para almacenar las predicciones
    for test_point in X_test:
        # Calcular la distancia Euclidiana entre el punto de prueba y los puntos de entrenamiento
        distances = np.sqrt(np.sum((X_train - test_point) ** 2, axis=1))
        # Obtener los índices de los k vecinos más cercanos
        k_indices = distances.argsort()[:k]
        # Obtener las etiquetas de los k vecinos más cercanos
        k_nearest_labels = y_train[k_indices]
        # Determinar la clase más común entre los vecinos
        most_common_label = Counter(k_nearest_labels).most_common(1)[0][0]
        predictions.append(most_common_label)
    return np.array(predictions)

# Implementación de validación cruzada
def cross_validate(X, y, k=5):
    """
    Realiza validación cruzada manual con k pliegues y calcula las métricas promedio.
    """
    np.random.seed(42)  # Semilla para reproducibilidad
    indices = np.arange(len(y))  # Crear índices de los datos
    np.random.shuffle(indices)  # Mezclar los índices aleatoriamente
    folds = np.array_split(indices, k)  # Dividir los índices en k pliegues

    # Listas para almacenar métricas en cada pliegue
    accuracies, recalls, f1_scores = [], [], []

    for i in range(k):  # Para cada pliegue
        test_idx = folds[i]  # Índices del conjunto de prueba
        train_idx = np.setdiff1d(indices, test_idx)  # Índices del conjunto de entrenamiento

        # Dividir datos en entrenamiento y prueba
        X_train, X_test = X[train_idx], X[test_idx]
        y_train, y_test = y[train_idx], y[test_idx]

        # Entrenar el clasificador KNN y obtener predicciones
        y_pred = knn_classifier(X_train, y_train, X_test, k=3)

        # Calcular y almacenar métricas
        accuracies.append(accuracy_score(y_test, y_pred))
        recalls.append(recall_score(y_test, y_pred))
        f1_scores.append(f1_score(y_test, y_pred))

    # Imprimir los promedios de las métricas
    print("Promedio de Accuracy:", np.mean(accuracies))
    print("Promedio de Recall:", np.mean(recalls))
    print("Promedio de F1 Score:", np.mean(f1_scores))

# Cargar el dataset y ejecutar validación cruzada
X, y = load_iris()  # Cargar el dataset Iris
cross_validate(X, y, k=5)  # Realizar validación cruzada con 5 pliegues
