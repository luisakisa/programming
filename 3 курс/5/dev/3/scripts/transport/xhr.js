var toServer = (function() {
    //*********************************************  

    function _delete(method, URL) {
        let xhr = new XMLHttpRequest();
        xhr.open(method, URL);
        xhr.send();
    }

    function _else(method, URL, valueHeader, object, callback) {

        var xhr = new XMLHttpRequest();
        xhr.open(method, URL);
        xhr.setRequestHeader("Content-Type", valueHeader);
        xhr.send(object);
        xhr.onload = function() {
            if (xhr.status !== 200) {
                console.log('Error: ' + xhr.status + ': ' + xhr.statusText);
            } else {
                callback(xhr.response);
            }
        }
    }
    return {
        delete: _delete,
        postPut: _else,
    };



    //*********************************************   
})();