#include <iostream>
#include <string>
#ifndef class_user
#define class_user class_user

//Make program beautiful
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class User
{
private:
    static int accountId;
    std::string username;
    std::string password;
    double deposit;

    bool isValid(int accountId, std::string username, std::string password)
    {
        if ((accountId == this->accountId) && (password == this->password) && (username == this->username))
        {
            return true;
        }
        std::cout << RED << "[ERROR]Bad credentials!" << RESET
                  << "\n";
        return false;
    }

public:
    explicit User() {}
    explicit User(std::string username, std::string password)
    {
        this->accountId += 1;
        this->username = username;
        this->password = password;
        this->deposit = 0;
    }

    ~User() {}

    //getters and setters
    void setUsername(std::string username)
    {
        this->username = username;
    }
    void setPassword(std::string newPassword)
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
    void save(double value)
    {
        this->deposit += value;
    }
    void withdraw(double value)
    {
        if (value > deposit)
        {
            std::cout << RED << "[ERROR]No enough deposit!" << RESET
                      << "\n";
            return;
        }
        this->deposit -= value;
    }

    int getAccountId()
    {
        return this->accountId;
    }
    std::string getUsername()
    {
        return this->username;
    }
    std::string getPassword()
    {
        return this->password;
    }
    double getDeposit()
    {
        return this->deposit;
    }

    void getInfo()
    {
        std::cout << GREEN << "[-]Account ID:" << RESET << BLUE << this->accountId << RESET << "\n";
        std::cout << GREEN << "[-]Username:" << RESET << BLUE << this->username << RESET << "\n";
        std::cout << GREEN << "[-]Deposit:" << RESET << BLUE << this->deposit << RESET << "\n";
    }
};

#endif