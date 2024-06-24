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
    $platillo= $data['platillo'];
    $tipo= $data['tipo'];
    $ingredientes= $data['ingredientes'];
    $notas= $data['notas'];
    $precio= $data['precio'];

    if($ingredientes == "")
    {
        $ingredientes = NULL;
    }

    if($notas == "")
    {
        $notas = NULL;
    }


    $insert = "INSERT INTO `menu` (`item`, `tipo`, `ingredientes`, `notas`, `precio` ) VALUES ('$platillo','$tipo','$ingredientes','$notas','$precio')";

    //Checa si ese platillo ya está asignado a ese grupo
    $checkItem = "SELECT * FROM `menu` WHERE `item` = '$platillo' AND tipo='$tipo'";
    $resultadoItem = mysqli_query($conexion,$checkItem);

    
    if(mysqli_num_rows($resultadoItem) == 1)
    {
        echo json_encode([
            'status' => 'encontrado',
            'message' => 'Platillo ya registrado en el grupo'
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
                'message' => 'No se pudo registrar platillo, intentelo de nuevo'
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