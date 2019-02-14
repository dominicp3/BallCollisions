#include "dialog.h"
#include "ui_dialog.h"
#include <QTimer>
#include <QColor>
#include "ball.h"
#include "surface.h"

static int frameWidth = 600;
static int frameHeight = 600;

static Surface surface (frameWidth, frameHeight);

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog) {

    this->setFixedSize(frameWidth, frameHeight);

    surface.addBall(new Ball (Arrow(70, 300), 2, 30, Arrow(9, -5), QColor (Qt::blue)));
    surface.addBall(new Ball (Arrow(550, 270), 5, 40, Arrow(10, -3), QColor (Qt::red)));
    surface.addBall(new Ball (Arrow(300, 100), 2, 30, Arrow(-6, -9), QColor (Qt::cyan)));

    QTimer* timer = new QTimer (this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(32);

    ui->setupUi(this);
}

Dialog::~Dialog() {
    delete ui;
}

void Dialog::nextFrame() {
    update();
}

void Dialog::paintEvent(QPaintEvent *event) {
    QPainter painter (this);
    surface.renderSurface(painter);
}
