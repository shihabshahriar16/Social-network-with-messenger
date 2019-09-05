#ifndef UPDATEPROFILEDIALOG_H
#define UPDATEPROFILEDIALOG_H

#include <QDialog>

namespace Ui {
class updateprofileDialog;
}

class updateprofileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit updateprofileDialog(QWidget *parent = nullptr);
    ~updateprofileDialog();

private slots:
    void on_update_clicked();

private:
    Ui::updateprofileDialog *ui;
};

#endif // UPDATEPROFILEDIALOG_H
