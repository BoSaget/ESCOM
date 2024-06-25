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

        <title>Agregar Empleado</title>
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
                    <a href="./index.php" class="bg-blue-900 text-white block rounded-md px-3 py-2 text-base font-medium" aria-current="page">Inicio</a>
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

            <h2 class="text-xl font-bold underline">
                Agregar Empleado 
            </h2>

            <!-- Formulario -->
            <div class="lg:grid lg:grid-cols-4 lg:gap-3 mx-2">
                <div class="lg:col-start-2 lg:col-span-2 mx-6">
                    <form id="agregarEmpleado" autocomplete="off">  
                            <div class="rounded-md bg-gray-100 px-3 py-2 text-base text-center md:container md:mx-auto">
                                <div class="text-2xl">Agregar Empleado</div>
                                <div class="grid grid-cols-2 gap-3">
                                    <div class="...">
                                        <div>Rol</div>
                                    </div>
                                    <div class="col-span-2 ...">
                                        <select id="rol" name="rol" class="rounded-md px-3 py-2 shadow-sm focus:outline-none focus:ring-indigo-500 focus:border-indigo-500">
                                            <option value="Cocina">Cocina</option>
                                            <option value="Admin">Admin</option>
                                        </select>
                                    </div>
                                    <div class="... text-center">
                                        <div>Correo</div>
                                    </div>
                                    <div class="col-span-2 ...">
                                        <input type="text" id="correo" name="correo" class="rounded-md px-3 py-2">
                                    </div>
                                    <div class="...">
                                        <div>Nombre</div>
                                    </div>
                                    <div class="col-span-2 ...">
                                        <input type="text" id="nombre" name="nombre" class="rounded-md px-3 py-2">
                                    </div>
                                    <div class="...">
                                        <div>Contraseña</div>
                                    </div>
                                    <div class="col-span-2 ...">
                                        <input type="password" id="pass" name="pass" class="rounded-md px-3 py-2">
                                    </div>
                                    <div class="col-span-2"></div>
                                </div>
                                <div class="grid grid-cols-3 gap-3">
                                    <div class="col-start-2 ...">
                                        <button class="bg-green-700 text-white block rounded-md px-3 py-2 text-base font-medium" id="add-button">Agregar</button>
                                    </div>
                                </div>
                            </div>
                    </form>
                </div>
            </div>
        </div>
        <script src="https://cdn.tailwindcss.com"></script>
        <script src="https://kit.fontawesome.com/8a3c5cedf1.js" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/sweetalert2@11"></script>
        <script src="./js/navbar.js"></script>
        <script src="./js/empleados.js"></script>
        <script src="./js/agregarEmpleado.js"></script>
    </body>
</html>

<?php
    }
    else
    {
        header("location: ./../login/login.html");
    }
?>