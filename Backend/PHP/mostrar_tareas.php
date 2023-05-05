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

$sql = "select * from tareas";  
$result = mysqli_query($conn, $sql);  
$flag= array();

if($result){  
   
    while($row=mysqli_fetch_array($result))
     {
         $index['task']=$row['task'];
         $index['id']=$row['id'];
         $index['med']=$row['med'];
         $index['cant']=$row['cant'];
         $index['hora']=$row['hora'];
         $index['tanque']=$row['tanque'];

        array_push($flag,$index);
    }

    print(json_encode($flag));
    
}     

mysqli_close($conn);

?>