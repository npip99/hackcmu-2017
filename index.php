<?php
session_start();
header("Cache-Control: no-store, no-cache, must-revalidate, max-age=0");
header("Cache-Control: post-check=0, pre-check=0", false);
header("Pragma: no-cache");
?>

<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" href="style.css">
    <meta charset="UTF-8">
</head>
<body>
    <h1 class="tk-henriette"><span>--------------&nbsp;&nbsp;</span>scotty buddy<span>&nbsp;--------------</span></h1>
    <img src="img/scottyHappy.gif">
    <section>
        <span>“</span><h1>Hello! I'm Scotty, and I'm here to keep you company with encouragement and good memes!</h1><span>”</span>
    </section>
    <section>
        <div><button onclick="window.location.href='todo.php'">Let's Start Working!</button></div>
    </section>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
</body>
</html>
