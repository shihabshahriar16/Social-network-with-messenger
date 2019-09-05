#ifndef PEOPLEYOUMAYKNOW_DIALOG_H
#define PEOPLEYOUMAYKNOW_DIALOG_H

#include <QDialog>

namespace Ui {
class peopleYouMayKnow_dialog;
}

class peopleYouMayKnow_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit peopleYouMayKnow_dialog(QWidget *parent = nullptr);
    ~peopleYouMayKnow_dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::peopleYouMayKnow_dialog *ui;
};

#endif // PEOPLEYOUMAYKNOW_DIALOG_H
