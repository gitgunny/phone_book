#include "phone_book.h"

void PhoneBook::Delete()
{
    int select_delete;
    int delete_idx;
    string delete_name, delete_number;
    PBData* pPBData = nullptr;

    while (1)
    {
        Show();
        cout << endl << "�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    ����    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�" << endl;

        cout << endl << "\t1. ���� ����  2. �̸� ����  3. ��ȣ ����  0. �������� : ";
        select_delete = _getch();

        if (select_delete == MENU_0)
            break;
        else if (select_delete == MENU_1)
        {
            cout << endl << endl << "\t������ ���� : ";
            cin >> delete_idx;

            pPBData = SearchIdx(delete_idx);
        }
        else if (select_delete == MENU_2)
        {
            cout << endl << endl << "\t������ �̸� : ";
            cin >> delete_name;

            pPBData = SearchName(delete_name);
        }
        else if (select_delete == MENU_3)
        {
            cout << endl << endl << "\t������ ��ȣ : ";
            cin >> delete_number;

            pPBData = SearchNumber(delete_number);
        }
        else
        {
            cout << endl << endl << "\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)";
            _getchar();
            continue;
        }

        if (DeletePBData(pPBData))
            cout << endl << "\t[����] ���� �Ǿ����ϴ�. (����)";
        else
            cout << endl << "\t[����] ������ ����� �����ϴ�. (����)";

        _getchar();
    }
}

int PhoneBook::DeletePBData(const PBData* _pPBData)
{
    if (_pPBData == nullptr)
        return 0;

    if (_pPBData == head)
    {
        if (head == tail)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = _pPBData->next;
            head->prev = nullptr;
        }
    }
    else if (_pPBData == tail)
    {
        tail = _pPBData->prev;
        tail->next = nullptr;
    }
    else
    {
        _pPBData->prev->next = _pPBData->next;
        _pPBData->next->prev = _pPBData->prev;
    }
    delete _pPBData;
    max_idx--;

    return 1;
}
