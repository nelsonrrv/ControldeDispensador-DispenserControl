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

$mac = $_POST['mac'];
$nom_dis = $_POST['nom_dis'];


$query = " UPDATE nom_dis = '$nom_dis' FROM dispositivos WHERE mac ='$mac' " ;
$resultado = mysqli_query($conn,$query);

if($resultado) {

    echo "Cambio de nombre correcto";

}else{

    echo "Error al cambiar de nombre";

} 

?>