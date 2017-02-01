#include "login.h"

#include <Cutelyst/Plugins/Authentication/authentication.h>

using namespace Cutelyst;

Login::Login(QObject *parent) : Controller(parent)
{
}

Login::~Login()
{
}

void Login::index(Context *c)
{
    // Get the username and password from form
    QString username = c->request()->param("username");
    QString password = c->request()->param("password");

    // If the username and password values were found in form
    if (!username.isNull() && !password.isNull()) {
        // Attempt to log the user in
        if (Authentication::authenticate(c, { {"username", username}, {"password", password} })) {
            // If successful, then let them use the application
            c->response()->redirect(c->uriFor(c->controller("Books")->actionFor("list")));
            return;
        } else {
            // Set an error message
            c->setStash("error_msg", "Bad username or password.");
        }
    } else if (!Authentication::userExists(c)) {
        // Set an error message
        c->setStash("error_msg", "Empty username or password.");
    }

    // If either of above don't work out, send to the login page
    c->setStash("template", "login.html");
}

