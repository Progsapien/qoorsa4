#include "circularlist.h"

CircularList::CircularList(QObject *parent) :
    QObject(parent)
{
    list_size = 0;
    first = NULL;
    current = NULL;
}

void CircularList::push(QString str) {
    List *new_item = new List;

    if(isEmpty()) {
        first = new_item;
    } else {
        current->next = new_item;
    }

    new_item->str = str;
    new_item->next = first;
    current = new_item;
    list_size++;
}

void CircularList::pop() {

    if(isEmpty()) {
        return;
    } else if(current->next == current) {
        delete first;
        current = NULL;
        first = NULL;
        list_size--;
        return;
    }

    List *remove_item = current;
    current = first;

    while(current->next != remove_item) {
        next();
    }

    current->next = remove_item->next;
    delete remove_item;
    list_size--;
}

void CircularList::next() {
    if(isEmpty()) {
        return;
    }
    current = current->next;
}

CircularList::List *CircularList::element() {
    return current;
}

int CircularList::size() {
    return list_size;
}

bool CircularList::isEmpty() {
    return first == NULL;
}

CircularList::~CircularList() {
    while(!isEmpty()) {
        pop();
    }
}
