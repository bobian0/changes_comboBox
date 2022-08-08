#ifndef PAGE_2_H
#define PAGE_2_H


#include <QWidget>

namespace Ui {
class page_2;
}

class page_2 : public QWidget
{
    Q_OBJECT

public:
    explicit page_2(QWidget *parent = nullptr);
    ~page_2();

private:
    Ui::page_2 *ui;
};

#endif // PAGE_2_H
