<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>factorial</title>
</head>
<body>
    <?php
        function fact($n)
        {
            $s=1;
            for($i=1;$i<$n+1;$i++)
            {
                $s=$s*$i;
            }
            echo"factorial is: $s";
        }
    fact(5);
    ?>


    
</body>
</html>