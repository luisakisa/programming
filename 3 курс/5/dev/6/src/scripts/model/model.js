import { del, post, put } from "../transport/xhr.js";

class Product {
    constructor(id, name, parametrs, total) {
        this._id = id
        this._name = name;
        this._parametrs = parametrs;
        this._total = total;
    }

    get id() {
        return this._id;
    }
    get parametrs() {
        return this._parametrs;
    }
    get product() {
        return this._product;
    }
    get total() {
        return this._total;
    }
}

export function async_getProducts(object) {
    return new Promise((resolve) => {
        post("POST", "api/products", "text/plain;charset=UTF-8", object)
            .then((response) => response.json())
            .then((data) => {
                console.log(data)
                resolve(_response(data));
            });
    });
}

export function async_getBasket(object) {
    return new Promise((resolve) => {
        post("POST", "api/basket", "text/plain;charset=UTF-8", object)
            .then((response) => response.json())
            .then((data) => {
                resolve(_response(data));
            });
    });
}

export function async_login(object) {
    return new Promise((resolve) => {
        post("POST", "api/login", "application/json;charset=UTF-8", object)
            .then(response => {
                resolve(response.text())
            });
    });
}

export function addProductToBasket(id) {
    URL = "api/adding/" + id;
    put("PUT", URL);

}

export function delProduct(id) {
    URL = "api/deleting/" + id;
    del("DELETE", URL);
}

function _response(p) {
    if (p != null) {
        let products = [];
        for (let i = 0; i < p.length; i++) {
            products.push(new Product(p[i].id, p[i].name, p[i].parametrs, p[i].total))

        }
        return products;
    }
}