/*

* ��ü ���� �ּ� �߰�
* ���� XOR���� ����� ������ ��ȣȭ ��ȣȭ ��� �߰�
* ���� �����ͷ� ������ ����ӵ� ���Ͻ� ������ ���� ����(����� ���� ���� -> Ʈ�� ����)
*
* ALL : ���� �̸� ��ȣ �Է� �ܰ迡�� �߰� ��� ó�� 0 �Է½� �������� ��� �߰�
* search.cpp : �ߺ� ã�� ��� �߰�(���� �ߺ� ������ ���� �� ����, ���� ��� �߰�)
* update.cpp : �̸� ��ȭ��ȣ ���� ���� �߰�(CheckLength, CheckNumber �̿�)

////////////////////////////////////////////////////////////////////////////////////////////////////
show.cpp : C++ ��Ÿ��ȭ
create.cpp : �̸� ��ȭ��ȣ �Է� ��� ���Ἲ Ȯ��
create.cpp : C++ ��Ÿ��ȭ
create.cpp : create ���� ����Լ� ����
phonebook.h : PBData ������ �߰�(create ����ȭ)

(����)
show.cpp : ���� ���߱�
updata.cpp : C++ ��Ÿ��ȭ

delete.cpp : delete_all ��ġ��
delete_all.cpp

search.cpp
common.cpp : ������ �����ε� Search�� Ȱ��ȭ

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
        phone_book.Show();
        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");
        printf("�� 1. �˻�  �� 2. �߰�  �� 3. ����  �� 4. ����  �� 5. ���λ���  �� 0. ����  ��\n");
        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

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
