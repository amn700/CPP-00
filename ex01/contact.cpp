#include "phonebook.hpp"

std :: string Contact:: get_first_name() const { return first_name; }
void  Contact:: set_first_name(std :: string value) { first_name = value; }

std :: string  Contact:: get_last_name() const { return last_name; }
void  Contact:: set_last_name(std :: string value) { last_name = value; }

std :: string  Contact:: get_nickname() const { return nickname; }
void  Contact:: set_nickname(std :: string value) { nickname = value; }

std :: string  Contact:: get_phone_number() const { return phone_number; }
void  Contact:: set_phone_number(std :: string value) { phone_number = value; }

std :: string  Contact:: get_darkest_secret() const { return darkest_secret; }
void  Contact:: set_darkest_secret(std :: string value) { darkest_secret = value; }
