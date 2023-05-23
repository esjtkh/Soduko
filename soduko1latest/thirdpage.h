#ifndef THIRDPAGE_H
#define THIRDPAGE_H

#include <QDialog>
#include"fourth.h"
namespace Ui {
class thirdpage;
}

class thirdpage : public QDialog
{
    Q_OBJECT

public:
    explicit thirdpage(QWidget *parent = nullptr);
    ~thirdpage();

private slots:
    void on_tableWidget_cellChanged(int row, int column);

    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::thirdpage *ui;
    fourth *four;
};

#endif // THIRDPAGE_H
