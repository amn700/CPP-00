#include "phonebook.hpp"

int main ()
{
    Phonebook phonebook;
    std :: string cmd;

    while (true)
    {
        std::cout << "********** PHONE BOOK **********" << std::endl;
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, cmd);

        if
            (cmd == "ADD") phonebook.add();
        else if
            (cmd == "SEARCH") phonebook.search();
        else if
            (cmd == "EXIT") phonebook.quit();
    }
}
