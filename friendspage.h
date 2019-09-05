#ifndef FRIENDSPAGE_H
#define FRIENDSPAGE_H

#include <QDialog>

namespace Ui {
class friendspage;
}

class friendspage : public QDialog
{
    Q_OBJECT

public:
    explicit friendspage(QWidget *parent = nullptr);
    ~friendspage();

private:
    Ui::friendspage *ui;
};

#endif // FRIENDSPAGE_H
