function enterClick() {
    var b = document.getElementById("enter");
    b.onclick = function() {
        var form = document.getElementById("form");
        var email = form.querySelector("[id=email]");
        var password = form.querySelector("[id=password]");
        var error = document.querySelector("#error");
        var user = {
            email: email.value,
            password: password.value,
        };

        createRequest("POST", "api/autorization", "application/json;charset=UTF-8", JSON.stringify(user),

            function checkSession(response) {
                if (response == "nothash" || response == "") {
                    if (response == "nothash") {
                        error.value = "User not founded try again";
                    }
                } else {
                    const hash = response;
                    localStorage.setItem("login", user.email);
                    localStorage.setItem("pass", user.password);
                    localStorage.setItem("hash", hash);
                    createRequest("POST", "api/table", "text/plain;charset=UTF-8", localStorage.getItem("hash"), tablePageRender)
                };
            })

    }
};