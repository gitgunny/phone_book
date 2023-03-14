#include "phone_book.h"

void PhoneBook::Search()
{
	int select_search;
	int search_idx;
	char search_name[name_max_len];
	char search_number[number_max_len];
	PBData *pPBData = nullptr;

	while (1)
	{
		select_search = 0;
		search_idx = 0;
		memset(search_name, '\0', sizeof(search_name));
		memset(search_number, '\0', sizeof(search_number));

		system("cls");

		printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    �˻�    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

		printf("\n\t1. ���� �˻�  2. �̸� �˻�  3. ��ȣ �˻�  0. �������� : ");
		select_search = _getch();

		if (select_search == MENU_0)
			break;
		else if (select_search == MENU_1)
		{
			printf("\n\n\t�˻��� ���� : ");
			_fscanf(stdin, "%d", &search_idx);

			pPBData = SearchIdx(&search_idx);
		}
		else if (select_search == MENU_2)
		{
			printf("\n\n\t�˻��� �̸� : ");
			_fgets(search_name, sizeof(search_name), stdin);

			pPBData = SearchName(search_name);
		}
		else if (select_search == MENU_3)
		{
			printf("\n\n\t�˻��� ��ȣ : ");
			_fgets(search_number, sizeof(search_number), stdin);

			pPBData = SearchNumber(search_number);
		}
		else
		{
			printf("\n\n\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)");
			_getchar();
		}

		if (select_search >= MENU_1 && select_search <= MENU_3)
		{
			if (pPBData != nullptr)
				printf("\n\t[���]\t%-5d\t%-15s\t%-15s (����)", pPBData->idx, pPBData->name, pPBData->number);
			else
				printf("\n\t[����] �˻��� ����� �����ϴ�. (����)");

			_getchar();
		}
	}
}

/* �ߺ� ã�� ��� �߰�(���� �ߺ� ������ ���� �� ����, ���� ��� �߰�) */

PBData *PhoneBook::SearchIdx(const int *_idx)
{
	PBData *pPBData = head;

	while (pPBData != NULL)
	{
		if (pPBData->idx == *_idx)
			return pPBData;

		pPBData = pPBData->next;
	}

	return nullptr;
}

PBData *PhoneBook::SearchName(const char *_name)
{
	PBData *pPBData = head;

	while (pPBData != NULL)
	{
		if (strcmp(pPBData->name, _name) == 0)
			return pPBData;

		pPBData = pPBData->next;
	}

	return nullptr;
}

PBData *PhoneBook::SearchNumber(const char *_number)
{
	PBData *pPBData = head;

	while (pPBData != NULL)
	{
		if (strcmp(pPBData->number, _number) == 0)
			return pPBData;

		pPBData = pPBData->next;
	}

	return nullptr;
}