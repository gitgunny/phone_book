#pragma once

#include <conio.h> // getch
#include <iostream>
#include <string.h> // strlen, strcpy, strcmp

enum
{
    MENU_0 = 48,
    MENU_1,
    MENU_2,
    MENU_3,
    MENU_4,
    MENU_5
};

const unsigned int name_max_len = 15;
const unsigned int number_max_len = 20;

class PBData
{
public:
    PBData* prev;
    int idx;
    char name[name_max_len];
    char number[number_max_len];
    PBData* next;
};

class PhoneBook
{
public:
    PhoneBook();
    ~PhoneBook();

private:
    int max_idx;
    PBData* head;
    PBData* tail;

public:
    void ReadFile();  /////
    void WriteFile(); /////
    void Show();      // Search 연동 가능?
    void Search();
    void Create();
    void Update();
    void Delete();
    void DeleteAll();

    /*
    public:
        // 공개 : 연산자 오버로딩 선언
        PhoneBook &operator<(const NameNumber &_name_number);  // < 연산자 오버로딩 시 PushBack
        PhoneBook &operator<<(const NameNumber &_name_number); // << 연산자 오버로딩 시 PushFront
        PhoneBook &operator>(const PBData *_pPBData);		   // > 연산자 오버로딩 시 Delete
        PhoneBook &operator>>(const PhoneBook *_phone_book);   // >> 연산자 오버로딩 시 DeleteAll
        PhoneBook &operator*(const NameNumber &_name_number);  // * 연산자 오버로딩 시 Search(Address)
        PhoneBook &operator&(const NameNumber &_name_number);  // & 연산자 오버로딩 시 Search(Reference)
    */

private:
    PBData* SearchIdx(const int* _idx);
    PBData* SearchName(const char* _name);
    PBData* SearchNumber(const char* _number);

    void PushFirst(const char* _name, const char* _number);
    void PushBack(const char* _name, const char* _number);
    void PushFront(const char* _name, const char* _number);

    int UpdateName(PBData* _pPBData, const char* _name);
    int UpdateNumber(PBData* _pPBData, const char* _number);

    int Delete(const PBData* _pPBData);

    int DeleteAll(const PhoneBook* _phone_book);
};

void _getchar();                                          // 엔터 입력용(버퍼 비우기 포함)
void _fscanf(FILE* _Stream, const char* _Format, ...);    // 정수 입력용(fgets는 문자열 이외 입력 불가)
void _fgets(char* _Buffer, int _MaxCount, FILE* _Stream); // 문자열 입력용(fscanf는 띄어쓰기 입력 불가)
