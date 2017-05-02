#include "player.h"

Player::Player(QWidget *parent)
    : QWidget(parent)
{

    // create objects;

    ob_circ_list = new CircularList;

    ob_button_add = new QPushButton("Добавить");
    ob_button_delete = new QPushButton("Удалить");
    ob_button_next = new QPushButton("Следующая запись");

    ob_label_name = new QLabel("Круговой односвязный список");
    ob_label_add = new QLabel("Добавить запись");
    ob_label_controls = new QLabel("Управление списком");

    ob_vbox_main = new QVBoxLayout;
    ob_hbox_controls = new QHBoxLayout;

    ob_line_add = new QLineEdit;

    ob_list_records = new QListWidget;

    // config;

    setLayout(ob_vbox_main);

    ob_vbox_main->addWidget(ob_label_name);
    ob_vbox_main->addWidget(ob_list_records);
    ob_vbox_main->addWidget(ob_label_add);
    ob_vbox_main->addWidget(ob_line_add);
    ob_vbox_main->addWidget(ob_button_add);
    ob_vbox_main->addWidget(ob_label_controls);
    ob_vbox_main->addLayout(ob_hbox_controls);

    ob_hbox_controls->addWidget(ob_button_delete);
    ob_hbox_controls->addWidget(ob_button_next);

    connect(ob_button_add,SIGNAL(clicked()),SLOT(addRecord()));
    connect(ob_button_delete,SIGNAL(clicked()),SLOT(deleteRecord()));
    connect(ob_button_next,SIGNAL(clicked()),SLOT(next()));
}


void Player::addRecord() {
    if(ob_line_add->text().count() != 0) {
        ob_circ_list->push(ob_line_add->text());
        ob_list_records->addItem(ob_line_add->text());
        setAllToBlack();
        ob_list_records->item(ob_circ_list->pos())->setTextColor(QColor(0,200,0));
    }
}

void Player::setAllToBlack() {
    for(int i = 0; i < ob_list_records->count(); i++) {
        ob_list_records->item(i)->setTextColor(QColor(0,0,0));
    }
}

void Player::deleteRecord() {
    ob_list_records->takeItem(ob_circ_list->pos());
    ob_circ_list->pop();
    setAllToBlack();
    ob_list_records->item(ob_circ_list->pos())->setTextColor(QColor(0,200,0));
}

void Player::next() {
    ob_circ_list->next();
    setAllToBlack();
    ob_list_records->item(ob_circ_list->pos())->setTextColor(QColor(0,200,0));
    qDebug() << ob_circ_list->pos();
}


Player::~Player()
{

}
