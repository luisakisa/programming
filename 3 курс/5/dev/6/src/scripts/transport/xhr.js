export function del(method, URL) {
    fetch(URL, { method: method });
}
export function put(method, URL) {
    fetch(URL, { method: method });
}

export function post(method, URL, header, object) {
    return fetch(URL, {
        method: method,
        headers: { 'Content-Type': header },
        body: object
    })
}