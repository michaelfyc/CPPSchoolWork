#include "Bank.h"

User Bank::fetchUser(int accountId)
{
    if (userMap.empty() || userMap.count(accountId) == 0)
    {
        std::string msg = "\033[31m[ERROR]NO ACCOUNTS FOUND.\033[0m";
        throw std::out_of_range(msg);
    }
    return userMap[accountId];
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
    int accountId = user.getAccountId();
    userMap[accountId] = user;
    std::cout << GREEN << "[SUCCESS]Account Created." << RESET << "\n";
    std::cout << "--------------------"
              << "\n";
    std::cout << YELLOW << "Dear " << username << ", your account info is:" << RESET << "\n";
    user.getInfo();
    std::cout << "--------------------"
              << "\n\n";
    return user;
}

//Is remove account really a good idea?
bool Bank::removeAccount(int accountId)
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

// operations on deposit

bool Bank::save(User user, double value)
{
    return this->fetchUser(user.getAccountId()).save(value);
}

bool Bank::withdraw(User user, double value)
{
    return this->fetchUser(user.getAccountId()).withdraw(value);
}

void Bank::showStatus(User user)
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
    if (user.isValid(accountID, username, password))
    {
        std::cout << YELLOW << "Account Info:" << RESET << "\n";
        this->fetchUser(user.getAccountId()).getInfo();
        std::cout << "--------------------"
                  << "\n\n";
        return;
    }
    std::cout << RED << "[ERROR]Permission Denied." << RESET << "\n";
}