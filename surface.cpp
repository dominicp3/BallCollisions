#include "surface.h"
#include "dialog.h"
#include "arrow.h"
#include <cmath>

Surface::Surface(int frameWidth, int frameHeight) :
    m_frameWidth(frameWidth),
    m_frameHeight(frameHeight) {}

Surface::Surface(std::vector<Ball*> balls, int frameWidth, int frameHeight) :
    m_balls(balls),
    m_frameWidth(frameWidth),
    m_frameHeight(frameHeight) {}

void Surface::renderSurface(QPainter& painter) {

    unsigned long long size = m_graph.size();

    for (unsigned int i = 0; i < size; i++) {
        if (ballsColide(m_graph[i]->a, m_graph[i]->b)) {
            setCollisionVelocity(m_graph[i]->a, m_graph[i]->b);
        }
    }

    for (unsigned int i = 0; i < m_balls.size(); i++) {
        m_balls[i]->wallCollision(m_frameWidth, m_frameHeight);
        m_balls[i]->move();
        m_balls[i]->render(painter);
    }
}

void Surface::addBall(Ball *ball) {
    m_balls.push_back(ball);
    unsigned long long size = m_balls.size();
    if (size > 1) {
        for (unsigned int i = 0; i < size - 1; i++) {
            m_graph.push_back(new TwoBalls(m_balls[i], ball));
        }
    }
}

bool Surface::ballsColide(Ball *a, Ball *b) {
    Arrow diff = minus(a->getCentre(), b->getCentre());
    return magnitude(diff) <= a->getRadius() + b->getRadius();
}

void Surface::setCollisionVelocity(Ball *a, Ball *b) {

    Arrow aCentre = reflectHoriztonal(a->getCentre());
    Arrow bCentre = reflectHoriztonal(b->getCentre());

    Arrow x1_2 = minus(aCentre, bCentre);
    Arrow x2_1 = negate(x1_2);

    double m12 = magnitudeSq(x1_2);

    Arrow v1_2 = minus(a->getVelocity(), b->getVelocity());

    double cT = 2 * b->getMass() * dotProduct(v1_2, x1_2) /
            ( (a->getMass() + b->getMass()) * m12);

    double cB = 2 * a->getMass() * dotProduct(v1_2, x1_2) /
            ( (a->getMass() + b->getMass()) * m12);

    x1_2.scale(cT);
    x2_1.scale(cB);

    a->setVelocity(minus(a->getVelocity(), x1_2));
    b->setVelocity(minus(b->getVelocity(), x2_1));
}

double magnitude(const Arrow &v) {
    return sqrt(pow(v.x, 2) + pow(v.y, 2));
}

double magnitudeSq(const Arrow &v) {
    return pow(v.x, 2) + pow(v.y, 2);
}

double dotProduct(const Arrow &v, const Arrow &w) {
    return v.x*w.x + v.y*w.y;
}

Arrow minus(const Arrow &v, const Arrow &w) {
    return Arrow(v.x - w.x, v.y - w.y);
}

Arrow negate(const Arrow &v) {
    return Arrow(-v.x, -v.y);
}

Arrow reflectHoriztonal(const Arrow &v) {
    return Arrow(v.x, - v.y);
}
