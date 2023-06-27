<?php

    // db_credentials
    // in order to connect to a dockerized database you need to be on the same network
    // and you need to have the IP address of the docker container

    // Since the db container address changes at every launch, use the network feature
    // to find the container's IP by the name, must have some sort of DNS

    // start the session
    session_start();

    $_SESSION['loggedin'] = false;

?>

<!DOCTYPE html>
<html>
<head>
    <title>Login Page</title>
    <style>
        * {text-align:  center;}
    </style>
</head>
<body>
    <h1>Banca Stella</h1>
    <br>
    <br>
    <h2>Login Page</h2>
    <?php if (isset($error)) { ?>
        <p><?php echo $error; ?></p>
    <?php } ?>
    <form method="POST" action="./verify.php">
        <label>Username:</label>
        <input type="text" name="username" required><br><br>
        
        <label>Password:</label>
        <input type="password" name="password" required><br><br>
        
        <input type="submit" value="Login">
    </form>
</body>
</html>