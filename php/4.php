<!DOCTYPE html>
<html>
  <head>
  </head>
  <body>
    <button id="button" type="button">Click me!</button>

    <canvas id="myCanvas">canvas>
      <script>
       var canvas=document.getElementById('myCanvas');
       var ctx=canvas.getContext('2d');
       ctx.fillStyle='#FF0000';
       ctx.fillRect(0,0,80,100);
      </script>
    </canvas>
    <p style="text-align:center;">center</p>
    <center>center -- this tag is deprecated, use CSS instead</center>
  </body>
</html>
