<?
$album = $_POST['album'];
$cancion = $_POST['cancion'];
$letra = $_POST ['letra'];
$lanzamiento = $_POST ['lanz'];

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

if ($connexion->connect_error)
{
	die("Connection failed: " . $connexion->connect_error);
}

if (!($stmt = $connexion->prepare("INSERT INTO Cancion (Titulo, Letra, Lanzamiento, cod_alb) VALUES(?, ?, ?, ?)")))
{
	echo "Prepare failed\n";
}

if (!$stmt->bind_param("ssss", $cancion, $letra, $lanzamiento, $con))
{
	echo "Binding parameters failed: (" . $stmt->errno . ") " . $stmt->error;
}

if (!$stmt->execute())
{
	echo "Execute failed: (" . $stmt->errno . ") " . $stmt->error;
}	
	echo "<script>document.location.href='Admin.html';</script>";

?>