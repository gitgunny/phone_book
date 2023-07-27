#include "phone_book.h"
#include <fstream>

void PhoneBook::ReadFile()
{
    std::ifstream input_file;
    input_file.open("phone_book.pb", std::ios::in);
    string name, number;

    while (input_file >> name >> number)
        PushBack(name, number);

    input_file.close();
}

void PhoneBook::WriteFile()
{
    std::ofstream output_file;
    output_file.open("phone_book.pb", std::ios::out);
    PBData* pPBData = head;
    PBData* pTemp = nullptr;

    while (pPBData != nullptr)
    {
        output_file << pPBData->name << " " << pPBData->number << endl;
        pTemp = pPBData->next;
        delete pPBData;
        pPBData = pTemp;
    }

    output_file.close();
}
