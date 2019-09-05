#ifndef JOINGROUPDIALOGUE_H
#define JOINGROUPDIALOGUE_H

#include <QDialog>

namespace Ui {
class joingroupdialogue;
}

class joingroupdialogue : public QDialog
{
    Q_OBJECT

public:
    explicit joingroupdialogue(QWidget *parent = nullptr);
    ~joingroupdialogue();

private slots:
    void on_join_clicked();

private:
    Ui::joingroupdialogue *ui;
};

#endif // JOINGROUPDIALOGUE_H
