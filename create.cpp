#include "phone_book.h"

void PhoneBook::Create()
{
    string create_name, create_number;

    while (1)
    {
        cout << "\n▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎    추가    ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n";

        cout << "\n\t이름(이전으로 0) : ";
        cin >> create_name;

        if (create_name.length() == 1 && (create_name.find("0") != string::npos))
            break;

        /* 이름 전화번호 입력 즉시 실패 메시지 출력 여부 판단 추가 */

        cout << "\n\t전화번호(이전으로 0) : ";
        cin >> create_number;

        if (create_number.length() == 1 && (create_number.find("0") != string::npos))
            break;

        if (create_name.length() > name_max_len)
            printf("\n\t[실패] 이름은 영어 %d자 또는 한글 %d자를 초과할 수 없습니다. (엔터)", name_max_len, name_max_len / 2);
        else if (create_number.length() > number_max_len)
            printf("\n\t[실패] 전화번호는 숫자 %d자를 초과할 수 없습니다. (엔터)", number_max_len);
        else
        {
            PushBack(create_name, create_number);
            printf("\n\t[성공] 추가 되었습니다. (엔터)");
        }
        _getchar();
    }
}

void PhoneBook::PushFirst(const string& _name, const string& _number)
{
    PBData* pPBData = new PBData;

    pPBData->prev = nullptr;
    max_idx++;
    pPBData->name = _name;
    pPBData->number = _number;
    pPBData->next = nullptr;

    head = pPBData;
    tail = pPBData;
}

void PhoneBook::PushBack(const string& _name, const string& _number)
{
    if (head == nullptr)
    {
        PushFirst(_name, _number);
        return;
    }

    PBData* pPBData = new PBData;

    pPBData->prev = tail;
    max_idx++;
    pPBData->name = _name;
    pPBData->number = _number;
    pPBData->next = nullptr;

    pPBData->prev->next = pPBData;
    tail = pPBData;
}

void PhoneBook::PushFront(const string& _name, const string& _number)
{
    if (head == nullptr)
    {
        PushFirst(_name, _number);
        return;
    }

    PBData* pPBData = new PBData;

    pPBData->prev = nullptr;
    max_idx++;
    pPBData->name = _name;
    pPBData->number = _number;
    pPBData->next = head;

    pPBData->next->prev = pPBData;
    head = pPBData;
}
