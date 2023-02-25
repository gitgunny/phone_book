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
    char name[15];
    char number[15];
    struct Node *next;
} *head, *tail, *ptr;

int idx_cnt = 1;

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
        case 49: // 1
            Search();
            break;
        case 50: // 2
            Add();
            break;
        case 51: // 3
            Update();
            break;
        case 52: // 4
            Delete();
            break;
        case 53: // 5
            DeleteAll();
            break;
        case 48: // 0
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
    printf("\tNo.\t�̸�\t\t��ȭ��ȣ\n\n");

    if (head == NULL)
        printf("\t��ϵ� ��ȣ�� �����ϴ�.\n");
    else
    {
        ptr = head;

        while (ptr != NULL)
        {
            printf("\t%-5d\t%-15s\t%-15s\n", ptr->idx, ptr->name, ptr->number);
            ptr = ptr->next;
        }
    }
}

void Search()
{
    int serch_select = 0;
    int search_idx;
    char search_name[15];
    char search_number[15];

    while (1)
    {
        system("cls");

        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    �˻�    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

        printf("\n\t1. �������� ã��  2. �̸����� ã��  3. ��ȣ�� ã��  0. �������� : ");
        scanf("%d", &serch_select);
        fflush(stdin);

        if (serch_select == 0)
            break;
        if (serch_select >= 1 && serch_select <= 3)
        {
            if (serch_select == 1)
            {
                printf("\n\tã�� ���� : ");
                scanf("%d", &search_idx);
                fflush(stdin);
            }
            if (serch_select == 2)
            {
                printf("\n\tã�� �̸� : ");
                scanf("%s", search_name);
                fflush(stdin);
            }
            if (serch_select == 3)
            {
                printf("\n\tã�� �ּ� : ");
                scanf("%s", search_number);
                fflush(stdin);
            }

            ptr = head;

            while (ptr != NULL)
            {
                if (serch_select == 1 && ptr->idx == search_idx)
                    break;
                if (serch_select == 2 && strcmp(ptr->name, search_name) == 0)
                    break;
                if (serch_select == 3 && strcmp(ptr->number, search_number) == 0)
                    break;

                ptr = ptr->next;
            }

            if (ptr != NULL)
                printf("\n\t[���]\t%-5d\t%-15s\t%-15s (����)", ptr->idx, ptr->name, ptr->number);
            else
                printf("\n\t[����] ã�� ���߽��ϴ�. (����)");

            getchar();
            fflush(stdin);
        }
        else
        {
            printf("\n\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)");
            getchar();
            fflush(stdin);
        }
    }
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
            strcpy(ptr->name, add_name);
            strcpy(ptr->number, add_number);
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