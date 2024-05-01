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
        <script src="./gmenu.js"></script>
        <script src="https://kit.fontawesome.com/8a3c5cedf1.js" crossorigin="anonymous"></script>
        
        <title>Admin-Palomino</title>
        
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
            <li><a class="black-text" href="./adminindex.php">Inicio</a></li>
            <li><a class="black-text" href="./adminmenu.php">Platillos</a></li>
        </ul>
        <nav class="grey">
            <div class="nav-wrapper">
            <a href="#" data-target="mobile-demo" class="sidenav-trigger"><i class="fas fa-bars"></i></a>
            <ul class="right hide-on-med-and-down">
                <?php
                    echo "<li><i class='fas fa-user-shield' style='color:blue;'></i></li>";
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
                <li><a class="black-text" href="./adminindex.php">Inicio</a></li>
                <li><a class="black-text" href="./adminmenu.php">Platillos</a></li>
                <li><a class="light-blue" href="salir.php">Cerrar Sesion</a></li>
              </div>
            </ul>
        </nav>

        <!--Galeria de Imagenes-->
        <div class="slider">
            <ul class="slides">
              <li>
                <a href="./gmenu.php">
                    <img src="./../Img/menu.jpg" > <!-- random image -->
                    <div class="caption center-align">
                        <h3 class="blue-text">Gestion de Menu</h3>
                    </div>
                </a>
              </li>
              <li>
                <a href="./ginventario.php">
                    <img src="./../Img/inventario.jpg"> <!-- random image -->
                    <div class="caption center-align">
                        <h3 class="blue-text">Gestion de Inventario</h3>
                    </div>
                </a>
              </li>
              <li>
                <a href="./gpago.php">
                    <img src="./../Img/pago.jpg"> <!-- random image -->
                    <div class="caption center-align">
                        <h3 class="blue-text">Gestion de Pagos</h3>
                    </div>
                </a>
              </li>
              <li>
                <a href="./gpedido.php">
                    <img src="./../Img/pedido.jpg"> <!-- random image -->
                        <div class="caption center-align">
                            <h3 class="blue-text">Gestion de Pedidos</h3>
                        </div>
                </a>
              </li>
              <li>
                <a  href="./gusuario.php">
                    <img src="./../Img/usuario.png"> <!-- random image -->
                        <div class="caption center-align">
                            <h3 class="blue-text">Gestion de Usuarios</h3>
                        </div>
                </a>
              </li>
            </ul>
        </div> <!-- /slider -->
        
        <!--Contenedor-->
        <div class="container">
            <div class="center-align">
                <h2 class="blue-grey-text">Gestion de Menu</h2>
            </div>

            <!--Menu-->
            <!--1-->
            <h4 class="blue-text">Cafe</h4>
            <?php
                $conexion = mysqli_connect("localhost","root","","web");
                mysqli_query($conexion, "SET character_set_results = 'utf8', character_set_client = 'utf8', character_set_connection = 'utf8', character_set_database = 'utf8', character_set_server = 'utf8'");
                              
                $sql = "SELECT * FROM  menu WHERE grupo = 1";
                $resultado = mysqli_query($conexion,$sql);
                $info = mysqli_num_rows($resultado);
                $datos = mysqli_fetch_array($resultado);
            ?>
            <table class="responsive-table centered">
                <thead>
                <tr>
                    <th class="white-text">Producto</th>
                    <th class="white-text">Descripcion</th>
                    <th class="white-text">Precio</th>
                    <th class="white-text">Opciones</th>
                </tr>
                </thead>

                <tbody>
                <tr>
                    <td class="white-text" data-producto="<?php $datos["producto"];?>"><?php echo $datos["producto"]; ?></td>
                    <td class="white-text"><?php echo $datos["descripción"]; ?></td>
                    <td class="white-text"><?php echo $datos["precio"]; ?></td>
                    <td>
                        <i class="fas fa-edit editar" style="color: cyan;"></i></a>
                        <i class="fas fa-trash-alt eliminar" style="color: red;"></i></a>
                    </td>
                </tr>
                </tbody>
            </table>

            <!--2-->
            <h4 class="blue-text">Bebidas Calientes</h4>
            <div class="row">
                <div class="s12 m2">
                </div>
            </div>

            <!--3-->
           <h4 class="blue-text">Bebidas Frias</h4>
            <div class="row">
                <div class="s12 m2">      
                </div>
            </div>

            <!--4-->
            <h4 class="blue-text">Metodos Artesanales</h4>
            <div class="row">
                <div class="s12 m2">
                </div>
            </div>

            <!--5-->
            <h4 class="blue-text">Postres</h4>
            <div class="row">
                <div class="s12 m2">
                </div>
            </div>

            <!--6-->
            <h4 class="blue-text">Panques/Galletas/Scones</h4>
            <div class="row">
                <div class="s12 m2">
                </div>
            </div>

            <!--7-->
            <h4 class="blue-text">Cafe en Grano</h4>
                <div class="row">
                    <div class="s12 m2">
                    </div>
                </div>

            <!--8-->
            <h4 class="blue-text">Sandwiches</h4>
            <div class="row">
                <div class="s12 m2">
                </div>
            </div>

            <!--9-->
            <h4 class="blue-text">Hamburguesas</h4>
            <div class="row">
                <div class="s12 m2">
                </div>
            </div>
        </div>

    </body>
</html>

<?php
    }
    else
    {
        header("location: ./login.html");
    }
?>