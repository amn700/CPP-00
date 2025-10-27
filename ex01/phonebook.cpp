#include "phonebook.hpp"

int Phonebook :: get_next_index() const { return next_index; }
int Phonebook :: get_contact_count() const { return contact_count; }
void Phonebook :: set_next_index(int value) { next_index = value; }
void Phonebook :: set_contact_count(int value) { contact_count = value; }

int Phonebook :: ascii_to_integer(const std :: string &input)
{
    if (input.empty())
        return -1;

    int value = 0;
    for (size_t i = 0; i < input.size(); i++)
    {
        if (!isdigit(input[i]))
            return -1;
        value = value * 10 + (input[i] - '0');
    }
    return value;
}

std :: string format_field(const std :: string &field)
{
    if (field.size() > 10)
        return field.substr(0, 9) + ".";
    return field;
}

// --- add ---
void Phonebook :: add()
{
    std :: string input;
    int index = get_next_index();

    std :: cout << "First name: ";
    std :: getline(std :: cin, input);
    contacts[index].set_first_name(input);

    std :: cout << "Last name: ";
    std :: getline(std :: cin, input);
    contacts[index].set_last_name(input);

    std :: cout << "Nickname: ";
    std :: getline(std :: cin, input);
    contacts[index].set_nickname(input);

    std :: cout << "Phone number: ";
    std :: getline(std :: cin, input);
    contacts[index].set_phone_number(input);

    std :: cout << "Darkest secret: ";
    std :: getline(std :: cin, input);
    contacts[index].set_darkest_secret(input);

    set_next_index((get_next_index() + 1) % 8);
    int count = get_contact_count();
    if (count < 8)
        set_contact_count(count + 1);
}

// --- search ---
void Phonebook :: search()
{
    std :: cout << "┌" << std :: string(10, '-') << "┬" << std :: string(10, '-') << "┬"
            << std :: string(10, '-') << "┬" << std :: string(10, '-') << "┐" << std :: endl;

    std :: cout << "│" << std :: setw(10) << "index"
            << "│" << std :: setw(10) << "first name"
            << "│" << std :: setw(10) << "last name"
            << "│" << std :: setw(10) << "nickname"
            << "│" << std :: endl;

    std :: cout << "├" << std :: string(10, '-') << "┼" << std :: string(10, '-') << "┼"
            << std :: string(10, '-') << "┼" << std :: string(10, '-') << "┤" << std :: endl;

    int count = get_contact_count();
    for (int i = 0; i < count; i++)
    {
        std :: cout << "│" << std :: setw(10) << i
                << "│" << std :: setw(10) << format_field(contacts[i].get_first_name())
                << "│" << std :: setw(10) << format_field(contacts[i].get_last_name())
                << "│" << std :: setw(10) << format_field(contacts[i].get_nickname())
                << "│" << std :: endl;

        if (i != count - 1) // only between rows
            std :: cout << "├" << std :: string(10, '-') << "┼" << std :: string(10, '-') << "┼"
                    << std :: string(10, '-') << "┼" << std :: string(10, '-') << "┤" << std :: endl;
    }

    std :: cout << "└" << std :: string(10, '-') << "┴" << std :: string(10, '-') << "┴"
            << std :: string(10, '-') << "┴" << std :: string(10, '-') << "┘" << std :: endl;

    std :: string input;
    std :: cout << std :: endl << "Choose Contact index: ";
    std :: getline(std :: cin, input);
    int target = ascii_to_integer(input);

    if (target < 0 || target >= get_contact_count())
    {
        std :: cout << "Invalid index" << std :: endl;
    }
    else
    {
        std :: cout << "First name: " << contacts[target].get_first_name() << std :: endl;
        std :: cout << "Last name: " << contacts[target].get_last_name() << std :: endl;
        std :: cout << "Nickname: " << contacts[target].get_nickname() << std :: endl;
        std :: cout << "Phone number: " << contacts[target].get_phone_number() << std :: endl;
        std :: cout << "Darkest secret: " << contacts[target].get_darkest_secret() << std :: endl;
    }
}

// --- exit ---
void Phonebook :: quit()
{
    exit(0);
}
