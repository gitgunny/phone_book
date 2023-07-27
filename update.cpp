#include "phone_book.h"

void PhoneBook::Update()
{
    int select_update;
    int select_new_update;
    int update_idx;
    string update_name, update_number;
    string update_new_name, update_new_number;
    PBData* pPBData = nullptr;
    bool result;

    while (1)
    {
        Show();
        cout << endl << "�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    ����    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�" << endl;

        printf("\n\t1. ���� ����  2. �̸� ����  3. ��ȣ ����  0. �������� : ");
        select_update = _getch();

        if (select_update == MENU_0)
            break;
        else if (select_update == MENU_1)
        {
            cout << endl << endl << "\t������ ���� : ";
            cin >> update_idx;

            pPBData = SearchIdx(update_idx);
        }
        else if (select_update == MENU_2)
        {
            cout << endl << endl << "\t������ �̸� : ";
            cin >> update_name;

            pPBData = SearchName(update_name);
        }
        else if (select_update == MENU_3)
        {
            cout << endl << endl << "\t������ ��ȣ : ";
            cin >> update_number;

            pPBData = SearchNumber(update_number);
        }
        else
        {
            cout << endl << endl << "\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)";
            _getchar();
            continue;
        }

        if (pPBData == nullptr)
        {
            cout << endl << "\t[����] ������ ����� �����ϴ�. (����)";
            _getchar();
            continue;
        }

        while (1)
        {
            cout << endl << "\t1. �̸� ����  2. ��ȣ ����  0. �������� : ";
            select_new_update = _getch();

            if (select_new_update == MENU_0)
                break;
            else if (select_new_update == MENU_1)
            {
                cout << endl << endl << "\t������ �̸� : ";
                cin >> update_new_name;

                result = UpdateName(pPBData, update_new_name);
            }
            else if (select_new_update == MENU_2)
            {
                cout << endl << endl << "\t������ ��ȣ : ";
                cin >> update_new_number;

                result = UpdateNumber(pPBData, update_new_number);
            }
            else
            {
                cout << endl << endl << "\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)";
                _getchar();
                continue;
            }

            if (result)
            {
                cout << endl << "\t[����] ���� �Ǿ����ϴ�. (����)";
                _getchar();
                break;
            }
            else
            {
                if (select_new_update == MENU_1)
                    cout << endl << "\t[����] �̸��� ���� " << name_max_len << "�� �Ǵ� �ѱ� " << name_max_len / 2 << "�ڸ� �ʰ��� �� �����ϴ�. (����)";
                else
                    cout << endl << "\t[����] ��ȭ��ȣ�� ���� " << number_max_len << "�ڸ� �ʰ��� �� �����ϴ�. (����)";

                _getchar();
                continue;
            }
        }
    }
}

int PhoneBook::UpdateName(PBData* _pPBData, const string& _name)
{
    if (_name.length() > name_max_len)
        return 0;

    _pPBData->name = _name;
    return 1;
}

int PhoneBook::UpdateNumber(PBData* _pPBData, const string& _number)
{
    if (_number.length() > number_max_len || isNum(_number) == false)
        return 0;

    _pPBData->number = _number;
    return 1;
}
