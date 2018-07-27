#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStringList>
#include <QMouseEvent>
#include <QDrag>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include "mygraphicsview.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

//    void mousePressEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);
//    void dragEnterEvent(QDragEnterEvent *e);
//    void dropEvent(QDropEvent *e);
        bool readFile(const QString &fileName);
private slots:
    void on_getImgBtn_clicked();

    void on_convertBtn_clicked();

private:
    Ui::Widget *ui;
    QStringList filename;
};

#endif // WIDGET_H
