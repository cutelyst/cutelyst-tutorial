#ifndef AUTHSTORESQL_H
#define AUTHSTORESQL_H

#include <Cutelyst/Plugins/Authentication/authenticationstore.h>

using namespace Cutelyst;

class AuthStoreSql : public AuthenticationStore
{
public:
    explicit AuthStoreSql(QObject *parent = 0);

    virtual AuthenticationUser findUser(Context *c, const ParamsMultiMap &userinfo);

private:
    QString m_idField;
};

#endif // AUTHSTORESQL_H

