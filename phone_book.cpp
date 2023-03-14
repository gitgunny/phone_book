#include "phone_book.h"

void _getchar()
{
	getchar();
	fflush(stdin); // ��� ���� ����
	rewind(stdin); // �Է� ���� ����
}

void _fscanf(FILE *_Stream, const char *_Format, ...)
{
	fscanf(_Stream, _Format);
	fflush(_Stream); // ��� ���� ����
	rewind(_Stream); // �Է� ���� ����
}

void _fgets(char *_Buffer, int _MaxCount, FILE *_Stream)
{
	fgets(_Buffer, _MaxCount, _Stream);
	_Buffer[strlen(_Buffer) - 1] = '\0'; // ������ �ٹٲ� ���� ����
	fflush(_Stream);					 // ��� ���� ����
	rewind(_Stream);					 // �Է� ���� ����
}

PhoneBook::PhoneBook() : max_idx(0), head(nullptr), tail(nullptr)
{
}

PhoneBook::~PhoneBook()
{
	if (head != nullptr)
	{
		PBData *pPBData = head;
		PBData *pTmpPBData = nullptr;

		while (pPBData != nullptr)
		{
			pTmpPBData = pPBData->next;
			delete pPBData;
			pPBData = pTmpPBData;
		}

		max_idx = 0;
		head = nullptr;
		tail = nullptr;
	}
}