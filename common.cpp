#include "phone_book.h"

void _getchar()
{
    fflush(stdin); // 출력 버퍼 비우기
    rewind(stdin); // 입력 버퍼 비우기
    getchar();
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
    ReadFile();
}

PhoneBook::~PhoneBook()
{
    WriteFile();
}

PhoneBook& PhoneBook::operator*() // * 연산자 오버로딩 시 Search //////////
{
    return *this;
}
