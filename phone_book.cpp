#include "phone_book.h"

void _getchar()
{
	getchar();
	fflush(stdin); // 출력 버퍼 비우기
	rewind(stdin); // 입력 버퍼 비우기
}

void _fscanf(FILE *_Stream, const char *_Format, ...)
{
	fscanf(_Stream, _Format);
	fflush(_Stream); // 출력 버퍼 비우기
	rewind(_Stream); // 입력 버퍼 비우기
}

void _fgets(char *_Buffer, int _MaxCount, FILE *_Stream)
{
	fgets(_Buffer, _MaxCount, _Stream);
	_Buffer[strlen(_Buffer) - 1] = '\0'; // 마지막 줄바꿈 문자 비우기
	fflush(_Stream);					 // 출력 버퍼 비우기
	rewind(_Stream);					 // 입력 버퍼 비우기
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