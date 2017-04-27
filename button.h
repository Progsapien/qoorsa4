#ifndef BUTTON_H
#define BUTTON_H

#include <QLabel>
#include <QTimer>
#include <QEvent>
#include <QMouseEvent>

class Button : public QLabel
{
    Q_OBJECT
public:
    explicit Button();

private:

    QTimer *ob_timer_animator; // Таймер для осуществления анимации
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

    void setBackgroundOpacity(qreal opacity);

    qreal old_opacity,
          new_opacity;

private slots:
    void onTimer();
signals:
    void clicked();
};

#endif // BUTTON_H
