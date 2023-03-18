#include "phone_book.h"

// 문자열의 최소 글자수와 최대 글자수의 범위를 초과하면 1 반환
int CheckLength(const char *_string, int _min_length, int _max_length)
{
	if (strlen(_string) < _min_length || strlen(_string) > _max_length)
		return 1;

	return 0;
}

// 문자열에 하이픈(-), 숫자 이외 문자가 포함되어 있다면 1 반환
int CheckNumber(const char *_number)
{
	for (int i = 0; i < strlen(_number); i++)
	{
		if (!(_number[i] == '-' || _number[i] >= '0' && _number[i] <= '9'))
			return 1;
	}

	return 0;
}

void PhoneBook::Create()
{
	char create_name[name_max_len];
	char create_number[number_max_len];

	while (1)
	{
		memset(create_name, '\0', sizeof(create_name));
		memset(create_number, '\0', sizeof(create_number));

		printf("\n▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎    추가    ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");

		printf("\n\t이름(이전으로 0) : ");
		_fgets(create_name, sizeof(create_name), stdin);

		if (strlen(create_name) == 1 && strchr(create_name, '0'))
			break;

		/* 이름 전화번호 입력 즉시 실패 메시지 출력 여부 판단 추가 */

		printf("\n\t전화번호(이전으로 0) : ");
		_fgets(create_number, sizeof(create_number), stdin);

		if (strlen(create_number) == 1 && strchr(create_number, '0'))
			break;

		/* 버퍼 오버플로우 방지 함수 다듬기 */

		if (CheckLength(create_name, 1, name_max_len - 3))
			printf("\n\t[실패] 이름은 영어 %d자 또는 한글 %d자를 넘을 수 없습니다. (엔터)", name_max_len - 3, (name_max_len - 3) / 2);
		else if (CheckLength(create_number, 1, number_max_len - 3) || CheckNumber(create_number))
			printf("\n\t[실패] 전화번호는 숫자(하이픈(-) 포함)만 입력할 수 있고 %d자를 넘을 수 없습니다. (엔터)", number_max_len - 3);
		else
		{
			PushBack(create_name, create_number);
			printf("\n\t[성공] 추가 되었습니다. (엔터)");
		}
		_getchar();
	}
}

void PhoneBook::PushFirst(const char *_name, const char *_number)
{
	PBData *pPBData = new PBData;

	pPBData->prev = nullptr;
	max_idx++;
	strcpy(pPBData->name, _name);
	strcpy(pPBData->number, _number);
	pPBData->next = nullptr;

	head = pPBData;
	tail = pPBData;
}

void PhoneBook::PushBack(const char *_name, const char *_number)
{
	if (head == nullptr)
	{
		PushFirst(_name, _number);
		return;
	}

	PBData *pPBData = new PBData;

	pPBData->prev = tail;
	max_idx++;
	strcpy(pPBData->name, _name);
	strcpy(pPBData->number, _number);
	pPBData->next = nullptr;

	pPBData->prev->next = pPBData;
	tail = pPBData;
}

void PhoneBook::PushFront(const char *_name, const char *_number)
{
	if (head == nullptr)
	{
		PushFirst(_name, _number);
		return;
	}

	PBData *pPBData = new PBData;

	pPBData->prev = nullptr;
	max_idx++;
	strcpy(pPBData->name, _name);
	strcpy(pPBData->number, _number);
	pPBData->next = head;

	pPBData->next->prev = pPBData;
	head = pPBData;
}