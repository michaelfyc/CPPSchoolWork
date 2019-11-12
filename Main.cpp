#include <iostream>
#include "User.h"
#include "Bank.h"
int User::accountId = 0;

int main()
{
    std::cout<<"\n";
    Bank bank;
    User user=bank.createAccount();
    bank.save(user,120);
    bank.showStatus(user);
    return 0;
}