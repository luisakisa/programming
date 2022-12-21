function getArticles() {
    fetch('/articles', { method: "GET" })
        .then((response) => response.json())
        .then((data) => {
            let root = document.querySelector('.container');
            let child = document.getElementsByTagName("button");
            root.removeChild(child[0])
            root.innerHTML = `  <table>
            <tr>
            <th>порядковый номер</th>
            <th>название</th>
                <th>авторы</th>
                <th>дата размещения</th>
                <th>подробнее о статье</th>
                <th>удалить</th>
                <th>создать статью</th>
            </tr>
           </table><br>
           `
            let t = document.querySelector("table");
            let keys = ['_id', 'name', 'author', 'dateOfPublication']
            for (let i = 0; i < data.length; i++) {
                var row;
                row = t.insertRow();
                for (let j = 0; j < 4; j++) {
                    cell = row.insertCell();
                    cell.innerHTML = data[i][keys[j]];
                    if (j == 3) {
                        cell = row.insertCell();
                        cell.innerHTML = "<button onclick = 'getInfo(this)'><img height = '25' width = '25' src='/info.png'/></button>"
                        cell = row.insertCell();
                        cell.innerHTML = "<button onclick = 'delArticle(this)'><img height = '25' width = '25' src='/garbage.png'/></button>"
                        cell = row.insertCell();
                        cell.innerHTML = "<button onclick = 'addArticle(this)'><img height = '25' width = '25' src='/add.png'/></button>"
                    }
                }
            }
            var div = document.createElement("div")
            div.className = "input"
            div.innerHTML = `
            <input type="text" id="name"><br>
            <input type="button" value="поиск по названию" onclick="getArticleByName()">`
            document.body.appendChild(div);
            var div = document.createElement("div")
            div.className = "input"
            div.innerHTML = `
            <select id="s">
  <option>Иванов Иван</option>
  <option>Петров Петр</option>
  <option>Кудинов Роман</option>
  <option>Пасютин Александр</option>
  <option>Ульяна Топташ</option>
</select>

            <input type="button" value="поиск по автору" onclick="getArticleByAuthor()">`
            document.body.appendChild(div);
        })

}

function getArticleByName() {
    let name = document.getElementById("name").value
    fetch('/article', {
            method: "POST",
            body: name
        }).then((response) => response.json())
        .then((data) => {
            let root = document.querySelector('.container');
            root.innerHTML = `  <table>
            <tr>
            <th>порядковый номер</th>
            <th>название</th>
                <th>авторы</th>
                <th>дата размещения</th>
                <th>подробнее о статье</th>
                <th>удалить</th>
            </tr>
           </table><br>
           `
            let t = document.querySelector("table");
            let keys = ['_id', 'name', 'author', 'dateOfPublication']
            for (let i = 0; i < data.length; i++) {
                var row;
                row = t.insertRow();
                for (let j = 0; j < 4; j++) {
                    cell = row.insertCell();
                    cell.innerHTML = data[i][keys[j]];
                    if (j == 3) {
                        cell = row.insertCell();
                        cell.innerHTML = "<button onclick = 'getInfo(this)'><img height = '25' width = '25' src='/info.png'/></button>"
                        cell = row.insertCell();
                        cell.innerHTML = "<button onclick = 'delArticle(this)'><img height = '25' width = '25' src='/garbage.png'/></button>"
                        cell = row.insertCell();
                        cell.innerHTML = "<button onclick = 'addArticle(this)'><img height = '25' width = '25' src='/add.png'/></button>"
                    }
                }
            }

        })
}

