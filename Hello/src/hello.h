#ifndef HELLO_H
#define HELLO_H

#include <Cutelyst/Application>

using namespace Cutelyst;

class Hello : public Application
{
    Q_OBJECT
    CUTELYST_APPLICATION(IID "Hello")
public:
    Q_INVOKABLE explicit Hello(QObject *parent = 0);
    ~Hello();

    bool init();
};

#endif //HELLO_H

