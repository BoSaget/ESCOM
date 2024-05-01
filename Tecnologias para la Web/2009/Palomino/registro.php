<?php
  $nombre = $_POST["nombre"];
  $paterno = $_POST["paterno"];
  $materno = $_POST["materno"];
  $pass = md5($_POST["pass"]);
  $correo = $_POST["correo"];
  $celular = $_POST["celular"];

  $conexion = mysqli_connect("localhost","root","","web");
  mysqli_query($conexion, "SET character_set_results = 'utf8', character_set_client = 'utf8', character_set_connection = 'utf8', character_set_database = 'utf8', character_set_server = 'utf8'");

  /*
  // La respuesta que el servidor generará será en formato HTML
  $respAX_HTML = "";
  $sql = "INSERT INTO alumnos VALUES('$boleta','$nombre','$correo','$contrasena',NOW())";
  $sqlCheckBoleta = "SELECT * FROM alumnos WHERE boleta = '$boleta'";
  $resultadoCheckBoleta = mysqli_query($conexion,$sqlCheckBoleta);
  if(mysqli_num_rows($resultadoCheckBoleta) == 1){
    $respAX_HTML .= "<h3>Error. El número ya está registrado. Favor de intentarlo nuevamente :(</h3>";
  }else{
    $resultado = mysqli_query($conexion,$sql);
    if(mysqli_affected_rows($conexion) == 1){
      $respAX_HTML .= "<h3>Gracia. Tu registro se realizó correctamente :)</h3>";
    }else{
      $respAX_HTML .= "<h3>Error. Favor de intentarlo nuevamente :(</h3>";
    }
  }
  */

  // La respuesta que el servidor generará será en formato JSON
  $respAX_JSON = array();
  
  $conexion = mysqli_connect("localhost","root","","web");
  $sql = "INSERT INTO cafeteria (`nombre`, `paterno`, `materno`,  `pass` , `rango`, `correo`, `celular`) VALUES ('$nombre','$paterno','$materno','$pass', 'Sin Rango', '$correo', '$celular')";
  
  $checkcorreo = "SELECT * FROM cafeteria WHERE correo = '$correo'";
  $resultadocorreo = mysqli_query($conexion,$checkcorreo);

  if(mysqli_num_rows($resultadocorreo) == 1)
  {
    $respAX_JSON["codigo"] = 2;
    $respAX_JSON["msj"] = "<h5 class='center-align' style='color: white;'>Error. El correo ya está registrado.<br>Favor de intentarlo nuevamente</h5>";
  }
  else
  {
    $checkcel = "SELECT * FROM cafeteria WHERE celular = '$celular'";
    $resultadocel = mysqli_query($conexion,$checkcel);
    if(mysqli_num_rows($resultadocel) == 1)
    {
      $respAX_JSON["codigo"] = 2;
      $respAX_JSON["msj"] = "<h5 class='center-align' style='color: white;'>Error. El numero telefonico ya está registrado.<br>Favor de intentarlo nuevamente</h5>";
    }
    else
    {
      $resultado = mysqli_query($conexion,$sql);
      if(mysqli_affected_rows($conexion) == 1)
      {
        $respAX_JSON["codigo"] = 1;
        $respAX_JSON["msj"] = "<h5 class='center-align' style='color: white;'>Gracias. Tu registro se realizó correctamente</h5>";
      }
      else
      {
        $respAX_JSON["codigo"] = 0;
        $respAX_JSON["msj"] = "<h5 class='center-align' style='color: white;'>Error. Favor de intentarlo nuevamente</h5>";
      }
    }
  }
  
  //{"codigo":1,"msj":"<h3>Gracias|Error...</h3"}
  echo json_encode($respAX_JSON);
?>