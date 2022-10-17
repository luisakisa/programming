function addDelClick() {
    var add = document.getElementById("add");
    add.onclick = function() {
        addPage()
        addEnterClick();
    };
    var del = document.getElementById("delete");
    del.onclick = function() {
        createRequest("POST", "api/deletion", "text/plain;charset=UTF-8", document.querySelector("[name=id]").value, tablePageRender)
    };
}