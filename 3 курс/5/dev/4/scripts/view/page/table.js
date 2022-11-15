import {
    _init as renderBasketPage
} from './basket.js'
import {
    _init as renderLoginPage
} from './login.js'
import {
    _addProductToBasket as addProduct,
    _async_getBasket as getBasket
} from '../../model/model.js'
//*********************************************  

let root = undefined;
let products;
async function _toBasket() {
    products = await getBasket(localStorage.getItem("hash"));
    renderBasketPage(products);
}

function _add() {
    let tr = document.querySelectorAll('.table-row');
    for (let i = 0; i < tr.length; i++) {
        if (tr[i].style.backgroundColor == 'rgb(187, 216, 192)')
            addProduct(i + 1);
    }
}



function _render() {
    root.innerHTML = `   
    <header>
    <input type="button" id="logout" value="logout" onclick="localStorage.clear();location.reload();">
    <input type="button" id="to-basket" value="to basket">
    </header>
    <link rel="stylesheet" href="./style/style.css">
    <div class="container">

        <div class="table">
            <div class="table-header">
                <div class="header__item">
                    <th id="name" class="filter__link" href="#">Name</th>
                </div>
                <div class="header__item">
                    <th id="wins" class="filter__link filter__link--number" href="#">Parametrs</th>
                </div>
                <div class="header__item">
                    <th id="total" class="filter__link filter__link--number" href="#">Total</a>
                </div>
            </div>
            <div class="table-content">
            </div>
            <div class="table-buttons">
                <input type="button" value="add to basket" id="add"></td>
            </div>
        </div>
    `

    let t = document.querySelector(".table-content");

    for (let i = 0; i < products.length; i++) {

        t.insertAdjacentHTML('beforeEnd', `<div class="table-row"> </div>`);
        let r = t.lastElementChild;
        r.addEventListener('click', () => {
            if (r.style.backgroundColor != 'rgb(187, 216, 192)') r.style.backgroundColor = 'rgb(187, 216, 192)';
            else r.style.backgroundColor = '#EEEEEE'
        });
        r.insertAdjacentHTML('beforeEnd', `<div class="table-data">${products[i]._name}</div>`);
        r.insertAdjacentHTML('beforeEnd', `<div class="table-data">${products[i]._parametrs}</div>`);
        r.insertAdjacentHTML('beforeEnd', `<div class="table-data">${products[i]._total}</div>`);

    }

    let bAdd = document.getElementById("add");
    bAdd.addEventListener('click', _add);
    let bBasket = document.getElementById("to-basket");
    bBasket.addEventListener('click', _toBasket);


}

export function _init(_products) {
    products = _products;
    root = document.getElementById('root');
    if (products == 0) {
        pageLogin.error = 1
        renderLoginPage()
    } else {
        _render()
    }
}