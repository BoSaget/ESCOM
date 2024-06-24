<?php

//Conexion a base de datos
$conexion = mysqli_connect("localhost","root","","cafeteria");
mysqli_query($conexion, "SET character_set_results = 'utf8', character_set_client = 'utf8', character_set_connection = 'utf8', character_set_database = 'utf8', character_set_server = 'utf8'");



// Configurar el tipo de respuesta a JSON
header('Content-Type: application/json');

// Obtener el cuerpo de la solicitud
$data = json_decode(file_get_contents('php://input'), true);

if ($data) 
{
    $rol= $data['rol'];
    $email= $data['email'];
    $nombre= $data['nombre'];
    $pass=md5($data['pass']);


    $insert = "INSERT INTO `empleados` (`rol`, `correo`, `nombre`, `contraseña`) VALUES ('$rol','$email','$nombre','$pass')";
    $checkcorreo = "SELECT * FROM `empleados` WHERE `correo` = '$email'";
    $resultadocorreo = mysqli_query($conexion,$checkcorreo);

    
    if(mysqli_num_rows($resultadocorreo) == 1)
    {
        echo json_encode([
            'status' => 'encontrado',
            'message' => 'Usuario previamente registrado, favor de intentarlo con una cuenta nueva'
        ]);
    }
    
    else
    {
        
        $resultado = mysqli_query($conexion,$insert);
        if(mysqli_affected_rows($conexion) == 1)
        {
            echo json_encode([
                'status' => 'success',
            ]);
        }
        else
        {
            echo json_encode([
                'status' => 'no registrado',
                'message' => 'No se pudo registrar usuario, intentelo de nuevo'
            ]);
        }
    }  
}

else
{
    echo json_encode([
        'status' => 'error',
        'message' => 'No se recibieron datos.'
    ]);
}
?>