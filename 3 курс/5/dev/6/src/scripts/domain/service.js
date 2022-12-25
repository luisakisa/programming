console.log("Log:Exporting service");

class Store {
  // определяет основную функциональности любого храеиоища

  constructor() {
    this._callbacks = []; //массив колбэков
  }

  _emit(state) {
    //принимает новое значение глобального состояния
    this._callbacks.forEach((callback) => callback(state)); //и для каждого коллбэка из массива передает это новое состояние
  }

  subscribe(callback) {
    this._callbacks.push(callback); //принимает коллбэк и добавляет  в массив коллюэков
  }
}

//store хранит глобальное состояние всех компонентов
//какой-то компонент изменяетя глобальное состояние например кнопка
// другие компоненты подписаны на изменение эого состояния(два лаейбла)
// как только изменитя состояние сработабт коллбэки на подписку
// эти лейблы получают измененное глобальное состояние
// обновляют свое локальное состояние
// и на основе локального состояния происходит ререндеринг(видим обновление инфы)

class User extends Store {
  constructor() {
    super();
    this._user = {email:0, password:0};
  }

  fixUserName(userName) {
    this._user = userName;
    console.log("User::fixUserName: " + this._user);
    super._emit(this._user);
  }

  giveUserName() {
    console.log("User::giveUserName: " + this._user);
    return this._user;
  }
}

class UserFactory {
  static _user = null;

  static _createInstance() {
    return new User();
  }

  static createInstance() {
    if (UserFactory._user === null) {
      UserFactory._user = UserFactory._createInstance();
    }
    return UserFactory._user;
  }
}

export { UserFactory }; //другие классы работают только с фабриками и они могут вызвать единственный публичный метод createinstance
