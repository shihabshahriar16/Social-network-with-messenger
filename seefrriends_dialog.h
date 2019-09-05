#ifndef SEEFRRIENDS_DIALOG_H
#define SEEFRRIENDS_DIALOG_H

#include <QDialog>

namespace Ui {
class seefrriends_dialog;
}

class seefrriends_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit seefrriends_dialog(QWidget *parent = nullptr);
    //explicit seefrriends_dialog(const QString &name, QWidget *parent = nullptr);
    ~seefrriends_dialog();

private slots:
    void on_removeFriend_button_clicked();

    void on_seeFriendprofile_button_clicked();

    void on_seFriendposts_button_clicked();

    void on_message_button_clicked();

private:
    Ui::seefrriends_dialog *ui;
   // QString uname2;
};

#endif // SEEFRRIENDS_DIALOG_H
