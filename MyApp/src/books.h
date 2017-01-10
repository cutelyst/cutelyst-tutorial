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

    /**
     * Can place common logic to start chained dispatch here
     */
    C_ATTR(base, :Chained("/") :PathPart("books") :CaptureArgs(0))
    void base(Context *c);

    /**
     * Create a book with the supplied title, rating, and author
     */
    C_ATTR(url_create, :Chained("base") :PathPart("url_create") :Args(3))
    void url_create(Context *c, const QString &title, const QString &rating, const QString &authorId);
};

#endif //BOOKS_H

