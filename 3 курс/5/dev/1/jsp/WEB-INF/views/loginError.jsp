
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=Windows-1251">
    <title>login</title>

</head>
<style>
    .container{
        background-color: rgb(228, 201, 235);
        margin: 150px 600px;
        padding: 70px 50px;
        border-radius: 4px;
    }
    input[type="text"]{
        padding-left: 12px;
        position: relative;
        display: flex;
        flex-direction: row;
        font-size: 14px;
        border-color: rgba(31, 33, 65, 0.25);
        border-radius: 4px;
        border-width: 1px;}
    input[type="password"]{
        padding-left: 12px;
        position: relative;
        display: flex;
        flex-direction: row;
        font-size: 14px;
        border-color: rgba(31, 33, 65, 0.25);
        border-radius: 4px;
        border-width: 1px;}
    input[type="submit"]{color: #ffffff;
        padding-top: 9px;
        padding-bottom: 9px;
        padding-left: 19px;
        padding-right: 19px;
        border-color: #8ba4f9;
        background: linear-gradient(180deg, #bc9cff 0%, #8ba4f9 100%);
        border-radius: 22px;}
</style>
<body>
<div class="container">
    <form action="login" method="post">
        <p>login</p>
        <input name="email" type="text"><br>
        <p>password</p>
        <input name="password" type="password"><br>
        <input type="submit" value="enter"><br>
    </form>
    <h1>User are not founded, try again</h1>
</div>
</body>

</html>
