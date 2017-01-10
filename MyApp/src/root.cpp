#include "root.h"

#include <Cutelyst/Plugins/Authentication/authentication.h>

using namespace Cutelyst;

Root::Root(QObject *parent) : Controller(parent)
{
}

Root::~Root()
{
}

void Root::index(Context *c)
{
    c->response()->body() = "Welcome to Cutelyst!";
}

void Root::defaultPage(Context *c)
{
    c->response()->body() = "Page not found!";
    c->response()->setStatus(404);
}

bool Root::Auto(Context *c)
{
    // Allow unauthenticated users to reach the login page.  This
    // allows unauthenticated users to reach any action in the Login
    // controller.  To lock it down to a single action, we could use:
    //   if (c->action() eq c->controller("Login")->actionFor("index"))
    // to only allow unauthenticated access to the 'index' action we
    // added above
    if (c->controller() == c->controller("Login")) {
        return true;
    }

    // If a user doesn't exist, force login
    if (!Authentication::userExists(c)) {
        // Dump a log message to the development server debug output
        qDebug("***Root::Auto User not found, forwarding to /login");

        // Redirect the user to the login page
        c->response()->redirect(c->uriFor("/login"));

        // Return false to cancel 'post-auto' processing and prevent use of application
        return false;
    }

    // User found, so return true to continue with processing after this 'auto'
    return true;
}

