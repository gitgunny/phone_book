#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

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

//////////////////////////////////////////////////////////////////////////////////////////////////// ���� �ڵ����� ����(�߰� ������ ���� �� �߰��� �߰� ���� ����)

void Search()
{
    int search_select = 0;
    int search_idx;
    char search_name[15];
    char search_number[15];

    while (1)
    {
        system("cls");

        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    �˻�    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

        printf("\n\t1. ���� �˻�  2. �̸� �˻�  3. ��ȣ �˻�  0. �������� : ");
        scanf("%d", &search_select);
        fflush(stdin);

        if (search_select == 0)
            break;

        if (search_select >= 1 && search_select <= 3)
        {
            if (search_select == 1)
            {
                printf("\n\t�˻��� ���� : ");
                scanf("%d", &search_idx);
                fflush(stdin);
            }
            if (search_select == 2)
            {
                printf("\n\t�˻��� �̸� : ");
                scanf("%s", search_name);
                fflush(stdin);
            }
            if (search_select == 3)
            {
                printf("\n\t�˻��� ��ȣ : ");
                scanf("%s", search_number);
                fflush(stdin);
            }

            ptr = head;

            while (ptr != NULL)
            {
                if (search_select == 1 && ptr->idx == search_idx)
                    break;
                if (search_select == 2 && strcmp(ptr->name, search_name) == 0)
                    break;
                if (search_select == 3 && strcmp(ptr->number, search_number) == 0)
                    break;

                ptr = ptr->next;
            }

            if (ptr != NULL)
                printf("\n\t[���]\t%-5d\t%-15s\t%-15s (����)", ptr->idx, ptr->name, ptr->number);
            else
                printf("\n\t[����] �˻��� ����� �����ϴ�. (����)");

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
    int update_select = 0;
    int update_idx;
    char update_name[15];
    char update_number[15];

    int update_new_select = 0;
    char update_new_name[15];
    char update_new_number[15];

    while (1)
    {
        system("cls");

        //////////////////////////////////////////////////////////////////////////////////////////////////// 0. (�˻� ���� ���� �Լ�) ���� �κ� �ݺ��Է½� �����÷ο� ���

        //////////////////////////////////////////////////////////////////////////////////////////////////// 1. (��ü) else if �߰��� ���ʿ��� if ���� ���̱�
        //////////////////////////////////////////////////////////////////////////////////////////////////// 2. (���� �Լ�) 1�ܰ� �Է� 2�ܰ� �Է� ���� �κ� ����(UI�κ� ����� ��ü ���� ����)
        //////////////////////////////////////////////////////////////////////////////////////////////////// 3. �������� -> �������� ���� ����???

        //////////////////////////////////////////////////////////////////////////////////////////////////// 4. (���� �Լ�) 2�ܰ� �Է� while �߰��� �߸� �Է½� �ݺ� �Է� ��� �߰�����(�������� -> ��������)???

        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    ����    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

        //////////////////////////////////////////////////////////////////////////////////////////////////// 0. (�˻� ���� ���� �Լ�) ���� �κ� �ݺ��Է½� �����÷ο� ���
        //////////////////////////////////////////////////////////////////////////////////////////////////// 3. �������� -> �������� ���� ����???

        printf("\n\t1. ���� ����  2. �̸� ����  3. ��ȣ ����  0. �������� : ");
        scanf("%d", &update_select);
        fflush(stdin);

        if (update_select == 0)
            break;

        if (update_select >= 1 && update_select <= 3)
        {
            if (update_select == 1)
            {
                printf("\n\t������ ���� : ");
                scanf("%d", &update_idx);
                fflush(stdin);
            }
            else if (update_select == 2)
            {
                printf("\n\t������ �̸� : ");
                scanf("%s", update_name);
                fflush(stdin);
            }
            else if (update_select == 3)
            {
                printf("\n\t������ ��ȣ : ");
                scanf("%s", update_number);
                fflush(stdin);
            }

            //////////////////////////////////////////////////////////////////////////////////////////////////// 0. (�˻� ���� ���� �Լ�) ���� �κ� �ݺ��Է½� �����÷ο� ���
            //////////////////////////////////////////////////////////////////////////////////////////////////// 3. �������� -> �������� ���� ����???
            //////////////////////////////////////////////////////////////////////////////////////////////////// 4-1. (���� �Լ�) 2�ܰ� �Է� while �߰��� �߸� �Է½� �ݺ� �Է� ��� �߰�����(�������� -> ��������)???

            //////////////////////////////////////////////////////////////////////////////////////////////////// 4-2. �� �ܰ迡�� ������ ����� ���ٸ� �޽��� ���

            printf("\n\t1. �̸� ����  2. ��ȣ ����  0. �������� : ");
            scanf("%d", &update_new_select);
            fflush(stdin);

            if (update_new_select == 0)
                break;

            if (update_new_select >= 1 && update_new_select <= 2)
            {
                if (update_new_select == 1)
                {
                    printf("\n\t������ �̸� : ");
                    scanf("%s", update_new_name);
                }
                else if (update_new_select == 2)
                {
                    printf("\n\t������ ��ȣ : ");
                    scanf("%s", update_new_number);
                }
                fflush(stdin);
            }
            else
            {
                printf("\n\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)");
                getchar();
                fflush(stdin);
                break;
            }

            ptr = head;

            while (ptr != NULL)
            {
                if ((update_select == 1 && ptr->idx == update_idx) || (update_select == 2 && strcmp(ptr->name, update_name) == 0) || (update_select == 3 && strcmp(ptr->number, update_number) == 0))
                {
                    if (update_new_select == 1)
                        strcpy(ptr->name, update_new_name);
                    else if (update_new_select == 2)
                        strcpy(ptr->number, update_new_number);

                    break;
                }

                ptr = ptr->next;
            }

            if (ptr != NULL)
                printf("\n\t[���] ���� �Ǿ����ϴ�. (����)");
            else
                printf("\n\t[����] ������ ����� �����ϴ�. (����)");

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

void Delete()
{
    int delete_select = 0;
    int delete_idx;
    char delete_name[15];
    char delete_number[15];

    while (1)
    {
        system("cls");

        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    ����    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

        printf("\n\t1. ���� ����  2. �̸� ����  3. ��ȣ ����  0. �������� : ");
        scanf("%d", &delete_select);
        fflush(stdin);

        if (delete_select == 0)
            break;

        if (delete_select >= 1 && delete_select <= 3)
        {
            if (delete_select == 1)
            {
                printf("\n\t������ ���� : ");
                scanf("%d", &delete_idx);
                fflush(stdin);
            }
            if (delete_select == 2)
            {
                printf("\n\t������ �̸� : ");
                scanf("%s", delete_name);
                fflush(stdin);
            }
            if (delete_select == 3)
            {
                printf("\n\t������ ��ȣ : ");
                scanf("%s", delete_number);
                fflush(stdin);
            }

            ptr = head;

            while (ptr != NULL)
            {
                if ((delete_select == 1 && ptr->idx == delete_idx) || (delete_select == 2 && strcmp(ptr->name, delete_name) == 0) || (delete_select == 3 && strcmp(ptr->number, delete_number) == 0))
                {
                    if (ptr == head)
                        head = ptr->next;
                    else if (ptr == tail)
                    {
                        if (ptr->prev == head)
                            head->next = NULL;
                        else
                        {
                            tail = ptr->prev;
                            tail->next = NULL;
                        }
                    }
                    else
                    {
                        ptr->prev->next = ptr->next;
                        ptr->next->prev = ptr->prev;
                    }
                    free(ptr);
                    idx_cnt--;
                    break;
                }

                ptr = ptr->next;
            }

            if (ptr != NULL)
                printf("\n\t[���] ���� �Ǿ����ϴ�. (����)");
            else
                printf("\n\t[����] ������ ����� �����ϴ�. (����)");

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

void DeleteAll()
{
    char answer[10];

    while (1)
    {
        system("cls");
        strcpy(answer, "");

        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��  ���λ���  �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

        printf("\n\t���� ������ ���Ͻ� ��� \"���λ���\"�� �Է� ���ּ���(�������� 0) : ");
        scanf("%s", answer);
        fflush(stdin);

        if (strlen(answer) == 1 && strchr(answer, '0'))
            break;

        if (strcmp(answer, "���λ���") == 0)
        {
            ptr = head;
            head = NULL;
            while (ptr != NULL)
            {
                tail = ptr->next;
                free(ptr);
                ptr = tail;
            }
            idx_cnt = 1;

            printf("\n\t[����] ���� ���� �Ǿ����ϴ�. (����)");
            getchar();
            fflush(stdin);
            break;
        }
        else
        {
            printf("\n\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)");
            getchar();
            fflush(stdin);
        }
    }
}