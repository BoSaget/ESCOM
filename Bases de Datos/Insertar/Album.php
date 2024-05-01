<?
$musico= $_POST['nom_mus'];
$album = $_POST['titulo'];
$songs = $_POST['songs'];
$genero = $_POST ['genero'];
$lanzamiento = $_POST ['lanz'];
$disquera = $_POST ['disquera'];
$artista = $_POST ['artista'];
$premios = $_POST ['premios'];

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

if ($connexion->connect_error)
{
	die("Connection failed: " . $connexion->connect_error);
}

if (!($stmt = $connexion->prepare("INSERT INTO Album (Titulo, Lanzamiento, Canciones, cod_mus) VALUES(?, ?, ?, ?)")))
{
	echo "Prepare failed\n";
}

if (!$stmt->bind_param("ssss", $album, $lanzamiento, $songs, $con))
{
	echo "Binding parameters failed: (" . $stmt->errno . ") " . $stmt->error;
}

if (!$stmt->execute())
{
	echo "Execute failed: (" . $stmt->errno . ") " . $stmt->error;
}


$mus=$connexion->query("SELECT id FROM Album WHERE Titulo = '$album'");
if($r= mysqli_fetch_array ($mus))
{
	$con=$r['id'];
}

if ($connexion->connect_error)
{
	die("Connection failed: " . $connexion->connect_error);
}

if (!($stmt = $connexion->prepare("INSERT INTO Genero (Nombre, cod_alb) VALUES(?, ?)")))
{
	echo "Prepare failed\n";
}

if (!$stmt->bind_param("ss", $genero, $con))
{
	echo "Binding parameters failed: (" . $stmt->errno . ") " . $stmt->error;
}

if (!$stmt->execute())
{
	echo "Execute failed: (" . $stmt->errno . ") " . $stmt->error;
}

//
if ($connexion->connect_error)
{
	die("Connection failed: " . $connexion->connect_error);
}

if (!($stmt = $connexion->prepare("INSERT INTO Disquera (Nombre, cod_alb) VALUES(?, ?)")))
{
	echo "Prepare failed\n";
}

if (!$stmt->bind_param("ss", $disquera, $con))
{
	echo "Binding parameters failed: (" . $stmt->errno . ") " . $stmt->error;
}

if (!$stmt->execute())
{
	echo "Execute failed: (" . $stmt->errno . ") " . $stmt->error;
}
	
//
if ($connexion->connect_error)
{
	die("Connection failed: " . $connexion->connect_error);
}

if (!($stmt = $connexion->prepare("INSERT INTO Artista (Nombre, Premios, cod_alb) VALUES(?, ?, ?)")))
{
	echo "Prepare failed\n";
}

if (!$stmt->bind_param("sss", $artista, $premios, $con))
{
	echo "Binding parameters failed: (" . $stmt->errno . ") " . $stmt->error;
}

if (!$stmt->execute())
{
	echo "Execute failed: (" . $stmt->errno . ") " . $stmt->error;
}	
	
	echo "<script>document.location.href='Admin.html';</script>";

?>