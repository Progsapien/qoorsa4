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
        current = first;
        current->next = first;
    }

    List *old_next = current->next;
    current->next = new_item;
    new_item->str = str;
    new_item->next = old_next;
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

    if(remove_item == first) {
        first = remove_item->next;
    }

    current->next = remove_item->next;

    delete remove_item;
    next();

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

int CircularList::pos() {
    int pos = 0;

    if(!isEmpty()) {
        List *new_current = first;

        while(new_current != current) {
            new_current = new_current->next;
            pos++;
        }
    } else {
        return -1;
    }

    return pos;
}

CircularList::~CircularList() {
    while(!isEmpty()) {
        pop();
    }
}
