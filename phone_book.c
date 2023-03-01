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
//////////////////////////////////////////////////////////////////////////////////////////////////// C++ ��������
//////////////////////////////////////////////////////////////////////////////////////////////////// ���ұ��� �߰�
//////////////////////////////////////////////////////////////////////////////////////////////////// ��������� �߰�
//////////////////////////////////////////////////////////////////////////////////////////////////// XOR���� ����� ������ ��ȣȭ ��ȣȭ �߰�
//////////////////////////////////////////////////////////////////////////////////////////////////// ���� �����ͷ� ������ ����ӵ� ���Ͻ� ������ ���� ����(����� ���� ���� -> Ʈ�� ����)

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

//////////////////////////////////////////////////////////////////////////////////////////////////// Search �Լ� return�� �Լ��� �ٲ㼭 ���ڰ�(����, �̸�, ��ȣ) ���� �� �ּ� ��ȯ���� ����

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
        strcpy(search_name, "");
        strcpy(search_number, "");

        system("cls");

        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    �˻�    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

        printf("\n\t1. ���� �˻�  2. �̸� �˻�  3. ��ȣ �˻�  0. �������� : ");
        //////////////////////////////////////////////////////////////////////////////////////////////////// �����÷ο� �ǵ� �� �극��ũ �� �����÷ο� �߻�
        scanf("%d", &search_select);
        fflush(stdin);

        if (search_select == 0)
        {
            break;
        }
        else if (search_select == 1)
        {
            printf("\n\t�˻��� ���� : ");
            scanf("%d", &search_idx);
        }
        else if (search_select == 2)
        {
            printf("\n\t�˻��� �̸� : ");
            scanf("%s", search_name);
        }
        else if (search_select == 3)
        {
            printf("\n\t�˻��� ��ȣ : ");
            scanf("%s", search_number);
        }
        else
        {
            printf("\n\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)");
            getchar();
        }

        // ���� �ʱ�ȭ
        fflush(stdin);

        if (search_select == 1 || search_select == 2 || search_select == 3)
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
        strcpy(add_name, "");
        strcpy(add_number, "");

        system("cls");

        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    �߰�    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

        printf("\n\t�̸�(�������� 0) : ");
        //////////////////////////////////////////////////////////////////////////////////////////////////// �����÷ο� �ǵ� �� �극��ũ �� �����÷ο� �߻�
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
        strcpy(update_name, "");
        strcpy(update_number, "");

        //////////////////////////////////////////////////////////////////////////////////////////////////// �Ʒ� �ش�κ� while ������ �Ʒ� ������ �ش�κ����� �̵�
        // �ʱ�ȭ
        update_new_select = 0;
        strcpy(update_new_name, "");
        strcpy(update_new_number, "");

        system("cls");

        //////////////////////////////////////////////////////////////////////////////////////////////////// 2. (���� �Լ�) 1�ܰ� �Է� 2�ܰ� �Է� ���� �κ� ����(UI�κ� ����� ��ü ���� ����)
        //////////////////////////////////////////////////////////////////////////////////////////////////// 3. �������� -> �������� ���� ����???
        //////////////////////////////////////////////////////////////////////////////////////////////////// 4. (���� �Լ�) 2�ܰ� �Է� while �߰��� �߸� �Է½� �ݺ� �Է� ��� �߰�����(�������� -> ��������)???

        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    ����    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

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

            //////////////////////////////////////////////////////////////////////////////////////////////////// 3. �������� -> �������� ���� ����???
            //////////////////////////////////////////////////////////////////////////////////////////////////// 4-1. (���� �Լ�) 2�ܰ� �Է� while �߰��� �߸� �Է½� �ݺ� �Է� ��� �߰�����(�������� -> ��������)???
            //////////////////////////////////////////////////////////////////////////////////////////////////// 4-2. �� �ܰ迡�� ������ ����� ���ٸ� �޽��� ���(Search �Լ� ����)

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
        strcpy(delete_name, "");
        strcpy(delete_number, "");

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
            else if (delete_select == 2)
            {
                printf("\n\t������ �̸� : ");
                scanf("%s", delete_name);
                fflush(stdin);
            }
            else if (delete_select == 3)
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
                    --idx_cnt;
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

// DeleteAll �Լ� ����
void DeleteAll()
{
    // DeleteAll �������� ����
    char answer[10];

    while (1)
    {
        // �ʱ�ȭ
        strcpy(answer, "");

        system("cls");

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
            idx_cnt = 0;

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