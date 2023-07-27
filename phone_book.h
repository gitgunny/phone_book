#pragma once

#include <conio.h>  // getch
#include <iomanip>  // setw
#include <iostream> // cin, cout, endl
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
    // ����� : ��� ����
private:
    int max_idx;
    PBData* head;
    PBData* tail;

    // ���� : ��� �Լ�
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

    // ����� : ��� �Լ� ���� �Լ�
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

    // ���� : ������ �� �Ҹ���
public:
    PhoneBook();
    ~PhoneBook();
};

void _getchar();
bool isNum(const string& str);
