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

public:
    explicit User() {}
    explicit User(std::string username, std::string password);

    ~User() {}

    //getters and setters
    void setUsername(std::string username);

    void setPassword(std::string newPassword);

    bool save(double value);

    bool withdraw(double value);

    int getAccountId();

    std::string getUsername();

    std::string getPassword();

    double getDeposit();

    void getInfo();

    bool isValid(int accountId, std::string username, std::string password);
};

#endif