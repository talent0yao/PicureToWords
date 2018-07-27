#include "mygraphicsview.h"
#include <QDebug>
#include <QMimeData>
#include <QGraphicsSceneDragDropEvent>
myGraphicsView::myGraphicsView(QWidget *parent):QGraphicsView(parent)
{
    setDragMode(ScrollHandDrag);
    setAcceptDrops(true);

}


void myGraphicsView::dragEnterEvent(QDragEnterEvent *event )
{
    qDebug()<<"dragEvent";
    event->setAccepted( true );
    if(event->mimeData()->hasImage())
    {
        qDebug()<<"dragEvent--";

    }
    else
    {
        event->setAccepted( false );
    }
}
void myGraphicsView::dropEvent(QDragEnterEvent *event)
{
    qDebug()<<"drop";
    m_bOnDrag =  false ;
    if  (event->mimeData()->hasFormat( "nlsdata/items" ))
    {
        QByteArray itemData = event->mimeData()->data( "nlsdata/items" );
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);
        //dataStream >> m_dragType >> m_dragName;
        setAcceptDrops( false );
    }
    update();
}
//bool Widget::readFile(const QString &fileName) //读文件
//{
//    QFile file(fileName);
//    if(!file.open(QFile::ReadOnly))
//          return false;

//    QByteArray data;
//    data = file.readAll();
//    //ui->wordResult->setText(QString::fromLocal8Bit(data));
//    qDebug()<<"readFile:"<<fileName;
//    QImage *img = new QImage(fileName);
//    QPixmap pixmap = QPixmap::fromImage(*img);
//    QGraphicsScene *scene = new QGraphicsScene(this);
//    scene->addPixmap(pixmap);
//    ui->imgPreview->setScene(scene);
//    return true;
//}
