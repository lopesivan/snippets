<html>
  <head>
    <title>My homepage</title>
  </head>
  <body>
    <?php
    echo "Test get alpha parameter: alpha = ".$_GET['alpha']."<br/>";
    if($_GET['submitbutt']) {
      echo "username: " . $_GET['username'] . "<br />";
      echo "password: " . $_GET['password'] . "<br />";
    }
    else {
    ?>
      <form action="form_get.php" method="GET">
        Username <input type="text" name="username"><br />
        Password <input type="password" name="password"><br />
        <input type="submit" name="submitbutt" value="Login!"><br />
      </form>
      <?php
      }
      ?>
  </body>
</html>
