#include "phone_book.h"

// ���ڿ��� �ּ� ���ڼ��� �ִ� ���ڼ��� ������ �ʰ��ϸ� 1 ��ȯ
int CheckLength(const char *_string, int _min_length, int _max_length)
{
	if (strlen(_string) < _min_length || strlen(_string) > _max_length)
		return 1;

	return 0;
}

// ���ڿ��� ������(-), ���� �̿� ���ڰ� ���ԵǾ� �ִٸ� 1 ��ȯ
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

		printf("\n�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    �߰�    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

		printf("\n\t�̸�(�������� 0) : ");
		_fgets(create_name, sizeof(create_name), stdin);

		if (strlen(create_name) == 1 && strchr(create_name, '0'))
			break;

		/* �̸� ��ȭ��ȣ �Է� ��� ���� �޽��� ��� ���� �Ǵ� �߰� */

		printf("\n\t��ȭ��ȣ(�������� 0) : ");
		_fgets(create_number, sizeof(create_number), stdin);

		if (strlen(create_number) == 1 && strchr(create_number, '0'))
			break;

		/* ���� �����÷ο� ���� �Լ� �ٵ�� */

		if (CheckLength(create_name, 1, name_max_len - 3))
			printf("\n\t[����] �̸��� ���� %d�� �Ǵ� �ѱ� %d�ڸ� ���� �� �����ϴ�. (����)", name_max_len - 3, (name_max_len - 3) / 2);
		else if (CheckLength(create_number, 1, number_max_len - 3) || CheckNumber(create_number))
			printf("\n\t[����] ��ȭ��ȣ�� ����(������(-) ����)�� �Է��� �� �ְ� %d�ڸ� ���� �� �����ϴ�. (����)", number_max_len - 3);
		else
		{
			PushBack(create_name, create_number);
			printf("\n\t[����] �߰� �Ǿ����ϴ�. (����)");
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