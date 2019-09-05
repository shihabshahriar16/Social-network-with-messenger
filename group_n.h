#pragma once
#include <iostream>
#include <string>
#include <QString>
#include <QMessageBox>
using namespace std;

class group_n
{
private:
    string groupname;
public:
    group_n(string groupname);
    ~group_n();
    void showuserinfo();
    string get_groupname();
}static *obj3= new group_n("default");
