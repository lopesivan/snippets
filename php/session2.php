<?php
session_start();
echo "Session variable value of foo is ".$_SESSION['foo']."<br/>";
if (isset( $_SESSION['counter'] ))
  $_SESSION['counter']++;
else
  $_SESSION['counter'] = 1;
echo "This is a simple counter: ".$_SESSION['counter']."<br/>";
?>
