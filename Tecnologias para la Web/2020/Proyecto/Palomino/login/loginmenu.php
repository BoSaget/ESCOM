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
                <img src="./../Img/cafe.jpeg"> <!-- random image -->
                <div class="caption center-align">
                  <h3>Café</h3>
                </div>
              </li>
              <li>
                <img src="./../Img/te.jpg"> <!-- random image -->
                <div class="caption center-align">
                  <h3>Bebidad Calientes/Frias</h3>
                </div>
              </li>
              <li>
                <img src="./../Img/galleta.jpg"> <!-- random image -->
                <div class="caption center-align">
                  <h3>Galletas/Panques/Scone</h3>
                </div>
              </li>
              <li>
                <img src="./../Img/grano.jpg"> <!-- random image -->
                <div class="caption center-align">
                  <h3>Granos/Metodos Artesanales</h3>
                </div>
              </li>
              <li>
                <img src="./../Img/hamburguesa.jpg"> <!-- random image -->
                <div class="caption center-align">
                  <h3>hamburguesa</h3>
                </div>
              </li>
              <li>
                <img src="./../Img/sandwich.jpg"> <!-- random image -->
                <div class="caption center-align">
                  <h3>Sandwich</h3>
                </div>
              </li>
              <li>
                <img src="./../Img/pay.jpg"> <!-- random image -->
                <div class="caption center-align">
                  <h3>Postres</h3>
                </div>
              </li>
            </ul>
          </div> <!-- /slider -->

        <!--Contenedor-->
        <div class="container">
            <div class="center-align">
                <h2 class="blue-grey-text">Productos para todo tipo de gustos.</h2>
            </div>
        </div>

        <!--Menu con Descripcion-->
        <!--1-->
        <div class="row">
            <div class="col s12 m2 center-align">
                <a href="cafe.php"><i class="fas fa-coffee" style="font-size:30px;color: white"></i></a>
                <p class="white-text">CAFÉ</p>
            </div>
            <div class="col s12 m10">
                <p class="justificado">La especialidad de Cafeteria Palomino, es el café, puesto que somos amantes de este grano,
                    ademas de nosotros tener nuestra propia granja de granos de cafe de la mejor calidad, tambien tenemos granos
                    para todos los gutos, nacionales e internacionales, para asi lograr ofrecerte una experiencia de calidad de la que no te 
                    arrepentiras.
                </p>
            </div>
        </div>
        <!--2-->
        <div class="row">
            <div class="col s12 m10">
                <p class="justificado">Contamos aparte con diferentes bebidas calientes, para las personas que disfrutan de otro tipos
                    de bebidas, contamos con un menu demasiado amplio, en el cual de sseguro encontrararas una bebida de tu agrado, contamos
                    con los mejores ingredientes de calidadpara que tu experiencia sea unica.
                </p>
            </div>
            <div class="col s12 m2 center-align">
                <a href="bcaliente.php"><i class="fas fa-mug-hot" style="font-size:30px;color: white"></i></a>
                <p class="white-text">BEBIDAS CALIENTES</p>
            </div>
        </div>
        <!--3-->
        <div class="row">
            <div class="col s12 m2 center-align">
                <a href="bfria.php"><i class="fas fa-glass-whiskey" style="font-size:30px;color: white"></i></a>
                <p class="white-text">BEBIDAS FRIAS</p>
            </div>
            <div class="col s12 m10">
                <p class="justificado">Contamos aparte con diferentes bebidas frias, para las personas que disfrutan de otro tipos
                    de bebidas, contamos con un menu demasiado amplio, en el cual de sseguro encontrararas una bebida de tu agrado, contamos
                    con los mejores ingredientes de calidadpara que tu experiencia sea unica.
                </p>
            </div>
        </div>
        <!--4-->
        <div class="row">
            <div class="col s12 m10">
                <p class="justificado">Utilizamos los mejores elementos para asi lograr obtee¡ner todo el potencial que ofrece el café,
                estos productos son para la gente que desea llevar su experiencia en el café a u nivel superior, alcanzando una satisfaccion
                extrema al sentir el delicioso aroma y sabor del cafe con nuesrtros metodos artesanales, no se arrepentira.
                </p>
            </div>
            <div class="col s12 m2 center-align">
                <a href="artesanal.php"><i class="fas fa-hand-sparkles" style="font-size:30px;color: white"></i></a>
                <p class="white-text">METODOS ARTESANALES</p>
            </div>
        </div>
        <!--5-->
        <div class="row">
            <div class="col s12 m2 center-align">
                <a href="postre.php"><i class="fas fa-ice-cream" style="font-size:30px;color: white"></i></a>
                <p class="white-text">POSTRES</p>
            </div>
            <div class="col s12 m10">
                <p class="justificado">Para las persona que desean explorar en el lado dulce, tenemos varios platillos que los podrian
                    llevar a un destino increible, ademas de que si se combinan con alguna de nuestras bebidas, la experienciaes aun
                    mejor, pruebe nuestros postres, ya que cuentan con un gran sabor.
                </p>
            </div>
        </div>
        <!--6-->
        <div class="row">
            <div class="col s12 m10">
                <p class="justificado">Nuestro personal esta listo para servirle un perfecto panqué esponjoso que de seguro mas de una rebanada
                    la gustara, puesto que son realizados con una calidad superor. Nuestras galletas no se quedan atras, ya que utilizamos los
                    elementos de mas alta calidad para que disfrute cada migaja acompañada de una de nuestras bebidas.
                </p>
            </div>
            <div class="col s12 m2 center-align">
                <a href="panque.php"><i class="fas fa-bread-slice" style="font-size:30px;color: white"></i></a>
                <p class="white-text">PANQUÉS/GALLETAS/SCONES</p>
            </div>
        </div>
        <!--7-->
        <div class="row">
            <div class="col s12 m2 center-align">
                <a href="cafegrano.php"><i class="fas fa-seedling" style="font-size:30px;color: white"></i></a>
                <p class="white-text">CAFÉ EN GRANO</p>
            </div>
            <div class="col s12 m10">
                <p class="justificado">Ponemos a su disposicion el delicioso sabor de nuestro café para que usted puedo realizarlo
                    desde la comodidad de su casa, contamos con granos de alta calidad para que pueda satisfacer su antojo de cafe sin
                    importar que hora sea, ya que el sabor del grano lo dejara completamente satisfecho.
                </p>
            </div>
        </div>
        <!--8-->
        <div class="row">
            <div class="col s12 m10">
                <p class="justificado">Si desea tener un alimento un poco menos ligero, contamos con ingredientes frescos y de alta calidad, 
                    para lograr realizar el sandwich que se merece, ademas de que es hecho al momento, no encontrara ningun lugar mejor para
                    satisfacer sus antojo de sandwiches.
                </p>
            </div>
            <div class="col s12 m2 center-align">
                <a href="sandwich.php"><i class="fas fa-cheese" style="font-size:30px;color: white"></i></a>
                <p class="white-text">SANDWICHES</p>
            </div>
        </div>
        <!--9-->
        <div class="row">
            <div class="col s12 m2 center-align">
                <a href="hambur.php"><i class="fas fa-hamburger" style="font-size:30px;color: white"></i></a>
                <p class="white-text">HAMBURGUESAS</p>
            </div>
            <div class="col s12 m10">
                <p class="justificado">Gracias a nuestros ingredientes frescos y a la increible calidad de nuestras carnes, podemos 
                    ofrecerle una hamburguesa de una calidad superior, usted realizara una gran viaje en el camino del sabor con la
                    mejor hamburguesa de la zona, un platillo excelente para satisfacer el hambre que se genere en el dia. 
                </p>
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
