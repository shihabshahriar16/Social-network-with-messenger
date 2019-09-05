#ifndef MENUDIALOGUE_H
#define MENUDIALOGUE_H

#include <QDialog>

namespace Ui {
class menudialogue;
}

class menudialogue : public QDialog
{
    Q_OBJECT

public:
    explicit menudialogue(QWidget *parent = nullptr);
    ~menudialogue();

private slots:
    void on_signin_clicked();

    void on_signup_clicked();

private:
    Ui::menudialogue *ui;
};

#endif // MENUDIALOGUE_H
