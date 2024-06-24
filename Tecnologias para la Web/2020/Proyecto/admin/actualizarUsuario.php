<?php
$conexion = mysqli_connect("localhost", "root", "", "cafeteria");

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $input = json_decode(file_get_contents('php://input'), true);
    $id = $input['id'];
    $data = $input['data'];

    
    $correo = $data['correo'];
    $telefono = $data['telefono'];
    $nombre = $data['nombre'];
    $pass = md5($data['pass']);
    $rango = $data['rango'];

    $sql = "UPDATE usuarios SET correo='$correo', telefono='$telefono', nombre='$nombre', contraseña='$pass', rango='$rango' WHERE id='$id'";
    
    if (mysqli_query($conexion, $sql)) {
        echo json_encode(['success' => true]);
    } else {
        echo json_encode(['success' => false]);
    }
}
?>
