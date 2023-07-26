#include "phone_book.h"

void PhoneBook::Show(const int& menu)
{
    if (menu == MAIN)
    {
        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� �� ��ȭ��ȣ�� �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");
        printf("\n\tNo.\t�̸�\t\t��ȭ��ȣ\n");
        Show(MENU_1);
        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");
        printf("�� 1. �˻�  �� 2. �߰�  �� 3. ����  �� 4. ����  �� 5. ���λ���  �� 0. ����  ��\n");
        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");
    }

    else if (menu == MENU_1)
    {
        if (head == nullptr)
            printf("\n\t��ϵ� ��ȣ�� �����ϴ�.\n");
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
