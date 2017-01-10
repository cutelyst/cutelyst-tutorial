#ifndef ROOT_H
#define ROOT_H

#include <Cutelyst/Controller>

using namespace Cutelyst;

class Root : public Controller
{
    Q_OBJECT
    C_NAMESPACE("")
public:
    explicit Root(QObject *parent = 0);
    ~Root();

    C_ATTR(index, :Path :Args(0))
    void index(Context *c);

    C_ATTR(defaultPage, :Path)
    void defaultPage(Context *c);

private:
    /**
     * Check if there is a user and, if not, forward to login page
     */
    C_ATTR(Auto, :Private)
    bool Auto(Context *c);

    C_ATTR(End, :ActionClass("RenderView"))
    void End(Context *c) { Q_UNUSED(c); }
};

#endif //ROOT_H

