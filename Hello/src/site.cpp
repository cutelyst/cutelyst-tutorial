#include "site.h"

using namespace Cutelyst;

Site::Site(QObject *parent) : Controller(parent)
{
}

Site::~Site()
{
}

void Site::index(Context *c)
{
    c->response()->body() = "Matched Controller::Site in Site.";
}

