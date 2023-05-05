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

$user = $_POST['user'];
$cantidad = $_POST['cant'];
$med = $_POST['med'];
$tanque = $_POST['tanque'];
$horayfecha = $_POST['hora']


$query = " INSERT INTO tareas (cant, med, tanque,hora) values ('$cantidad','$med','$tanque','$horayfecha')" ;
$resultado = mysqli_query($conn,$query);

if($resultado) {

    echo "Tarea creada con exito";

}else{

    echo "Error al creaar tarea";

} 

?>