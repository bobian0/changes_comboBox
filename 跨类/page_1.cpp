#include "page_1.h"
#include "ui_page_1.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QComboBox>
#include <QDebug>
#include <QMouseEvent>
#include <QStringList>

page_1::page_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page_1)
{
    ui->setupUi(this);
}

page_1::~page_1()
{
    delete ui;
}

