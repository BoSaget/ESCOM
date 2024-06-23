<?php
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $name = htmlspecialchars($_POST['user-login']);
    $email = htmlspecialchars($_POST['user-login-pass']);

    // Aquí puedes agregar la lógica para procesar los datos, como guardarlos en una base de datos
    // Ejemplo simple de respuesta:
    echo "Nombre: $name<br>";
    echo "Correo Electrónico: $email<br>";
} else {
    echo "Método de solicitud no permitido.";
}
?>