<html>
<body align="center">
<?php
$album= $_POST['album'];
$cancion= $_POST['cancion'];

// Datos de Coneccion
$servername = "sql200.epizy.com";
$username = "epiz_24772960";
$password = "mPZ2HwzXoh85Wmm";
$dbname = "epiz_24772960_Proyecto";

// Crea Coneccion
$link = new mysqli($servername, $username, $password, $dbname);

if($album == 0)
{
	$sql = "SELECT * FROM Artista WHERE Album='$album'
			IN (SELECT Album FROM Album WHERE Canciones='$cancion')";
}

else if($cancion == 0)
{
	$sql = "SELECT * FROM Artista WHERE Album='$album'";
}

else
{
	$sql = "SELECT * FROM Artista WHERE Album='$album'";
}

if($result = mysqli_query($link, $sql))
{
    if(mysqli_num_rows($result) > 0)
	{
        echo "<table>";
            echo "<tr>";
                echo "<th>Artista</th>";
                echo "<th>Album</th>";
            echo "</tr>";
        while($row = mysqli_fetch_array($result))
		{
            echo "<tr>";
                echo "<td>" . $row['Artista'] . "</td>";
                echo "<td>" . $row['Album'] . "</td>";
            echo "</tr>";
        }
        echo "</table>";
        // Free result set
        mysqli_free_result($result);
    }
	else
	{
        echo "No Hay Registros ";
    }
}
else
{
    echo "ERROR" . mysqli_error($link);
}
 
// Close connection
mysqli_close($link);
?>
	<form action="index.html" method="get">
    <input type="submit" value="regresar">
	</form>
</p>
</body>
</html>