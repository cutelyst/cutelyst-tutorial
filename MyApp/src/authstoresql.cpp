#include "authstoresql.h"

#include <Cutelyst/Plugins/Utils/Sql>

#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>

AuthStoreSql::AuthStoreSql(QObject *parent) : AuthenticationStore(parent)
{
    m_idField = "username";
}

AuthenticationUser AuthStoreSql::findUser(Context *c, const ParamsMultiMap &userinfo)
{
    QString id = userinfo[m_idField];

    QSqlQuery query = CPreparedSqlQueryThreadForDB("SELECT * FROM users WHERE username = :username", "MyDB");
    query.bindValue(":username", id);
    if (query.exec() && query.next()) {
        QVariant userId = query.value("id");
        qDebug() << "FOUND USER -> " << userId.toInt();
        AuthenticationUser user(userId.toString());

        int columns = query.record().count();
        // send column headers
        QStringList cols;
        for (int j = 0; j < columns; ++j) {
            cols << query.record().fieldName(j);
        }

        for (int j = 0; j < columns; ++j) {
            user.insert(cols.at(j),
                        query.value(j).toString());
        }

        return user;
    }
    qDebug() << query.lastError().text();

    return AuthenticationUser();
}

