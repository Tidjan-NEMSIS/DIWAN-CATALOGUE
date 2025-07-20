#include "rotatablelabel.h"

RotatableLabel::RotatableLabel(QWidget *parent) : QLabel(parent)
{
}

qreal RotatableLabel::rotation() const
{
    return m_rotation;
}

void RotatableLabel::setRotation(qreal rotation)
{
    m_rotation = rotation;
    update(); // Request a repaint
}

void RotatableLabel::paintEvent(QPaintEvent *event)
{
    const auto& px = pixmap();
    if (!px.isNull()) {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setRenderHint(QPainter::SmoothPixmapTransform);

        // Translate to the center of the widget
        painter.translate(width() / 2, height() / 2);
        // Rotate
        painter.rotate(m_rotation);
        // Translate back
        painter.translate(-width() / 2, -height() / 2);

        // Draw the pixmap scaled to the widget size
        painter.drawPixmap(rect(), pixmap());
    } else {
        QLabel::paintEvent(event);
    }
}
