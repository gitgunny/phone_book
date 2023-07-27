#include "phone_book.h"

bool isNum(const string& str)
{
    for (char const& let : str)
        if (std::isdigit(let) == false)
            return false;

    return true;
}

void PhoneBook::Create()
{
    string create_name, create_number;

    while (1)
    {
        Show();
        cout << endl << "�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    �߰�    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�" << endl;

        cout << endl << "\t�̸�(�������� 0) : ";
        cin >> create_name;

        if (create_name.length() == 1 && (create_name.find("0") != string::npos))
            break;
        if (create_name.length() > name_max_len)
        {
            cout << endl << "\t[����] �̸��� ���� " << name_max_len << "�� �Ǵ� �ѱ� " << name_max_len / 2 << "�ڸ� �ʰ��� �� �����ϴ�. (����)";
            _getchar();
            continue;
        }

        cout << endl << "\t��ȭ��ȣ(�������� 0) : ";
        cin >> create_number;

        if (create_number.length() == 1 && (create_number.find("0") != string::npos))
            break;
        if (create_number.length() > number_max_len || isNum(create_number) == false)
        {
            cout << endl << "\t[����] ��ȭ��ȣ�� ���� " << number_max_len << "�ڸ� �ʰ��� �� �����ϴ�. (����)";
            _getchar();
            continue;
        }

        PushBack(create_name, create_number);
        cout << endl << "\t[����] �߰� �Ǿ����ϴ�. (����)";
        _getchar();
    }
}

void PhoneBook::PushBack(const string& _name, const string& _number)
{
    PBData* pPBData = new PBData(_name, _number);

    if (head == nullptr)
    {
        head = pPBData;
        tail = pPBData;
    }
    else
    {
        pPBData->prev = tail;
        tail->next = pPBData;
        tail = pPBData;
    }

    max_idx++;
}

void PhoneBook::PushFront(const string& _name, const string& _number)
{
    PBData* pPBData = new PBData(_name, _number);

    if (head == nullptr)
    {
        head = pPBData;
        tail = pPBData;
    }
    else
    {
        pPBData->next = head;
        head->prev = pPBData;
        head = pPBData;
    }

    max_idx++;
}
