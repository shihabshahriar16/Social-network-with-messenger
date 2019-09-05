#ifndef MESSAGE_DIALOG_H
#define MESSAGE_DIALOG_H

#include <QDialog>

namespace Ui {
class message_dialog;
}

class message_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit message_dialog(const QString &name, QWidget *parent = nullptr);
    ~message_dialog();

private slots:
    void on_send_button_clicked();

private:
    Ui::message_dialog *ui;
    QString uname2;
};

#endif // MESSAGE_DIALOG_H
