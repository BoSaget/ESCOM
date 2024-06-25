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

        <title>Usuarios</title>
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
                Usuarios 
            </h2>

            <?php
                              
                $sqlUsuarios = "SELECT * FROM  usuarios ORDER BY rango";
                $resultadoUsuarios = mysqli_query($conexion,$sqlUsuarios);
            ?>

            <div class="flex space-x-4 left">
                <a href="./agregarUsuario.php" class="bg-green-700 rounded-md px-3 py-2 text-sm font-medium">Agregar Usuario</a>
            </div>

            <div class="overflow-x-auto lg:px-50">
                <table class="border-separate border-spacing-2 border border-slate-800 leading-relaxed text-justify min-w-full">
                    <thead>
                        <tr>
                            <th class="border border-slate-900">Editar</th>
                            <th class="border border-slate-900">Correo</th>
                            <th class="border border-slate-900">Telefono</th>
                            <th class="border border-slate-900">Nombre</th>
                            <th class="border border-slate-900">Contraseña</th>
                            <th class="border border-slate-900">Rango</th>
                            <th class="border border-slate-900">Eliminar</th>
                        </tr>
                    </thead>
                    <tbody>
                        

                        <?php
                        // Recorre todos los resultados
                        while ($datosUsuarios = mysqli_fetch_array($resultadoUsuarios)) {
                        ?>
                            <tr data-id="<?php echo $datosUsuarios["id"]; ?>">
                                <td class="border border-slate-700">
                                    <button class="bg-blue-500 text-white px-4 py-2" onclick="editRow(this)">Editar</button>
                                    <button class="bg-green-500 text-white px-4 py-2 hidden" onclick="saveRow(this)">Guardar</button>
                                </td>
                                <td class="border border-slate-700" data-column="correo"><?php echo $datosUsuarios["correo"]; ?></td>
                                <td class="border border-slate-700" data-column="telefono"><?php echo $datosUsuarios["telefono"]; ?></td>
                                <td class="border border-slate-700" data-column="nombre"><?php echo $datosUsuarios["nombre"]; ?></td>
                                <td class="border border-slate-700" data-column="pass"><?php echo $datosUsuarios["contraseña"]; ?></td>
                                <td class="border border-slate-700" data-column="rango"><?php echo $datosUsuarios["rango"]; ?></td>
                                <td class="border border-slate-700">
                                    <button class="bg-red-500 text-white px-4 py-2" onclick="deleteRow(this)">Eliminar</button>
                                </td>
                            </tr>
                        <?php
                        }
                        ?>
                    </tbody>
                </table>
            </div>
        <script src="https://cdn.tailwindcss.com"></script>
        <script src="https://kit.fontawesome.com/8a3c5cedf1.js" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/sweetalert2@11"></script>
        <script src="./js/navbar.js"></script>
        <script src="./js/usuarios.js"></script>
    </body>
</html>

<?php
    }
    else
    {
        header("location: ./../login/login.html");
    }
?>