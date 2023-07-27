#include "phone_book.h"

void PhoneBook::Show()
{
    system("cls");

    cout << "▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎ 전화번호부 ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦" << endl;
    cout << endl << std::setw(10) << "No." << std::setw(20) << "이름" << std::setw(25) << "전화번호" << endl;

    if (head == nullptr)
        cout << endl << "\t등록된 번호가 없습니다." << endl;
    else
    {
        PBData* pPBData = head;
        int cnt_idx = 1;

        while (pPBData != nullptr)
        {
            pPBData->idx = cnt_idx++;
            cout << endl << std::setw(10) << pPBData->idx << std::setw(20) << pPBData->name << std::setw(25) << pPBData->number << endl;
            pPBData = pPBData->next;
        }
    }
    cout << endl;
}
