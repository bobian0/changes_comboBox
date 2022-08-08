#pragma once

#include <QtWidgets/QWidget>
#include "ui_Atlas.h"
#include <QMouseEvent>
class Atlas : public QWidget
{
    Q_OBJECT

public:
    Atlas(QWidget *parent = Q_NULLPTR);
	bool eventFilter(QObject *obj, QEvent *event);	// 添加时间过滤器声明
private:
    Ui::AtlasClass ui;
};
