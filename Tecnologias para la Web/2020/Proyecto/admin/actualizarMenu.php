<?php
$conexion = mysqli_connect("localhost", "root", "", "cafeteria");

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $input = json_decode(file_get_contents('php://input'), true);
    $id = $input['id'];
    $data = $input['data'];

    $item = $data['item'];
    $tipo = $data['tipo'];
    $ingredientes = $data['ingredientes'];
    $notas = $data['notas'];
    $precioCadena = $data['precio'];

    // Usamos filter_var para extraer el número
    $precio = filter_var($precioCadena, FILTER_SANITIZE_NUMBER_INT);


    if($data['ingredientes'] == NULL)
    {
        $ingredientes=NULL;
    }
   
    if($data['notas'] == NULL)
    {
        $notas=NULL;
    }

    $sql = "UPDATE menu SET item='$item', tipo='$tipo', ingredientes='$ingredientes', notas='$notas', precio='$precio' WHERE id='$id'";
    
    if (mysqli_query($conexion, $sql)) {
        echo json_encode(['success' => true]);
    } else {
        echo json_encode(['success' => false]);
    }
}
?>
