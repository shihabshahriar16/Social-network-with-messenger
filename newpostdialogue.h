#ifndef NEWPOSTDIALOGUE_H
#define NEWPOSTDIALOGUE_H

#include <QDialog>
#include "user.h"

namespace Ui {
class newpostdialogue;
}

class newpostdialogue : public QDialog
{
    Q_OBJECT

public:
    explicit newpostdialogue(QWidget *parent = nullptr);
    ~newpostdialogue();

private slots:
    void on_post_clicked();

private:
    Ui::newpostdialogue *ui;
};

#endif // NEWPOSTDIALOGUE_H
