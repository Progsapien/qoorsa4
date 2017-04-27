#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QListWidgetItem>
#include <QFileDialog>
#include "circularlist.h"
#include <QDebug>
#include "button.h"

class Player : public QWidget
{
    Q_OBJECT

public:
    Player(QWidget *parent = 0);
    ~Player();
private:
    CircularList *ob_circ_list;

    QListWidget *ob_list_playlist;

    QPushButton *ob_button_next,
                *ob_button_prev,
                *ob_button_play,
                *ob_button_stop,
                *ob_button_playlist,
                *ob_button_open;

    QVBoxLayout *ob_vbox_main;

    QHBoxLayout *ob_hbox_controls_buttons;

    QLabel *ob_label_track;
};

#endif // PLAYER_H
