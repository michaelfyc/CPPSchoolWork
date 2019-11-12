#include <iostream>
#include <string>
#include "User.h"
#include <map>
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

    User fetchUser(int accountId);

public:
    Bank() {}
    ~Bank() {}
    //create an account and put it in the list
    User createAccount();

    //Is remove account really a good idea?
    bool removeAccount(int accountId);

    // operations on deposit

    bool save(User user, double value);

    bool withdraw(User user, double value);

    void showStatus(User user);
};

#endif