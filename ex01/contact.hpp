#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
private:
    std :: string first_name;
    std :: string last_name;
    std :: string nickname;
    std :: string phone_number;
    std :: string darkest_secret;

public:
    std :: string get_first_name() const;
    void set_first_name(std :: string value);

    std :: string get_last_name() const;
    void set_last_name(std :: string value);

    std :: string get_nickname() const ;
    void set_nickname(std :: string value) ;

    std :: string get_phone_number() const ;
    void set_phone_number(std :: string value) ;

    std :: string get_darkest_secret() const;
    void set_darkest_secret(std :: string value) ;
};


#endif