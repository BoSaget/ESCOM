<?php
//Conexion a base de datos
$conexion = mysqli_connect("localhost","root","","cafeteria");
mysqli_query($conexion, "SET character_set_results = 'utf8', character_set_client = 'utf8', character_set_connection = 'utf8', character_set_database = 'utf8', character_set_server = 'utf8'");

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $input = json_decode(file_get_contents('php://input'), true);
    
    $id = $input['id'];

    $borrar = "DELETE FROM `menu` WHERE id='$id'";
    
    if (mysqli_query($conexion, $borrar)) {
        echo json_encode(['success' => true]);
    } else {
        echo json_encode(['success' => false]);
    }
}
?>
