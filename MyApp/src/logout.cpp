#include "logout.h"

#include <Cutelyst/Plugins/Authentication/authentication.h>

using namespace Cutelyst;

Logout::Logout(QObject *parent) : Controller(parent)
{
}

Logout::~Logout()
{
}

void Logout::index(Context *c)
{
    // Clear the user's state
    Authentication::logout(c);

    // Send the user to the starting point
    c->response()->redirect(c->uriFor("/"));
}

