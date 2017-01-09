#ifndef MYAPP_H
#define MYAPP_H

#include <Cutelyst/Application>

using namespace Cutelyst;

class MyApp : public Application
{
    Q_OBJECT
    CUTELYST_APPLICATION(IID "MyApp")
public:
    Q_INVOKABLE explicit MyApp(QObject *parent = 0);
    ~MyApp();

    bool init();
};

#endif //MYAPP_H

