#ifndef SITE_H
#define SITE_H

#include <Cutelyst/Controller>

using namespace Cutelyst;

class Site : public Controller
{
    Q_OBJECT
public:
    explicit Site(QObject *parent = 0);
    ~Site();

    C_ATTR(index, :Path :Args(0))
    void index(Context *c);

    C_ATTR(test, :Local)
    void test(Context *c) {
        c->stash({
                     {"username", "John"},
                     {"template", "site/test.html"}
                 });
    }
};

#endif //SITE_H

