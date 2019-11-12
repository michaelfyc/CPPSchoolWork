#include <iostream>
#include "User.h"
#include "Bank.h"
int User::accountId = 0;

int main()
{
    std::cout<<"\n";
    Bank bank;
    User user=bank.createAccount();
    user.save(100.23);
    bank.save(user,120);
    user.getInfo();
    bank.showStatus(user);
    return 0;
}