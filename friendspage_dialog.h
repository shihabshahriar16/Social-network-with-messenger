#ifndef FRIENDSPAGE_DIALOG_H
#define FRIENDSPAGE_DIALOG_H

#include <QDialog>

namespace Ui {
class friendspage_dialog;
}

class friendspage_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit friendspage_dialog(QWidget *parent = nullptr);
    ~friendspage_dialog();

private slots:
    void on_seeFriends_button_clicked();

    void on_makeNewFriend_button_clicked();

    void on_peopleYouMayKow_button_clicked();

private:
    Ui::friendspage_dialog *ui;
};

#endif // FRIENDSPAGE_DIALOG_H
