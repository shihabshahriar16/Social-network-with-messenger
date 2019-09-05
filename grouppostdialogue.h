#ifndef GROUPPOSTDIALOGUE_H
#define GROUPPOSTDIALOGUE_H

#include <QDialog>

namespace Ui {
class grouppostdialogue;
}

class grouppostdialogue : public QDialog
{
    Q_OBJECT

public:
    explicit grouppostdialogue(QWidget *parent = nullptr);
    ~grouppostdialogue();

private slots:
    void on_pushButton_clicked();

private:
    Ui::grouppostdialogue *ui;
};

#endif // GROUPPOSTDIALOGUE_H
