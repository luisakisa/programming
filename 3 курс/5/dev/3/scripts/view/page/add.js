var pageAdd = (function() {
    //*********************************************  
    var root = undefined;

    function _add() {
        let add = {
            id: 0,
            name: document.querySelector("[id=name]").value,
            surname: document.querySelector("[id=surname]").value,
            patronymic: document.querySelector("[id=patronymic]").value,
        };
        model.addUser(JSON.stringify(add), pageTable.render)

    }


    function _render() {
        root.innerHTML = `
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
        `
        var bAdd = document.getElementById("entr");
        bAdd.addEventListener('click', _add);
    }



    function _init(_root) {
        root = _root
        _render();
    }

    return {
        render: _init
    };



    //*********************************************   
})();