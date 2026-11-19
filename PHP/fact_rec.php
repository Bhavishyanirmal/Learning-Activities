<?php
function Xfact($n)
{
    if ($n==0 || $n==1 )
    {
        return $n;
    }
    else
    {
        $c=$n*(Xfact($n-1));
        return $c;
    }
}
$val=Xfact(5);
echo $val;
?>