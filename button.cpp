#include "button.h"
#include <QDebug>

Button::Button()
{
    // create objects;

    ob_timer_animator = new QTimer;

    old_opacity = 1;
    new_opacity = 1;

    // config;

    connect(ob_timer_animator,SIGNAL(timeout()),SLOT(onTimer()));

    setText("<p align='center'><img src=':/res/play-button.png'></p>");
}

void Button::onTimer() {

    if(old_opacity != new_opacity) {
        if(new_opacity > old_opacity) {
            old_opacity += 0.01;
        } else {
            old_opacity -= 0.01;
        }
    } else {
        ob_timer_animator->stop();
    }
    qDebug() << old_opacity << " " << new_opacity;
    setStyleSheet("border: 1px solid rgba(0,0,0,"+QString::number(old_opacity)+"); background: rgba(0,0,0,"+QString::number(old_opacity)+"); border-radius: 4px;");
}

void Button::setBackgroundOpacity(qreal opacity) {
    new_opacity = opacity;
    if(ob_timer_animator->isActive()) {
        ob_timer_animator->stop();
    }
    ob_timer_animator->start(1);
}

void Button::leaveEvent(QEvent *event) {
    event->accept();
    setBackgroundOpacity(0);
}

void Button::enterEvent(QEvent *event) {
    event->accept();
    setBackgroundOpacity(0.5);
}

void Button::mousePressEvent(QMouseEvent *event) {
    event->accept();
    setBackgroundOpacity(0.6);
}

void Button::mouseReleaseEvent(QMouseEvent *event) {
    event->accept();
    setBackgroundOpacity(0.5);
}
