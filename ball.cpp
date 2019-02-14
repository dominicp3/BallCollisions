#include "ball.h"
#include <iostream>

Ball::Ball(double x,
           double y,
           double mass,
           double radius,
           double xv,
           double yv,
           QColor qcolour,
           std::string scolour) :
    m_xCen(x),
    m_yCen(y),
    m_mass(mass),
    m_radius(radius),
    m_xV(xv),
    m_yV(yv),
    m_colour(qcolour),
    m_colourString(scolour) {}

Ball::Ball(Arrow centre,
           double mass,
           double radius,
           Arrow velocity,
           QColor qcolour,
           std::string scolour) :
    m_xCen(centre.x),
    m_yCen(centre.y),
    m_mass(mass),
    m_radius(radius),
    m_xV(velocity.x),
    m_yV(velocity.y),
    m_colour(qcolour),
    m_colourString(scolour) {}


void Ball::render(QPainter &paint) {
    paint.setBrush(QBrush (m_colour));
    paint.drawEllipse(QPoint ((int) m_xCen, (int) m_yCen),
                      (int) m_radius, (int) m_radius);
}

void Ball::reflectH() {
    m_xV *= -1;
}

void Ball::reflectV() {
    m_yV *= -1;
}

void Ball::move() {
    m_xCen += m_xV;
    m_yCen -= m_yV;
}

bool Ball::wallCollision(int width, int height) {

    if ((m_xCen + m_radius >= width && m_xV >= 0)
            || (m_xCen - m_radius <= 0 && m_xV <= 0)) {
        reflectH();
        return true;
    } else if ((m_yCen + m_radius >= height && m_yV <= 0)
               || (m_yCen - m_radius <= 0 && m_yV >= 0)) {
        reflectV();
        return true;
    }

    return false;
}
