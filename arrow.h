#ifndef ARROW_H
#define ARROW_H

struct Arrow {

    Arrow(double x = 0, double y = 0);
    void scale(double scale);
    void rotate(double angle);
    void printArrow() const;

    double x;
    double y;

};

#endif // ARROW_H
