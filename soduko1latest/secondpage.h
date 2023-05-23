#ifndef SECONDPAGE_H
#define SECONDPAGE_H

#include <QDialog>
#include "thirdpage.h"
namespace Ui {
class secondpage;
}

class secondpage : public QDialog
{
    Q_OBJECT

public:
    explicit secondpage(QWidget *parent = nullptr);
    ~secondpage();

private slots:
    void on_submitbtn_clicked();

private:
    Ui::secondpage *ui;
    thirdpage *third;
};

#endif // SECONDPAGE_H
