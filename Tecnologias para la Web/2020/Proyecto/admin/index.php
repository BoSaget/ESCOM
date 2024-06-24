<?php
    session_start();
    if(isset($_SESSION["correo"]) && isset($_SESSION["user"])){
        
        $rol = $_SESSION["rol"];
        $correo = $_SESSION["correo"];
        $user = $_SESSION["user"];


        $conexion = mysqli_connect("localhost","root","","cafeteria");
        mysqli_query($conexion, "SET character_set_results = 'utf8', character_set_client = 'utf8', character_set_connection = 'utf8', character_set_database = 'utf8', character_set_server = 'utf8'");

        $sqlInfo = "SELECT * FROM `empleados` WHERE `correo`= '$correo' AND `nombre` = '$user'";
        $resInfo = mysqli_query($conexion,$sqlInfo);

        $info = mysqli_fetch_row($resInfo);
?>

<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link href="./../output.css" rel="stylesheet">
        <script src="https://cdn.tailwindcss.com"></script>
        <script src="https://kit.fontawesome.com/8a3c5cedf1.js" crossorigin="anonymous"></script>

        <title>Administrción</title>
    </head>

    <body class="bg-slate-600">
        <nav class="bg-blue-800">
            <div class="mx-auto max-w-7xl px-2 sm:px-6 lg:px-8">
                <div class="relative flex h-16 items-center justify-between">
                    <div class="absolute inset-y-0 left-0 flex items-center sm:hidden">
                        <!-- Mobile menu button-->
                        <button type="button" id="mobile-menu-button" class="relative inline-flex items-center justify-center rounded-md p-2 text-gray-400 hover:bg-gray-700 hover:text-white focus:outline-none focus:ring-2 focus:ring-inset focus:ring-white" aria-controls="mobile-menu" aria-expanded="false">
                            <span class="absolute -inset-0.5"></span>
                            <span class="sr-only">Open main menu</span>
                            <!--
                            Icon when menu is closed.
          
                            Menu open: "hidden", Menu closed: "block"
                            -->
                            <svg class="block h-6 w-6" fill="none" viewBox="0 0 24 24" stroke-width="1.5" stroke="currentColor" aria-hidden="true">
                                <path stroke-linecap="round" stroke-linejoin="round" d="M3.75 6.75h16.5M3.75 12h16.5m-16.5 5.25h16.5" />
                            </svg>
                            <!--
                            Icon when menu is open.
          
                            Menu open: "block", Menu closed: "hidden"
                            -->
                            <svg class="hidden h-6 w-6" fill="none" viewBox="0 0 24 24" stroke-width="1.5" stroke="currentColor" aria-hidden="true">
                                <path stroke-linecap="round" stroke-linejoin="round" d="M6 18L18 6M6 6l12 12" />
                            </svg>
                        </button>
                    </div>

                    <div class="flex flex-1 items-center justify-center sm:items-stretch sm:justify-start">
                        <div class="flex flex-shrink-0 items-center">
                            <img class="h-8 w-auto" src="./../img/Logo.png" alt="Palomino Logo">
                        </div>
                        <div class="hidden sm:ml-6 sm:block">
                            <div class="flex space-x-4">
                            <!-- Current: "bg-gray-900 text-white", Default: "text-gray-300 hover:bg-gray-700 hover:text-white" -->
                                <a href="./index.php" class="bg-blue-900 text-white rounded-md px-3 py-2 text-sm font-medium" aria-current="page">Inicio</a>
                                <a href="./modificarMenu.php" class="text-gray-300 hover:bg-gray-700 hover:text-white rounded-md px-3 py-2 text-sm font-medium">Modificar Menú</a>
                                <a href="./empleados.php" class="text-gray-300 hover:bg-gray-700 hover:text-white rounded-md px-3 py-2 text-sm font-medium">Empleados</a>
                                <a href="./usuarios.php" class="text-gray-300 hover:bg-gray-700 hover:text-white rounded-md px-3 py-2 text-sm font-medium">Usuarios</a>
                            </div>
                        </div>
                    </div>
                    <!-- Login -->
                    <div class="hidden sm:ml-6 sm:block">
                        <div class="flex space-x-4 left">
                            <a href="./logout.php" class="bg-red-700 rounded-md px-3 py-2 text-sm font-medium">Logout</a>
                        </div>
                    </div>
                </div>
            </div>
          
            <!-- Mobile menu, show/hide based on menu state. -->
            <div id="mobile-menu" class="hidden">
                <div class="space-y-1 px-2 pb-3 pt-2">
                    <!-- Current: "bg-gray-900 text-white", Default: "text-gray-300 hover:bg-gray-700 hover:text-white" -->
                    <a href="./index.html" class="bg-blue-900 text-white block rounded-md px-3 py-2 text-base font-medium" aria-current="page">Inicio</a>
                    <a href="../modificarMenu.php" class="text-gray-300 hover:bg-gray-700 hover:text-white block rounded-md px-3 py-2 text-base font-medium">Modificar Menú</a>
                    <a href="./empleados.php" class="text-gray-300 hover:bg-gray-700 hover:text-white block rounded-md px-3 py-2 text-base font-medium">Empleados</a>
                    <a href="./usuarios.php" class="text-gray-300 hover:bg-gray-700 hover:text-white block rounded-md px-3 py-2 text-base font-medium">Empleados</a>
                    <a href="./logout.php" class="bg-red-700 text-white block rounded-md px-3 py-2 text-base font-medium">Logout</a>
                </div>
            </div>
        </nav>

        <div class="container my-5 mx-auto lg:mx-10 flex-auto text-center ">

            <h1 class="text-3xl font-bold underline">
                Bienvenido <?php echo "$user"; ?>
            </h1>

            <div class="contain-none leading-relaxed text-justify my-5 mx-2 lg:mx-60">
                <p class="font-medium lg:text-lg">
                    Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed vel augue metus. Praesent consectetur justo non lorem euismod, ut hendrerit dui rhoncus. Aliquam finibus odio ipsum, id molestie nulla imperdiet sit amet. Nunc sem nunc, consequat sit amet dolor nec, sagittis rutrum metus. Duis cursus augue urna, non lobortis odio varius vel. Aliquam erat volutpat. Interdum et malesuada fames ac ante ipsum primis in faucibus.

                    Praesent pulvinar dui purus, sed cursus velit eleifend vel. Suspendisse potenti. Nulla pretium purus a lacinia scelerisque. Aenean accumsan sagittis dui, eu tristique elit vulputate in. Vestibulum lacinia nisl ut purus dapibus, id laoreet turpis malesuada. In semper dolor non faucibus auctor. Quisque eget rutrum quam. Fusce ultricies dui venenatis ligula molestie efficitur. Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Pellentesque facilisis mauris interdum tempus auctor. Sed ac blandit lacus, eget bibendum arcu. Sed eu nulla eu nulla malesuada volutpat. Maecenas placerat suscipit purus eget eleifend. Ut tristique cursus elit non commodo.

                    Vivamus et ipsum tincidunt, volutpat elit ut, tincidunt ligula. Suspendisse lacinia consequat urna, ac egestas sem molestie eu. Duis lorem ante, lacinia vel luctus id, porta sit amet felis. Sed facilisis molestie neque eget congue. Morbi cursus mattis aliquet. Praesent tempor leo neque, ut gravida massa dignissim in. Maecenas placerat enim in quam placerat convallis. Praesent placerat ut tellus vel pulvinar. Quisque a erat tempus purus hendrerit dictum. Maecenas justo enim, vehicula a nisl nec, fermentum ultricies nisi. Vestibulum aliquam hendrerit justo pulvinar consequat. Nullam nibh massa, dapibus a eleifend pharetra, euismod luctus turpis. Fusce egestas, nulla rhoncus vestibulum facilisis, dui mi mattis erat, quis lacinia velit orci vitae nulla. Nullam mattis magna enim, ac aliquet sapien tempor et. Maecenas sed lacus pellentesque, egestas felis in, semper est.

                    Cras et nisi quis purus interdum auctor. Ut scelerisque iaculis mauris vel commodo. Aenean dui metus, rhoncus at ultrices in, auctor at felis. Sed vel elit quis neque hendrerit mollis. Quisque et nunc non tellus vestibulum eleifend non et purus. Curabitur in vulputate nulla. Proin suscipit magna augue, in venenatis libero iaculis ut. Aliquam erat volutpat.

                    Morbi enim leo, maximus sit amet felis in, rutrum sodales arcu. Suspendisse potenti. Cras at faucibus sapien. In suscipit a libero ullamcorper tincidunt. Phasellus eget elit felis. Etiam commodo orci eget nibh convallis facilisis. Quisque et odio eu magna auctor mollis ac ornare ligula. Interdum et malesuada fames ac ante ipsum primis in faucibus. Praesent ut feugiat elit, quis elementum libero. Donec maximus molestie turpis. Donec rutrum hendrerit vehicula. Vivamus laoreet nisi in ipsum laoreet feugiat. Quisque quis fermentum magna. Duis feugiat bibendum nisl, sed interdum nunc imperdiet ornare. Nunc at accumsan sapien.
                </p>
            </div>
        <script src="./js/navbar.js"></script>
    </body>
</html>

<?php
    }
    else
    {
        header("location: ./../login/login.html");
    }
?>