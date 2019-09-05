#ifndef FRIENDPOST_DIALOG_H
#define FRIENDPOST_DIALOG_H

#include <QDialog>

namespace Ui {
class friendpost_dialog;
}

class friendpost_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit friendpost_dialog(const QString &name, QWidget *parent = nullptr);
    ~friendpost_dialog();

private:
    Ui::friendpost_dialog *ui;
    QString uname2;
};

#endif // FRIENDPOST_DIALOG_H
