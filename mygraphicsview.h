#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H
#include <QGraphicsView>
#include <QDragEnterEvent>

class myGraphicsView:public QGraphicsView
{
public:
    myGraphicsView(QWidget *parent = 0);

    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDragEnterEvent *event);
private:
    bool m_bOnDrag;
};
#endif // MYGRAPHICSVIEW_H
