<?php
$servername = "localhost";
$dbname = "nome_base_de_dados";
$username = "root";
$password = "senha";
$mysqli = new mysqli($servername, $username, $password, $dbname);
if ($mysqli->connect_error)
{
die("[ERROR] Connection Failed: " . $mysqli->connect_error);
}
?>