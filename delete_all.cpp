#include "phone_book.h"

void PhoneBook::DeleteAll()
{
    char answer[10];

    while (1)
    {
        memset(answer, 0, sizeof(answer));

        printf("\n�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��  ���λ���  �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

        printf("\n\t���� ������ ���Ͻ� ��� \"���λ���\"�� �Է� ���ּ���(�������� 0) : ");
        _fgets(answer, sizeof(answer), stdin);

        if (strlen(answer) == 1 && strchr(answer, '0'))
            break;

        if (strcmp(answer, "���λ���") == 0)
        {
            if (DeleteAll(this))
                printf("\n\t[����] ���� ���� �Ǿ����ϴ�. (����)");
            else
                printf("\n\t[����] ������ �����Ͱ� �����ϴ�. (����)");

            _getchar();
            break;
        }
        else
        {
            printf("\n\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)");
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
