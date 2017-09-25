<?php
session_start();
header("Cache-Control: no-store, no-cache, must-revalidate, max-age=0");
header("Cache-Control: post-check=0, pre-check=0", false);
header("Pragma: no-cache");

if( isset($_GET['task']) ) {
    array_splice($_SESSION['tasks'], $_GET['task'], 1);
}
?>

<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" href="style.css">
    <meta charset="UTF-8">
</head>
<body>
    <h1 class="tk-henriette"><span>--------------&nbsp;&nbsp;</span>scotty buddy<span>&nbsp;--------------</span></h1>
    <aside class="left">
        <img src="img/scottyHappy.gif">
        <section>
            <span>“</span><h1>Good Job! Here's a Meme!</h1><span>”</span>
        </section>
    </aside>
    <section class="right">
        <section>
            <iframe width="560" height="315" src="https://www.youtube.com/embed/mYSb7jVKZwQ" frameborder="0" allowfullscreen></iframe>
        </section>
        <figure>
            <div><div>&nbsp;</div></div>
            <div id="timer"></div>
        </figure>
    </section>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
    <script src="main.js"></script>
</body>
</html>
