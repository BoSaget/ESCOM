<?
$id= $_POST['user'];
$pass = $_POST['pass'];

// Datos de Coneccion
$servername = "localhost";
$username = "intrang4_soloav";
$password = "SA2012pc_WEB";
$dbname = "intrang4_mcfly";

// Crea Coneccion
$connexion = new mysqli($servername, $username, $password, $dbname);

//Obtencion
$PASS=$connexion->query("SELECT Pass FROM Usuarios WHERE User = '$id'");
if($r= mysqli_fetch_array ($PASS))
{
	$con=$r['Pass'];
}

if($con == $pass)
{
	echo "<script>document.location.href='Insertar/Admin.html';</script>";
}

else
{
	echo "<script>document.location.href='Login.html';</script>";
}
?>