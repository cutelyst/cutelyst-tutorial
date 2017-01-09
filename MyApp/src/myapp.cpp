#include "myapp.h"

#include <Cutelyst/Plugins/StaticSimple/staticsimple.h>

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

    return true;
}

