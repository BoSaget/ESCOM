<?php
    session_start();
    if(isset($_SESSION["correo"]) && isset($_SESSION["user"])){

        $correo= $_SESSION["correo"];
        $user = $_SESSION["user"];
        $rango = $_SESSION["rango"];


        $conexion = mysqli_connect("localhost","root","","cafeteria");
        mysqli_query($conexion, "SET character_set_results = 'utf8', character_set_client = 'utf8', character_set_connection = 'utf8', character_set_database = 'utf8', character_set_server = 'utf8'");

        $sqlInfo = "SELECT * FROM `usuarios` WHERE `correo`= '$correo'";
        $resInfo = mysqli_query($conexion,$sqlInfo);

        $info = mysqli_fetch_row($resInfo);
?>

<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link href="./../output.css" rel="stylesheet">
        <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/sweetalert2@11/dist/sweetalert2.min.css">
        <script src="https://cdn.tailwindcss.com"></script>
        <script src="https://kit.fontawesome.com/8a3c5cedf1.js" crossorigin="anonymous"></script>

        <title>Tienda en Linea</title>
    </head>

    <?php 
        if($rango == "0")
        {
            $fondo = "gray";
        }

        else
        {
            $fondo = "amber";
        }
    ?>

    <body class="bg-slate-600">
    <nav class="bg-<?php echo"$fondo" ?>-800">
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
                                <a href="./index.php" class="bg-<?php echo"$fondo" ?>-900 text-white rounded-md px-3 py-2 text-sm font-medium" aria-current="page">Inicio</a>
                                <a href="./menu.php" class="text-gray-300 hover:bg-gray-700 hover:text-white rounded-md px-3 py-2 text-sm font-medium">Menú</a>
                                <a href="./nosotros.php" class="text-gray-300 hover:bg-gray-700 hover:text-white rounded-md px-3 py-2 text-sm font-medium">Nosotros</a>
                                <a href="./faq.php" class="text-gray-300 hover:bg-gray-700 hover:text-white rounded-md px-3 py-2 text-sm font-medium">FAQ</a>
                            </div>
                        </div>
                        <d class="absolute inset-y-0 right-0 flex items-center pr-2 sm:static sm:inset-auto sm:ml-6 sm:pr-0">
                        <button id="user-menu-button" class="relative rounded-full bg-<?php echo"$fondo" ?>-800 p-1 text-gray-400 hover:text-white focus:outline-none focus:ring-2 focus:ring-white focus:ring-offset-2 focus:ring-offset-gray-800">
                            <span class="absolute -inset-1.5"></span>
                            <span class="sr-only">View notifications</span>
                            <svg class="h-6 w-6" fill="none" viewBox="0 0 24 24" stroke-width="1.5" stroke="currentColor" aria-hidden="true">
                                <path stroke-linecap="round" stroke-linejoin="round" d="M14.857 17.082a23.848 23.848 0 005.454-1.31A8.967 8.967 0 0118 9.75v-.7V9A6 6 0 006 9v.75a8.967 8.967 0 01-2.312 6.022c1.733.64 3.56 1.085 5.455 1.31m5.714 0a24.255 24.255 0 01-5.714 0m5.714 0a3 3 0 11-5.714 0" />
                            </svg>
                        </button>
          
                        <!-- Profile dropdown -->
                        <div class="relative ml-3">
                            <!--
                            Dropdown menu, show/hide based on menu state.
                                
                            Entering: "transition ease-out duration-100"
                            From: "transform opacity-0 scale-95"
                            To: "transform opacity-100 scale-100"
                            Leaving: "transition ease-in duration-75"
                            From: "transform opacity-100 scale-100"
                            To: "transform opacity-0 scale-95"
                            -->
                            <div id="user-menu" class="absolute right-0 z-10 mt-2 w-48 origin-top-right rounded-md bg-white py-1 shadow-lg ring-1 ring-black ring-opacity-5 focus:outline-none hidden" role="menu" aria-orientation="vertical" aria-labelledby="user-menu-button" tabindex="-1">
                                <!-- Active: "bg-gray-100", Not Active: "" -->
                                <a href="./perfil.php" class="block px-4 py-2 text-sm text-gray-700" role="menuitem" tabindex="-1" id="user-menu-item-1">Perfil</a>
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
                    <a href="./index.php" class="bg-<?php echo"$fondo" ?>-900 text-white block rounded-md px-3 py-2 text-base font-medium" aria-current="page">Inicio</a>
                    <a href="./menu.php" class="text-gray-300 hover:bg-gray-700 hover:text-white block rounded-md px-3 py-2 text-base font-medium">Menu</a>
                    <a href="./nosotros.php" class="text-gray-300 hover:bg-gray-700 hover:text-white block rounded-md px-3 py-2 text-base font-medium">Nosotros</a>
                    <a href="./faq.php" class="text-gray-300 hover:bg-gray-700 hover:text-white block rounded-md px-3 py-2 text-base font-medium">FAQ</a>
                    <a href="./logout.php" class="bg-red-700 text-white block rounded-md px-3 py-2 text-base font-medium">Logout</a>
                </div>
            </div>
        </nav>

        <div class="container my-5 mx-auto lg:mx-10 flex-auto text-center ">
            <h1 class="text-3xl font-bold underline">
                    Bienvenido 
                    <?php 
                    if($user != NULL)
                    {
                        echo "$user";
                    }

                    else
                    {
                        echo "$correo";
                    }
                    ?>
                </h1>

            <h1 class="text-3xl font-bold underline">
                Menú
            </h1>

            <?php
                              
                $sql = "SELECT * FROM  menu WHERE tipo !='Prueba' ORDER BY tipo";
                $resultadoMenu = mysqli_query($conexion,$sql);
            ?>

            <div class="overflow-x-auto lg:px-50">
                <table class="border-separate border-spacing-2 border border-slate-800 leading-relaxed text-justify min-w-full">
                    <thead>
                        <tr>
                            <th class="border border-slate-900">Platillo</th>
                            <th class="border border-slate-900">Tipo</th>
                            <th class="border border-slate-900">Ingredientes</th>
                            <th class="border border-slate-900">Notas</th>
                            <th class="border border-slate-900">Precio</th>
                            <th class="border border-slate-900">-</th>
                        </tr>
                    </thead>
                    <tbody>
                        

                        <?php
                        // Recorre todos los resultados
                        while ($datosMenu = mysqli_fetch_array($resultadoMenu)) {
                        ?>
                            <tr>
                                <td class="border border-slate-700"><?php echo $datosMenu["item"]; ?></td>
                                <td class="border border-slate-700"><?php echo $datosMenu["tipo"]; ?></td>
                                <td class="border border-slate-700"><?php echo $datosMenu["ingredientes"]; ?></td>
                                <td class="border border-slate-700"><?php echo $datosMenu["notas"]; ?></td>
                                <td class="border border-slate-700">$ 
                                    <?php if($rango == "1")
                                    {
                                        $precio =  ($datosMenu["precio"]-($datosMenu["precio"]*.20));
                                    } 
                                    else
                                    {
                                        $precio = $datosMenu["precio"];
                                    }
                                    echo $precio
                                    ?>MXN
                                </td>
                                <td class="border border-slate-800">
                                    <button class="add-to-cart bg-blue-500 text-white px-4 py-2" 
                                            data-id="<?php echo $datosMenu['id']; ?>" 
                                            data-name="<?php echo $datosMenu['item']; ?>" 
                                            data-price="<?php echo $precio; ?>">
                                            Añadir al carrito
                                    </button>
                                </td>
                            </tr>
                        <?php
                        }
                        ?>
                    </tbody>
                </table>
            </div>

             <!-- Carrito Container -->
            <div class="carrito my-5 p-5 bg-sale-800 rounded-lg shadow-lg">
                <h2 class="text-2xl font-bold mb-4">Carrito de Compras</h2>
                <ul id="carrito-list" class="list-disc pl-5">
                    <!-- Carrito Items -->
                </ul>
                <div class="mt-4">
                    <strong>Total: $<span id="carrito-total">0</span> MXN</strong>                    
                </div>
                <div class="mt-4">
                    <label for="notas-pedido" class="block text-sm font-medium text-slate-950">Notas del Pedido</label>
                    <textarea id="notas-pedido" rows="4" class="mt-1 block w-full rounded-md bg-gray-400 border-gray-300 shadow-sm focus:border-indigo-500 focus:ring-indigo-500 sm:text-sm"></textarea>
                </div>
                <button id="generar-pedido" class="mt-4 bg-emerald-500 text-white px-4 py-2 rounded">Generar Pedido</button>
            </div>

        </div>
        <script src="https://cdn.tailwindcss.com"></script>
        <script src="https://kit.fontawesome.com/8a3c5cedf1.js" crossorigin="anonymous"></script>
        <script src="https://cdn.jsdelivr.net/npm/sweetalert2@11"></script>
        <script src="./js/navbar.js"></script>
        <script src="./js/carrito.js"></script>
    </body>
</html>

<?php
    }
    else
    {
        header("location: ./../login/login.html");
    }
?>