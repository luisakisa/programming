function createRequest(method, URL, valueHeader, object, callback) {
    console.log(typeof(callback))

    var xhr = new XMLHttpRequest();
    xhr.open(method, URL);
    xhr.setRequestHeader("Content-Type", valueHeader);
    xhr.send(object)
    xhr.onreadystatechange = function() {
        if (xhr.status !== 200) {
            console.log("Request error: " + xhr.status + ": " + xhr.status);
        } else {
            console.log("res[onse request")
            console.log(xhr.response)

            callback(xhr.response)
        }
    }
}