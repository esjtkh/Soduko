#ifndef FOURTH_H
#define FOURTH_H

#include <QWidget>

namespace Ui {
class fourth;
}

class fourth : public QWidget
{
    Q_OBJECT

public:
    explicit fourth(QWidget *parent = nullptr);
    ~fourth();


    Ui::fourth *ui;
};

#endif // FOURTH_H
