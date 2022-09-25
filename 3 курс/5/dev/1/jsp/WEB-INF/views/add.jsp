<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<style>
    .container{
        display:flex;
        justify-content:space-between;
    }
    body{
        margin: 40px;
        display:flex;
        justify-content: center;
    }
    input[name="name"]{
        margin-top:50px;
    }
    input[name="enter"]{
        margin: 50px 10px;
    }
</style>

<body>
<div class="container">
    <form action="enter" method="post" >
        Name:<input name="name" type="text">
        Patronymic:<input name="patronymic" type="text">
        Surname:<input name="surname" type="text">
        <input type="submit" value="enter">
    </form>
</div>
</body>
</html>