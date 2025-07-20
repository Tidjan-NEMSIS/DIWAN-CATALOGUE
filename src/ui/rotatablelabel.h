#ifndef ROTATABLELABEL_H
#define ROTATABLELABEL_H

#include <QLabel>
#include <QPainter>

class RotatableLabel : public QLabel
{
    Q_OBJECT
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation)

public:
    explicit RotatableLabel(QWidget *parent = nullptr);

    qreal rotation() const;
    void setRotation(qreal rotation);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    qreal m_rotation = 0.0;
};

#endif // ROTATABLELABEL_H
