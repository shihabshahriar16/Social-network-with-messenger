#pragma once
#include <iostream>
#include <string>
#include <QString>
#include <QMessageBox>
using namespace std;

class user
{
private:
	string username;
	string password;
	string email;
	int numberoffriends;
	string *friendlist;
public:
	user(string username, string password, string email);
	~user();
	void showuserinfo();
    string get_username();
    string get_email();
}static *obj1= new user("default","default","default");
