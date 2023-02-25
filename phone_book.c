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

        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎ 전화번호부 ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");
        printf("\n");
        View();
        printf("\n");
        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");
        printf("▦ 1. 검색  ▦ 2. 추가  ▦ 3. 수정  ▦ 4. 삭제  ▦ 5. 전부삭제  ▦ 0. 종료  ▦\n");
        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");

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
            printf("프로그램을 종료합니다. (엔터)");
            getchar();
            fflush(stdin);
            // free();
            exit(0);
        default:
            printf("잘못 입력 하셨습니다. 다시 입력 해주세요 (엔터)");
            getchar();
            fflush(stdin);
            break;
        }
    }

    return 0;
}

void View()
{
    printf("\tNo.\t이름\t\t전화번호\n\n");

    if (head == NULL)
        printf("\t등록된 번호가 없습니다.\n");
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

        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎    검색    ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");

        printf("\n\t1. 순번으로 찾기  2. 이름으로 찾기  3. 번호로 찾기  0. 이전으로 : ");
        scanf("%d", &serch_select);
        fflush(stdin);

        if (serch_select == 0)
            break;
        if (serch_select >= 1 && serch_select <= 3)
        {
            if (serch_select == 1)
            {
                printf("\n\t찾을 순번 : ");
                scanf("%d", &search_idx);
                fflush(stdin);
            }
            if (serch_select == 2)
            {
                printf("\n\t찾을 이름 : ");
                scanf("%s", search_name);
                fflush(stdin);
            }
            if (serch_select == 3)
            {
                printf("\n\t찾을 주소 : ");
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
                printf("\n\t[결과]\t%-5d\t%-15s\t%-15s (엔터)", ptr->idx, ptr->name, ptr->number);
            else
                printf("\n\t[실패] 찾지 못했습니다. (엔터)");

            getchar();
            fflush(stdin);
        }
        else
        {
            printf("\n\t[실패] 잘못 입력 하셨습니다. (엔터)");
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

        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎    추가    ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");

        printf("\n\t이름(이전으로 0) : ");
        scanf("%s", add_name);
        fflush(stdin);

        if (strlen(add_name) == 1 && strchr(add_name, '0'))
            break;

        printf("\n\t전화번호(이전으로 0) : ");
        scanf("%s", add_number);
        fflush(stdin);

        if (strlen(add_number) == 1 && strchr(add_number, '0'))
            break;

        // 유효성 검사
        if (strlen(add_name) > 14 || strlen(add_number) > 14)
        {
            printf("\n\t[실패] 이름이나 전화번호는 영어 14자 또는 한글 7자를 넘을 수 없습니다. (엔터)");
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

            printf("\n\t[성공] 추가 되었습니다. (엔터)");
            getchar();
            fflush(stdin);
        }
    }
}

void Update()
{
    system("cls");

    printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎    수정    ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");
    system("pause");
}

void Delete()
{
    system("cls");

    printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎    삭제    ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");
    system("pause");
}

void DeleteAll()
{
    system("cls");

    printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎  전부삭제  ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");
    system("pause");
}