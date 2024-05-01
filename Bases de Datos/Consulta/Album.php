<html style="background-color:#FCDF67">
<body align="center">
<?
$songs = $_POST['songs'];
$genero = $_POST ['genero'];
$lanzamiento = $_POST ['lanz'];
$disquera = $_POST ['disquera'];
$artista = $_POST ['artista'];

// Datos de Coneccion
$servername = "localhost";
$username = "intrang4_soloav";
$password = "SA2012pc_WEB";
$dbname = "intrang4_mcfly";


// Crea Coneccion
$connexion = new mysqli($servername, $username, $password, $dbname);

$mus=$connexion->query("SELECT id FROM Musico WHERE Nombre = '$musico'");
if($r= mysqli_fetch_array ($mus))
{
	$con=$r['id'];
}


?>
	<form action="index.html" method="get">
    <input type="submit" value="regresar">
	</form>
</p>
</body>
</html>