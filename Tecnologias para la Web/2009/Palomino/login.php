<?php
  session_start();
  $usuario = $_POST["usuario"];
  $pass = md5($_POST["pass"]);
  
  $conexion = mysqli_connect("localhost","root","","web");
  mysqli_query($conexion, "SET character_set_results = 'utf8', character_set_client = 'utf8', character_set_connection = 'utf8', character_set_database = 'utf8', character_set_server = 'utf8'");

  $sql = "SELECT * FROM cafeteria WHERE correo = '$usuario' AND pass = '$pass'";
  $resultado = mysqli_query($conexion,$sql);
  $info = mysqli_num_rows($resultado);
  $datos = mysqli_fetch_row($resultado);
  $respAX = array();
  if($info == 1)
  {
    $nombre=$datos[0];
    $rango=$datos[4];
    $respAX["codigo"] = 1;
    $respAX["msj"] = "<h3 class='center-align'>¡Bienvenido! $nombre</h3>";
    $_SESSION["login"] = $nombre;
    $_SESSION["rango"] = $rango;
    
    if($rango == "Admin")
      {
        $respAX["codigo"] = -1;
      }
  }
  else
  {
    $sql = "SELECT * FROM cafeteria WHERE celular = '$usuario' AND pass = '$pass'";
    $resultado = mysqli_query($conexion,$sql);
    $info = mysqli_num_rows($resultado);
    $nombre = mysqli_fetch_row($resultado);
    $respAX = array();
    
    if($info == 1)
    {
      $nombre=$datos[0];
      $rango=$datos[4]; 
      $respAX["codigo"] = 1;
      $respAX["msj"] = "<h3 class='center-align'>¡Bienvenido! $nombre</h3>";
      $_SESSION["login"] = $nombre;
      $_SESSION["rango"] = $rango;

      if($rango == "Admin")
      {
        $respAX["codigo"] = -1;
      }
    }
    else
    {
        $respAX["codigo"] = 0;
        $respAX["msj"] = "<h3 class='center-align'>Error. Favor de intentarlo nuevamente</h3>";
    }
  }

  echo json_encode($respAX);
?>