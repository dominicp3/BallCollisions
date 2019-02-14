#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPainter>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog {
    Q_OBJECT

public:
    explicit Dialog(QWidget* parent = nullptr);
    ~Dialog();
    void paintEvent(QPaintEvent *event);

public slots:
    void nextFrame();

private:
    Ui::Dialog *ui;
    int m_counter = 0;
};

#endif // DIALOG_H
