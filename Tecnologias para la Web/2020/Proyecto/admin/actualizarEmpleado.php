<?php
$conexion = mysqli_connect("localhost", "root", "", "cafeteria");

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $input = json_decode(file_get_contents('php://input'), true);
    $id = $input['id'];
    $data = $input['data'];

    $rol = $data['rol'];
    $correo = $data['correo'];
    $nombre = $data['nombre'];
    $pass = md5($data['pass']);

    $sql = "UPDATE empleados SET rol='$rol', correo='$correo', nombre='$nombre', contraseña='$pass' WHERE id='$id'";
    
    if (mysqli_query($conexion, $sql)) {
        echo json_encode(['success' => true]);
    } else {
        echo json_encode(['success' => false]);
    }
}
?>
