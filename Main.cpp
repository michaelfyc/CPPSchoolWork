#include "pch.h"
#include <iostream>
#include "Bank.h"


int main()
{
	Bank bank;
	User user = bank.createAccount();
	bank.save(1,10);
	bank.getInfo(1);
	return 0;
}

