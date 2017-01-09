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

