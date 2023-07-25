#include "phone_book.h"

void _getchar()
{
    getchar();
    fflush(stdin); // 출력 버퍼 비우기
    rewind(stdin); // 입력 버퍼 비우기
}

void _fscanf(FILE* _Stream, const char* _Format, ...)
{
    fscanf(_Stream, _Format);
    fflush(_Stream); // 출력 버퍼 비우기
    rewind(_Stream); // 입력 버퍼 비우기
}

void _fgets(char* _Buffer, int _MaxCount, FILE* _Stream)
{
    fgets(_Buffer, _MaxCount, _Stream);
    _Buffer[strlen(_Buffer) - 1] = '\0'; // 마지막 줄바꿈 문자 비우기
    fflush(_Stream);                     // 출력 버퍼 비우기
    rewind(_Stream);                     // 입력 버퍼 비우기
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
// < 연산자 오버로딩 시 PushBack
PhoneBook &PhoneBook::operator<(const NameNumber &_name_number)
{
    PushBack(_name_number.name, _name_number.number);

    return *this;
}

// << 연산자 오버로딩 시 PushFront
PhoneBook &PhoneBook::operator<<(const NameNumber &_name_number)
{
    PushFront(_name_number.name, _name_number.number);

    return *this;
}

// > 연산자 오버로딩 시 Delete
PhoneBook &PhoneBook::operator>(const PBData *_pPBData)
{
    Delete(_pPBData);

    return *this;
}

// >> 연산자 오버로딩 시 DeleteAll
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
// * 연산자 오버로딩 시 Search(Address)
PhoneBook &PhoneBook::operator*(const NameNumber &_name_number)
{
    return *this;
}

// & 연산자 오버로딩 시 Search(Reference)
PhoneBook &PhoneBook::operator&(const NameNumber &_name_number)
{
    return *this;
}
*/
