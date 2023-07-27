#include "phone_book.h"

void PhoneBook::Delete()
{
    int select_delete;
    int delete_idx;
    char delete_name[name_max_len];
    char delete_number[number_max_len];
    PBData* pPBData = nullptr;
    bool result = 0;

    while (1)
    {
        select_delete = 0;
        delete_idx = 0;
        memset(delete_name, '\0', sizeof(delete_name));
        memset(delete_number, '\0', sizeof(delete_number));

        printf("\n�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    ����    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

        printf("\n\t1. ���� ����  2. �̸� ����  3. ��ȣ ����  0. �������� : ");
        select_delete = _getch();

        if (select_delete == MENU_0)
            break;
        else if (select_delete == MENU_1)
        {
            printf("\n\n\t������ ���� : ");
            _fscanf(stdin, "%d", &delete_idx);

            pPBData = SearchIdx(delete_idx);
        }
        else if (select_delete == MENU_2)
        {
            printf("\n\n\t������ �̸� : ");
            _fgets(delete_name, sizeof(delete_name), stdin);

            pPBData = SearchName(delete_name);
        }
        else if (select_delete == MENU_3)
        {
            printf("\n\n\t������ ��ȣ : ");
            _fgets(delete_number, sizeof(delete_number), stdin);

            pPBData = SearchNumber(delete_number);
        }
        else
        {
            printf("\n\n\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)");
            _getchar();
        }

        if (select_delete >= MENU_1 && select_delete <= MENU_3)
        {
            if (DeletePBData(pPBData))
            {
                printf("\n\t[����] ���� �Ǿ����ϴ�. (����)");
            }
            else
                printf("\n\t[����] ������ ����� �����ϴ�. (����)");

            _getchar();
        }
    }
}

int PhoneBook::DeletePBData(const PBData* _pPBData)
{
    if (_pPBData != nullptr)
    {
        if (_pPBData == head)
            head = _pPBData->next;
        else if (_pPBData == tail)
        {
            if (_pPBData->prev == head)
                head->next = nullptr;
            else
            {
                tail = _pPBData->prev;
                tail->next = nullptr;
            }
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

    return 0;
}
