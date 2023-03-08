/*
    분할구현 추가
    파일입출력 추가
    XOR만을 사용한 데이터 암호화 복호화 추가
    이후 데이터량 증가로 연산속도 저하시 데이터 구조 변경(양방향 선형 구조 -> 트리 구조)

    같은 파일 내 분할 구현

    전체 설명 주석 추가
    UI 수정
    메뉴, 선택, 결과, 성공, 실패 구문 수정

    종료시 동적 메모리 해제 기능 구현

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

        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎ 전화번호부 ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");
        printf("\n");
        View();
        printf("\n");
        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");
        printf("▦ 1. 검색  ▦ 2. 추가  ▦ 3. 수정  ▦ 4. 삭제  ▦ 5. 전부삭제  ▦ 0. 종료  ▦\n");
        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");

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
            printf("프로그램을 종료합니다. (엔터)");
            _getchar();
            /* head -> node . . . -> tail */
            // free();
            exit(0);
        default:
            printf("잘못 입력 하셨습니다. 다시 입력 해주세요 (엔터)");
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
    printf("\tNo.\t이름\t\t전화번호\n\n");

    if (head == NULL)
        printf("\t등록된 번호가 없습니다.\n");
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
        // 초기화
        search_select = 0;
        search_idx = 0;
        memset(search_name, 0, sizeof(search_name));
        memset(search_number, 0, sizeof(search_number));

        system("cls");

        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎    검색    ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");

        printf("\n\t1. 순번 검색  2. 이름 검색  3. 번호 검색  0. 이전으로 : ");
        _fscanf(stdin, "%d", &search_select);

        if (search_select == 0)
        {
            break;
        }
        else if (search_select == 1)
        {
            printf("\n\t검색할 순번 : ");
            _fscanf(stdin, "%d", &search_idx);
        }
        else if (search_select == 2)
        {
            printf("\n\t검색할 이름 : ");
            _fgets(search_name, sizeof(search_name), stdin);
        }
        else if (search_select == 3)
        {
            printf("\n\t검색할 번호 : ");
            _fgets(search_number, sizeof(search_number), stdin);
        }
        else
        {
            printf("\n\t[실패] 잘못 입력 하셨습니다. (엔터)");
            _getchar();
        }

        if (search_select >= 1 && search_select <= 3)
        {
            ptr = Search(search_idx, search_name, search_number);
            if (ptr)
                printf("\n\t[결과]\t%-5d\t%-15s\t%-15s (엔터)", ptr->idx, ptr->name, ptr->number);
            else
                printf("\n\t[실패] 검색된 결과가 없습니다. (엔터)");

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
        // 초기화
        memset(add_name, 0, sizeof(add_name));
        memset(add_number, 0, sizeof(add_number));

        system("cls");

        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎    추가    ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");

        printf("\n\t이름(이전으로 0) : ");
        _fgets(add_name, sizeof(add_name), stdin);

        if (strlen(add_name) == 1 && strchr(add_name, '0'))
            break;

        printf("\n\t전화번호(이전으로 0) : ");
        _fgets(add_number, sizeof(add_number), stdin);

        if (strlen(add_number) == 1 && strchr(add_number, '0'))
            break;

        if (CheckLength(add_name, 1, 12) || CheckName(add_name))
            printf("\n\t[실패] 이름은 영어나 한글만 입력할 수 있고 영어 12자 또는 한글 6자를 넘을 수 없습니다. (엔터)");
        else if (CheckLength(add_number, 1, 15) || CheckNumber(add_number))
            printf("\n\t[실패] 전화번호는 숫자(하이픈(-) 포함) 15자까지만 입력 할 수 있습니다. (엔터)");
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

            printf("\n\t[성공] 추가 되었습니다. (엔터)");
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
        // 초기화
        update_select = 0;
        update_idx = 0;
        memset(update_name, 0, sizeof(update_name));
        memset(update_number, 0, sizeof(update_number));

        system("cls");

        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎    수정    ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");

        printf("\n\t1. 순번 선택  2. 이름 선택  3. 번호 선택  0. 이전으로 : ");
        _fscanf(stdin, "%d", &update_select);

        if (update_select == 0)
        {
            break;
        }
        else if (update_select == 1)
        {
            printf("\n\t선택할 순번 : ");
            _fscanf(stdin, "%d", &update_idx);
        }
        else if (update_select == 2)
        {
            printf("\n\t선택할 이름 : ");
            _fgets(update_name, sizeof(update_name), stdin);
        }
        else if (update_select == 3)
        {
            printf("\n\t선택할 번호 : ");
            _fgets(update_number, sizeof(update_number), stdin);
        }
        else
        {
            printf("\n\t[실패] 잘못 입력 하셨습니다. (엔터)");
            _getchar();
        }

        while (update_select >= 1 && update_select <= 3)
        {
            ptr = Search(update_idx, update_name, update_number);
            if (ptr == NULL)
            {
                printf("\n\t[실패] 수정할 대상이 없습니다. (엔터)");
                _getchar();
                break;
            }

            // 초기화
            update_new_select = 0;
            memset(update_new_name, 0, sizeof(update_new_name));
            memset(update_new_number, 0, sizeof(update_new_number));

            printf("\n\t1. 이름 수정  2. 번호 수정  0. 이전으로 : ");
            _fscanf(stdin, "%d", &update_new_select);

            if (update_new_select == 0)
            {
                break;
            }
            else if (update_new_select == 1)
            {
                printf("\n\t수정할 이름 : ");
                _fgets(update_new_name, sizeof(update_new_name), stdin);
            }
            else if (update_new_select == 2)
            {
                printf("\n\t수정할 번호 : ");
                _fgets(update_new_number, sizeof(update_new_number), stdin);
            }
            else
            {
                printf("\n\t[실패] 잘못 입력 하셨습니다. (엔터)");
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
                    printf("\n\t[결과] 수정 되었습니다. (엔터)");
                else
                    printf("\n\t[실패] 수정할 대상이 없습니다. (엔터)");

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
        // 초기화
        delete_select = 0;
        delete_idx = 0;
        memset(delete_name, 0, sizeof(delete_name));
        memset(delete_number, 0, sizeof(delete_number));

        system("cls");

        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎    삭제    ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");

        printf("\n\t1. 순번 삭제  2. 이름 삭제  3. 번호 삭제  0. 이전으로 : ");
        _fscanf(stdin, "%d", &delete_select);

        if (delete_select == 0)
        {
            break;
        }
        else if (delete_select == 1)
        {
            printf("\n\t삭제할 순번 : ");
            _fscanf(stdin, "%d", &delete_idx);
        }
        else if (delete_select == 2)
        {
            printf("\n\t삭제할 이름 : ");
            _fgets(delete_name, sizeof(delete_name), stdin);
        }
        else if (delete_select == 3)
        {
            printf("\n\t삭제할 번호 : ");
            _fgets(delete_number, sizeof(delete_number), stdin);
        }
        else
        {
            printf("\n\t[실패] 잘못 입력 하셨습니다. (엔터)");
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
                printf("\n\t[결과] 삭제 되었습니다. (엔터)");
            else
                printf("\n\t[실패] 삭제할 대상이 없습니다. (엔터)");

            _getchar();
        }
    }
}

void DeleteAll()
{
    char answer[10];

    while (1)
    {
        // 초기화
        memset(answer, 0, sizeof(answer));

        system("cls");

        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎  전부삭제  ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");

        printf("\n\t전부 삭제를 원하실 경우 \"전부삭제\"를 입력 해주세요(이전으로 0) : ");
        _fgets(answer, sizeof(answer), stdin);

        if (strlen(answer) == 1 && strchr(answer, '0'))
            break;

        if (strcmp(answer, "전부삭제") == 0)
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

            printf("\n\t[성공] 전부 삭제 되었습니다. (엔터)");
            _getchar();
            break;
        }
        else
        {
            printf("\n\t[실패] 잘못 입력 하셨습니다. (엔터)");
            _getchar();
        }
    }
}