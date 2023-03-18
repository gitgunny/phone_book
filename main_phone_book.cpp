/*

* ��ü ���� �ּ� �߰�
* ���� XOR���� ����� ������ ��ȣȭ ��ȣȭ ��� �߰�
* ���� �����ͷ� ������ ����ӵ� ���Ͻ� ������ ���� ����(����� ���� ���� -> Ʈ�� ����)
*
* ALL : ���� �̸� ��ȣ �Է� �ܰ迡�� �߰� ��� ó�� 0 �Է½� �������� ��� �߰�
* _create.cpp : ���� �����÷ο� ���� �Լ� �ٵ��
* _create.cpp : �̸� ��ȭ��ȣ �Է� ��� ���� �޽��� ��� ���� �Ǵ� �߰�
* _search.cpp : �ߺ� ã�� ��� �߰�(���� �ߺ� ������ ���� �� ����, ���� ��� �߰�)
* _update.cpp : �̸� ��ȭ��ȣ ���� ���� �߰�(CheckLength, CheckNumber �̿�)

////////////////////////////////////////////////////////////////////////////////////////////////////
���� ����� ��� �߰�(phone_book.pb)
��� �Լ� �߰� ReadFile, WriteFile
WriteFile ���� �Ҵ� ���� ��� ����
�������� ����ó ��½� ���� ���� �� ����� �޴� ��½� �ܼ� Ŭ���� ��� ����

�Լ��� ����(Create -> Push)
���� �Ҵ� ���� �ڵ� ����(new PBData[1] -> new PBData)
�Ϻ� �Լ� �Ű����� const ���ȭ

������ �����ε� �ӽ� ����
< 	PushBack
<<	PushFront
>	Delete
>> 	DeleteAll
*	Search(Address)
&	Search(Reference)
NameNumber ����ü �߰�(��� ���� name, number)
////////////////////////////////////////////////////////////////////////////////////////////////////

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

		printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� �� ��ȭ��ȣ�� �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");
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