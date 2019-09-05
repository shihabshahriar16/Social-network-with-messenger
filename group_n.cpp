#include "group_n.h"
#include <iostream>
#include<string>
#include <QString>

group_n::group_n(string groupname)
{
    this->groupname = groupname;
}
void group_n::showuserinfo()
{
    //cout << "\n\t username: " << username << "\n\t email: " << email << "\n\t Number of Friends: " << numberoffriends << endl;
    system("pause");
}

group_n::~group_n()
{
    cout << "in the desctructor. need work";
}

string group_n::get_groupname()
{
    return this->groupname;
}
