#ifndef SIGNUPDIALOGUE_H
#define SIGNUPDIALOGUE_H

#include <QDialog>

namespace Ui {
class signupdialogue;
}

class signupdialogue : public QDialog
{
    Q_OBJECT

public:
    explicit signupdialogue(QWidget *parent = nullptr);
    ~signupdialogue();

private slots:
    void on_pushButton_clicked();

private:
    Ui::signupdialogue *ui;
};

#endif // SIGNUPDIALOGUE_H
