#include "player.h"

Player::Player(QWidget *parent)
    : QWidget(parent)
{
    ob_circ_list = new CircularList;

    ob_circ_list->push("qeqe123");
    ob_circ_list->push("12345g23");

    qDebug() << ob_circ_list->size();

    if(!ob_circ_list->isEmpty()) {
        qDebug() << ob_circ_list->element()->str;
    }
    ob_circ_list->pop();
    if(!ob_circ_list->isEmpty()) {
        qDebug() << ob_circ_list->element()->str;
    }
    ob_circ_list->pop();
    if(!ob_circ_list->isEmpty()) {
        qDebug() << ob_circ_list->element()->str;
    }

    ob_circ_list->pop();

    qDebug() << ob_circ_list->size();

}

Player::~Player()
{

}
