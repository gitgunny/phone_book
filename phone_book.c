// ������� ����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

// �Լ� ����
void View();
void Search();
void Add();
void Update();
void Delete();
void DeleteAll();

// ������ ����
enum _e_menu_number
{
    MENU_0 = 48,
    MENU_1,
    MENU_2,
    MENU_3,
    MENU_4,
    MENU_5
};

// ����ü ����
struct Node
{
    struct Node *prev;
    int idx;
    char name[15];
    char number[15];
    struct Node *next;
} *head, *tail, *ptr;

// �������� ����
int idx_cnt;

//////////////////////////////////////////////////////////////////////////////////////////////////// (�ܹ��� ���� ����)
//////////////////////////////////////////////////////////////////////////////////////////////////// ���ұ��� �߰�
//////////////////////////////////////////////////////////////////////////////////////////////////// ��������� �߰�
//////////////////////////////////////////////////////////////////////////////////////////////////// XOR���� ����� ������ ��ȣȭ ��ȣȭ �߰�
//////////////////////////////////////////////////////////////////////////////////////////////////// ���� �����ͷ� ������ ����ӵ� ���Ͻ� ������ ���� ����(����� ���� ���� -> Ʈ�� ����)

//////////////////////////////////////////////////////////////////////////////////////////////////// 0-1. Search �Լ� return�� �Լ��� ���� �� ���ڰ�(����, �̸�, ��ȣ) ���� �� �ּ� ��ȯ���� ����
//////////////////////////////////////////////////////////////////////////////////////////////////// 0-2. Search �Լ� return ��� �߰� �� ���� �ܰ迡�� ������ ����� ���ٸ� �޽��� ���

//////////////////////////////////////////////////////////////////////////////////////////////////// ��ü ���� �ּ� �߰�
//////////////////////////////////////////////////////////////////////////////////////////////////// UI ����
//////////////////////////////////////////////////////////////////////////////////////////////////// �޴�, ����, ���, ����, ���� ���� ����

//////////////////////////////////////////////////////////////////////////////////////////////////// Add �Լ� // �̸��� ���� �Է� �Ұ� // ��ȭ��ȣ�� ���ڸ� �Է� ����(�����±���)

//////////////////////////////////////////////////////////////////////////////////////////////////// ����� ���� �޸� ���� ��� ����

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
        case MENU_1:
            Search();
            break;
        case MENU_2:
            Add();
            break;
        case MENU_3:
            Update();
            break;
        case MENU_4:
            Delete();
            break;
        case MENU_5:
            DeleteAll();
            break;
        case MENU_0:
            printf("���α׷��� �����մϴ�. (����)");
            getchar();
            fflush(stdin);
            // head -> node . . . -> tail
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

