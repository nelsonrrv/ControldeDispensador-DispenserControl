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

$id_enf = $_POST['id_enf'];


//to prevent from mysqli injection  
$id_enf = stripcslashes($id_enf);  
$id_enf = mysqli_real_escape_string($conn, $id_enf);  

$sql = "select * from enfermeras where id_enf = '$id_enf'";  
$result = mysqli_query($conn, $sql);  
$row = mysqli_fetch_array($result, MYSQLI_ASSOC);  
$count = mysqli_num_rows($result);  
  
if($count == 1){  
    echo "Id Valido";  
}  
else{  
    echo "Id Invalido";  
}     

?>