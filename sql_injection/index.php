<?php

    session_start();

    if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
        // Redirect to login page or display access denied message
        header('Location: login.php');
        exit;
    }

    $flag = "FLAG{5Ql_1nj3ct10N_13_c00L}";

?>

<!DOCTYPE html>
<html>
    <head>
        <title>Login Page</title>
        <style>
            * {text-align: center;}
        </style>
    </head>
    <body>
        <h1>Login page</h1>
        <?php
            echo "<h1> Congratulations on violating the Authentication property! </h1>";
            echo "<br>";
            echo "<h2> Reward: " . $flag . "</h2>";
        ?>
    </body>
</html>