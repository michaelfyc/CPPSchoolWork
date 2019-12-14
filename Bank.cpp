#include "pch.h"
#include "Bank.h"

//Make program beautiful
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

Bank::Bank()
{
}

User Bank::createAccount()
{
	std::cout << YELLOW << "Creating New Account..." << RESET << "\n";
	std::string username;
	std::string password;
	std::cout << BLUE << "Please enter your username:" << RESET;
	std::cin >> username;
	std::cout << BLUE << "Please enter your password:" << RESET;
	std::cin >> password;
	User user(username, password);
	usr = user;
	int accountId = user.getAccountId();
	userMap[accountId] = usr;
	std::cout << GREEN << "[SUCCESS]Account Created." << RESET << "\n";
	std::cout << "--------------------"
		<< "\n";
	std::cout << YELLOW << "Dear " << username << ", your account info is:" << RESET << "\n";
	user.getInfo();
	std::cout << "--------------------"
		<< "\n\n";
	return usr;
}

User Bank::getUser(int accountId)
{	
	if (userMap.empty() || userMap.count(accountId) == 0)
	{
		std::string msg = "\033[31m[ERROR]NO ACCOUNTS FOUND.\033[0m";
		throw std::out_of_range(msg);
	}
	return userMap[accountId];
}

bool Bank::save(int accountId, double value)
{
	if (getUser(accountId).save(value)) {
		
		std::cout << GREEN << "[SUCCESS]You have saved $" << value << " into your account." << RESET
			<< "\n";
		return true;
	}
	return false;
}

bool Bank::withdraw(int accountId, double value)
{
	return getUser(accountId).withdraw(value);
}

void Bank::getInfo(int accountId)
{
	int accountID;
	std::string username;
	std::string password;
	std::cout << BLUE << "Please enter your account ID:" << RESET;
	std::cin >> accountID;
	std::cout << BLUE << "Please enter your username:" << RESET;
	std::cin >> username;
	std::cout << BLUE << "Please enter your password:" << RESET;
	std::cin >> password;
	if (getUser(accountId).isValid(accountID, username, password))
	{
		std::cout << YELLOW << "Account Info:" << RESET << "\n";
		getUser(accountId).getInfo();
		std::cout << "--------------------"
			<< "\n\n";
		return;
	}
	std::cout << RED << "[ERROR]Permission Denied." << RESET << "\n";
}




Bank::~Bank()
{
}
