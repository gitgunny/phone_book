#include "phone_book.h"

void PhoneBook::DeleteAll()
{
    string answer;

    while (1)
    {
        Show();
        cout << endl << "�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��  ���λ���  �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�" << endl;

        cout << endl << "\t���� ������ ���Ͻ� ��� \"���λ���\"�� �Է� ���ּ���(�������� 0) : ";
        cin >> answer;

        if (answer.length() == 1 && (answer.find('0') != string::npos))
            break;

        if (answer.find("���λ���") == string::npos)
        {
            cout << endl << "\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)";
            _getchar();
            continue;
        }

        DeletePhoneBook();
        cout << endl << "\t[����] ���� ���� �Ǿ����ϴ�. (����)";
        _getchar();
        break;
    }
}

void PhoneBook::DeletePhoneBook()
{
    PBData* pPBData = head;
    PBData* pTemp = nullptr;

    while (pPBData != nullptr)
    {
        pTemp = pPBData->next;
        delete pPBData;
        pPBData = pTemp;
    }

    max_idx = 0;
    head = nullptr;
    tail = nullptr;
}
