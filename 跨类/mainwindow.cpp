#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "page_1.h"
#include "ui_page_1.h"
#include <QPushButton>
#include <QComboBox>
#include <QDebug>
#include <QMouseEvent>
#include <QStringList>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    stackedPage1 = new page_1;

    connect(ui->page1,&QPushButton::clicked,stackedPage1,[=](){
        stackedPage1->show();
        QStringList list;

         list << "1" << "2" << "3" << "4";
         ui->comboBox->addItems(list);
         ui->comboBox_2->addItems(list);
         // 安装事件过滤器
         stackedPage1->ui->bone1_1->installEventFilter(this);
         stackedPage1->ui->bone1_2->installEventFilter(this);
         stackedPage1->ui->bone1_3->installEventFilter(this);
         stackedPage1->ui->bone1_4->installEventFilter(this);
    });




}

MainWindow::~MainWindow()
{
    delete ui;
}






bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    //指定Label
    if (obj == stackedPage1->ui->bone1_1|| obj ==  stackedPage1->ui->bone1_2|| obj == stackedPage1->ui->bone1_3|| obj ==  stackedPage1->ui->bone1_4)
    {
        //鼠标点击
        if (event->type() == QEvent::MouseButtonPress)
        {
            // 事件转换
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            if (mouseEvent->button() == Qt::LeftButton)
            {
                qDebug() << obj->objectName();
                auto num = obj->objectName().split("_");
                //获取所有子控件
                QList<QWidget*> objectList = this->findChildren<QWidget*>();
                foreach(QWidget* control, objectList)
                {
                    if (control->inherits("QComboBox") && control->objectName()=="comboBox")
                    {
                        QComboBox *combox = qobject_cast<QComboBox *>(control);
                        combox->setCurrentIndex(combox->findText(num[1]));
                    }
                }
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        //附加到父类
        return QWidget::eventFilter(obj, event);
    }
}

