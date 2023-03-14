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

		printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎    수정    ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");

		printf("\n\t1. 순번 선택  2. 이름 선택  3. 번호 선택  0. 이전으로 : ");
		select_update = _getch();

		if (select_update == MENU_0)
			break;
		else if (select_update == MENU_1)
		{
			printf("\n\n\t선택할 순번 : ");
			_fscanf(stdin, "%d", &update_idx);

			pPBData = SearchIdx(&update_idx);
		}
		else if (select_update == MENU_2)
		{
			printf("\n\n\t선택할 이름 : ");
			_fgets(update_name, sizeof(update_name), stdin);

			pPBData = SearchName(update_name);
		}
		else if (select_update == MENU_3)
		{
			printf("\n\n\t선택할 번호 : ");
			_fgets(update_number, sizeof(update_number), stdin);

			pPBData = SearchNumber(update_number);
		}
		else
		{
			printf("\n\n\t[실패] 잘못 입력 하셨습니다. (엔터)");
			_getchar();
		}

		while (select_update >= MENU_1 && select_update <= MENU_3)
		{
			if (pPBData == nullptr)
			{
				printf("\n\t[실패] 수정할 대상이 없습니다. (엔터)");
				_getchar();
				break;
			}

			select_new_update = 0;
			memset(update_new_name, 0, sizeof(update_new_name));
			memset(update_new_number, 0, sizeof(update_new_number));

			printf("\n\t1. 이름 수정  2. 번호 수정  0. 이전으로 : ");
			select_new_update = _getch();

			if (select_new_update == MENU_0)
				break;
			else if (select_new_update == MENU_1)
			{
				printf("\n\n\t수정할 이름 : ");
				_fgets(update_new_name, sizeof(update_new_name), stdin);

				result = UpdateName(pPBData, update_new_name);
			}
			else if (select_new_update == MENU_2)
			{
				printf("\n\n\t수정할 번호 : ");
				_fgets(update_new_number, sizeof(update_new_number), stdin);

				result = UpdateNumber(pPBData, update_new_number);
			}
			else
			{
				printf("\n\n\t[실패] 잘못 입력 하셨습니다. (엔터)");
				_getchar();
			}

			if (select_new_update >= MENU_1 && select_new_update <= MENU_2)
			{
				// result 임시 변수
				printf("\n\t[성공] 수정 되었습니다. (엔터)");
				_getchar();
				break;
			}
		}
	}
}

/* 이름 전화번호 제한 조건 추가(Create의 CheckLength, CheckNumber 이용) */

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