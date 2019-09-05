#ifndef FRIENDPROFILE_DIALOG_H
#define FRIENDPROFILE_DIALOG_H

#include <QDialog>

namespace Ui {
class friendprofile_dialog;
}

class friendprofile_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit friendprofile_dialog(const QString &name, QWidget *parent = nullptr);
    ~friendprofile_dialog();
    void set_uname2(QString uname2);
    QString get_uname2();

private:
    Ui::friendprofile_dialog *ui;
    QString uname2;
};

#endif // FRIENDPROFILE_DIALOG_H
