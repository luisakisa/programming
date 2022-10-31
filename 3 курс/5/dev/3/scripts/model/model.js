var model = (function() {
    //*********************************************  
    var _callback;

    function _getData(object, callback) {
        _callback = callback;
        console.log("model obj " + object)
        toServer.postPut("POST", "api/peoples", "text/plain;charset=UTF-8", object, _response);
    }

    function _login(object, callback) {
        _callback = callback;
        console.log("model obj " + object)
        toServer.postPut("POST", "api/login", "application/json;charset=UTF-8", object, _response);
    }

    function _addUser(object, callback) {
        _callback = callback;
        toServer.postPut("PUT", "api/new_people", "application/json;charset=UTF-8", object, _response);

    }

    function _delUser(id, callback) {
        _callback = callback;
        URL = "api/deleting/" + id
        toServer.delete("DELETE", URL, _response)
    }

    function _response(response) {
        if (response != null) {
            _callback(response);
        }
    }
    return {
        getData: _getData,
        delUser: _delUser,
        login: _login,
        addUser: _addUser
    };
    //*********************************************   
})();