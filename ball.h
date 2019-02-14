#ifndef BALL_H
#define BALL_H

#include <QPainter>
#include <string>
#include "arrow.h"

class Ball {
public:
    Ball(double x,
         double y,
         double m = 1,
         double r = 20,
         double xv = 0,
         double yv = 0,
         QColor c = Qt::black,
         std::string color = "");

    Ball(Arrow centre,
         double m = 1,
         double r = 20,
         Arrow velocity = Arrow(0, 0),
         QColor c = Qt::black,
         std::string color = "");

    void render(QPainter &paint);
    void renderVect(QPainter paint, QPen& pen);

    void collision(int frameX, int frameY);

    void reflectH();
    void reflectV();

    void move();
    bool wallCollision(int w, int h);

    Arrow getCentre() const {return Arrow(m_xCen, m_yCen);}
    Arrow getVelocity() const {return Arrow(m_xV, m_yV);}
    double getMass() const {return m_mass;}
    QColor getColour() const {return m_colour;}
    std::string getColourString() const {return m_colourString;}
    double getRadius() const {return m_radius;}

    void setVelocity(double x, double y) {m_xV = x; m_yV = y;}
    void setVelocity(Arrow v) {m_xV = v.x; m_yV = v.y;}

private:
    double m_xCen;
    double m_yCen;
    double m_mass;
    double m_radius;
    double m_xV;
    double m_yV;
    QColor m_colour;
    std::string m_colourString;

};

#endif // BALL_H
