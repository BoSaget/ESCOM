<?php

//Conexion a base de datos
$conexion = mysqli_connect("localhost","root","","extra");
mysqli_query($conexion, "SET character_set_results = 'utf8', character_set_client = 'utf8', character_set_connection = 'utf8', character_set_database = 'utf8', character_set_server = 'utf8'");



// Configurar el tipo de respuesta a JSON
header('Content-Type: application/json');

// Obtener el cuerpo de la solicitud
$data = json_decode(file_get_contents('php://input'), true);

if ($data) 
{

    $id =  $data['id'];


    $insert = "DELETE FROM `cursos` WHERE id='$id'";
     
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

else
{
    echo json_encode([
        'status' => 'error',
        'message' => 'No se recibieron datos.'
    ]);
}
?>