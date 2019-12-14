#pragma once
#include "User.h"
#include <map>

class Bank
{
private:
	std::map<int, User> userMap;
	User usr;
public:
	Bank();
	User createAccount();
	User getUser(int accountId);
	bool save(int accountId,double value);
	bool withdraw(int accountId, double value);
	void getInfo(int accoutId);
	~Bank();
};

