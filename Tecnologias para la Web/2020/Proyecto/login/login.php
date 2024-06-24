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
    $user= $data['user'];
    $pass=md5($data['pass']);

    //Checará si el correo ingresado es del tipo @pl.com, ya que con esa terminación ingresan los empleados
    if (preg_match('/^[a-zA-Z0-9._%+-]+@pl\.com$/', $user))
    {
        //Hace la consulta en la base de datos de empleado si coincide con el tipo @pl.com
        $sql = "SELECT * FROM `empleados` WHERE `correo`= '$user' AND `contraseña` = '$pass'";
        $resultado = mysqli_query($conexion,$sql);
        $info = mysqli_num_rows($resultado);
        $datos = mysqli_fetch_row($resultado);
        if($info == 1)
        {
            $rol=$datos[1];
            $correo=$datos[2];
            $user=$datos[3];
            
            session_start();
            $_SESSION["rol"] = $rol;
            $_SESSION["correo"] = $correo;
            $_SESSION["user"] = $user;
            
            echo json_encode([
                'status' => 'success',
                'empleado' => 1,
                'rol' => $rol
            ]);
        }
        else
        {
            echo json_encode([
                'status' => 'not found',
                'message' => 'Error, favor de intentarlo nuevamente Usuario no encontrado'
            ]);
        }
    }

    //De lo contrario checa en la base de datos de usuarios
    else
    {
        //Revisa si tiene que consultar por correo electronico o numero
        if (preg_match("/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/", $user)) 
        {
            $sql = "SELECT * FROM `usuarios` WHERE `correo`= '$user' AND `contraseña` = '$pass'";
            $resultado = mysqli_query($conexion,$sql);
            $info = mysqli_num_rows($resultado);
            $datos = mysqli_fetch_row($resultado);
            if($info == 1)
            {
                
                $correo=$datos[1];
                $user=$datos[3];
                $rango=$datos[5];

                session_start();
                $_SESSION["correo"] = $correo;
                $_SESSION["user"] = $user;
                $_SESSION["rango"] = $rango;

                echo json_encode([
                    'status' => 'success',
                    'empleado' => 0,
                ]);
            }
            else
            {
                echo json_encode([
                    'status' => 'not found',
                    'message' => 'Error, favor de intentarlo nuevamente Usuario no encontrado'
                ]);
            }
        }
        else
        {
            $sql = "SELECT * FROM `usuarios` WHERE `telefono`= '$user' AND `contraseña` = '$pass'";
            $resultado = mysqli_query($conexion,$sql);
            $info = mysqli_num_rows($resultado);
            $datos = mysqli_fetch_row($resultado);
            if($info == 1)
            {
                $correo=$datos[1];
                $user=$datos[3];
                $rango=$datos[5];

                session_start();
                $_SESSION["correo"] = $correo;
                $_SESSION["user"] = $user;
                $_SESSION["rango"] = $rango;

                echo json_encode([
                    'status' => 'success',
                    'empleado' => 0,
                ]);
            }
            else
            {
                echo json_encode([
                    'status' => 'not found',
                    'message' => 'Error, favor de intentarlo nuevamente Usuario no encontrado'
                ]);
            }
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