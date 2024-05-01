<?php
    session_start();
    if(isset($_SESSION["login"])){
        $nombre = $_SESSION["login"];
        $rango = $_SESSION["rango"];
        $conexion = mysqli_connect("localhost","root","","web");
        $sqlInfo = "SELECT * FROM cafeteria WHERE nombre = '$nombre'";
        $resInfo = mysqli_query($conexion,$sqlInfo);
        $info = mysqli_fetch_row($resInfo);
?>

<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
        <meta name='viewport' content='width=device-width,initial-scale=1,minimum-scale=1,maximum-scale=1,user-scalable=no'/>
        <meta name="description" content="">
        <meta name="keywords" content="">
        
        <link rel="stylesheet" href="./../styles.css">
        <link rel="stylesheet" href="./../../Materialize/css/materialize.css">
        <link rel="stylesheet" href="./../../Jquery/Plugins/validetta/validetta.css">
        <link rel="stylesheet" href="./../../Jquery/Plugins/confirm/css/jquery-confirm.css">
        <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">

        <script src="./../../Jquery/jquery-3.6.0.js"></script>
        <script src="./../../Materialize/js/materialize.js"></script>
        <script src="./../../Jquery/Plugins/validetta/validetta.js"></script>
        <script src="./../../Jquery/Plugins/validetta/validettaLang-es-ES.js"></script>
        <script src="./../../Jquery/Plugins/confirm/js/jquery-confirm.js"></script>
        <script src="https://kit.fontawesome.com/8a3c5cedf1.js" crossorigin="anonymous"></script>
        
        <title>Palomino</title>
        
        <div class="row">
            <div class="col s6"><h1 class="white-text">Cafeteria Palomino</h1></div>
            <div class="col s6"><i class="fas fa-dove" style="font-size:50px;color: white"></i></div>
        </div>

        <script>
            $(document).ready(function(){
                $('.dropdown-trigger').dropdown();
                $('.sidenav').sidenav();
                $('.slider').slider();
            });
        </script>

    </head>    
    
    <body>
        <!-- MEnu de Navegacion -->
        <ul id="dropdown1" class="dropdown-content grey">
            <li><a class="black-text" href="./loginindex.php">Inicio</a></li>
            <li><a class="black-text" href="./loginmenu.php">Platillos</a></li>
            <li><a class="black-text" href="./loginrewards.php">Recompensas</a></li>
            <li><a class="black-text" href="./loginfaq.php">Preguntas Frecuentas</a></li>
        </ul>
        <nav class="grey">
            <div class="nav-wrapper">
            <a href="#" data-target="mobile-demo" class="sidenav-trigger"><i class="fas fa-bars"></i></a>
            <ul class="right hide-on-med-and-down">
                <?php
                    if($rango=="Sin Rango")
                    {
                        echo "<li><i class='fas fa-circle-notch'></i></li>";
                    }

                    else
                    {

                        echo "<li><i class='fas fa-circle-notch' style='color:gold;'></i></li>";
                    }

                    echo "<li>$nombre</li>";
                ?>
                <li><a href="salir.php">Cerrar Sesion</a></li>
            </ul>
            <ul  class="left hide-on-med-and-down">
                 <!-- Dropdown Trigger -->
                 <li><a class="dropdown-trigger" href="#!" data-target="dropdown1"><i class="fas fa-bars"></i></a></li>
            </ul>
            </div>

            <ul class="sidenav" id="mobile-demo">
              <div class="grey">
                <?php
                    echo "<li class='black-text'>$nombre</li>";
                ?>
                <li><a class="black-text" href="./loginindex.php">Inicio</a></li>
                <li><a class="black-text" href="./loginmenu.php">Platillos</a></li>
                <li><a class="black-text" href="./loginrewards.php">Recompensas</a></li>
                <li><a class="black-text" href="./loginfaq.php">Preguntas Frecuentas</a></li>
                <li><a class="light-blue" href="salir.php">Cerrar Sesion</a></li>
              </div>
            </ul>
        </nav>

        <!--Galeria de Imagenes-->
        <div class="slider">
            <ul class="slides">
              <li>
                <img src="./../Img/1.jpg"> <!-- random image -->
                <div class="caption center-align">
                </div>
              </li>
              <li>
                <img src="./../Img/2.jpg"> <!-- random image -->
                <div class="caption center-align">
                </div>
              </li>
              <li>
                <img src="./../Img/3.jpg"> <!-- random image -->
                <div class="caption center-align">
                </div>
              </li>
              <li>
                <img src="./../Img/4.jpg"> <!-- random image -->
                <div class="caption center-align">
                </div>
              </li>
            </ul>
          </div> <!-- /slider -->

        <!--Contenedor-->
        <div class="container">
            <div class="center-align">
                <h2 class="blue-grey-text">¿Quienes Somos?</h2>
            </div>
        </div>
    </body>
</html>

<?php
    }
    else
    {
        header("location: ./../login.html");
    }
?>
