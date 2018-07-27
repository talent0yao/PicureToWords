#include "widget.h"
#include "ui_widget.h"
#include "ocr.h"
#include "json/json_tool.h"
#include <QString>
#include <string>
#include <QFileDialog>
#include <QDebug>
#include <QImage>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QMessageBox>
#include <QMimeData>
#pragma execution_character_set("utf-8")
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("OCR");
    ui->imgPreview->setAcceptDrops(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_getImgBtn_clicked()
{

    QFileDialog *getImageDialog = new QFileDialog(this,"打开文件","D:","图片文件(*.jpg *.png)");
    //getImageDialog->setFileMode(QFileDialog::FileName);
    if(getImageDialog->exec() == QFileDialog::Accepted)
    {
        filename = getImageDialog->selectedFiles();
        qDebug()<<filename;
        QImage *img = new QImage(filename[0]);
        QPixmap pixmap = QPixmap::fromImage(*img);
        QGraphicsScene *scene = new QGraphicsScene(this);
        scene->addPixmap(pixmap);
        ui->imgPreview->setScene(scene);
    }
    else
    {
        qDebug()<<"reject";
    }



}

void Widget::on_convertBtn_clicked()
{

    if(filename.isEmpty())
    {
        QMessageBox::warning(this,"提示","请先选择图片");
        return;
    }

    // 读取配置文件
    QString path = QCoreApplication::applicationDirPath();
    path += "/config.ini";
    QSettings *settings = new QSettings(path,QSettings::IniFormat);
    settings->beginGroup("config");
    QString appid = settings->value("app_id").toString();
    QString apikey = settings->value("api_key").toString();
    QString secretkey = settings->value("secret_key").toString();

    std::string app_id =appid ;
    std::string api_key = apikey;
    std::string secret_key = secretkey;
    aip::Ocr client(app_id, api_key, secret_key);
    Json::Value result;

    std::string image;
    std::string file = filename[0].toStdString();
    aip::get_file_content(file.c_str(), &image);

    // 调用通用文字识别, 图片参数为本地图片
    result = client.general_basic(image, aip::null);
    Json::Value wordsRes = result["words_result"];
    Json::Value wordsnum = result["words_result_num"];
    int wordsNum = wordsnum.asInt();

    QStringList wordsList;
    for(int i = 0;i<wordsNum;++i)
    {
        Json::Value word = wordsRes[i]["words"];
        std::string word_str = word.asString();
        QString word_qstr = QString(QString::fromStdString(word_str));
        wordsList.push_back(word_qstr);
        qDebug()<<word_qstr;
    }
    qDebug()<<"end";
    QString text = wordsList.join("\n");
    ui->wordResult->setText(text);
}

