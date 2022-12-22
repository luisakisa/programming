let express = require("express");
const path = require("path");
const app = express();
var bodyParser = require("body-parser");
app.set("view engine", "ejs");
app.use(express.static("styles"));
const createPath = (page) => path.resolve(__dirname, "ejs_view", `${page}.ejs`);
app.get("/", function (req, res) {
  const title = "Start";
  res.render(createPath("index"), { title });
});
const startDir = __dirname;


app.get("/readers", function (req, res) {
  const title = "Readers";
  const MongoClient = require("mongodb").MongoClient;
  let mongoClient = new MongoClient("mongodb://127.0.0.1:27017/");
  async function getCollection() {
    try {
      await mongoClient.connect();
      const db = mongoClient.db("SemestrBase");
      const collection = db.collection("readers");
      const result = await collection.find().toArray();
      res.render(createPath("readers"), { result, title });
    } catch (err) {
      console.log(err);
    } finally {
      await mongoClient.close();
    }
  }
  getCollection().catch(console.error);
});
app.get("/readers/:id", (req, res) => {
  const title = "Reader";
  const MongoClient = require("mongodb").MongoClient;
  let mongoClient = new MongoClient("mongodb://127.0.0.1:27017/");
  async function getCollection() {
    try {
      await mongoClient.connect();
      const db = mongoClient.db("SemestrBase");
      const collection = db.collection("readers");
      const reader = await collection
        .aggregate([
          {
            $match: {
              _id: new require("mongodb").ObjectId(req.params.id),
            },
          },
          { $unwind: "$books" },
          {
            $lookup: {
              from: "books",
              localField: "books.book._id",
              foreignField: "copys._id",
              as: "bookData",
            },
          },
        ])
        .toArray();
      res.render(createPath("reader"), { reader, title });
    } catch (err) {
      console.log(err);
    } finally {
      await mongoClient.close();
    }
  }
  getCollection().catch(console.error);
});
app.get("/books", function (req, res) {
  const title = "Books";
  const MongoClient = require("mongodb").MongoClient;
  let mongoClient = new MongoClient("mongodb://127.0.0.1:27017/");
  async function getCollection() {
    try {
      await mongoClient.connect();
      const db = mongoClient.db("SemestrBase");
      const collection = db.collection("books");
      const books = await collection.find().toArray();
      res.render(createPath("books"), { books, title });
    } catch (err) {
      console.log(err);
    } finally {
      await mongoClient.close();
    }
  }
  getCollection().catch(console.error);
});
app.get("/books/:id", (req, res) => {
  const title = "Book";
  const MongoClient = require("mongodb").MongoClient;
  let mongoClient = new MongoClient("mongodb://127.0.0.1:27017/");
  async function getCollection() {
    try {
      await mongoClient.connect();
      const db = mongoClient.db("SemestrBase");
      const collection = db.collection("books");
      const book = await collection
        .aggregate([
          {
            $match: {
              _id: new require("mongodb").ObjectId(req.params.id),
            },
          },
          { $unwind: "$copys" },
        ])
        .toArray();
      res.render(createPath("book"), { book, title });
    } catch (err) {
      console.log(err);
    } finally {
      await mongoClient.close();
    }
  }
  getCollection().catch(console.error);
});
app.get("/return", (req, res) => {
  const title = "Return book";
  res.render(createPath("return"), { title });
});
app.post(
  "/return",
  bodyParser.text({ defaultCharset: "utf-8" }),
  function (req, res) {
    let copyId = req.body;
    console.log(copyId);
    const MongoClient = require("mongodb").MongoClient;
    let mongoClient = new MongoClient("mongodb://127.0.0.1:27017/");
    async function getCollection() {
      try {
        await mongoClient.connect();
        const db = mongoClient.db("SemestrBase");
        const collectionB = db.collection("books");
        const collectionR = db.collection("readers");
        await collectionB.updateOne(
          { "copys._id": new require("mongodb").ObjectId(copyId) },
          { $set: { "copys.$.status": "in storage" } }
        );
        await collectionR.updateOne(
          { "books.book._id": new require("mongodb").ObjectId(copyId) },
          {
            $set: {
              "books.$.status": "returned",
              "books.$.book.status": "in storage",
            },
          }
        );
        const title = "Return book";
        res.render(path.resolve(startDir, "ejs_view", `return.ejs`), { title });
      } catch (err) {
        console.log(err);
      } finally {
        await mongoClient.close();
      }
    }
    getCollection().catch(console.error);
  }
);
app.post("/deletingReader", bodyParser.text({ defaultCharset: "utf-8" }), (req, res) => {
    const MongoClient = require("mongodb").MongoClient;
  console.log(req.body)
    let mongoClient = new MongoClient("mongodb://127.0.0.1:27017/");
    async function getCollection() {
      try {
        await mongoClient.connect();
        const db = mongoClient.db("SemestrBase");
        const collection = db.collection("readers");
        await  collection.deleteOne({
          ticket: req.body,
        });
        res.send("ok");
      } catch (err) {
        console.log(err);
      } finally {
        await mongoClient.close();
      }
    }
    getCollection().catch(console.error);
  }
  );

app.post("/deleting", bodyParser.text({ defaultCharset: "utf-8" }), (req, res) => {
  const MongoClient = require("mongodb").MongoClient;
console.log(req.body)
  let mongoClient = new MongoClient("mongodb://127.0.0.1:27017/");
  async function getCollection() {
    try {
      await mongoClient.connect();
      const db = mongoClient.db("SemestrBase");
      const collection = db.collection("books");
      await  collection.deleteOne({
        _id: new require("mongodb").ObjectId(req.body),
      });
      res.send("ok");
    } catch (err) {
      console.log(err);
    } finally {
      await mongoClient.close();
    }
  }
  getCollection().catch(console.error);
}
);

