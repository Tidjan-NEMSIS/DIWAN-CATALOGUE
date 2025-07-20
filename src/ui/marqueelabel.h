#ifndef MARQUEELABEL_H
#define MARQUEELABEL_H

#include <QLabel>
#include <QTimer>
#include <QPainter>

class MarqueeLabel : public QLabel
{
    Q_OBJECT

public:
    explicit MarqueeLabel(QWidget *parent = nullptr);
    ~MarqueeLabel();

    void setSpeed(int speed); // Vitesse en pixels par mise à jour

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void showEvent(QShowEvent *event) override;

private slots:
    void updateScroll();

private:
    void updateAnimationState();
    QTimer m_timer;
    int m_scrollOffset;
    int m_speed;
};

#endif // MARQUEELABEL_H
       