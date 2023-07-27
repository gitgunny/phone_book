#include "phone_book.h"

void PhoneBook::Show()
{
    system("cls");

    cout << "�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� �� ��ȭ��ȣ�� �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�" << endl;
    cout << endl << std::setw(10) << "No." << std::setw(20) << "�̸�" << std::setw(25) << "��ȭ��ȣ" << endl;

    if (head == nullptr)
        cout << endl << "\t��ϵ� ��ȣ�� �����ϴ�." << endl;
    else
    {
        PBData* pPBData = head;
        int cnt_idx = 1;

        while (pPBData != nullptr)
        {
            pPBData->idx = cnt_idx++;
            cout << endl << std::setw(10) << pPBData->idx << std::setw(20) << pPBData->name << std::setw(25) << pPBData->number << endl;
            pPBData = pPBData->next;
        }
    }
    cout << endl;
}
