#ifndef BUTTON_H
#define BUTTON_H

#include <QLabel>
#include <QMouseEvent>
#include <QPixmap>

class button : public QLabel
{
    Q_OBJECT
public:
    button(QWidget *parent = nullptr);
protected:
    bool is_already_pressed;
    QPixmap m_pressed_pixmap, m_released_pixmap;
protected:

    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

signals:
    void clicked();
public slots:
    void setPixmaps(const QPixmap &released, const QPixmap &pressed);
};

#endif // BUTTON_H
