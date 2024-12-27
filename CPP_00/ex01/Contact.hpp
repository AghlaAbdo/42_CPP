#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Contact {
private:
    string  firstName;
    string  lastName;
    string  nickName;
    string  phoneNumber;
    string  darkestSecret;
public:
    void    fillContact();
    void    search();
    string    getFirstName();
    string    getLastName();
    string    getNickname();
    string    getPhoneNumber();
    string    getSecret();
};

#endif