#include "phone_book.h"

void PhoneBook::Search()
{
    int select_search;
    int search_idx;
    string search_name, search_number;
    PBData* pPBData = nullptr;

    while (1)
    {
        Show();
        cout << endl << "�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    �˻�    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�" << endl;

        cout << endl << "\t1. ���� �˻�  2. �̸� �˻�  3. ��ȣ �˻�  0. �������� : ";
        select_search = _getch();

        if (select_search == MENU_0)
            break;
        else if (select_search == MENU_1)
        {
            cout << endl << endl << "\t�˻��� ���� : ";
            cin >> search_idx;

            pPBData = SearchIdx(search_idx);
        }
        else if (select_search == MENU_2)
        {
            cout << endl << endl << "\t�˻��� �̸� : ";
            cin >> search_name;

            pPBData = SearchName(search_name);
        }
        else if (select_search == MENU_3)
        {
            cout << endl << endl << "\t�˻��� ��ȣ : ";
            cin >> search_number;

            pPBData = SearchNumber(search_number);
        }
        else
        {
            cout << endl << endl << "\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)";
            _getchar();
            continue;
        }

        if (pPBData)
            cout << endl << "\t[���]" << std::setw(10) << pPBData->idx << std::setw(20) << pPBData->name << std::setw(20) << pPBData->number << " (����)";
        else
            cout << endl << "\t[����] �˻��� ����� �����ϴ�. (����)";

        _getchar();
    }
}

PBData* PhoneBook::SearchIdx(const int& _idx)
{
    PBData* pPBData = head;

    while (pPBData != NULL)
    {
        if (pPBData->idx == _idx)
            return pPBData;

        pPBData = pPBData->next;
    }

    return nullptr;
}

PBData* PhoneBook::SearchName(const string& _name)
{
    PBData* pPBData = head;

    while (pPBData != NULL)
    {
        if (pPBData->name.compare(_name) == 0)
            return pPBData;

        pPBData = pPBData->next;
    }

    return nullptr;
}

PBData* PhoneBook::SearchNumber(const string& _number)
{
    PBData* pPBData = head;

    while (pPBData != NULL)
    {
        if (pPBData->number.compare(_number) == 0)
            return pPBData;

        pPBData = pPBData->next;
    }

    return nullptr;
}
