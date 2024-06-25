<?php
    session_start();
    $tmp = $_GET["nombreSesion"];
    unset($_SESSION[$tmp]);
    header("location: ./..//index/index.html");
?>