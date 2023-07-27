#include "phone_book.h"

void PhoneBook::DeleteAll()
{
    string answer;

    while (1)
    {
        Show();
        cout << endl << "▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎  전부삭제  ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦" << endl;

        cout << endl << "\t전부 삭제를 원하실 경우 \"전부삭제\"를 입력 해주세요(이전으로 0) : ";
        cin >> answer;

        if (answer.length() == 1 && (answer.find('0') != string::npos))
            break;

        if (answer.find("전부삭제") == string::npos)
        {
            cout << endl << "\t[실패] 잘못 입력 하셨습니다. (엔터)";
            _getchar();
            continue;
        }

        DeletePhoneBook();
        cout << endl << "\t[성공] 전부 삭제 되었습니다. (엔터)";
        _getchar();
        break;
    }
}

void PhoneBook::DeletePhoneBook()
{
    PBData* pPBData = head;
    PBData* pTemp = nullptr;

    while (pPBData != nullptr)
    {
        pTemp = pPBData->next;
        delete pPBData;
        pPBData = pTemp;
    }

    max_idx = 0;
    head = nullptr;
    tail = nullptr;
}
