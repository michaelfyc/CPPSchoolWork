#include <iostream>
#include <string>
#include "User.h"
#include <list>
#include <map>
#include <algorithm>
#ifndef class_bank
#define class_bank class_bank

//Make program beautiful
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class Bank
{
private:
    /**userMap: Map<int,User>
     * int for accountID,
     * User for user
    */
    std::map<int, User> userMap;

    User fetchUser(int accountId)
    {
        if (userMap.empty() || userMap.count(accountId) == 0)
        {
            std::string msg = "\033[31m[ERROR]NO ACCOUNTS FOUND.\033[0m";
            throw std::out_of_range(msg);
        }
        return userMap[accountId];
    }

public:
    Bank() {}
    ~Bank() {}
    //create an account and put it in the list
    void createAccount()
    {
        std::cout << YELLOW << "Creating New Account..." << RESET << "\n";
        std::string username;
        std::string password;
        std::cout << BLUE << "Please enter your username:" << RESET;
        std::cin >> username;
        std::cout << BLUE << "Please enter your password:" << RESET;
        std::cin >> password;
        User user(username, password);
        int accountId = user.getAccountId();
        userMap[accountId] = user;
        std::cout << GREEN << "[SUCCESS]Account Created." << RESET << "\n";
        std::cout << "--------------------"
                  << "\n";
        std::cout << YELLOW << "Dear " << username << ", your account info is:" << RESET << "\n";
        user.getInfo();
        std::cout << "--------------------"
                  << "\n\n";
    }

    //Is remove account really a good idea?
    bool removeAccount(int accountId)
    {
        std::cout << YELLOW << "Signing off Accounts..." << RESET << "\n";

        /** Mind that User::accountId is modified with 'static', newing temporary user instance affects accountId. 
         * (Maybe I should remove the default constructor..)
         */

        //check validity before removal
        int accountID;
        std::string username;
        std::string password;
        std::cout << BLUE << "Please enter your account ID:" << RESET;
        std::cin >> accountID;
        std::cout << BLUE << "Please enter your username:" << RESET;
        std::cin >> username;
        std::cout << BLUE << "Please enter your password:" << RESET;
        std::cin >> password;

        if (!fetchUser(accountId).isValid(accountID, username, password))
        {
            std::cout << RED << "[ERROR]Permission Denied." << RESET << "\n";
            return false;
        }
        userMap.erase(accountId);
        std::cout << GREEN << "[SUCCESS]Account " << accountId << " removed." << RESET << "\n";
        return true;
    }
};

#endif