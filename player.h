#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include "circularlist.h"
#include <QDebug>
#include <QLineEdit>

class Player : public QWidget
{
    Q_OBJECT

public:
    Player(QWidget *parent = 0);
    ~Player();
private:
    CircularList *ob_circ_list;

    QListWidget *ob_list_records;

    QPushButton *ob_button_add,
                *ob_button_delete,
                *ob_button_next;

    QVBoxLayout *ob_vbox_main;
    QHBoxLayout *ob_hbox_controls;

    QLabel *ob_label_name,
           *ob_label_add,
           *ob_label_controls;

    QLineEdit *ob_line_add;


    void setAllToBlack(); // set black color to items in list;
private slots:

    void addRecord();
    void deleteRecord();
    void next();
};

#endif // PLAYER_H
