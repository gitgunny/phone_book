/*

* ��ü ���� �ּ� �߰�
* ���� XOR���� ����� ������ ��ȣȭ ��ȣȭ ��� �߰�
* ���� �����ͷ� ������ ����ӵ� ���Ͻ� ������ ���� ����(����� ���� ���� -> Ʈ�� ����)
*
* ALL : ���� �̸� ��ȣ �Է� �ܰ迡�� �߰� ��� ó�� 0 �Է½� �������� ��� �߰�
* search.cpp : �ߺ� ã�� ��� �߰�(���� �ߺ� ������ ���� �� ����, ���� ��� �߰�)
* update.cpp : �̸� ��ȭ��ȣ ���� ���� �߰�(CheckLength, CheckNumber �̿�)

////////////////////////////////////////////////////////////////////////////////////////////////////
��� �Ű����� ������ ���� -> ���۷��� ���� ���� �� ����ȭ
string Ŭ���� �߰��� �����÷ο� �ذ�
create �̸� ��ȭ��ȣ �Է� ��� ���Ἲ Ȯ��(������ Ȯ�� ����)(������)

(���� ��Ȱ��ȭ)
���� ����� ��� ��Ȱ��ȭ
������ �����ε� ��� ��Ȱ��ȭ(NameNumber Ŭ���� ����)
< 	PushBack
<<	PushFront
>	Delete
>> 	DeleteAll
*	Search(Address)
&	Search(Reference)
////////////////////////////////////////////////////////////////////////////////////////////////////

*/

#include "phone_book.h"

int main()
{
    PhoneBook phone_book;
    int select_menu;

    while (1)
    {
        system("cls");

        phone_book.Show(MAIN);

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
            printf("\n\t���α׷��� �����մϴ�. (����)");
            _getchar();
            return 0;
        default:
            printf("\n\t�߸� �Է� �ϼ̽��ϴ�. �ٽ� �Է� ���ּ��� (����)");
            _getchar();
            break;
        }
    }

    return 0;
}
