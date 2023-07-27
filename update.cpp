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
        cout << endl << "▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎    수정    ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦" << endl;

        printf("\n\t1. 순번 선택  2. 이름 선택  3. 번호 선택  0. 이전으로 : ");
        select_update = _getch();

        if (select_update == MENU_0)
            break;
        else if (select_update == MENU_1)
        {
            cout << endl << endl << "\t선택할 순번 : ";
            cin >> update_idx;

            pPBData = SearchIdx(update_idx);
        }
        else if (select_update == MENU_2)
        {
            cout << endl << endl << "\t선택할 이름 : ";
            cin >> update_name;

            pPBData = SearchName(update_name);
        }
        else if (select_update == MENU_3)
        {
            cout << endl << endl << "\t선택할 번호 : ";
            cin >> update_number;

            pPBData = SearchNumber(update_number);
        }
        else
        {
            cout << endl << endl << "\t[실패] 잘못 입력 하셨습니다. (엔터)";
            _getchar();
            continue;
        }

        if (pPBData == nullptr)
        {
            cout << endl << "\t[실패] 수정할 대상이 없습니다. (엔터)";
            _getchar();
            continue;
        }

        while (1)
        {
            cout << endl << "\t1. 이름 수정  2. 번호 수정  0. 이전으로 : ";
            select_new_update = _getch();

            if (select_new_update == MENU_0)
                break;
            else if (select_new_update == MENU_1)
            {
                cout << endl << endl << "\t수정할 이름 : ";
                cin >> update_new_name;

                result = UpdateName(pPBData, update_new_name);
            }
            else if (select_new_update == MENU_2)
            {
                cout << endl << endl << "\t수정할 번호 : ";
                cin >> update_new_number;

                result = UpdateNumber(pPBData, update_new_number);
            }
            else
            {
                cout << endl << endl << "\t[실패] 잘못 입력 하셨습니다. (엔터)";
                _getchar();
                continue;
            }

            if (result)
            {
                cout << endl << "\t[성공] 수정 되었습니다. (엔터)";
                _getchar();
                break;
            }
            else
            {
                if (select_new_update == MENU_1)
                    cout << endl << "\t[실패] 이름은 영어 " << name_max_len << "자 또는 한글 " << name_max_len / 2 << "자를 초과할 수 없습니다. (엔터)";
                else
                    cout << endl << "\t[실패] 전화번호는 숫자 " << number_max_len << "자를 초과할 수 없습니다. (엔터)";

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
