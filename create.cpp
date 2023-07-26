#include "phone_book.h"

void PhoneBook::Create()
{
    string create_name, create_number;

    while (1)
    {
        cout << "\n�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    �߰�    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n";

        cout << "\n\t�̸�(�������� 0) : ";
        cin >> create_name;

        if (create_name.length() == 1 && (create_name.find("0") != string::npos))
            break;

        /* �̸� ��ȭ��ȣ �Է� ��� ���� �޽��� ��� ���� �Ǵ� �߰� */

        cout << "\n\t��ȭ��ȣ(�������� 0) : ";
        cin >> create_number;

        if (create_number.length() == 1 && (create_number.find("0") != string::npos))
            break;

        if (create_name.length() > name_max_len)
            printf("\n\t[����] �̸��� ���� %d�� �Ǵ� �ѱ� %d�ڸ� �ʰ��� �� �����ϴ�. (����)", name_max_len, name_max_len / 2);
        else if (create_number.length() > number_max_len)
            printf("\n\t[����] ��ȭ��ȣ�� ���� %d�ڸ� �ʰ��� �� �����ϴ�. (����)", number_max_len);
        else
        {
            PushBack(create_name, create_number);
            printf("\n\t[����] �߰� �Ǿ����ϴ�. (����)");
        }
        _getchar();
    }
}

void PhoneBook::PushFirst(const string& _name, const string& _number)
{
    PBData* pPBData = new PBData;

    pPBData->prev = nullptr;
    max_idx++;
    pPBData->name = _name;
    pPBData->number = _number;
    pPBData->next = nullptr;

    head = pPBData;
    tail = pPBData;
}

void PhoneBook::PushBack(const string& _name, const string& _number)
{
    if (head == nullptr)
    {
        PushFirst(_name, _number);
        return;
    }

    PBData* pPBData = new PBData;

    pPBData->prev = tail;
    max_idx++;
    pPBData->name = _name;
    pPBData->number = _number;
    pPBData->next = nullptr;

    pPBData->prev->next = pPBData;
    tail = pPBData;
}

void PhoneBook::PushFront(const string& _name, const string& _number)
{
    if (head == nullptr)
    {
        PushFirst(_name, _number);
        return;
    }

    PBData* pPBData = new PBData;

    pPBData->prev = nullptr;
    max_idx++;
    pPBData->name = _name;
    pPBData->number = _number;
    pPBData->next = head;

    pPBData->next->prev = pPBData;
    head = pPBData;
}
