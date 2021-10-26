#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <cstring>
#include <iomanip>
#include "Contact.hpp"

enum
{
    SIZE = 8
};

class PhoneBook
{
private:
    static int mNum;
    int mIndex;
    Contact mList[SIZE];

public:
    PhoneBook();
    void AddList();
    void PrintListDigit(const std::string s, bool isEnd) const;
    void ShowAllList() const;
    void ShowOneContact() const;
};

#endif