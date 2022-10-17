function addEnterClick() {
    var entr = document.getElementById("entr");
    entr.onclick = function() {
        let add = {
            id: 0,
            name: document.querySelector("[id=name]").value,
            surname: document.querySelector("[id=surname]").value,
            patronymic: document.querySelector("[id=patronymic]").value,
        };
        createRequest("POST", "api/adding", "application/json;charset=UTF-8", JSON.stringify(add), tablePageRender)
    };
}