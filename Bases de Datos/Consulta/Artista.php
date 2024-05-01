<html style="background-color:#FCDF67">
<body align="center">
<?
$album = $_POST['album'];

// Datos de Coneccion
$servername = "localhost";
$username = "intrang4_soloav";
$password = "SA2012pc_WEB";
$dbname = "intrang4_mcfly";


// Crea Coneccion
$connexion = new mysqli($servername, $username, $password, $dbname);

$mus=$connexion->query("SELECT id FROM Album WHERE Titulo = '$album'");

if($r= mysqli_fetch_array ($mus))
{
	$con=$r['id'];
}

$mus=$connexion->query("SELECT * FROM Artista WHERE cod_alb = '$con'");
	if(mysqli_num_rows($mus) > 0)
	{
        echo "<table>";
            echo "<tr>";
                echo "<th>Nombre</th>";
                echo "<th>Premios</th>";
				echo "<th></th>";;
            echo "</tr>";
        while($row = mysqli_fetch_array($mus))
		{
            echo "<tr>";
                echo "<td>" . $row['Nombre'] . "</td>";
                echo "<td>" . $row['Premios'] . "</td>";
            echo "</tr>";
        }
        echo "</table>";
        // Free result set
        mysqli_free_result($mus);
    }
	else
	{
        echo "No Hay Registros ";
    }




?>
	<form action="index.html" method="get">
    <input type="submit" value="regresar">
	</form>
</p>
</body>
</html>