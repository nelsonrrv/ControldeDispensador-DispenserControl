<?php

$servername = "localhost";
$username = "mayoaxpj_nelsonrrv94";
$password = "Nel.,ro038*";
$db = "mayoaxpj_dispensador";

// Create connection
$conn = mysqli_connect($servername, $username, $password, $db);

// Check connection
if (!$conn) {
   die("Connection failed: " . mysqli_connect_error());
} 

$username = $_POST['user'];
$mac = $_POST['mac'];


$query = " INSERT INTO conexion (user, mac) values ('$user','$mac')" ;
$resultado = mysqli_query($conexion,$query);

if($resultado) {

    echo "Registro correcto";

}else{

    echo "Error en registro";

} 

?>

