<?php
    session_start();
    if(isset($_SESSION["correo"]) && isset($_SESSION["user"])){
        
        $rol = $_SESSION["rol"];
        $correo = $_SESSION["correo"];
        $user = $_SESSION["user"];


        $conexion = mysqli_connect("localhost","root","","cafeteria");
        mysqli_query($conexion, "SET character_set_results = 'utf8', character_set_client = 'utf8', character_set_connection = 'utf8', character_set_database = 'utf8', character_set_server = 'utf8'");

        $sqlInfo = "SELECT * FROM `empleados` WHERE `correo`= '$correo' AND `nombre` = '$user'";
        // Consulta para obtener todos los pedidos de todos los clientes
        $sqlPedidos = "SELECT p.id AS pedido_id, p.fecha, p.notas, u.user, 
        GROUP_CONCAT(CONCAT(m.item, ' x', dp.cantidad) SEPARATOR '<br>') AS detalles
        FROM pedidos p
        INNER JOIN usuarios u ON p.user_id = u.id
        INNER JOIN detalles_pedido dp ON p.id = dp.pedido_id
        INNER JOIN menu m ON dp.item_id = m.id
        GROUP BY p.id
        ORDER BY p.fecha DESC";

        $resultadoPedidos = mysqli_query($conexion, $sqlPedidos);
    
?>

<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link href="./../output.css" rel="stylesheet">
        <script src="https://cdn.tailwindcss.com"></script>
        <script src="https://kit.fontawesome.com/8a3c5cedf1.js" crossorigin="anonymous"></script>

        <title>Cocina</title>
    </head>

    <body class="bg-slate-600">
        <nav class="bg-fuchsia-800">
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
                    <a href="./logout.php" class="bg-red-700 text-white block rounded-md px-3 py-2 text-base font-medium">Logout</a>
                </div>
            </div>
        </nav>

        <div class="container my-5 mx-auto lg:mx-10 flex-auto text-center ">
            <h1 class="text-3xl font-bold underline">
                Bienvenido <?php echo "$user"; ?>
            </h1>

            <div class="container mx-auto p-4">
                <h1 class="text-3xl font-bold text-center mb-8">Todos los Pedidos</h1>
                <div class="overflow-x-auto">
                    <table class="min-w-full bg-white border-gray-200 shadow-sm rounded-lg overflow-hidden">
                        <thead class="bg-gray-200">
                            <tr>
                                <th class="border border-slate-900">Pedido #</th>
                                <th class="border border-slate-900">Fecha</th>
                                <th class="border border-slate-900">Cliente</th>
                                <th class="border border-slate-900">Detalles</th>
                                <th class="border border-slate-900">Notas</th>
                            </tr>
                        </thead>
                        <tbody>
                            <?php while ($pedido = mysqli_fetch_assoc($resultadoPedidos)) { ?>
                                <tr>
                                    <td class="border border-slate-700"><?php echo $pedido['pedido_id']; ?></td>
                                    <td class="border border-slate-700"><?php echo $pedido['fecha']; ?></td>
                                    <td class="border border-slate-700"><?php echo $pedido['user']; ?></td>
                                    <td class="border border-slate-700"><?php echo $pedido['detalles']; ?></td>
                                    <td class="border border-slate-700"><?php echo nl2br($pedido['notas']); ?></td>
                                </tr>
                            <?php } ?>
                        </tbody>
                    </table>
                </div>
            </div>

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