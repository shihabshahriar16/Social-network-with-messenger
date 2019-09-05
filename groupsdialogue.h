#ifndef GROUPSDIALOGUE_H
#define GROUPSDIALOGUE_H

#include <QDialog>

namespace Ui {
class groupsdialogue;
}

class groupsdialogue : public QDialog
{
    Q_OBJECT

public:
    explicit groupsdialogue(QWidget *parent = nullptr);
    ~groupsdialogue();

private slots:
    void on_creategroup_clicked();

    void on_joingroup_clicked();

    void on_gogroup_clicked();

private:
    Ui::groupsdialogue *ui;
};

#endif // GROUPSDIALOGUE_H
