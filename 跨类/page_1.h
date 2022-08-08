#ifndef PAGE_1_H
#define PAGE_1_H


#include <QWidget>

namespace Ui {
class page_1;
}

class page_1 : public QWidget
{
    Q_OBJECT

public:
    explicit page_1(QWidget *parent = nullptr);
    ~page_1();

    Ui::page_1 *ui;



private:
//    Ui::page_1 *ui;
};

#endif // PAGE_1_H