function getArticleByAuthor() {
    let list = document.getElementById("s");
    let ind = list.selectedIndex;
    let option = list.querySelectorAll("option")[ind].value;
    fetch('/author', {
            method: "POST",
            body: option
        }).then((response) => response.json())
        .then((data) => {
            let root = document.querySelector('.container');
            root.innerHTML = `  <table>
        <tr>
        <th>порядковый номер</th>
        <th>название</th>
            <th>авторы</th>
            <th>дата размещения</th>
            <th>подробнее о статье</th>
                <th>удалить</th>
        </tr>
       </table><br>
       `
            let t = document.querySelector("table");
            let keys = ['_id', 'name', 'author', 'dateOfPublication']
            for (let i = 0; i < data.length; i++) {
                var row;
                row = t.insertRow();
                for (let j = 0; j < 4; j++) {
                    cell = row.insertCell();
                    cell.innerHTML = data[i][keys[j]];
                    if (j == 3) {
                        cell = row.insertCell();
                        cell.innerHTML = "<button onclick = 'getInfo(this)'><img height = '25' width = '25' src='/info.png'/></button>"
                        cell = row.insertCell();
                        cell.innerHTML = "<button onclick = 'delArticle(this)'><img height = '25' width = '25' src='/garbage.png'/></button>"
                        cell = row.insertCell();
                        cell.innerHTML = "<button onclick = 'addArticle()'><img height = '25' width = '25' src='/add.png'/></button>"
                    }
                }
            }

        })
}

function getInfo(obj) {
    let tdName = obj.parentNode.parentNode.children;
    fetch('/info', {
            method: "POST",
            body: tdName[1].innerHTML
        })
        .then((response) => response.json())
        .then((data) => {
            let root = document.querySelector('.container');
            root.innerHTML = `  
       `
            document.body.innerHTML = `  
       `
            let head1 = document.createElement("h1");
            console.log(data[0]["name"]);
            head1.appendChild(document.createTextNode(data[0]["name"]));
            document.body.appendChild(head1);

            let head2 = document.createElement("h2");
            head2.appendChild(document.createTextNode("Автор: "));
            head2.appendChild(document.createTextNode(data[0]["author"]));
            head2.appendChild(document.createElement("br"));
            head2.appendChild(document.createTextNode("Дата публикации: "));
            head2.appendChild(document.createTextNode(data[0]["dateOfPublication"]));
            document.body.appendChild(head2);


            let content = document.createElement("div");
            content.appendChild(document.createTextNode("Тэги: "));
            content.appendChild(document.createTextNode(data[0]["tags"]));
            content.appendChild(document.createElement("br"));

            content.appendChild(document.createTextNode("Рецензии: "));
            content.appendChild(document.createElement("br"));
            for (let i of data[0]["comments"]) {
                content.appendChild(document.createTextNode(i["name"] + ": "));
                content.appendChild(document.createTextNode(i["text"]));
                content.appendChild(document.createTextNode(" Оценка: " + i["score"] + ". "));
                content.appendChild(document.createElement("br"));
            }
            //content.appendChild(document.createTextNode(JSON.stringify(data[0]["comments"])));
            content.appendChild(document.createElement("br"));
            document.body.appendChild(content);

        })

}

function delArticle(obj) {
    let tdName = obj.parentNode.parentNode.children;
    fetch('/deleting', {
            method: "POST",
            body: tdName[1].innerHTML
        })
        .then((response) => response.json())
        .then((data) => {
            let root = document.querySelector('.container');
            root.innerHTML = `  <table>
    <tr>
    <th>порядковый номер</th>
    <th>название</th>
        <th>авторы</th>
        <th>дата размещения</th>
        <th>подробнее о статье</th>
            <th>удалить</th>
    </tr>
   </table><br>
   `
            let t = document.querySelector("table");
            let keys = ['_id', 'name', 'author', 'dateOfPublication']
            for (let i = 0; i < data.length; i++) {
                var row;
                row = t.insertRow();
                for (let j = 0; j < 4; j++) {
                    cell = row.insertCell();
                    cell.innerHTML = data[i][keys[j]];
                    if (j == 3) {
                        cell = row.insertCell();
                        cell.innerHTML = "<button onclick = 'getInfo(this)'><img height = '25' width = '25' src='/info.png'/></button>"
                        cell = row.insertCell();
                        cell.innerHTML = "<button onclick = 'delArticle(this)'><img height = '25' width = '25' src='/garbage.png'/></button>"
                    }
                }
            }
        })
}

