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

$sql = "select * from conexion";  
$result = mysqli_query($conn, $sql);  


if($result){  
   
    while($row=mysqli_fetch_array($result))
     {
        $flag[]=$row;
    }

    print(json_encode($flag));
    
}     

mysqli_close($conn);

?>