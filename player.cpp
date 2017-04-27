#include "player.h"

Player::Player(QWidget *parent)
    : QWidget(parent)
{

    // create objects;

    ob_circ_list = new CircularList;

    ob_button_next = new QPushButton(QIcon(":/res/next.png"), "Следующий");
    ob_button_open = new QPushButton(QIcon(":/res/open.png"), "Открыть");
    ob_button_play = new QPushButton(QIcon(":/res/play-button.png"), "Воспроизвести");
    ob_button_prev = new QPushButton(QIcon(":/res/prev.png"), "Предыдущий");
    ob_button_stop = new QPushButton(QIcon(":/res/stop.png"),"Стоп");
    ob_button_playlist = new QPushButton(QIcon(":/res/list.png"), "Плейлист");

    ob_vbox_main = new QVBoxLayout;
    ob_hbox_controls_buttons = new QHBoxLayout;

    ob_list_playlist = new QListWidget;

    ob_label_track = new QLabel;

    // config;

    setLayout(ob_vbox_main);

    ob_vbox_main->addWidget(ob_label_track);
    ob_vbox_main->addLayout(ob_hbox_controls_buttons);
    ob_vbox_main->addWidget(ob_list_playlist);

    ob_hbox_controls_buttons->addWidget(ob_button_open);
    ob_hbox_controls_buttons->addWidget(ob_button_prev);
    ob_hbox_controls_buttons->addWidget(ob_button_play);
    ob_hbox_controls_buttons->addWidget(ob_button_next);
    ob_hbox_controls_buttons->addWidget(ob_button_stop);
    ob_hbox_controls_buttons->addWidget(ob_button_playlist);

    ob_label_track->setMinimumHeight(200);

    ob_list_playlist->hide();

    ob_button_play->setIconSize(QSize(32,32));
    ob_button_next->setIconSize(ob_button_play->iconSize());
    ob_button_open->setIconSize(ob_button_play->iconSize());
    ob_button_playlist->setIconSize(ob_button_play->iconSize());
    ob_button_prev->setIconSize(ob_button_play->iconSize());
    ob_button_stop->setIconSize(ob_button_play->iconSize());
}

Player::~Player()
{

}
