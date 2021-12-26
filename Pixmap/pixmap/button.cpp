#include "button.h"

button::button(QWidget *parent):QLabel(parent), is_already_pressed(false)
{

}

void button::setPixmaps(const QPixmap &released, const QPixmap &pressed){
    m_released_pixmap = released;
    m_pressed_pixmap = pressed;

    setPixmap(is_already_pressed ? m_pressed_pixmap : m_released_pixmap);

}

void button::mousePressEvent(QMouseEvent *ev){
    setPixmap(m_pressed_pixmap);
    is_already_pressed = true;

    //QLabel::mousePressEvent(ev);
}

void button::mouseReleaseEvent(QMouseEvent *ev){
    setPixmap(m_released_pixmap);
    if (is_already_pressed == false || ev->pos().x() < 0 || ev->pos().x() >= width() || ev->pos().y() < 0 || ev->pos().y() >= height()){
        QLabel::mouseReleaseEvent(ev);
        return;
    }
    is_already_pressed = false;
    //QLabel::mouseReleaseEvent(ev);

    emit clicked();
}
