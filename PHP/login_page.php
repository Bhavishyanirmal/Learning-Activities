<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>login_page</title>
</head>
<body>
    <?php
        $name=($_POST['username']);
        $password=($_POST['password']);

        if ($name=="abc" && $password=="123")
        {
            echo"login sucsessfully";
        }
        else
        {
            echo"incurrent usarname and password";
        }
        
    ?>

    
</body>
</html>