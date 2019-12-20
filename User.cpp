#include "pch.h"
#include "User.h"

//Make program beautiful
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

int User::accountId = 0;

User::User()
{
}

User::User(std::string username, std::string password)
{
	accountId += 1;
	this->username = username;
	this->password = password;
	this->deposit = 0;
}

void User::setUsername(std::string username)
{
	this->username = username;
}

void User::setPassword(int accountId,std::string newPassword)
{
	//check validity before changing password
	std::string username;
	std::string oldPassword;
	std::cout << BLUE << "Please enter your username:" << RESET;
	std::cin >> username;
	std::cout << BLUE << "Please enter your original password:" << RESET;
	std::cin >> oldPassword;

	if (isValid(accountId, username, oldPassword))
	{
		this->password = newPassword;
		std::cout << GREEN << "[SUCCESS]Password changing successful!" << RESET << "\n";
	}
}

void User::setDeposit(double value)
{
	this->deposit = value;
}

bool User::save(double value)
{
	if (value < 0)
	{
		std::cout << RED << "[ERROR]Invalid input." << RESET << "\n";
		return false;
	}
	this->deposit += value;
	return true;
}

bool User::withdraw(double value)
{	
	if (value < 0)
	{
		std::cout << RED << "[ERROR]Invalid input." << RESET << "\n";
		return false;
	}
	if (value > deposit)
	{
		std::cout << RED << "[ERROR]No enough deposit!" << RESET
			<< "\n";
		return false;
	}
	this->deposit -= value;
	return true;
}

int User::getAccountId()
{
	return this->accountId;
}

std::string User::getUsername()
{
	return this->username;
}

std::string User::getPassword()
{
	return this->password;
}

double User::getDeposit()
{
	return this->deposit;
}

void User::getInfo()
{
	std::cout << GREEN << "[-]Account ID:" << RESET << BLUE << this->accountId << RESET << "\n";
	std::cout << GREEN << "[-]Username:" << RESET << BLUE << this->username << RESET << "\n";
	std::cout << GREEN << "[-]Deposit:" << RESET << BLUE << this->deposit << RESET << "\n";
}


bool User::isValid(int accountId, std::string username, std::string password)
{
	if ((accountId == this->accountId) && (password == this->password) && (username == this->username))
	{
		return true;
	}
	std::cout << RED << "[ERROR]Bad credentials!" << RESET
		<< "\n";
	return false;
}

User::~User()
{
}
