db.books.drop()
db.readers.drop()
//-----------------------books------------------------------------------------------------------------

let books_1 = db.books.insertOne({ 
    name: "Jane Eyre", 
    author: "Charlotte Bronte",
    copys: [
        {
            _id: ObjectId(),
            createdAt: "2012",
            date: new Date("2021-12-20"),
            status: "in reading",
            place: "abonement"
        },
        {
            _id: ObjectId(),
            createdAt: "2013",
            date: new Date("2022-01-20"),
            status: "in storage",
            place: "reading room"
        },
        {
            _id: ObjectId(),
            createdAt: "2016",
            date: new Date("2022-01-20"),
            status: "in reading",
            place: "interlib abonement"
        }
    ]
    
})

let books_2 = db.books.insertOne({ 
    name: "War and peace", 
    author: "Lev Tolstoy", 
    copys: [
        {
            _id: ObjectId(),
            createdAt: "2013",
            date: new Date("2021-12-22"),
            status: "in storage",
            place: "reading room"
        },
        {
            _id: ObjectId(),
            createdAt: "2013",
            date: new Date("2022-01-20"),
            status: "losted",
            place: "abonement"
        },
        {
            _id: ObjectId(),
            createdAt: "2013",
            date: new Date("2022-01-20"),
            status: "in reading",
            place: "interlib abonement"
        }
    ]
})

let books_3 = db.books.insertOne({ 
    name: "1984", 
    author: "George Orwell",
    copys: [
        {
            _id: ObjectId(),
            createdAt: "2017",
            date: new Date("2022-01-10"),
            status: "in storage",
            place: "reading room"
        },
        {
            _id: ObjectId(),
            createdAt: "2018",
            date: new Date("2022-01-10"),
            status: "in reading",
            place: "abonement"
        },
        {
            _id: ObjectId(),
            createdAt: "2018",
            date: new Date("2022-01-21"),
            status: "in storage",
            place: "interlib abonement"
        }
    ]
})

let books_4 = db.books.insertOne({ 
    name: "Mysterious island", 
    author: "Jules Verne",
    copys: [
        {
            _id: ObjectId(),
            createdAt: "2019",
            date: new Date("2020-10-11"),
            status: "in storage",
            place: "reading room"
        },
        {
            _id: ObjectId(),
            createdAt: "2018",
            date: new Date("2021-11-13"),
            status: "in storage",
            place: "abonement"
        },
        {
            _id: ObjectId(),
            createdAt: "2020",
            date: new Date("2022-01-21"),
            status: "in storage",
            place: "interlib abonement"
        }
    ]
})

let books_5 = db.books.insertOne({ 
    name: "The art of loving", 
    author: "Erich Fromm",
    copys: [
        {
            _id: ObjectId(),
            createdAt: "2019",
            date: new Date("2022-02-01"),
            status: "in storage",
            place: "reading room"
        },
        {
            _id: ObjectId(),
            createdAt: "2018",
            date: new Date("2021-12-03"),
            status: "in reading",
            place: "abonement"
        },
        {
            _id: ObjectId(),
            createdAt: "2020",
            date: new Date("2022-04-12"),
            status: "in storage",
            place: "interlib abonement"
        }
    ]
})

let books_6 = db.books.insertOne({ 
    name: "Three comrades", 
    author: "Erich Maria Remarque",
    copys: [
        {
            _id: ObjectId(),
            createdAt: "2013",
            date: new Date("2020-07-25"),
            status: "in storage",
            place: "reading room"
        },
        {
            _id: ObjectId(),
            createdAt: "2018",
            date: new Date("2020-07-07"),
            status: "in storage",
            place: "abonement"
        },
        {
            _id: ObjectId(),
            createdAt: "2020",
            date: new Date("2020-09-05"),
            status: "in storage",
            place: "interlib abonement"
        }
    ]
})

let books_7 = db.books.insertOne({ 
    name: "Extremely Loud & Incredibly Close", 
    author: "Jonathan Safran Foer",
    copys: [
        {
            _id: ObjectId(),
            createdAt: "2011",
            date: new Date("2019-07-12"),
            status: "in storage",
            place: "reading room"
        },
        {
            _id: ObjectId(),
            createdAt: "2022",
            date: new Date("2022-05-01"),
            status: "in reading",
            place: "abonement"
        },
        {
            _id: ObjectId(),
            createdAt: "2020",
            date: new Date("2021-09-15"),
            status: "in storage",
            place: "interlib abonement"
        }
    ]
})

