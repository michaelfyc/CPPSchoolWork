#include<iostream>
#include<string>
#include "User.h"
#include<list>
#include<algorithm>
#ifndef class_bank 
#define class_bank class_bank



class Bank{
    private:
        std::list<User> userList;

    public:
        Bank(){}

        //create an account and put it in the list
        void createAccount(){
            std::string username;
            std::string password;
            std::cout<<"Please enter your username:";
            std::cin>>username;
            std::cout<<"Please enter your password:";
            std::cin>>password;
            User user(username,password);
            userList.push_back(user);
        }


};

#endif