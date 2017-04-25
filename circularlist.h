#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <QObject>

class CircularList : public QObject
{
    Q_OBJECT
public:
    explicit CircularList(QObject *parent = 0);

    void push(QString str);
    List* pop();

private:
    struct List {
        List *next;
        QString *str;
    };

    List *current, *first;
};

#endif // CIRCULARLIST_H
