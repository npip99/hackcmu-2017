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
    <img src="<?=isset($_GET['sad']) ? 'img/scottySad.gif' : 'img/scottyHappy.gif'?>">
    <section>
        <span>“</span><h1>
<?php
if( isset($_GET['sad']) ) {
    echo "I know you're better than that! We should get your work done first!";
} else if( isset($_GET['work']) ) {
    echo "Okay, let's get back to work!";
} else {
    echo "What are your goals for today?";
}
?>
        </h1><span>”</span>
    </section>
    <table>
<?php
for( $i = 0; $i < count($_SESSION['tasks']) / 3; $i++ ) {
?>
        <tr>
            <td><img src="img/check.png" onclick="window.location.href='success.php?task=<?=3*$i?>'"><?=$_SESSION['tasks'][3*$i]?></td>
<?php
    if( !isset($_SESSION['tasks'][3*$i+1]) ) {
?>
            <td><input id="add" onchange="add()"></td>
            <td style="visibility: hidden;"></td>
<?php
    } else if( !isset($_SESSION['tasks'][3*$i+2]) ) {
?>
            <td><img src="img/check.png" onclick="window.location.href='success.php?task=<?=3*$i+1?>'"><?=$_SESSION['tasks'][3*$i + 1]?></td>
            <td><input id="add" onchange="add()"></td>
<?php
    } else {
?>
            <td><img src="img/check.png" onclick="window.location.href='success.php?task=<?=3*$i+1?>'"><?=$_SESSION['tasks'][3*$i + 1]?></td>
            <td><img src="img/check.png" onclick="window.location.href='success.php?task=<?=3*$i+2?>'"><?=$_SESSION['tasks'][3*$i + 2]?></td>
<?php
    }
?>
        </tr>
<?php
}

if( count($_SESSION['tasks']) % 3 == 0 ) {
?>

        <tr>
            <td><input id="add" onchange="add()"></td>
            <td style="visibility: hidden;"></td>
            <td style="visibility: hidden;"></td>
        </tr>
<?php
}
?>
            <!--td><input id="add" onchange="add()"></td-->
    </table>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
    <script src="main.js"></script>
    <script>
        var tasks = <?=count($_SESSION['tasks'])?>;
    </script>
</body>
</html>
