#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QListWidgetItem>
#include "circularlist.h"
#include <QDebug>

class Player : public QWidget
{
    Q_OBJECT

public:
    Player(QWidget *parent = 0);
    ~Player();
private:
    CircularList *ob_circ_list;

};

#endif // PLAYER_H
