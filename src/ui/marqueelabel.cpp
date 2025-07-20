#include "marqueelabel.h"
#include <QFontMetrics>

MarqueeLabel::MarqueeLabel(QWidget *parent)
    : QLabel(parent), m_scrollOffset(0), m_speed(1)
{
    connect(&m_timer, &QTimer::timeout, this, &MarqueeLabel::updateScroll);
}

MarqueeLabel::~MarqueeLabel()
{
    m_timer.stop();
}

void MarqueeLabel::setSpeed(int speed)
{
    m_speed = qMax(1, speed); // Assurer une vitesse minimale de 1
}

void MarqueeLabel::updateScroll()
{
    m_scrollOffset -= m_speed;
    update(); // Demander une nouvelle peinture
}

void MarqueeLabel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    QFontMetrics fm(font());
    int textWidth = fm.horizontalAdvance(text());

    // Si le texte est plus court que le label, on utilise le rendu par défaut
    if (textWidth <= width()) {
        QLabel::paintEvent(event);
        return;
    }

    // Réinitialiser la position quand le texte a fini de défiler
    if (m_scrollOffset <= -textWidth) {
        m_scrollOffset = 0;
    }

    // Dessiner le texte deux fois pour une boucle fluide
    int y = (height() + fm.ascent() - fm.descent()) / 2;
    painter.drawText(m_scrollOffset, y, text());
    painter.drawText(m_scrollOffset + textWidth + 50, y, text()); // +50 pour un espace
}

void MarqueeLabel::resizeEvent(QResizeEvent *event)
{
    QLabel::resizeEvent(event);
    m_scrollOffset = 0;
    updateAnimationState();
}

void MarqueeLabel::showEvent(QShowEvent *event)
{
    QLabel::showEvent(event);
    updateAnimationState();
}

void MarqueeLabel::updateAnimationState()
{
    QFontMetrics fm(font());
    int textWidth = fm.horizontalAdvance(text());

    if (textWidth > width()) {
        if (!m_timer.isActive()) {
            m_timer.start(30); // Démarrer l'animation (30ms pour la fluidité)
        }
    } else {
        m_timer.stop(); // Arrêter si pas nécessaire
    }
    update();
}