function addArticle() {

    document.body.innerHTML = ``
    var div = document.createElement("div")
    div.className = "input"
    div.innerHTML = `
    <input type="text" id="newName" placeholder="введите название статьи"><br>
    <input type="text" id="newAuthor" placeholder="введите автора статьи"><br>
    <input type="button" value="создать" onclick="createArticle()">`
    document.body.appendChild(div);
}

function createArticle() {
    let name = document.getElementById("newName").value
    let author = document.getElementById("newAuthor").value
    let json = {
        name: name,
        author: author,
        dateOfPublication: new Date()
    }
    fetch('/adding', {
            method: "POST",
            body: JSON.stringify(json),
            headers: { 'Content-Type': "application/json;charset=UTF-8" },
        })
        .then((response) => response.json())
        .then((data) => {
            document.body.innerHTML = `  <table>
<tr>
<th>порядковый номер</th>
<th>название</th>
    <th>авторы</th>
    <th>дата размещения</th>
    <th>подробнее о статье</th>
        <th>удалить</th>
</tr>
</table><br>
`
            let t = document.querySelector("table");
            let keys = ['_id', 'name', 'author', 'dateOfPublication']
            for (let i = 0; i < data.length; i++) {
                var row;
                row = t.insertRow();
                for (let j = 0; j < 4; j++) {
                    cell = row.insertCell();
                    cell.innerHTML = data[i][keys[j]];
                    if (j == 3) {
                        cell = row.insertCell();
                        cell.innerHTML = "<button onclick = 'getInfo(this)'><img height = '25' width = '25' src='/info.png'/></button>"
                        cell = row.insertCell();
                        cell.innerHTML = "<button onclick = 'delArticle(this)'><img height = '25' width = '25' src='/garbage.png'/></button>"
                    }
                }
            }
        })
}

function getTopArticles() {
    fetch('/top', {
            method: "GET",
        })
        .then((response) => response.json())
        .then((data) => {
            let root = document.body
            root.innerHTML = `<h1>Топ 3 статей</h1><br>`

            for (let i = 0; i < data.length; i++) {
                root.append(document.createElement("h2"))
                c = root.children
                c[c.length - 1].innerHTML = `${i+1}`
                for (let key in data[i]) {
                    root.append(document.createElement("p"))
                    c = root.children
                    console.log(data[i][key])
                    c[c.length - 1].innerHTML = `
                    ${JSON.stringify(data[i][key])} <br> `
                }
            }

        })
}

function getArticlesDate() {
    let json = {
        startDate: new Date(document.getElementById("startDate").value),
        endDate: new Date(document.getElementById("endDate").value)
    }

    fetch('/date', {
            method: "POST",
            body: JSON.stringify(json),
            headers: { 'Content-Type': "application/json;charset=UTF-8" },
        })
        .then((response) => response.json())
        .then((data) => {
            document.body.innerHTML = `  <table>
<tr>
<th>порядковый номер</th>
<th>название</th>
<th>авторы</th>
<th>дата размещения</th>
<th>подробнее о статье</th>
    <th>удалить</th>
</tr>
</table><br>
`
            let t = document.querySelector("table");
            let keys = ['_id', 'name', 'author', 'dateOfPublication']
            for (let i = 0; i < data.length; i++) {
                var row;
                row = t.insertRow();
                for (let j = 0; j < 4; j++) {
                    cell = row.insertCell();
                    cell.innerHTML = data[i][keys[j]];
                    if (j == 3) {
                        cell = row.insertCell();
                        cell.innerHTML = "<button onclick = 'getInfo(this)'><img height = '25' width = '25' src='/info.png'/></button>"
                        cell = row.insertCell();
                        cell.innerHTML = "<button onclick = 'delArticle(this)'><img height = '25' width = '25' src='/garbage.png'/></button>"
                    }
                }
            }
        })
}