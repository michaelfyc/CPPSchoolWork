#pragma once
#include<iostream>
#include<string>

class User
{
private:
	static int accountId;
	std::string username;
	std::string password;
	double deposit;

public:
	User();
	User(std::string username, std::string password);

	//getters and setters
	void setUsername(std::string username);

	void setPassword(int accountId, std::string password);

	void setDeposit(double value);

	bool save(double value);

	bool withdraw(double value);

	int getAccountId();

	std::string getUsername();

	std::string getPassword();

	double getDeposit();

	void getInfo();

	bool isValid(std::string username, std::string password);
	~User();
};

