#ifndef FRIENDSEARCH_DIALOG_H
#define FRIENDSEARCH_DIALOG_H

#include <QDialog>

namespace Ui {
class friendsearch_dialog;
}

class friendsearch_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit friendsearch_dialog(QWidget *parent = nullptr);
    ~friendsearch_dialog();

private slots:
    void on_sendrequest_button_clicked();

private:
    Ui::friendsearch_dialog *ui;
};

#endif // FRIENDSEARCH_DIALOG_H
