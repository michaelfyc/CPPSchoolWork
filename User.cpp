#include "User.h"

int User::accountId = 0;
explicit User::User() {}
explicit User::User(std::string username, std::string password)
{
    this->accountId += 1;
    this->username = username;
    this->password = password;
    this->deposit = 0;
}

//check validity
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

//getters and setters

void User::setUsername(std::string username)
{
    this->username = username;
}

void User::setPassword(std::string newPassword)
{

    //check validity before changing password
    int accountID;
    std::string username;
    std::string oldPassword;
    std::cout << BLUE << "Please enter your account ID:" << RESET;
    std::cin >> accountID;
    std::cout << BLUE << "Please enter your username:" << RESET;
    std::cin >> username;
    std::cout << BLUE << "Please enter your original password:" << RESET;
    std::cin >> oldPassword;

    if (isValid(accountID, username, oldPassword))
    {
        this->password = newPassword;
        std::cout << GREEN << "[SUCCESS]Password changing successful!" << RESET << "\n";
    }
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
    this->password;
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

bool User::save(double value)
{
    if (value < 0)
    {
        std::cout << RED << "[ERROR]Invalid input." << RESET << "\n";
        return false;
    }
    this->deposit += value;
    std::cout << GREEN << "[SUCCESS]You have saved $" << value << " into your account." << RESET
              << "\n";
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
    std::cout << GREEN << "[SUCCESS]You have withdrawn $" << value << " from your account." << RESET
              << "\n";
    return true;
}
