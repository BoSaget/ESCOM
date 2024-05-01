<?
$musico= $_POST['nom_mus'];
$apellido = $_POST['ap_mus'];
$apodo = $_POST ['apodo_musico'];
$instrumento = $_POST ['ins'];

// Datos de Coneccion
$servername = "localhost";
$username = "intrang4_soloav";
$password = "SA2012pc_WEB";
$dbname = "intrang4_mcfly";

// Crea Coneccion
$connexion = new mysqli($servername, $username, $password, $dbname);

$PASS=$connexion->query("SELECT Nombre FROM Instrumento WHERE Nombre = '$instrumento'");
if($r= mysqli_fetch_array ($PASS))
{
	$con=$r['Nombre'];
}
if($con != $instrumento)
{
	if ($connexion->connect_error)
	{
		die("Connection failed: " . $connexion->connect_error);
	}

	if (!($stmt = $connexion->prepare("INSERT INTO Instrumento (Nombre) VALUES(?)")))
	{
		echo "Prepare failed\n";
	}

	if (!$stmt->bind_param("s", $instrumento))
	{
		echo "Binding parameters failed: (" . $stmt->errno . ") " . $stmt->error;
	}

	if (!$stmt->execute())
	{
		echo "Execute failed: (" . $stmt->errno . ") " . $stmt->error;
	}
}

$PASS=$connexion->query("SELECT id FROM Instrumento WHERE Nombre = '$instrumento'");
if($r= mysqli_fetch_array ($PASS))
{
	$con=$r['id'];
}

if ($connexion->connect_error)
{
	die("Connection failed: " . $connexion->connect_error);
}

if (!($stmt = $connexion->prepare("INSERT INTO Musico (Nombre, Apellido, Apodo, cod_ins) VALUES(?, ?, ?, ?)")))
{
	echo "Prepare failed\n";
}

if (!$stmt->bind_param("ssss", $musico, $apellido, $apodo, $con))
{
	echo "Binding parameters failed: (" . $stmt->errno . ") " . $stmt->error;
}

if (!$stmt->execute())
{
	echo "Execute failed: (" . $stmt->errno . ") " . $stmt->error;
}
	
	echo "<script>document.location.href='Admin.html';</script>";

?>