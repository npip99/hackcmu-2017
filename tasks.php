<?php
session_start();
header("Cache-Control: no-store, no-cache, must-revalidate, max-age=0");
header("Cache-Control: post-check=0, pre-check=0", false);
header("Pragma: no-cache");

if( $_POST['action'] == 'PUT' ) {
    $_SESSION['tasks'][] = $_POST['task'];
}

?>