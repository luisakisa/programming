var pageTable = (function() {
    //*********************************************  

    var root = undefined;


    function _add() {
        pageAdd.render(root)
    }

    function _del() {
        model.delUser(document.querySelector("[name=id]").value, _init)
        model.getData(localStorage.getItem("hash"), _init)
    }


    function _render(response) {
        root.innerHTML = `<style>  .container{
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
        <form method=delete"  name="del" target="myIFR">
            <div class="del">
                <p>enter id for delete</p>
                <input type="text" name="id"  ></td></div>
            <input type="button" value="delete" id="delete" onclick="del(); return false"></td>
        </form>
        <input id="logout" type="button" value="logout" onclick ="localStorage.clear();location.reload();"><br>
        </div>
    `


        let t = document.querySelector("table");
        peoples = JSON.parse(response)

        for (let i = 0; i < peoples.length; i++) {
            var row;
            row = t.insertRow();
            for (let key in peoples[i]) {
                cell = row.insertCell();
                cell.innerHTML = peoples[i][key];
            }
        }

        var bAdd = document.getElementById("add");
        bAdd.addEventListener('click', _add);
        var bDel = document.getElementById("delete");
        bDel.addEventListener('click', _del)

    }

    function _init(peoples) {
        root = document.getElementById('root');
        if (peoples == 0) {
            pageLogin.error = 1
            pageLogin.render()
        } else {
            _render(peoples)
        }
    }

    return {
        render: _init
    };



    //*********************************************   
})();