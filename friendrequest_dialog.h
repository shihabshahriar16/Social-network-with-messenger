#ifndef FRIENDREQUEST_DIALOG_H
#define FRIENDREQUEST_DIALOG_H

#include <QDialog>

namespace Ui {
class friendrequest_dialog;
}

class friendrequest_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit friendrequest_dialog(QWidget *parent = nullptr);
    ~friendrequest_dialog();

private slots:
    void on_accept_button_clicked();

    void on_decline_button_clicked();

private:
    Ui::friendrequest_dialog *ui;
};

#endif // FRIENDREQUEST_DIALOG_H
