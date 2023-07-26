#include "phone_book.h"

void PhoneBook::Show(const int& menu)
{
    if (menu == MAIN)
    {
        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎ 전화번호부 ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");
        printf("\n\tNo.\t이름\t\t전화번호\n");
        Show(MENU_1);
        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");
        printf("▦ 1. 검색  ▦ 2. 추가  ▦ 3. 수정  ▦ 4. 삭제  ▦ 5. 전부삭제  ▦ 0. 종료  ▦\n");
        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");
    }

    else if (menu == MENU_1)
    {
        if (head == nullptr)
            printf("\n\t등록된 번호가 없습니다.\n");
        else
        {
            PBData* pPBData = head;
            int cnt_idx = 1;

            while (pPBData != nullptr)
            {
                pPBData->idx = cnt_idx++;
                // printf("\n\t%-5d\t%-15s\t%-15s\n", pPBData->idx, pPBData->name, pPBData->number);
                cout << "\n\t" << pPBData->idx << "\t" << pPBData->name << "\t" << pPBData->number << "\n";
                pPBData = pPBData->next;
            }
        }
        printf("\n");
    }
}
