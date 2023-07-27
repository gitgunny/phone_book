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
        cout << endl << "▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎    삭제    ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦" << endl;

        cout << endl << "\t1. 순번 삭제  2. 이름 삭제  3. 번호 삭제  0. 이전으로 : ";
        select_delete = _getch();

        if (select_delete == MENU_0)
            break;
        else if (select_delete == MENU_1)
        {
            cout << endl << endl << "\t삭제할 순번 : ";
            cin >> delete_idx;

            pPBData = SearchIdx(delete_idx);
        }
        else if (select_delete == MENU_2)
        {
            cout << endl << endl << "\t삭제할 이름 : ";
            cin >> delete_name;

            pPBData = SearchName(delete_name);
        }
        else if (select_delete == MENU_3)
        {
            cout << endl << endl << "\t삭제할 번호 : ";
            cin >> delete_number;

            pPBData = SearchNumber(delete_number);
        }
        else
        {
            cout << endl << endl << "\t[실패] 잘못 입력 하셨습니다. (엔터)";
            _getchar();
            continue;
        }

        if (DeletePBData(pPBData))
            cout << endl << "\t[성공] 삭제 되었습니다. (엔터)";
        else
            cout << endl << "\t[실패] 삭제할 대상이 없습니다. (엔터)";

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
