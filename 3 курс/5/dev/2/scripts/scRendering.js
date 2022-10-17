function tablePage(response) {
    document.body.removeChild(document.body.firstChild);

    document.body.innerHTML = `<style>  .container{
                      background-color: rgb(228, 201, 235);
                      margin: 150px 600px;
                      
                      padding: 70px 50px;
                      padding-right: 8px;
                      border-radius: 4px;
                      display:flex;
                      justify-content:space-between;
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
                      input[type="text"]:focus {
                          color: rgba(31, 33, 65, 0.75);
                          outline: 1px rgba(31, 33, 65, 0.5);
                          border-width: 1px;
                          border-color: rgba(31, 33, 65, 0.5);
                        }
                  input[type="button"]{color: #ffffff;
                      padding-top: 9px;
                      padding-bottom: 9px;
                      padding-left: 19px;
                      padding-right: 19px;
                      border: none;
                      background: linear-gradient(180deg, #bc9cff 0%, #8ba4f9 100%);
                      border-radius: 22px;
                  }
              
                  p{
                      color: #5e2eaa;
                  }
                  body{
                      margin: 40px;
                      display:flex;
                      justify-content: center;
                  }
                  #add{
                      margin-top:10px;
                      margin-left: 30px;
                  }
                  #delete{
                      margin: 50px 20px;
                  }
                  
                  
                   th{
                      color: #5e2eaa;
                       background-color: #8ba4f9;
                       border-radius: 4px;
                   }
                   td{
                      color: #5e2eaa;
                       background-color: #bc9cff;
                       border-radius: 4px;
                   }
                   form[name='del']{
                       display: flex;
                       justify-content: space-between;
                       position: relative;
                     top: 50px;
                      right: 60px;
                  
                   }
                  
                  
                  </style>
              <div class="container">
                  <table>
                      <tr>
                      <th>id</th>
                      <th>name</th>
                          <th>surname</th>
                          <th>patronymic</th>
                      </tr>
                     </table>
                     <iframe name="myIFR" style="display: none"></iframe>
                  <form method="post" target="myIFR">
                      <input type="button" value="add" id="add" onclick="add(); return false"></td>
                  </form>
                  <form method="post"  name="del" target="myIFR">
                      <div class="del">
                          <p>enter id for delete</p>
                          <input type="text" name="id"  ></td></div>
                      <input type="button" value="delete" id="delete" onclick="del(); return false"></td>
                  </form>
                  <input id="logout" type="button" value="logout" onclick ="localStorage.clear();location.reload();"><br>
                  </div>
              `;
    if (response != null) {
        a = JSON.parse(response)

        console.log(response);
        let t = document.querySelector("table");

        for (let i = 0; i < a.length; i++) {
            var row;
            row = t.insertRow();
            for (let key in a[i]) {
                cell = row.insertCell();
                cell.innerHTML = a[i][key];
            }
        }
    }
}

function addPage() {
    document.body.removeChild(document.body.firstChild);
    document.body.innerHTML = `
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
<div class="container">
<iframe name="myIFR" style="display: none"></iframe>
<form method="post" target="myIFR">
    <input id="name" type="text">
   <input id="patronymic" type="text">
    <input id="surname" type="text">
    <input id="entr" value="enter" type="button">
</form>
</div>
`;
}

function loginPage() {
    document.body.removeChild(document.body.firstChild);
    document.body.innerHTML = `
    <style>
    .container{
        background-color: rgb(228, 201, 235);
        margin: 150px 600px;
        padding: 70px 50px;
        border-radius: 4px;
        position:fixed;
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
        input[type="text"]:focus {
            color: rgba(31, 33, 65, 0.75);
            outline: 1px rgba(31, 33, 65, 0.5);
            border-width: 1px;
            border-color: rgba(31, 33, 65, 0.5);
          }
    input[type="password"]{
        padding-left: 12px;
        position: relative;
        display: flex;
        flex-direction: row;
        font-size: 14px;
        border-color: rgba(31, 33, 65, 0.25);
        border-radius: 4px;
        border-width: 1px;}
        input[type="password"]:focus {
            color: rgba(31, 33, 65, 0.75);
            outline: 1px rgba(31, 33, 65, 0.5);
            border-width: 1px;
            border-color: rgba(31, 33, 65, 0.5);
          }
    input[type="button"]{color: #ffffff;
        padding-top: 9px;
        padding-bottom: 9px;
        padding-left: 19px;
        padding-right: 19px;
        border: none;
        background: linear-gradient(180deg, #bc9cff 0%, #8ba4f9 100%);
        border-radius: 22px;}
    #error{
        background-color: rgb(228, 201, 235);
    }
    p{
        color: #5e2eaa;
    }
    </style>
    <iframe name="myIFR" style="display: none"></iframe>
    <div class="container">
    <form id = 'form' method="post" target="myIFR">
    <p>login</p>
    <input id="email" type="text"><br>
    <p>password</p>
    <input id="password" type="password"><br>
    <input id="enter" type="button" value="enter"><br>
    <input id="error" type="text" style="color: red; border: none;" disabled></>
    </form>
    </div>   
    `;
}