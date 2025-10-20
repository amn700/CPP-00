#include "phonebook.hpp"

int main ()
{
    Phonebook phonebook;
    string cmd;

    while (true)
    {
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
