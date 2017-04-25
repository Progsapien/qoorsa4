#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <QObject>
#include <QDebug>

class CircularList : public QObject
{

    Q_OBJECT

public:

    explicit CircularList(QObject *parent = 0);
    ~CircularList();

    struct List {
        List *next;
        QString str;
    };


    void push(QString str);

    void pop();
    List* top();
    void next();
    List* element();

    int size();
    bool isEmpty();

private:
    List *current, *first;
    int list_size;

};

#endif // CIRCULARLIST_H
