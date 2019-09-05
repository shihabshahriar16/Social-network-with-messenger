#ifndef NEWFRIEND_DIALOG_H
#define NEWFRIEND_DIALOG_H

#include <QDialog>

namespace Ui {
class newfriend_dialog;
}

class newfriend_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit newfriend_dialog(QWidget *parent = nullptr);
    ~newfriend_dialog();

private slots:
    void on_seefriendrequest_button_clicked();

    void on_addnewfriend_button_clicked();

private:
    Ui::newfriend_dialog *ui;
};

#endif // NEWFRIEND_DIALOG_H
