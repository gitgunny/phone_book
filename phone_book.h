#pragma once

#include <iostream>
#include <conio.h>	// getch
#include <string.h> // strlen, strcpy, strcmp

enum
{
	MENU_0 = 48,
	MENU_1,
	MENU_2,
	MENU_3,
	MENU_4,
	MENU_5
};

const unsigned int name_max_len = 15;
const unsigned int number_max_len = 20;

struct PBData
{
	PBData *prev;
	int idx;
	char name[name_max_len];
	char number[number_max_len];
	PBData *next;
};

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

private:
	int max_idx;
	PBData *head;
	PBData *tail;

public:
	void Show(); // Search ���� ����?
	void Search();
	void Create();
	void Update();
	void Delete();
	void DeleteAll();

private:
	PBData *SearchIdx(const int *_idx);
	PBData *SearchName(const char *_name);
	PBData *SearchNumber(const char *_number);

	void CreateFirst(const char *_name, const char *_number);
	void CreateBack(const char *_name, const char *_number);
	void CreateFront(const char *_name, const char *_number);

	int UpdateName(PBData *_pPBData, const char *_name);
	int UpdateNumber(PBData *_pPBData, const char *_number);

	int Delete(PBData *_pPBData);

	int DeleteAll(PhoneBook *_phone_book);
};

void _getchar();										  // ���� �Է¿�(���� ���� ����)
void _fscanf(FILE *_Stream, const char *_Format, ...);	  // ���� �Է¿�(fgets�� ���ڿ� �̿� �Է� �Ұ�)
void _fgets(char *_Buffer, int _MaxCount, FILE *_Stream); // ���ڿ� �Է¿�(fscanf�� ���� �Է� �Ұ�)