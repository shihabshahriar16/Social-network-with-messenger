#ifndef SHOWBIODIALOGUE_H
#define SHOWBIODIALOGUE_H

#include <QDialog>

namespace Ui {
class showbiodialogue;
}

class showbiodialogue : public QDialog
{
    Q_OBJECT

public:
    explicit showbiodialogue(QWidget *parent = nullptr);
    ~showbiodialogue();

private:
    Ui::showbiodialogue *ui;
};

#endif // SHOWBIODIALOGUE_H
