<html>
  <meta http-equiv="Content-type" content="text/html; charset=utf-8" />
  <head>
    <title>My homepage</title>
  </head>
  <body>
    <?php
    echo "Now this is an example of an associative array (aka dictionary):<br/>";
    $arr['alfa']=4;
    $arr['beta']=5;
    echo $arr['alfa'] . " + " . $arr['beta'] . " = " . ($arr['alfa'] + $arr['beta']) . "<br/>";

    echo "Creating it with a constructor now:<br/>";
    $arr = Array("color1" => "blue", "color2" => "red");
    echo $arr["color1"] . " and " . $arr["color2"] . "<br/>";

    echo "Here is a for loop:<br/>";
    for ($i = 0; $i <= 10; ++$i) {
      echo "$i ";
    }
    echo "<br/>";
    for ($i = 0; $i <= 10; ++$i) {
      echo $i . " ";
    }
    echo "<br/>";

    if (1 == 2 )
      echo "1 == 2<br/>";
    else
      echo "falso<br/>";

    if (1 != 2 )
      echo "1 != 2<br/>";
    else
      echo "falso<br/>";
    $i = 0 ;
    while ($i < 5) {
      echo "$i ";
      $i++;
    }
    echo "<br/>";
    switch($i) {
      case 1:
      echo "i é 1<br/>";
      break;
      case 5:
      echo "i é 5<br/>";
      break;
      default:
      echo "i não é nada";
    }
    function dummy() {
      echo "flooooooooood<br/>";
    }
    dummy();
    function somamaisum($a, $b) {
      return $a + $b + 1;
    }
    $a=10;
    echo "Resultado é " . somamaisum($a, 5) . "<br/>";
    ?>
  </body>
</html>
