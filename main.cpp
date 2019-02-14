#include <QApplication>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include "dialog.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
