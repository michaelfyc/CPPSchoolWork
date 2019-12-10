#include<iostream>
#include "User.h"
int User::accountId=0;

int main(){
    User u1("H","222");
    u1.getInfo();
    u1.setPassword("Happy");
    u1.withdraw(100);
    return 0;
}