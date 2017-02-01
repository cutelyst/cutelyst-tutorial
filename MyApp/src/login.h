#ifndef LOGIN_H
#define LOGIN_H

#include <Cutelyst/Controller>

using namespace Cutelyst;

class Login : public Controller
{
    Q_OBJECT
public:
    explicit Login(QObject *parent = 0);
    ~Login();

    C_ATTR(index, :Path :Args(0))
    void index(Context *c);
};

#endif //LOGIN_H

