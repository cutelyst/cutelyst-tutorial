#ifndef BOOKS_H
#define BOOKS_H

#include <Cutelyst/Controller>

using namespace Cutelyst;

class Books : public Controller
{
    Q_OBJECT
public:
    explicit Books(QObject *parent = 0);
    ~Books();

    C_ATTR(index, :Path :Args(0))
    void index(Context *c);

    /**
     * Fetch all book objects and pass to books/list.html in stash to be displayed
     */
    C_ATTR(list, :Local)
    void list(Context *c);
};

#endif //BOOKS_H

