#ifndef SURFACE_H
#define SURFACE_H

#include <vector>
#include "arrow.h"
#include "ball.h"

double magnitude(const Arrow &v);
double magnitudeSq(const Arrow &v);
double dotProduct(const Arrow &v, const Arrow &w);
Arrow add(const Arrow &v, const Arrow &w);
Arrow minus(const Arrow &v, const Arrow &w);
Arrow negate(const Arrow &v);
Arrow reflectHoriztonal(const Arrow &v);

class Surface {
public:
    Surface(int frameWidth, int frameHeight);
    Surface(std::vector<Ball*> balls, int frameWidth, int frameHeight);
    void addBall(Ball *b);
    void renderSurface(QPainter &painter);
    void startAnimation();
    bool ballsColide(Ball *a, Ball *b);
    void render(Ball *ball, QPainter &paint);
    void setCollisionVelocity(Ball *a, Ball *b);

private:
    typedef struct TwoBalls {
        TwoBalls(Ball *a, Ball *b) : a(a), b(b) {}
        Ball* a;
        Ball* b;
    } TwoBalls;
    std::vector<Ball*> m_balls;
    int m_frameWidth;
    int m_frameHeight;
    std::vector<TwoBalls*> m_graph;
};

#endif // SURFACE_H
