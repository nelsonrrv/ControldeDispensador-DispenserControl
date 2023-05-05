<?php

include("conexion.php");

$user = $_POST['user'];
$password = $_POST['pass'];
$nombre = $_POST['name'];
$al = $_POST['al'];

$query = " INSERT INTO usuarios (user, pass, name, al) values ('$user','$password','$nombre','$al')" ;
$resultado = mysqli_query($conexion,$query);

if($resultado) {

    echo "Registro correcto";

}else{

    echo "Error en registro";

} 

?>