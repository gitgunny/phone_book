#include "phone_book.h"

void PhoneBook::Update()
{
	int select_update;
	int update_idx;
	char update_name[name_max_len];
	char update_number[number_max_len];
	PBData *pPBData = nullptr;

	int select_new_update;
	char update_new_name[name_max_len];
	char update_new_number[number_max_len];
	bool result = 0;

	while (1)
	{
		select_update = 0;
		update_idx = 0;
		memset(update_name, '\0', sizeof(update_name));
		memset(update_number, '\0', sizeof(update_number));

		system("cls");

		printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    ����    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

		printf("\n\t1. ���� ����  2. �̸� ����  3. ��ȣ ����  0. �������� : ");
		select_update = _getch();

		if (select_update == MENU_0)
			break;
		else if (select_update == MENU_1)
		{
			printf("\n\n\t������ ���� : ");
			_fscanf(stdin, "%d", &update_idx);

			pPBData = SearchIdx(&update_idx);
		}
		else if (select_update == MENU_2)
		{
			printf("\n\n\t������ �̸� : ");
			_fgets(update_name, sizeof(update_name), stdin);

			pPBData = SearchName(update_name);
		}
		else if (select_update == MENU_3)
		{
			printf("\n\n\t������ ��ȣ : ");
			_fgets(update_number, sizeof(update_number), stdin);

			pPBData = SearchNumber(update_number);
		}
		else
		{
			printf("\n\n\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)");
			_getchar();
		}

		while (select_update >= MENU_1 && select_update <= MENU_3)
		{
			if (pPBData == nullptr)
			{
				printf("\n\t[����] ������ ����� �����ϴ�. (����)");
				_getchar();
				break;
			}

			select_new_update = 0;
			memset(update_new_name, 0, sizeof(update_new_name));
			memset(update_new_number, 0, sizeof(update_new_number));

			printf("\n\t1. �̸� ����  2. ��ȣ ����  0. �������� : ");
			select_new_update = _getch();

			if (select_new_update == MENU_0)
				break;
			else if (select_new_update == MENU_1)
			{
				printf("\n\n\t������ �̸� : ");
				_fgets(update_new_name, sizeof(update_new_name), stdin);

				result = UpdateName(pPBData, update_new_name);
			}
			else if (select_new_update == MENU_2)
			{
				printf("\n\n\t������ ��ȣ : ");
				_fgets(update_new_number, sizeof(update_new_number), stdin);

				result = UpdateNumber(pPBData, update_new_number);
			}
			else
			{
				printf("\n\n\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)");
				_getchar();
			}

			if (select_new_update >= MENU_1 && select_new_update <= MENU_2)
			{
				// result �ӽ� ����
				printf("\n\t[����] ���� �Ǿ����ϴ�. (����)");
				_getchar();
				break;
			}
		}
	}
}

/* �̸� ��ȭ��ȣ ���� ���� �߰�(Create�� CheckLength, CheckNumber �̿�) */

int PhoneBook::UpdateName(PBData *_pPBData, const char *_name)
{
	if (_pPBData != nullptr)
	{
		strcpy(_pPBData->name, _name);

		return 1;
	}

	return 0;
}

int PhoneBook::UpdateNumber(PBData *_pPBData, const char *_number)
{
	if (_pPBData != nullptr)
	{
		strcpy(_pPBData->number, _number);

		return 1;
	}

	return 0;
}