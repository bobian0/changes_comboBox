#include "widget.h"
#include "ui_widget.h"
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QStringList list;
        list << "1" << "2" << "3" << "4" << "5" << "6" << "7";
        ui->comboBox->addItems(list);
        ui->comboBox_2->addItems(list);
        ui->comboBox_3->addItems(list);
        ui->comboBox_4->addItems(list);
        ui->comboBox_5->addItems(list);
        ui->comboBox_6->addItems(list);
        ui->comboBox_7->addItems(list);
        // 安装事件过滤器
        ui->atla_1->installEventFilter(this);
        ui->atla1_2->installEventFilter(this);
        ui->atla1_3->installEventFilter(this);
        ui->atla1_4->installEventFilter(this);
        ui->atla1_5->installEventFilter(this);
        ui->atla1_6->installEventFilter(this);
        ui->atla1_7->installEventFilter(this);
}

bool Widget::eventFilter(QObject *obj, QEvent *event)
{
    //指定Label
    if (obj == ui->atla_1|| obj == ui->atla1_2|| obj == ui->atla1_3|| obj == ui->atla1_4|| obj == ui->atla1_5|| obj == ui->atla1_6|| obj == ui->atla1_7)
    {
        if (event->type() == QEvent::MouseButtonPress) //鼠标点击
        {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event); // 事件转换

            if (mouseEvent->button() == Qt::LeftButton)
            {
                qDebug() << obj->objectName();
                auto num = obj->objectName().split("_");
                QList<QWidget*> objectList = this->findChildren<QWidget*>();//获取所有子控件
                foreach(QWidget* control, objectList)
                {
                    if (control->inherits("QComboBox"))
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
        // pass the event on to the parent class
        return QWidget::eventFilter(obj, event);
    }
}

Widget::~Widget()
{
    delete ui;
}

