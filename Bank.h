#pragma once
#include "User.h"
#include <map>

class Bank
{
private:
	std::map<int, User> userMap;
	User* usr;
	User* getUser(int accountId);
public:
	Bank();
	User* createAccount();
	bool save(int accountId,double value);
	bool withdraw(int accountId, double value);
	void getInfo(int accoutId);
	int getSize();
	void changePassword(int accountId);
	~Bank();
};

