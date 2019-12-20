#include "pch.h"
#include <iostream>
#include <fstream>
#include "Bank.h"
#include<Windows.h>

//Make program beautiful
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void printFrontPage() {
	system("cls");
	std::string s;
	std::ifstream infile("slogan.txt");
	int countline = 0;
	if (!infile) {
		std::cout << RED << "[ERROR]Slogan loading FAILED." << RESET << "\n";
		std::cout << "--------------------" << "\n";
	}
	else {
		while (std::getline(infile, s)) {
			countline++;
			if (countline < 16) {
				std::cout << BLUE << s.c_str() << RESET << "\n";
			}
			else {
				std::cout << YELLOW << s.c_str() << RESET << "\n";
			}
		}
	}
}

int main()
{
	int choice = 0;
	char alt = 0;
	Bank bank;
	printFrontPage();
	std::cout << "Do you want to experience?[y/n]";
	alt = getchar();
	if (alt != 'y') {
		std::cout << RED << "Exiting..." << RESET << "\n";
		return 0;
	}
	system("cls");
	//Loop to prompt user choices
	do {
		std::cout << GREEN << "There are already " << bank.getSize() << " users existed!" << RESET << "\n\n";
		std::cout << YELLOW << "What do you want to do?" << RESET << "\n";
		std::cout << BLUE << "\t1:Create Account" << RESET << "\n";
		std::cout << BLUE << "\t2:Save Money" << RESET << "\n";
		std::cout << BLUE << "\t3:Withdraw Money" << RESET << "\n";
		std::cout << BLUE << "\t4:Show User Info" << RESET << "\n";
		std::cout << BLUE << "\t5:Change User Password" << RESET << "\n";
		std::cout << BLUE << "\t6:Quit" << RESET << "\n";
		std::cin >> choice;
		std::cout << "--------------------" << "\n";
		switch (choice) {
		case 1:
			bank.createAccount();
			std::cout << "--------------------"
				<< "\n\n";
			break;
		case 2:
			std::cout << YELLOW << "SAVE SERVICE" << RESET << "\n";
			int id;
			double value;
			std::cout << BLUE << "Please enter your account ID:" << RESET;
			std::cin >> id;
			std::cout << BLUE << "Please enter the value:" << RESET;
			std::cin >> value;
			bank.save(id, value);
			std::cout << "--------------------" << "\n\n";
			break;
		case 3:
			std::cout << YELLOW << "WITHDRAW SERVICE" << RESET << "\n";
			std::cout << BLUE << "Please enter your account ID:" << RESET;
			std::cin >> id;
			std::cout << BLUE << "Please enter the value:" << RESET;
			std::cin >> value;
			bank.withdraw(id, value);
			std::cout << "--------------------" << "\n\n";
			break;
		case 4:
			std::cout << YELLOW << "CHECKING ACCOUNT INFO" << RESET << "\n";
			std::cout << BLUE << "Please enter your account number:" << RESET;
			std::cin >> id;
			bank.getInfo(id);
			break;
		case 5:
			std::cout << YELLOW << "CHANGING PASSWORD" << "\n";
			std::cout << BLUE << "Please enter your id:" << RESET;
			std::cin >> id;
			bank.changePassword(id);
			break;
		}
	} while (choice < 6 && choice>0);

	std::cout << RED << "Exiting..." << RESET << "\n";
	return 0;
}

