#include "myapp.h"

#include <Cutelyst/Plugins/StaticSimple/staticsimple.h>
#include <Cutelyst/Plugins/View/Grantlee/grantleeview.h>

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

    auto view = new GrantleeView(this);
    view->setIncludePaths({ pathTo({ "root", "src" }) });

    return true;
}

