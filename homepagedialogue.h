#ifndef HOMEPAGEDIALOGUE_H
#define HOMEPAGEDIALOGUE_H

#include <QDialog>

namespace Ui {
class homepagedialogue;
}

class homepagedialogue : public QDialog
{
    Q_OBJECT

public:
    explicit homepagedialogue(QWidget *parent = nullptr);
    ~homepagedialogue();

private slots:
    void on_profile_clicked();

    void on_logout_clicked();

    void on_groups_clicked();

    void on_pushButton_clicked();


private:
    Ui::homepagedialogue *ui;
};

#endif // HOMEPAGEDIALOGUE_H
