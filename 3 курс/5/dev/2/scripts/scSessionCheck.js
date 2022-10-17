window.onload = function() {
    if (localStorage.getItem('login') == null) {
        loginPage()
        enterClick()
    } else {
        createRequest("POST", "api/table", "text/plain;charset=UTF-8", localStorage.getItem("passSalt"), tablePageRender)


    }
}

tablePageRender = function(response) {
    if (response == 0) {
        error.value = "log in again";
    } else {
        tablePage(response)
        addDelClick()
    }
}