#ifndef SIGNINDIALOGUE_H
#define SIGNINDIALOGUE_H

#include <QDialog>

namespace Ui {
class signindialogue;
}

class signindialogue : public QDialog
{
    Q_OBJECT

public:
    explicit signindialogue(QWidget *parent = nullptr);
    ~signindialogue();

private slots:
    void on_pushButton_clicked();

private:
    Ui::signindialogue *ui;
};

#endif // SIGNINDIALOGUE_H
