#ifndef SHOWMEMBERSDIALOGUE_H
#define SHOWMEMBERSDIALOGUE_H

#include <QDialog>

namespace Ui {
class showmembersdialogue;
}

class showmembersdialogue : public QDialog
{
    Q_OBJECT

public:
    explicit showmembersdialogue(QWidget *parent = nullptr);
    ~showmembersdialogue();

private:
    Ui::showmembersdialogue *ui;
};

#endif // SHOWMEMBERSDIALOGUE_H
