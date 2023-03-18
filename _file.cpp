#include "phone_book.h"

void PhoneBook::ReadFile()
{
    FILE *fp = fopen("phone_book.pb", "rt");

    int max_idx;
    char name[name_max_len];
    char number[number_max_len];

    fscanf(fp, "%d\n", &max_idx);
    for (int i = 0; i < max_idx; i++)
    {
        fscanf(fp, "%s %s\n", name, number);
        PushBack(name, number);
    }

    fclose(fp);
}

void PhoneBook::WriteFile()
{
    FILE *fp = fopen("phone_book.pb", "wt");

    if (head != nullptr)
    {
        PBData *pPBData = head;
        PBData *pTmpPBData = nullptr;

        fprintf(fp, "%d\n", max_idx);
        while (pPBData != nullptr)
        {
            fprintf(fp, "%s %s\n", pPBData->name, pPBData->number);
            pTmpPBData = pPBData->next;
            delete pPBData;
            pPBData = pTmpPBData;
        }

        max_idx = 0;
        head = nullptr;
        tail = nullptr;
    }

    fclose(fp);
}