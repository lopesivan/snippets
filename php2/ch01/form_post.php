<html>
  <head>
    <title>My homepage</title>
  </head>
  <body>
    <?php
    if($_POST['submitbutt']) {
      echo "username: " . $_POST['username'] . "<br />";
      echo "password: " . $_POST['password'] . "<br />";
    }
    else {
    ?>
      <form action="form_post.php" method="POST">
        Username <input type="text" name="username"><br />
        Password <input type="password" name="password"><br />
        <input type="submit" name="submitbutt" value="Login!"><br />
      </form>
      <?php
      }
      ?>
  </body>
</html>
