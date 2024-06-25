<?php
session_start();
if (isset($_SESSION["correo"]) && isset($_SESSION["user"]) && $_SERVER['REQUEST_METHOD'] == 'POST') {
    $userId = $_SESSION["user_id"];
    $conexion = mysqli_connect("localhost", "root", "", "cafeteria");
    mysqli_query($conexion, "SET character_set_results = 'utf8', character_set_client = 'utf8', character_set_connection = 'utf8', character_set_database = 'utf8', character_set_server = 'utf8'");

    $data = json_decode(file_get_contents('php://input'), true);
    $carrito = $data['carrito'];
    $notas = mysqli_real_escape_string($conexion, $data['notas']);
    $fecha = date('Y-m-d H:i:s');

    $sqlPedido = "INSERT INTO pedidos (user_id, fecha, notas) VALUES ($userId, '$fecha', '$notas')";
    if (mysqli_query($conexion, $sqlPedido)) {
        $pedidoId = mysqli_insert_id($conexion);

        foreach ($carrito as $item) {
            $itemId = $item['id'];
            $cantidad = $item['quantity'];
            $sqlDetalle = "INSERT INTO detalles_pedido (pedido_id, item_id, cantidad) VALUES ($pedidoId, $itemId, $cantidad)";
            mysqli_query($conexion, $sqlDetalle);
        }
        echo json_encode(['status' => 'success']);
    }
    else
    {
        echo json_encode(['status' => 'error', 'message' => 'Error al guardar el pedido']);
    }
}
else
{
    echo json_encode(['status' => 'error', 'message' => 'Unauthorized']);
}
?>
