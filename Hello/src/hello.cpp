#include "hello.h"

#include <Cutelyst/Plugins/StaticSimple/staticsimple.h>
#include <Cutelyst/Plugins/View/Grantlee/grantleeview.h>

#include "root.h"
#include "site.h"

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
    new Site(this);

    new StaticSimple(this);

    new GrantleeView(this);

    return true;
}

