#include "phone_book.h"

void _getchar()
{
    getchar();
    fflush(stdin); // ��� ���� ����
    rewind(stdin); // �Է� ���� ����
}

void _fscanf(FILE* _Stream, const char* _Format, ...)
{
    fscanf(_Stream, _Format);
    fflush(_Stream); // ��� ���� ����
    rewind(_Stream); // �Է� ���� ����
}

void _fgets(char* _Buffer, int _MaxCount, FILE* _Stream)
{
    fgets(_Buffer, _MaxCount, _Stream);
    _Buffer[strlen(_Buffer) - 1] = '\0'; // ������ �ٹٲ� ���� ����
    fflush(_Stream);                     // ��� ���� ����
    rewind(_Stream);                     // �Է� ���� ����
}

PhoneBook::PhoneBook() : max_idx(0), head(nullptr), tail(nullptr)
{
    // ReadFile();
}

PhoneBook::~PhoneBook()
{
    // WriteFile();
}
/*
// < ������ �����ε� �� PushBack
PhoneBook &PhoneBook::operator<(const NameNumber &_name_number)
{
    PushBack(_name_number.name, _name_number.number);

    return *this;
}

// << ������ �����ε� �� PushFront
PhoneBook &PhoneBook::operator<<(const NameNumber &_name_number)
{
    PushFront(_name_number.name, _name_number.number);

    return *this;
}

// > ������ �����ε� �� Delete
PhoneBook &PhoneBook::operator>(const PBData *_pPBData)
{
    Delete(_pPBData);

    return *this;
}

// >> ������ �����ε� �� DeleteAll
PhoneBook &PhoneBook::operator>>(const PhoneBook *_phone_book)
{
    DeleteAll(_phone_book);

    return *this;
}
//
//
//
//
//
// * ������ �����ε� �� Search(Address)
PhoneBook &PhoneBook::operator*(const NameNumber &_name_number)
{
    return *this;
}

// & ������ �����ε� �� Search(Reference)
PhoneBook &PhoneBook::operator&(const NameNumber &_name_number)
{
    return *this;
}
*/
