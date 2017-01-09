#include "hello.h"

#include <Cutelyst/Plugins/StaticSimple/staticsimple.h>

#include "root.h"

using namespace Cutelyst;

Hello::Hello(QObject *parent) : Application(parent)
{
}

Hello::~Hello()
{
}

bool Hello::init()
{
    new Root(this);

    new StaticSimple(this);

    return true;
}

