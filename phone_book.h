#pragma once

#include <conio.h> // getch
#include <iostream>
#include <iomanip>
#include <string.h> // strlen, strcpy, strcmp
#include <string>

enum
{
    MENU_0 = 48,
    MENU_1,
    MENU_2,
    MENU_3,
    MENU_4,
    MENU_5
};

using std::cin;
using std::cout;
using std::endl;
using std::string;

const unsigned int name_max_len = 15;
const unsigned int number_max_len = 20;

class PBData
{
public:
    PBData* prev;
    int idx;
    string name;
    string number;
    PBData* next;

public:
    PBData(const string& _name, const string& _number) : prev(nullptr), name(_name), number(_number), next(nullptr) {}
};

class PhoneBook
{
private:
    int max_idx;
    PBData* head;
    PBData* tail;

public:
    // file.cpp
    void ReadFile();  /////
    void WriteFile(); /////

    // show.cpp
    void Show();

    // search.cpp
    void Search();

    // create.cpp
    void Create();

    // updata.cpp
    void Update();

    // delete.cpp
    void Delete();
    void DeleteAll();

private:
    PBData* SearchIdx(const int& _idx);
    PBData* SearchName(const string& _name);
    PBData* SearchNumber(const string& _number);

    void PushBack(const string& _name, const string& _number);
    void PushFront(const string& _name, const string& _number);

    int UpdateName(PBData* _pPBData, const string& _name);
    int UpdateNumber(PBData* _pPBData, const string& _number);

    int Delete(const PBData* _pPBData);

    int DeleteAll(const PhoneBook* _phone_book);

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

public:
    PhoneBook();
    ~PhoneBook();
};

void _getchar();                                          // 엔터 입력용(버퍼 비우기 포함)
void _fscanf(FILE* _Stream, const char* _Format, ...);    // 정수 입력용(fgets는 문자열 이외 입력 불가)
void _fgets(char* _Buffer, int _MaxCount, FILE* _Stream); // 문자열 입력용(fscanf는 띄어쓰기 입력 불가)
