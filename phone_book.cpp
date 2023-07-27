/*

* ��ü ���� �ּ� �߰�
* ���� XOR���� ����� ������ ��ȣȭ ��ȣȭ ��� �߰�
* ���� �����ͷ� ������ ����ӵ� ���Ͻ� ������ ���� ����(����� ���� ���� -> Ʈ�� ����)
*
* ALL : ���� �̸� ��ȣ �Է� �ܰ迡�� �߰� ��� ó�� 0 �Է½� �������� ��� �߰�
* search.cpp : �ߺ� ã�� ��� �߰�(���� �ߺ� ������ ���� �� ����, ���� ��� �߰�)
* update.cpp : �̸� ��ȭ��ȣ ���� ���� �߰�(CheckLength, CheckNumber �̿�)

////////////////////////////////////////////////////////////////////////////////////////////////////
phone_book.h : �Ϻ� �ּ� �߰� �� ����
file.cpp : C++ ��Ÿ��ȭ
common.cpp : ���� ����� ��� Ȱ��ȭ
phone_book.h : ���α׷� ����� �Ҹ��ڷ� �޸� �ʱ�ȭ Ȱ��ȭ(���� ����¿� ����)
delete_all.cpp : C++ ��Ÿ��ȭ
delete_all.cpp : string Ŭ���� �߰��� �����÷ο� ����
delete ��� : delete, delete_all ���� �Լ��� ����

(����)
search.cpp : C++ ��Ÿ��ȭ
search.cpp : search ������� delete, update ��� ����ȭ

delete.cpp : C++ ��Ÿ��ȭ
delete.cpp : string Ŭ���� �߰��� �����÷ο� ����

updata.cpp : C++ ��Ÿ��ȭ

common.cpp : C++ ��Ÿ��ȭ
common.cpp : ������ �����ε� Search�� Ȱ��ȭ �̿� ����
////////////////////////////////////////////////////////////////////////////////////////////////////

*/

#include "phone_book.h"

int main()
{
    PhoneBook phone_book;
    int select_menu;

    while (1)
    {
        phone_book.Show();
        cout << "�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�" << endl;
        cout << "�� 1. �˻�  �� 2. �߰�  �� 3. ����  �� 4. ����  �� 5. ���λ���  �� 0. ����  ��" << endl;
        cout << "�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�" << endl;

        switch (select_menu = _getch())
        {
        case MENU_1:
            phone_book.Search();
            break;
        case MENU_2:
            phone_book.Create();
            break;
        case MENU_3:
            phone_book.Update();
            break;
        case MENU_4:
            phone_book.Delete();
            break;
        case MENU_5:
            phone_book.DeleteAll();
            break;
        case MENU_0:
            cout << endl << "\t���α׷��� �����մϴ�. (����)";
            _getchar();
            return 0;
        default:
            cout << endl << "\t�߸� �Է� �ϼ̽��ϴ�. �ٽ� �Է� ���ּ��� (����)";
            _getchar();
            break;
        }
    }

    return 0;
}
