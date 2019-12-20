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

User* Bank::createAccount()
{
	std::cout << YELLOW << "Creating New Account..." << RESET << "\n";
	std::string username;
	std::string password;
	std::cout << BLUE << "Please enter your username:" << RESET;
	std::cin >> username;
	std::cout << BLUE << "Please enter your password:" << RESET;
	std::cin >> password;
	User user(username, password);
	usr = &user;
	int accountId = user.getAccountId();
	userMap[accountId] = user;
	std::cout << GREEN << "[SUCCESS]Account Created." << RESET << "\n";
	std::cout << "--------------------"
		<< "\n";
	std::cout << YELLOW << "Dear " << username << ", your account info is:" << RESET << "\n";
	user.getInfo();
	return usr;
}

User* Bank::getUser(int accountId)
{	
	if (userMap.empty() || userMap.count(accountId) == 0)
	{
		std::string msg = "\033[31m[ERROR]NO ACCOUNT FOUND.\033[0m";
		throw std::out_of_range(msg);
	}
	usr = &userMap[accountId];
	return usr;
}

bool Bank::save(int accountId, double value)
{
	try {
		if (getUser(accountId)->save(value)) {

			std::cout << GREEN << "[SUCCESS]You have saved $" << value << " into your account." << RESET
				<< "\n";
			std::cout << "--------------------"
				<< "\n\n";
			return true;
		}
	}
	catch (std::out_of_range e) {
		std::cout<<"\033[31m[ERROR]NO ACCOUNT FOUND.\033[0m"<<"\n";
		std::cout << "--------------------"
			<< "\n\n";
		return false;
	}
	return false;
}

bool Bank::withdraw(int accountId, double value)
{
	try {
		if (getUser(accountId)->withdraw(value)) {

			std::cout << GREEN << "[SUCCESS]You have withdrawn $" << value << " into your account." << RESET
				<< "\n";
			std::cout << "--------------------"
				<< "\n\n";
			return true;
		}
	}
	catch (std::out_of_range e) {
		std::cout << RED<<"[ERROR]NO ACCOUNT FOUND." <<RESET<< "\n";
		std::cout << "--------------------"
			<< "\n\n";
		return false;
	}
	return false;
}

void Bank::getInfo(int accountId)
{
	std::string username;
	std::string password;
	std::cout << BLUE << "Please enter your username:" << RESET;
	std::cin >> username;
	std::cout << BLUE << "Please enter your password:" << RESET;
	std::cin >> password;
	try {
		if (getUser(accountId)->isValid(accountId, username, password))
		{
			std::cout << YELLOW << "Account Info:" << RESET << "\n";
			getUser(accountId)->getInfo();
			std::cout << "--------------------"
				<< "\n\n";
			return;
		}
		std::cout << RED << "[ERROR]Permission Denied." << RESET << "\n";
		std::cout << "--------------------"
			<< "\n\n";
	}
	catch (std::out_of_range e) {
		std::cout << RED << "[ERROR]NO ACCOUNT FOUND." << RESET << "\n";
		std::cout << "--------------------"
			<< "\n\n";
	}
}



int Bank::getSize()
{
	return (int)userMap.size();
}

void Bank::changePassword(int accountId)
{
	std::string newPassword;
	std::cout << BLUE << "Please enter your new passord:" << RESET;
	std::cin >> newPassword;
	try { 
		getUser(accountId)->setPassword(accountId, newPassword); 
	}
	catch(std::out_of_range e){
		std::cout << RED << "[ERROR]NO ACCOUNT FOUND." << RESET << "\n";
		User* getUser(int accountId);
	}
}




Bank::~Bank()
{
}
