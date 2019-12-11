#include <iostream>
#include "User.h"
#include "Bank.h"
int User::accountId = 0;

int main()
{
    std::cout<<"\n";
    Bank bank;
    bank.createAccount();
    bank.removeAccount(1);
    return 0;
}