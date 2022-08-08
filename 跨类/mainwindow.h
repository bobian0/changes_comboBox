#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "page_1.h"


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

     Ui::MainWindow *ui;

    //点击图片更改comboBox (添加时间过滤器声明)
    bool eventFilter(QObject *obj, QEvent *event);





private:
//    Ui::MainWindow *ui;

    page_1 *stackedPage1;
};
#endif // MAINWINDOW_H
