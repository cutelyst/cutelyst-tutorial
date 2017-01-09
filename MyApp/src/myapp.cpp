#include "myapp.h"

#include <Cutelyst/Plugins/StaticSimple/staticsimple.h>
#include <Cutelyst/Plugins/View/Grantlee/grantleeview.h>
#include <Cutelyst/Plugins/Utils/Sql>

#include <QtSql>
#include <QDebug>

#include "root.h"
#include "books.h"

using namespace Cutelyst;

MyApp::MyApp(QObject *parent) : Application(parent)
{
}

MyApp::~MyApp()
{
}

bool MyApp::init()
{
    new Root(this);

    new Books(this);

    new StaticSimple(this);

    auto view = new GrantleeView(this);
    view->setIncludePaths({ pathTo({ "root", "src" }) });

    return true;
}

bool MyApp::postFork()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", Sql::databaseNameThread("MyDB"));
    db.setDatabaseName("myapp.db");
    db.setConnectOptions("foreign_keys = ON");
    if (!db.open()) {
        qCritical() << "Failed to open database:" << db.lastError().text();
        return false;
    }
    return true;
}

