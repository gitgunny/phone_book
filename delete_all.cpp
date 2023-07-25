#include "phone_book.h"

void PhoneBook::DeleteAll()
{
    char answer[10];

    while (1)
    {
        memset(answer, 0, sizeof(answer));

        printf("\n▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎  전부삭제  ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");

        printf("\n\t전부 삭제를 원하실 경우 \"전부삭제\"를 입력 해주세요(이전으로 0) : ");
        _fgets(answer, sizeof(answer), stdin);

        if (strlen(answer) == 1 && strchr(answer, '0'))
            break;

        if (strcmp(answer, "전부삭제") == 0)
        {
            if (DeleteAll(this))
                printf("\n\t[성공] 전부 삭제 되었습니다. (엔터)");
            else
                printf("\n\t[실패] 삭제할 데이터가 없습니다. (엔터)");

            _getchar();
            break;
        }
        else
        {
            printf("\n\t[실패] 잘못 입력 하셨습니다. (엔터)");
            _getchar();
        }
    }
}

int PhoneBook::DeleteAll(const PhoneBook* _phone_book)
{
    if (head != nullptr)
    {
        PBData* pPBData = head;
        PBData* pTmpPBData = nullptr;

        while (pPBData != nullptr)
        {
            pTmpPBData = pPBData->next;
            delete pPBData;
            pPBData = pTmpPBData;
        }

        max_idx = 0;
        head = nullptr;
        tail = nullptr;

        return 1;
    }
    else
        return 0;
}
