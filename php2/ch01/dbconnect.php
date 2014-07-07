<?php
$connection = mysqli_connect('localhost','root','yourpasswordhere','productsdb');
$query = "SELECT * FROM products;";
$result = mysqli_query($connection, $query);
while($row = mysqli_fetch_array($result)) {
  echo $row['id']." ".$row['product'];
  echo "<br/>";
}
mysqli_close($connection);
?>
