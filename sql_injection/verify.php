<?php session_start() ?>
<!DOCTYPE html>
<html>
    <head>
        <title>Credentials Verification</title>
        <style>
            * {text-align: center;}
        </style>
    </head>
    <body>
<?php

    require_once('db_connect.php');

    $conn = new mysqli($servername, $username, $password, $database);
 
    $sql = "select * from Users where username = '" . $_POST['username'] . "' and password = '" . $_POST['password'] . "'";
    $result = $conn->query($sql);

    if($result->num_rows > 0) {

        $_SESSION['loggedin'] = true;
        echo "<h1 style=\"text-align: center; color: green;\"> Login Succesful </h1>";
        $conn->close();
        echo "<br>";
        echo "<form action=\"./index.php\" method=\"GET\"> <input type=\"submit\" name=\"Go to website\" value=\"Go to website\"></form>";
    } else {
        $conn->close();
        echo "<h1 style=\"text-align: center; color: red;\"> Login Failed </h1>";
        echo "<br>";
        echo "<form action=\"./login.php\" method=\"GET\"> <input type=\"submit\" name=\"retry\" value=\"Retry\"></form>";
    }

?> 
    </body>
</html>