//----------------------readers-------------------------------------------------------------------------------------
let reader_1 = db.readers.insertOne(
    { 
        name: "Katya", 
        lastname: "Sultanova", 
        status: "student", 
        faculty: "Fundamental Informatic and Information Technology", 
        group: "FIT-204",
        startRegistration: new Date("2020-09-01"),
        endRegistration: new Date("2024-06-30"),
        ticket:"2345",
        books: [
            {
                book:db.books.findOne({_id: books_1.insertedId}).copys[0],
                startDate: new Date("2022-05-10T16:00:00Z"),
                endDate: new Date("2022-06-20T16:00:00Z"),
                status: "in reading"
            },
            {
                book: db.books.findOne({_id: books_3.insertedId}).copys[0],
                startDate: new Date("2022-05-10T16:00:00Z"),
                endDate: new Date("2022-06-20T16:00:00Z"),
                status: "in reading"
            }
        ]
    }
)

let reader_2 = db.readers.insertOne(
    { 
        name: "Petya", 
        lastname: "Ivanov", 
        status: "student", 
        faculty: "Fundamental Informatic and Information Technology", 
        group: "FIT-204",
        startRegistration: new Date("2020-09-01"),
        endRegistration: new Date("2024-06-30"),
        ticket:"2635",
        books: [
            {
                book: db.books.findOne({_id: books_3.insertedId}).copys[1],
                startDate: new Date("2022-01-20T16:00:00Z"),
                endDate: new Date("2022-02-05T16:00:00Z"),
                status: "in reading"
            }
        ],
        penalty: [{
            startDate: new Date("2022-02-05T16:00:00Z"),
            endDate: new Date("2022-05-10T16:00:00Z"),
        }]
    }
)

let reader_3 = db.readers.insertOne(
    { 
        name: "Ksenia", 
        lastname: "Radchenko", 
        status: "student", 
        faculty: "Psychology", 
        group: "PSY-191",
        startRegistration: new Date("2019-09-01"),
        endRegistration: new Date("2023-06-30"),
        ticket:"2354",
        books: [
            {
                book: db.books.findOne({_id: books_7.insertedId}).copys[1],
                startDate: new Date("2022-05-13T16:00:00Z"),
                endDate: new Date("2022-06-25T16:00:00Z"),
                status: "in reading"
            }
        ], 
    }
)

let reader_4 = db.readers.insertOne(
    { 
        name: "Sergey", 
        lastname: "Stukolov", 
        status: "teacher", 
        department: "UNESCO", 
        degree: "Candidate of Physical and Mathematical Sciences",
        position: "Docent",
        startRegistration: new Date("2017-09-01"),
        endRegistration: new Date("2030-06-30"),
        ticket:"5345",
        books: [
            {
                book:db.books.findOne({_id: books_1.insertedId}).copys[2],
                startDate: new Date("2022-05-10T16:00:00Z"),
                endDate: new Date("2022-06-20T16:00:00Z"),
                status: "in reading"
            }
        ]
    }
)

let reader_5 = db.readers.insertOne(
    { 
        name: "Sergey", 
        lastname: "Karabcev", 
        status: "teacher", 
        department: "Information Security", 
        degree: "Candidate of Physical and Mathematical Sciences",
        position: "Docent",
        startRegistration: new Date("2019-09-01"),
        endRegistration: new Date("2043-06-30"),
        ticket:"5445",
        books: [
            {
                book: db.books.findOne({_id: books_5.insertedId}).copys[0],
                startDate: new Date("2021-04-10T16:00:00Z"),
                endDate: new Date("2021-05-20T16:00:00Z"),
                status: "returned"
            },
            {
                book:  db.books.findOne({_id: books_2.insertedId}).copys[2],
                startDate: new Date("2022-05-10T16:00:00Z"),
                endDate: new Date("2022-06-20T16:00:00Z"),
                status: "losted"
            }
        ]
    }
)

let reader_6 = db.readers.insertOne(
    { 
        name: "Sofia", 
        lastname: "Prohorenkova", 
        status: "student", 
        faculty: "Architecture", 
        group: "A-180",
        startRegistration: new Date("2017-09-01"),
        endRegistration: new Date("2022-06-30"),
        ticket:"2785",
        books: [] 
    }
)



let reader_7 = db.readers.insertOne(
    { 
        "name": "Stanislav", 
        "lastname": "Mordvinov", 
        "status": "Abiturient", 
    }
)