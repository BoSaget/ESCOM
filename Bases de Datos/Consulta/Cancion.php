<html style="background-color:#FCDF67">
<body align="center">
<?
$album = $_POST['album'];
$letra = $_POST ['letra'];
$lanzamiento = $_POST ['lanz'];

// Datos de Coneccion
$servername = "localhost";
$username = "intrang4_soloav";
$password = "SA2012pc_WEB";
$dbname = "intrang4_mcfly";

// Crea Coneccion
$connexion = new mysqli($servername, $username, $password, $dbname);

if($album != NULL)
{
	$mus=$connexion->query("SELECT id FROM Album WHERE Titulo = '$album'");
	if($r= mysqli_fetch_array ($mus))
	{
		$id=$r['id'];
	}
	
	$mus=$connexion->query("SELECT * FROM Cancion WHERE cod_alb = '$id'");
	if(mysqli_num_rows($mus) > 0)
	{
        echo "<table>";
            echo "<tr>";
                echo "<th>Nombre</th>";
                echo "<th>Letra</th>";
				echo "<th>Lanzamiento</th>";;
            echo "</tr>";
        while($row = mysqli_fetch_array($mus))
		{
            echo "<tr>";
                echo "<td>" . $row['Titulo'] . "</td>";
                echo "<td>" . $row['Letra'] . "</td>";
                echo "<td>" . $row['Lanzamiento'] . "</td>";
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
}

else
{
	$mus=$connexion->query("SELECT * FROM Cancion WHERE Letra = %'$letra' OR Lanzamiento = '$lanzamiento'");
	
	if(mysqli_num_rows($mus) > 0)
	{
        echo "<table>";
            echo "<tr>";
                echo "<th>Nombre</th>";
                echo "<th>Lanzamiento</th>";
				echo "<th>Letras</th>";;
            echo "</tr>";
        while($row = mysqli_fetch_array($mus))
		{
            echo "<tr>";
                echo "<td>" . $row['Titulo'] . "</td>";
                echo "<td>" . $row['Lanzamiento'] . "</td>";
                echo "<td>" . $row['Letra'] . "</td>";
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
}
 
?>
	<form action="index.html" method="get">
    <input type="submit" value="regresar">
	</form>
</p>
</body>
</html>

