/*
////////////////////////////////////////////////////////////////////////////////////////////////////
(�Ϸ�)
updata.cpp : C++ ��Ÿ��ȭ(string Ŭ���� �߰��� �����÷ο� ����)
update.cpp : �̸� �� ��ȣ ���Ἲ Ȯ�� ��� �߰�
common.cpp : create.cpp isNum �Լ� update.cpp ���Ἲ �˻縦 ���� ���� ���
phone_book.h : string.h ���� ����
common.cpp : C++ ��Ÿ��ȭ(C ��Ÿ��(_fscanf, _fgets) �Լ� ����)
common.cpp : ������ �����ε� ����
common.cpp : _getchar ���� ���� �ذ�
////////////////////////////////////////////////////////////////////////////////////////////////////
* (����)
* ��ü ���� �ּ� �߰�
* XOR ������ ���Ἲ �˻� �� ��ȣȭ ��ȣȭ ��� �߰�
* �ߺ� ã�� ��� �߰�(���� �ߺ� ������ ���� �� ����, ���� ��� �߰�)
* �����ͷ� ������ ����ӵ� ���Ͻ� ������ ���� ����(����� ���� ���� -> Ʈ�� ����)
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