app.get("/addCopys", (req, res) => {
  const title = "Add Copys";
  res.render(createPath("addCopys"), { title });
});
app.get("/addReader", (req, res) => {
  const title = "Add Reader";
  res.render(createPath("addReader"), { title });
});
app.get("/giveBook", (req, res) => {
  const title = "Give Book";
  res.render(createPath("giveBook"), { title });
});

app.get("/addBook", (req, res) => {
  const title = "Add Book";
  res.render(createPath("addBook"), { title });
});
app.post("/addBook", bodyParser.json(), function (req, res) {
  const MongoClient = require("mongodb").MongoClient;
  let mongoClient = new MongoClient("mongodb://127.0.0.1:27017/", {
    useNewUrlParser: true,
    useUnifiedTopology: true,
  });
  mongoClient.connect();
  const db = mongoClient.db("SemestrBase");
  const collectionB = db.collection("books");
  console.log(req.body);
  const { name, author, createdAt, date, place, count } = req.body;
  const year = parseInt(createdAt, 10);
  collectionB
    .insertOne({
      name: name,
      author: author,
      copys: new Array(),
    })
    .then((book) => {
      for (var i = 0; i < count; i++) {
        collectionB.findOneAndUpdate(
          { name: name, author: author },
          {
            $push: {
              copys: {
                _id: new require("mongodb").ObjectId(),
                createdAt: year,
                date: new Date(date),
                status: "in storage",
                place: place,
              },
            },
          }
        );
      }
      res.send("ok");
    });
});
app.post("/addReader", bodyParser.json(), function (req, res) {
  const MongoClient = require("mongodb").MongoClient;
  let mongoClient = new MongoClient("mongodb://127.0.0.1:27017/", {
    useNewUrlParser: true,
    useUnifiedTopology: true,
  });
  mongoClient.connect();
  const db = mongoClient.db("SemestrBase");
  const collectionR = db.collection("readers");
  console.log(req.body);
  const {
    name,
    lastname,
    status,
    faculty,
    group,
    startRegistration,
    endRegistration,
  } = req.body;

  collectionR.insertOne({
    name: name,
    lastname: lastname,
    status: "student",
    faculty: faculty,
    group: group,
    startRegistration: new Date(startRegistration),
    endRegistration: new Date(endRegistration),
    lendings: null,
    penalty: null
  })
  res.send("ok");
});
app.post("/giveBook", bodyParser.json(), function (req, res) {
  const MongoClient = require("mongodb").MongoClient;
  let mongoClient = new MongoClient("mongodb://127.0.0.1:27017/", {
    useNewUrlParser: true,
    useUnifiedTopology: true,
  });
  mongoClient.connect();
  const db = mongoClient.db("SemestrBase");
  const collectionR = db.collection("readers");
  const collectionB = db.collection("books");
  console.log(req.body);
  const { ticket, copyId, startDate, endDate } = req.body;

  collectionB
    .aggregate([
      { $unwind: "$copys" },
      {
        $match: {
          "copys._id": new require("mongodb").ObjectId(copyId),
        },
      },
    ])
    .toArray()
    .then((book) => {
      collectionB.findOneAndUpdate(
        { "copys._id": new require("mongodb").ObjectId(copyId) },
        { $set: { "copys.$.status": "in reading" } }
      );
      collectionR.findOneAndUpdate(
        { ticket: ticket },
        {
          $push: {
            books: {
                book:book[0].copys, 
              startDate: new Date(startDate),
              endDate: new Date(endDate),
              status: "in reading",
            },
          },
        }
      );
      res.send("ok");
    });
});

app.post("/addCopys", bodyParser.json(), function (req, res) {
  const MongoClient = require("mongodb").MongoClient;
  let mongoClient = new MongoClient("mongodb://127.0.0.1:27017/", {
    useNewUrlParser: true,
    useUnifiedTopology: true,
  });
  mongoClient.connect();
  const db = mongoClient.db("SemestrBase");
  const collectionB = db.collection("books");
  const { _id, createdAt, date, place, count } = req.body;
  const id_book = new require("mongodb").ObjectId(_id);
  const year = parseInt(createdAt, 10);
  console.log( req.body)
  for (var i = 0; i < count; i++) {
    collectionB.findOneAndUpdate(
      { _id: id_book },
      {
        $push: {
          copys: {
            _id: new require("mongodb").ObjectId(),
            createdAt: year,
            date: new Date(date),
            status: "in storage",
            place: place,
          },
        },
      }
    );
  }
  res.send("ok");
});

app.post("/date", bodyParser.json(), function (req, res) {
  let attr = req.body;
  const MongoClient = require("mongodb").MongoClient;
  let mongoClient = new MongoClient("mongodb://127.0.0.1:27017/");
  async function getCollection() {
    try {
      await mongoClient.connect();
      const db = mongoClient.db("FirstBase");
      const collection = db.collection("Articles");
      const result = await collection
        .find({
          dateOfPublication: {
            $gte: attr.startDate,
            $lt: attr.endDate,
          },
        })
        .toArray();
      res.send(result);
    } catch (err) {
      console.log(err);
    } finally {
      await mongoClient.close();
    }
  }
  getCollection().catch(console.error);
});
app.listen(3002);
