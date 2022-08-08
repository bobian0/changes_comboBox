#include "page_2.h"
#include "ui_page_2.h"

page_2::page_2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::page_2)
{
    ui->setupUi(this);
}

page_2::~page_2()
{
    delete ui;
}
