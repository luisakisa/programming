export function _delete(method, URL) {
    fetch(URL, { method: method });
}
export function _put(method, URL) {
    fetch(URL, { method: method });
}

export function _post(method, URL, header, object) {
    return fetch(URL, {
        method: method,
        headers: { 'Content-Type': header },
        body: object
    })
}