/*
    ���ұ��� �߰�
    ��������� �߰�
    XOR���� ����� ������ ��ȣȭ ��ȣȭ �߰�
    ���� �����ͷ� ������ ����ӵ� ���Ͻ� ������ ���� ����(����� ���� ���� -> Ʈ�� ����)

    ���� ���� �� ���� ����

    ��ü ���� �ּ� �߰�
    UI ����
    �޴�, ����, ���, ����, ���� ���� ����

    ����� ���� �޸� ���� ��� ����

////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////
*/

#include <iostream>
#include <conio.h>  // getch
#include <stdlib.h> // malloc, free, memset
#include <string.h> // strlen, strcpy, strcmp

enum e_MenuSelectNumber
{
    MENU_0 = 48,
    MENU_1,
    MENU_2,
    MENU_3,
    MENU_4,
    MENU_5
};

struct Node
{
    struct Node *prev;
    int idx;
    char name[15];
    char number[20];
    struct Node *next;
} *head, *tail, *ptr;

using namespace std;

int g_idx_cnt;

void _getchar();
void _fscanf(FILE *_Stream, const char *_Format, ...);
void _fgets(char *_Buffer, int _MaxCount, FILE *_Stream);

int CheckLength(const char *string, int min_length, int max_length);
int CheckName(const char *name);
int CheckNumber(const char *number);

void View();
Node *Search(int idx, char *name, char *number);
void Search();
void Add();
void Update();
void Delete();
void DeleteAll();

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

        select_menu = getch();

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
            _getchar();
            /* head -> node . . . -> tail */
            // free();
            exit(0);
        default:
            printf("�߸� �Է� �ϼ̽��ϴ�. �ٽ� �Է� ���ּ��� (����)");
            _getchar();
            break;
        }
    }

    return 0;
}

void _getchar()
{
    getchar();
    fflush(stdin);
}

void _fscanf(FILE *_Stream, const char *_Format, ...)
{
    fscanf(_Stream, _Format);
    fflush(_Stream);
}

void _fgets(char *_Buffer, int _MaxCount, FILE *_Stream)
{
    fgets(_Buffer, _MaxCount, _Stream);
    _Buffer[strlen(_Buffer) - 1] = '\0';
    fflush(_Stream);
}

int CheckLength(const char *string, int min_length, int max_length)
{
    if (strlen(string) < min_length || strlen(string) > max_length)
        return 1;

    return 0;
}

int CheckName(const char *name)
{
    for (int i = 0; i < strlen(name); i++)
    {
        if (name[i] >= '0' && name[i] <= '9')
            return 1;
    }

    return 0;
}

int CheckNumber(const char *number)
{
    for (int i = 0; i < strlen(number); i++)
    {
        if (!(number[i] == '-' || number[i] >= '0' && number[i] <= '9'))
            return 1;
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
        g_idx_cnt = 0;

        while (ptr != NULL)
        {
            ptr->idx = ++g_idx_cnt;
            printf("\t%-5d\t%-15s\t%-15s\n", ptr->idx, ptr->name, ptr->number);
            ptr = ptr->next;
        }
    }
}

Node *Search(int idx, char *name, char *number)
{
    ptr = head;

    while (ptr != NULL)
    {
        if (ptr->idx == idx || strcmp(ptr->name, name) == 0 || strcmp(ptr->number, number) == 0)
            break;

        ptr = ptr->next;
    }

    if (ptr != NULL)
        return ptr;

    return 0;
}

void Search()
{
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
        _fscanf(stdin, "%d", &search_select);

        if (search_select == 0)
        {
            break;
        }
        else if (search_select == 1)
        {
            printf("\n\t�˻��� ���� : ");
            _fscanf(stdin, "%d", &search_idx);
        }
        else if (search_select == 2)
        {
            printf("\n\t�˻��� �̸� : ");
            _fgets(search_name, sizeof(search_name), stdin);
        }
        else if (search_select == 3)
        {
            printf("\n\t�˻��� ��ȣ : ");
            _fgets(search_number, sizeof(search_number), stdin);
        }
        else
        {
            printf("\n\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)");
            _getchar();
        }

        if (search_select >= 1 && search_select <= 3)
        {
            ptr = Search(search_idx, search_name, search_number);
            if (ptr)
                printf("\n\t[���]\t%-5d\t%-15s\t%-15s (����)", ptr->idx, ptr->name, ptr->number);
            else
                printf("\n\t[����] �˻��� ����� �����ϴ�. (����)");

            _getchar();
        }
    }
}

