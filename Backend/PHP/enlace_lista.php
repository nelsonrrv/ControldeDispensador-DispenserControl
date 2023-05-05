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
$nom_dis = $_POST['nom_dis'];

$sql = "select * from conexion where user = '$username'";  
$result = mysqli_query($conn, $sql);  
$flag= array();

if($result){  
   
    while($row=mysqli_fetch_array($result))
     {
        $binder = $row['mac'];
        $sql_2 = "select * from dispositivos where mac = '$binder'";  
        $result_2 = mysqli_query($conn, $sql_2);  

        while($row_2=mysqli_fetch_array($result_2))
     {
         $index['mac']=$row_2['mac'];
         $index['nom_dis']=$row_2['nom_dis'];

        array_push($flag,$index);
     }

    }

    print(json_encode($flag));
    
}     

mysqli_close($conn);

?>