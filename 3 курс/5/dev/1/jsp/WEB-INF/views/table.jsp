<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
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
    input[name="add"]{
        margin-top:50px;
    }
    input[name="delete"]{
        margin: 50px 10px;
    }
</style>

<body>
<div table>


       <table border='1'>
        <tr>
        <td>id</td>
        <td>name</td>
            <td>surname</td>
            <td>patronymic</td>
        </tr>
           <c:forEach var="people" items="${peoples}">
           <tr><td>${people.id}</td>
               <td>${people.name}</td>
               <td>${people.surname}</td>
               <td>${people.patronymic}</td>
               </c:forEach>
       </table>
</div>
<div class="container">

    <form method="get" action="add">
        <input type="submit" value="Add" name="add"></td>
    </form>
    <form method="post" action="delete">
        <input type="submit" value="Delete" name="delete"></td>
        <p>Line number for delete</p>
        <input type="text" name="id"  ></td>
    </form>

</div>
</body>
</html>