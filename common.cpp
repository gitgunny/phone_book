#include "phone_book.h"
#include <limits>

void _getchar()
{
    cin.clear();
    cin.sync();
    // cin.ignore();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool isNum(const string& str)
{
    for (char const& let : str)
        if (std::isdigit(let) == false)
            return false;

    return true;
}

PhoneBook::PhoneBook() : max_idx(0), head(nullptr), tail(nullptr)
{
    ReadFile();
}

PhoneBook::~PhoneBook()
{
    WriteFile();
}
