#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void View();
void Search();
void Add();
void Update();
void Delete();
void DeleteAll();

struct Node
{
    struct Node *prev;
    int idx;
    char *name;
    char *number;
    struct Node *next;
} *head, *tail, *ptr;

int idx_cnt;

int main()
{
    int select_menu;

    head = NULL;

    while (1)
    {
        system("cls");

        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� �� ��ȭ��ȣ�� �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");
        printf("\n");
        View();
        printf("\n");
        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");
        printf("�� 1. �˻�  �� 2. �߰�  �� 3. ����  �� 4. ����  �� 5. ���λ���  �� 0. ����  ��\n");
        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

        select_menu = _getch();

        switch (select_menu)
        {
        case 49:
            Search();
            break;
        case 50:
            Add();
            break;
        case 51:
            Update();
            break;
        case 52:
            Delete();
            break;
        case 53:
            DeleteAll();
            break;
        case 48:
            printf("���α׷��� �����մϴ�. (����)");
            getchar();
            fflush(stdin);
            // free();
            exit(0);
        default:
            printf("�߸� �Է� �ϼ̽��ϴ�. �ٽ� �Է� ���ּ��� (����)");
            getchar();
            fflush(stdin);
            break;
        }
    }

    return 0;
}

void View()
{
    if (head == NULL)
        printf("\t��ϵ� ��ȣ�� �����ϴ�.\n");
    else
    {
        printf("\t��ϵ� ��ȣ�� �ֽ��ϴ�.\n");
        ////////////////////////////////////////////////////////////////////////////////////
        // ���� �ܰ�
        ////////////////////////////////////////////////////////////////////////////////////
    }
}

void Search()
{
    system("cls");

    printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    �˻�    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");
    system("pause");
}

void Add()
{
    char add_name[15] = "";
    char add_number[15] = "";

    while (1)
    {
        system("cls");

        strcpy(add_name, "");
        strcpy(add_number, "");

        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    �߰�    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

        printf("\n\t�̸�(�������� 0) : ");
        scanf("%s", add_name);
        fflush(stdin);

        if (strlen(add_name) == 1 && strchr(add_name, '0'))
            break;

        printf("\n\t��ȭ��ȣ(�������� 0) : ");
        scanf("%s", add_number);
        fflush(stdin);

        if (strlen(add_number) == 1 && strchr(add_number, '0'))
            break;

        // ��ȿ�� �˻�
        if (strlen(add_name) > 14 || strlen(add_number) > 14)
        {
            printf("\n\t[����] �̸��̳� ��ȭ��ȣ�� ���� 14�� �Ǵ� �ѱ� 7�ڸ� ���� �� �����ϴ�. (����)");
            getchar();
            fflush(stdin);
        }
        else
        {
            ptr = (struct Node *)malloc(sizeof(struct Node));

            if (head == NULL)
            {
                head = ptr;
                head->prev = NULL;
            }
            else
            {
                tail->next = ptr;
                ptr->prev = tail;
            }

            ptr->idx = idx_cnt++;
            ptr->name = add_name;
            ptr->number = add_number;
            ptr->next = NULL;

            tail = ptr;

            printf("\n\t[����] �߰� �Ǿ����ϴ�. (����)");
            getchar();
            fflush(stdin);
        }
    }
}

void Update()
{
    system("cls");

    printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    ����    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");
    system("pause");
}

void Delete()
{
    system("cls");

    printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    ����    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");
    system("pause");
}

void DeleteAll()
{
    system("cls");

    printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��  ���λ���  �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");
    system("pause");
}