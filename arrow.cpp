#include "arrow.h"
#include <cmath>
#include <iostream>

Arrow::Arrow(double x, double y) :
    x(x),
    y(y) {}

void Arrow::scale(double scale) {
    x *= scale;
    y *= scale;
}

void Arrow::rotate(double angle) {
    double a = x;
    double b = y;
    x = a*cos(angle) - b*sin(angle);
    y = a*sin(angle) + b*cos(angle);
}

void Arrow::printArrow() const {
    std::cout << "m_x: " << x << std::endl;
    std::cout << "m_y: " << y << std::endl;
}
