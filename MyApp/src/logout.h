#ifndef LOGOUT_H
#define LOGOUT_H

#include <Cutelyst/Controller>

using namespace Cutelyst;

class Logout : public Controller
{
    Q_OBJECT
public:
    explicit Logout(QObject *parent = 0);
    ~Logout();

    C_ATTR(index, :Path :Args(0))
    void index(Context *c);
};

#endif //LOGOUT_H

