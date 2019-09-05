#ifndef GOTOGROUPDIALOGUE_H
#define GOTOGROUPDIALOGUE_H

#include <QDialog>

namespace Ui {
class gotogroupdialogue;
}

class gotogroupdialogue : public QDialog
{
    Q_OBJECT

public:
    explicit gotogroupdialogue(QWidget *parent = nullptr);
    ~gotogroupdialogue();

private slots:
    void on_Go_clicked();

private:
    Ui::gotogroupdialogue *ui;
};

#endif // GOTOGROUPDIALOGUE_H