// View �Լ� ����
void View()
{
    printf("\tNo.\t�̸�\t\t��ȭ��ȣ\n\n");

    if (head == NULL)
        printf("\t��ϵ� ��ȣ�� �����ϴ�.\n");
    else
    {
        ptr = head;
        idx_cnt = 0;

        while (ptr != NULL)
        {
            ptr->idx = ++idx_cnt;
            printf("\t%-5d\t%-15s\t%-15s\n", ptr->idx, ptr->name, ptr->number);
            ptr = ptr->next;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////// 0-1

// Search �Լ� ����
void Search()
{
    // Search �������� ����
    int search_select;
    int search_idx;
    char search_name[15];
    char search_number[15];

    while (1)
    {
        // �ʱ�ȭ
        search_select = 0;
        search_idx = 0;
        memset(search_name, 0, sizeof(search_name));
        memset(search_number, 0, sizeof(search_number));

        system("cls");

        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    �˻�    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

        printf("\n\t1. ���� �˻�  2. �̸� �˻�  3. ��ȣ �˻�  0. �������� : ");
        scanf_s("%d", &search_select, sizeof(search_select));
        fflush(stdin);

        if (search_select == 0)
        {
            break;
        }
        else if (search_select == 1)
        {
            printf("\n\t�˻��� ���� : ");
            scanf_s("%d", &search_idx, sizeof(search_idx));
        }
        else if (search_select == 2)
        {
            printf("\n\t�˻��� �̸� : ");
            scanf_s("%s", search_name, sizeof(search_name));
        }
        else if (search_select == 3)
        {
            printf("\n\t�˻��� ��ȣ : ");
            scanf_s("%s", search_number, sizeof(search_number));
        }
        else
        {
            printf("\n\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)");
            getchar();
        }

        // ���� �ʱ�ȭ
        fflush(stdin);

        if (search_select >= 1 && search_select <= 3)
        {
            ptr = head;

            while (ptr != NULL)
            {
                if ((search_select == 1 && ptr->idx == search_idx) || (search_select == 2 && strcmp(ptr->name, search_name) == 0) || (search_select == 3 && strcmp(ptr->number, search_number) == 0))
                    break;

                ptr = ptr->next;
            }

            if (ptr != NULL)
                printf("\n\t[���]\t%-5d\t%-15s\t%-15s (����)", ptr->idx, ptr->name, ptr->number);
            else
                printf("\n\t[����] �˻��� ����� �����ϴ�. (����)");

            // ���� �ʱ�ȭ
            getchar();
            fflush(stdin);
        }
    }
}

// Add �Լ� ����
void Add()
{
    // Add �������� ����
    char add_name[15];
    char add_number[15];

    while (1)
    {
        // �ʱ�ȭ
        memset(add_name, 0, sizeof(add_name));
        memset(add_number, 0, sizeof(add_number));

        system("cls");

        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    �߰�    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

        printf("\n\t�̸�(�������� 0) : ");
        scanf_s("%s", add_name, sizeof(add_name));
        fflush(stdin);

        if (strlen(add_name) == 1 && strchr(add_name, '0'))
            break;

        printf("\n\t��ȭ��ȣ(�������� 0) : ");
        scanf_s("%s", add_number, sizeof(add_number));
        fflush(stdin);

        if (strlen(add_number) == 1 && strchr(add_number, '0'))
            break;

        // ��ȿ�� �˻�
        if ((strlen(add_name) < 1 || strlen(add_name) > 14) || (strlen(add_number) < 1 || strlen(add_number) > 14))
        {
            printf("\n\t[����] �̸��̳� ��ȭ��ȣ�� ���� 14�� �Ǵ� �ѱ� 7�ڸ� ���� �� �����ϴ�. (����)");
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

            ptr->idx = ++idx_cnt;
            strcpy(ptr->name, add_name);
            strcpy(ptr->number, add_number);
            ptr->next = NULL;

            tail = ptr;

            printf("\n\t[����] �߰� �Ǿ����ϴ�. (����)");
        }
        // ���� �ʱ�ȭ
        getchar();
        fflush(stdin);
    }
}

// Update �Լ� ����
void Update()
{
    // Update �������� ����
    int update_select;
    int update_idx;
    char update_name[15];
    char update_number[15];

    int update_new_select;
    char update_new_name[15];
    char update_new_number[15];

    while (1)
    {
        // �ʱ�ȭ
        update_select = 0;
        update_idx = 0;
        memset(update_name, 0, sizeof(update_name));
        memset(update_number, 0, sizeof(update_number));

        system("cls");

        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    ����    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

        printf("\n\t1. ���� ����  2. �̸� ����  3. ��ȣ ����  0. �������� : ");
        scanf_s("%d", &update_select, sizeof(update_select));
        fflush(stdin);

        if (update_select == 0)
        {
            break;
        }
        else if (update_select == 1)
        {
            printf("\n\t������ ���� : ");
            scanf_s("%d", &update_idx, sizeof(update_idx));
        }
        else if (update_select == 2)
        {
            printf("\n\t������ �̸� : ");
            scanf_s("%s", update_name, sizeof(update_name));
        }
        else if (update_select == 3)
        {
            printf("\n\t������ ��ȣ : ");
            scanf_s("%s", update_number, sizeof(update_number));
        }
        else
        {
            printf("\n\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)");
            getchar();
        }

        // ���� �ʱ�ȭ
        fflush(stdin);

        //////////////////////////////////////////////////////////////////////////////////////////////////// 0-2

        while (update_select >= 1 && update_select <= 3)
        {
            // �ʱ�ȭ
            update_new_select = 0;
            memset(update_new_name, 0, sizeof(update_new_name));
            memset(update_new_number, 0, sizeof(update_new_number));

            printf("\n\t1. �̸� ����  2. ��ȣ ����  0. �������� : ");
            scanf_s("%d", &update_new_select, sizeof(update_new_select));
            fflush(stdin);

            if (update_new_select == 0)
            {
                break;
            }
            else if (update_new_select == 1)
            {
                printf("\n\t������ �̸� : ");
                scanf_s("%s", update_new_name, sizeof(update_new_name));
            }
            else if (update_new_select == 2)
            {
                printf("\n\t������ ��ȣ : ");
                scanf_s("%s", update_new_number, sizeof(update_new_number));
            }
            else
            {
                printf("\n\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)");
                getchar();
            }

            // ���� �ʱ�ȭ
            fflush(stdin);

            if (update_new_select >= 1 && update_new_select <= 2)
            {
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

                // ���� �ʱ�ȭ
                getchar();
                fflush(stdin);
                break;
            }
        }
    }
}

// Delete �Լ� ����
void Delete()
{
    // Delete �������� ����
    int delete_select;
    int delete_idx;
    char delete_name[15];
    char delete_number[15];

    while (1)
    {
        // �ʱ�ȭ
        delete_select = 0;
        delete_idx = 0;
        memset(delete_name, 0, sizeof(delete_name));
        memset(delete_number, 0, sizeof(delete_number));

        system("cls");

        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    ����    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

        printf("\n\t1. ���� ����  2. �̸� ����  3. ��ȣ ����  0. �������� : ");
        scanf_s("%d", &delete_select, sizeof(delete_select));
        fflush(stdin);

        if (delete_select == 0)
        {
            break;
        }
        else if (delete_select == 1)
        {
            printf("\n\t������ ���� : ");
            scanf_s("%d", &delete_idx, sizeof(delete_idx));
        }
        else if (delete_select == 2)
        {
            printf("\n\t������ �̸� : ");
            scanf_s("%s", delete_name, sizeof(delete_name));
        }
        else if (delete_select == 3)
        {
            printf("\n\t������ ��ȣ : ");
            scanf_s("%s", delete_number, sizeof(delete_number));
        }
        else
        {
            printf("\n\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)");
            getchar();
        }

        // ���� �ʱ�ȭ
        fflush(stdin);

        if (delete_select >= 1 && delete_select <= 3)
        {
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
                    --idx_cnt;
                    break;
                }

                ptr = ptr->next;
            }

            if (ptr != NULL)
                printf("\n\t[���] ���� �Ǿ����ϴ�. (����)");
            else
                printf("\n\t[����] ������ ����� �����ϴ�. (����)");

            // ���� �ʱ�ȭ
            getchar();
            fflush(stdin);
        }
    }
}

// DeleteAll �Լ� ����
void DeleteAll()
{
    // DeleteAll �������� ����
    char answer[10];

    while (1)
    {
        // �ʱ�ȭ
        memset(answer, 0, sizeof(answer));

        system("cls");

        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��  ���λ���  �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

        printf("\n\t���� ������ ���Ͻ� ��� \"���λ���\"�� �Է� ���ּ���(�������� 0) : ");
        scanf_s("%s", answer, sizeof(answer));
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
            idx_cnt = 0;

            printf("\n\t[����] ���� ���� �Ǿ����ϴ�. (����)");
            // ���� �ʱ�ȭ
            getchar();
            fflush(stdin);
            break;
        }
        else
        {
            printf("\n\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)");
            // ���� �ʱ�ȭ
            getchar();
            fflush(stdin);
        }
    }
}