#include "myapp.h"

#include <Cutelyst/Plugins/StaticSimple/staticsimple.h>
#include <Cutelyst/Plugins/View/Grantlee/grantleeview.h>
#include <Cutelyst/Plugins/Utils/Sql>
#include <Cutelyst/Plugins/Session/Session>
#include <Cutelyst/Plugins/Authentication/authentication.h>
#include <Cutelyst/Plugins/Authentication/credentialpassword.h>

#include <QtSql>
#include <QDebug>

#include "root.h"
#include "books.h"

#include "authstoresql.h"

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
    view->setWrapper("wrapper.html");

    new Session(this);

    auto auth = new Authentication(this);
    auto credential = new CredentialPassword;
    credential->setPasswordType(CredentialPassword::Clear);

    auth->addRealm(new AuthStoreSql, credential);

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

