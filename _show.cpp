#include "phone_book.h"

void PhoneBook::Show()
{
	printf("\n\tNo.\t�̸�\t\t��ȭ��ȣ\n");

	if (head == nullptr)
		printf("\n\t��ϵ� ��ȣ�� �����ϴ�.\n");
	else
	{
		PBData *pPBData = head;
		int cnt_idx = 1;

		while (pPBData != nullptr)
		{
			pPBData->idx = cnt_idx++;
			printf("\n\t%-5d\t%-15s\t%-15s\n", pPBData->idx, pPBData->name, pPBData->number);
			pPBData = pPBData->next;
		}
	}
	printf("\n");
}