import { _async_login as login, _async_getProducts as getProducts } from '../../model/model.js'
import { _init as renderTablePage } from './table.js'
let root = undefined;
let error = undefined;
let products;

async function _auth() {
    let email = document.getElementById("email")
    let password = document.getElementById("password");
    let user = {
        email: email.value,
        password: password.value,
    };
    let hash = await login(JSON.stringify(user));
    console.log(hash)
    if (hash == "nothash") {
        error = 1;
        _render()
    } else if (hash == "") {

    } else {
        localStorage.setItem("login", user.email);
        localStorage.setItem("pass", user.password);
        localStorage.setItem("hash", hash);
        products = await getProducts(localStorage.getItem("hash"));
        renderTablePage(products);
    };

}



function _render(_error) {

    _error = error;
    if (_error == 1) {
        _error = "value='User not founded try again'";
    }
    root.innerHTML =
        `
        <style>
        /*body{*/
        /*    background:url("scr/giphy.gif")  no-repeat  right bottom;*/
        /*}*/
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
        <div class="container">
        <p>login</p>
        <input id="email" type="text"><br>
        <p>password</p>
        <input id="password" type="password"><br>
        <input id="enter" type="button" value="enter"><br> 
        <input id="error" type="text"` +
        _error +
        ` style="color: red; border: none;" disabled></>
        </div>   
        `

    let bEnter = document.getElementById("enter");
    bEnter.addEventListener('click', _auth);
}

export async function _init(_root) {
    root = _root;
    if (localStorage.getItem('login') == null) {
        _render();
    } else {
        products = await getProducts(localStorage.getItem("hash"));
        renderTablePage(products);
    }
}