<?php
$num=($_POST['number']);        
 $a=0;
 $b=1;
 echo"$a<br>";
 for($i=2;$i<$num;$i++)
 {
    $c=$a+$b;
    echo"$c"."<br>";
    $a=$b;
    $b=$c;
 }

?>