void Add()
{
    char add_name[15];
    char add_number[20];

    while (1)
    {
        // �ʱ�ȭ
        memset(add_name, 0, sizeof(add_name));
        memset(add_number, 0, sizeof(add_number));

        system("cls");

        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��    �߰�    �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

        printf("\n\t�̸�(�������� 0) : ");
        _fgets(add_name, sizeof(add_name), stdin);

        if (strlen(add_name) == 1 && strchr(add_name, '0'))
            break;

        printf("\n\t��ȭ��ȣ(�������� 0) : ");
        _fgets(add_number, sizeof(add_number), stdin);

        if (strlen(add_number) == 1 && strchr(add_number, '0'))
            break;

        if (CheckLength(add_name, 1, 12) || CheckName(add_name))
            printf("\n\t[����] �̸��� ��� �ѱ۸� �Է��� �� �ְ� ���� 12�� �Ǵ� �ѱ� 6�ڸ� ���� �� �����ϴ�. (����)");
        else if (CheckLength(add_number, 1, 15) || CheckNumber(add_number))
            printf("\n\t[����] ��ȭ��ȣ�� ����(������(-) ����) 15�ڱ����� �Է� �� �� �ֽ��ϴ�. (����)");
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

            ptr->idx = ++g_idx_cnt;
            strcpy(ptr->name, add_name);
            strcpy(ptr->number, add_number);
            ptr->next = NULL;

            tail = ptr;

            printf("\n\t[����] �߰� �Ǿ����ϴ�. (����)");
        }
        _getchar();
    }
}

void Update()
{
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
        _fscanf(stdin, "%d", &update_select);

        if (update_select == 0)
        {
            break;
        }
        else if (update_select == 1)
        {
            printf("\n\t������ ���� : ");
            _fscanf(stdin, "%d", &update_idx);
        }
        else if (update_select == 2)
        {
            printf("\n\t������ �̸� : ");
            _fgets(update_name, sizeof(update_name), stdin);
        }
        else if (update_select == 3)
        {
            printf("\n\t������ ��ȣ : ");
            _fgets(update_number, sizeof(update_number), stdin);
        }
        else
        {
            printf("\n\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)");
            _getchar();
        }

        while (update_select >= 1 && update_select <= 3)
        {
            ptr = Search(update_idx, update_name, update_number);
            if (ptr == NULL)
            {
                printf("\n\t[����] ������ ����� �����ϴ�. (����)");
                _getchar();
                break;
            }

            // �ʱ�ȭ
            update_new_select = 0;
            memset(update_new_name, 0, sizeof(update_new_name));
            memset(update_new_number, 0, sizeof(update_new_number));

            printf("\n\t1. �̸� ����  2. ��ȣ ����  0. �������� : ");
            _fscanf(stdin, "%d", &update_new_select);

            if (update_new_select == 0)
            {
                break;
            }
            else if (update_new_select == 1)
            {
                printf("\n\t������ �̸� : ");
                _fgets(update_new_name, sizeof(update_new_name), stdin);
            }
            else if (update_new_select == 2)
            {
                printf("\n\t������ ��ȣ : ");
                _fgets(update_new_number, sizeof(update_new_number), stdin);
            }
            else
            {
                printf("\n\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)");
                _getchar();
            }

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

                _getchar();
                break;
            }
        }
    }
}

void Delete()
{
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
        _fscanf(stdin, "%d", &delete_select);

        if (delete_select == 0)
        {
            break;
        }
        else if (delete_select == 1)
        {
            printf("\n\t������ ���� : ");
            _fscanf(stdin, "%d", &delete_idx);
        }
        else if (delete_select == 2)
        {
            printf("\n\t������ �̸� : ");
            _fgets(delete_name, sizeof(delete_name), stdin);
        }
        else if (delete_select == 3)
        {
            printf("\n\t������ ��ȣ : ");
            _fgets(delete_number, sizeof(delete_number), stdin);
        }
        else
        {
            printf("\n\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)");
            _getchar();
        }

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
                    --g_idx_cnt;
                    break;
                }

                ptr = ptr->next;
            }

            if (ptr != NULL)
                printf("\n\t[���] ���� �Ǿ����ϴ�. (����)");
            else
                printf("\n\t[����] ������ ����� �����ϴ�. (����)");

            _getchar();
        }
    }
}

void DeleteAll()
{
    char answer[10];

    while (1)
    {
        // �ʱ�ȭ
        memset(answer, 0, sizeof(answer));

        system("cls");

        printf("�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ� ��  ���λ���  �� �ˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�\n");

        printf("\n\t���� ������ ���Ͻ� ��� \"���λ���\"�� �Է� ���ּ���(�������� 0) : ");
        _fgets(answer, sizeof(answer), stdin);

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
            g_idx_cnt = 0;

            printf("\n\t[����] ���� ���� �Ǿ����ϴ�. (����)");
            _getchar();
            break;
        }
        else
        {
            printf("\n\t[����] �߸� �Է� �ϼ̽��ϴ�. (����)");
            _getchar();
        }
    }
}