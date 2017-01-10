#include "books.h"

#include <QtSql>
#include <Cutelyst/Plugins/Utils/Sql>

using namespace Cutelyst;

Books::Books(QObject *parent) : Controller(parent)
{
}

Books::~Books()
{
}

void Books::index(Context *c)
{
    c->response()->body() = "Matched Controller::Books in Books.";
}

void Books::list(Context *c)
{
    // c is the Cutelyst::Context that's used to 'glue together'
    // the various components that make up the application

    // Retrieve all of the book records as book model objects and store in the
    // stash where they can be accessed by the Grantlee template
    // c->setStash("books", sql result);
    // But, for now, use this code until we create the model later
    QSqlQuery query = CPreparedSqlQueryThreadForDB("SELECT * FROM book", "MyDB");
    if (query.exec()) {
        c->setStash("books", Sql::queryToHashList(query));
    }

    // Set the Grantlee template to use. You will almost always want to do this
    // in your action methods (action methods respond to user input in
    // your controllers).
    c->setStash("template", "books/list.html");
}

void Books::base(Context *c)
{
    // Print a message to the debug log
    qDebug("*** INSIDE BASE METHOD ***");
}

void Books::url_create(Context *c, const QString &title, const QString &rating, const QString &authorId)
{
    // In addition to context, get the title, rating, &
    // author_id args from the URL. Note that Cutelyst automatically
    // puts extra information after the "/<controller_name>/<action_name/"
    // as QStrings.  The args are separated  by the '/' char on the URL.

    // Insert the book into it's table
    QSqlQuery query = CPreparedSqlQueryThreadForDB("INSERT INTO book (title, rating) VALUES (:title, :rating)", "MyDB");
    query.bindValue(":title", title);
    query.bindValue(":rating", rating);
    int bookId = 0;
    bool error = true;
    if (query.exec()) {
        bookId = query.lastInsertId().toInt();

        query = CPreparedSqlQueryThreadForDB("INSERT INTO book_author (book_id, author_id) VALUES (:book_id, :author_id)", "MyDB");
        query.bindValue(":book_id", bookId);
        query.bindValue(":author_id", authorId);
        if (query.exec()) {
            error = false;
        }
    }

    // On error show the last one
    if (error) {
        c->stash()["error_msg"] = query.lastError().text();
    }

    QVariantHash book;
    book["title"] = title;
    book["rating"] = rating;

    // Assign the Book object to the stash for display and set template
    c->stash({
                 {"book", book},
                 {"template", "books/create_done.html"}
             });

    // Disable caching for this page
    c->response()->setHeader("Cache-Control", "no-cache");
}

void Books::form_create(Context *c)
{
    // Set the Grantlee Template to use
    c->setStash("template", "books/form_create.html");
}

void Books::form_create_do(Context *c)
{
    // Retrieve the values from the form
    QString title = c->request()->param("title", "N/A");
    QString rating = c->request()->param("rating", "N/A");
    QString authorId = c->request()->param("author_id", "1");

    // Insert the book into it's table
    QSqlQuery query = CPreparedSqlQueryThreadForDB("INSERT INTO book (title, rating) VALUES (:title, :rating)", "MyDB");
    query.bindValue(":title", title);
    query.bindValue(":rating", rating);
    int bookId = 0;
    bool error = true;
    if (query.exec()) {
        bookId = query.lastInsertId().toInt();

        query = CPreparedSqlQueryThreadForDB("INSERT INTO book_author (book_id, author_id) VALUES (:book_id, :author_id)", "MyDB");
        query.bindValue(":book_id", bookId);
        query.bindValue(":author_id", authorId);
        if (query.exec()) {
            error = false;
        }
    }

    // On error show the last one
    if (error) {
        c->stash()["error_msg"] = query.lastError().text();
    }

    // Assign the Book object to the stash for display and set template
    c->stash({
                 {"book", QVariant::fromValue(c->request()->params())},
                 {"template", "books/create_done.html"}
             });
}

