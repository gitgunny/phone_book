#pragma once

#include <conio.h>  // getch
#include <iomanip>  // setw
#include <iostream> // cin, cout, endl
#include <string.h> // strlen, strcpy, strcmp(삭제 예정)
#include <string>   // string

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
    // 비공개 : 멤버 변수
private:
    int max_idx;
    PBData* head;
    PBData* tail;

    // 공개 : 멤버 함수
public:
    // file.cpp
    void ReadFile();
    void WriteFile();

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

    // delete_all.cpp
    void DeleteAll();

    // 비공개 : 멤버 함수 내부 함수
private:
    // search.cpp
    PBData* SearchIdx(const int& _idx);
    PBData* SearchName(const string& _name);
    PBData* SearchNumber(const string& _number);

    // create.cpp
    void PushBack(const string& _name, const string& _number);
    void PushFront(const string& _name, const string& _number);

    // update.cpp
    int UpdateName(PBData* _pPBData, const string& _name);
    int UpdateNumber(PBData* _pPBData, const string& _number);

    // delete.cpp
    int DeletePBData(const PBData* _pPBData);

    // delete_all.cpp
    void DeletePhoneBook();

    // 공개 : 연산자 오버로딩
public:
    PhoneBook& operator*(); // * 연산자 오버로딩 시 Search //////////

    // 공개 : 생성자 및 소멸자
public:
    PhoneBook();
    ~PhoneBook();
};

void _getchar();                                          // 엔터 입력용(버퍼 비우기 포함)
void _fscanf(FILE* _Stream, const char* _Format, ...);    // 정수 입력용(fgets는 문자열 이외 입력 불가)
void _fgets(char* _Buffer, int _MaxCount, FILE* _Stream); // 문자열 입력용(fscanf는 띄어쓰기 입력 불가)
