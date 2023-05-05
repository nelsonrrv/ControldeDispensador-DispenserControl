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

$task = $_POST['task'];

$query = " DELETE FROM tareas WHERE task ='$task' " ;
$resultado = mysqli_query($conn,$query);

if($resultado) {

    echo "Se borro tarea con exito";

}else{

    echo "Error al borrar tarea";

} 

?>
