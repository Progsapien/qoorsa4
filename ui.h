#ifndef UI_H
#define UI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include "circularlist.h"
#include <QDebug>
#include <QLineEdit>

class UI : public QWidget
{
    Q_OBJECT

public:
    UI(QWidget *parent = 0);
    ~UI();
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

#endif // UI_H
