#ifndef PROFILEDIALOGUE_H
#define PROFILEDIALOGUE_H

#include <QDialog>

namespace Ui {
class profiledialogue;
}

class profiledialogue : public QDialog
{
    Q_OBJECT

public:
    explicit profiledialogue(QWidget *parent = nullptr);
    ~profiledialogue();

private slots:
    void on_newpost_clicked();

    void on_updateprofile_clicked();


    void on_pushButton_clicked();

private:
    Ui::profiledialogue *ui;
};

#endif // PROFILEDIALOGUE_H
