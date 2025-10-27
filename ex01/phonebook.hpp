#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "contact.hpp"

class Phonebook
{
private:
    int next_index;     // where the next contact goes
    int contact_count;  // how many contacts exist

public:
    Contact contacts[8];

    Phonebook() : next_index(0), contact_count(0) {}

    // --- utils ---
    int ascii_to_integer(const std :: string &input);

    std :: string format_field(const std :: string &field);
    void search();
    // --- add ---
    void add();
    // --- exit ---
    void quit();
    // --- getters ---
    int get_next_index() const ;
    int get_contact_count() const ;

    // --- setters ---
    void set_next_index(int value);
    void set_contact_count(int value);
};

#endif
