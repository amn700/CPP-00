#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Contact
{
private:
    string first_name;
    string last_name;
    string nickname;
    string phone_number;
    string darkest_secret;

public:
    string get_first_name() const { return first_name; }
    void set_first_name(string value) { first_name = value; }

    string get_last_name() const { return last_name; }
    void set_last_name(string value) { last_name = value; }

    string get_nickname() const { return nickname; }
    void set_nickname(string value) { nickname = value; }

    string get_phone_number() const { return phone_number; }
    void set_phone_number(string value) { phone_number = value; }

    string get_darkest_secret() const { return darkest_secret; }
    void set_darkest_secret(string value) { darkest_secret = value; }
};

class Phonebook
{
private:
    int next_index;     // where the next contact goes
    int contact_count;  // how many contacts exist

public:
    Contact contacts[8];

    Phonebook() : next_index(0), contact_count(0) {}

    // --- utils ---
    int ascii_to_integer(const string &input)
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

    string format_field(const string &field)
    {
        if (field.size() > 10)
            return field.substr(0, 9) + ".";
        return field;
    }

    // --- add ---
    void add()
    {
        string input;
        int index = get_next_index();

        cout << "First name: ";
        getline(cin, input);
        contacts[index].set_first_name(input);

        cout << "Last name: ";
        getline(cin, input);
        contacts[index].set_last_name(input);

        cout << "Nickname: ";
        getline(cin, input);
        contacts[index].set_nickname(input);

        cout << "Phone number: ";
        getline(cin, input);
        contacts[index].set_phone_number(input);

        cout << "Darkest secret: ";
        getline(cin, input);
        contacts[index].set_darkest_secret(input);

        set_next_index((get_next_index() + 1) % 8);
        int count = get_contact_count();
        if (count < 8)
            set_contact_count(count + 1);
    }

    // --- search ---
    void search()
    {
        cout << "┌" << string(10, '-') << "┬" << string(10, '-') << "┬"
             << string(10, '-') << "┬" << string(10, '-') << "┐" << endl;

        cout << "│" << setw(10) << "index"
             << "│" << setw(10) << "first name"
             << "│" << setw(10) << "last name"
             << "│" << setw(10) << "nickname"
             << "│" << endl;

        cout << "├" << string(10, '-') << "┼" << string(10, '-') << "┼"
             << string(10, '-') << "┼" << string(10, '-') << "┤" << endl;

        int count = get_contact_count();
        for (int i = 0; i < count; i++)
        {
            cout << "│" << setw(10) << i
                 << "│" << setw(10) << format_field(contacts[i].get_first_name())
                 << "│" << setw(10) << format_field(contacts[i].get_last_name())
                 << "│" << setw(10) << format_field(contacts[i].get_nickname())
                 << "│" << endl;

            if (i != count - 1) // only between rows
                cout << "├" << string(10, '-') << "┼" << string(10, '-') << "┼"
                     << string(10, '-') << "┼" << string(10, '-') << "┤" << endl;
        }

        cout << "└" << string(10, '-') << "┴" << string(10, '-') << "┴"
             << string(10, '-') << "┴" << string(10, '-') << "┘" << endl;

        string input;
        cout << endl << "Choose Contact index: ";
        getline(cin, input);
        int target = ascii_to_integer(input);

        if (target < 0 || target >= get_contact_count())
        {
            cout << "Invalid index" << endl;
        }
        else
        {
            cout << "First name: " << contacts[target].get_first_name() << endl;
            cout << "Last name: " << contacts[target].get_last_name() << endl;
            cout << "Nickname: " << contacts[target].get_nickname() << endl;
            cout << "Phone number: " << contacts[target].get_phone_number() << endl;
            cout << "Darkest secret: " << contacts[target].get_darkest_secret() << endl;
        }
    }

    // --- exit ---
    void quit()
    {
        exit(0);
    }

    // --- getters ---
    int get_next_index() const { return next_index; }
    int get_contact_count() const { return contact_count; }

    // --- setters ---
    void set_next_index(int value) { next_index = value; }
    void set_contact_count(int value) { contact_count = value; }
};

#endif
