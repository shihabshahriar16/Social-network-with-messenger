#ifndef CREATEGROUPSDIALOGUE_H
#define CREATEGROUPSDIALOGUE_H

#include <QDialog>

namespace Ui {
class creategroupsdialogue;
}

class creategroupsdialogue : public QDialog
{
    Q_OBJECT

public:
    explicit creategroupsdialogue(QWidget *parent = nullptr);
    ~creategroupsdialogue();

private slots:
    void on_create_clicked();

private:
    Ui::creategroupsdialogue *ui;
};

#endif // CREATEGROUPSDIALOGUE_H
