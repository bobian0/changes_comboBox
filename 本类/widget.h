#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    // 添加时间过滤器声明
    bool eventFilter(QObject *obj, QEvent *event);
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
