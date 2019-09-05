#ifndef INAGROUPDIALOGUE_H
#define INAGROUPDIALOGUE_H

#include <QDialog>

namespace Ui {
class inagroupdialogue;
}

class inagroupdialogue : public QDialog
{
    Q_OBJECT

public:
    explicit inagroupdialogue(QWidget *parent = nullptr);
    ~inagroupdialogue();

private slots:
    void on_post_clicked();

    void on_show_clicked();

    void on_leave_clicked();

private:
    Ui::inagroupdialogue *ui;
};

#endif // INAGROUPDIALOGUE_H
