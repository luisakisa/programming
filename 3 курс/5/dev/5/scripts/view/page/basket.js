import { _init as renderTablePage } from './table.js'
import {
    _init as renderLoginPage
} from './login.js'
import {
    _async_getBasket as getBasket,
    _delProduct as delProduct,
    _async_getProducts as getProducts
} from '../../model/model.js'
//*********************************************  

let root = undefined;
let basketIsNull;
let products;

async function _back() {
    products = await getProducts(localStorage.getItem("hash"))
    renderTablePage(products);
}

async function _del() {
    let tr = document.querySelectorAll('.table-row');
    for (let i = 0; i < tr.length; i++) {
        if (tr[i].style.backgroundColor == 'rgb(187, 216, 192)')
            delProduct(i + 1);
    }
    products = await getBasket(localStorage.getItem("hash"));
    _init(products);
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
            ` +
        basketIsNull + `
            </div>
            <div class="table-buttons">
                <input type="button" value="back" id="back"></td>
                <input type="button" value="delete" id="del"></td>
            </div>
        </div>
    `

    let t = document.querySelector(".table-content");

    for (let i = 0; i < products.length; i++) {
        t.insertAdjacentHTML('afterBegin', '<div class="table-row"></div>');
        let r = document.querySelector(".table-row");
        r.addEventListener('click', () => {
            if (r.style.backgroundColor != 'rgb(187, 216, 192)') r.style.backgroundColor = 'rgb(187, 216, 192)';
            else r.style.backgroundColor = '#EEEEEE'
        });
        r.insertAdjacentHTML('beforeEnd', `<div class="table-data">${products[i]._name}</div>`);
        r.insertAdjacentHTML('beforeEnd', `<div class="table-data">${products[i]._parametrs}</div>`);
        r.insertAdjacentHTML('beforeEnd', `<div class="table-data">${products[i]._total}</div>`);

    }

    let bDel = document.getElementById("del");
    bDel.addEventListener('click', _del)
    let bBack = document.getElementById("back");
    bBack.addEventListener('click', _back)

}

export function _init(_products) {
    products = _products;
    root = document.getElementById('root');
    if (products == 0) {
        basketIsNull = "basket is empty"
        _render()
    } else {
        basketIsNull = "";
        _render()
    }
}