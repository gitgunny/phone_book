// 헤더파일 선언
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

// 함수 선언
void View();
void Search();
void Add();
void Update();
void Delete();
void DeleteAll();

// 열거형 선언
enum _e_menu_number
{
    MENU_0 = 48,
    MENU_1,
    MENU_2,
    MENU_3,
    MENU_4,
    MENU_5
};

// 구조체 선언
struct Node
{
    struct Node *prev;
    int idx;
    char name[15];
    char number[15];
    struct Node *next;
} *head, *tail, *ptr;

// 전역변수 선언
int idx_cnt;

//////////////////////////////////////////////////////////////////////////////////////////////////// (잔버그 수정 이후)
//////////////////////////////////////////////////////////////////////////////////////////////////// C++ 문법으로(git 커밋시 cpp 파일 분할확인)
//////////////////////////////////////////////////////////////////////////////////////////////////// 분할구현 추가
//////////////////////////////////////////////////////////////////////////////////////////////////// 파일입출력 추가
//////////////////////////////////////////////////////////////////////////////////////////////////// XOR만을 사용한 데이터 암호화 복호화 추가
//////////////////////////////////////////////////////////////////////////////////////////////////// 이후 데이터량 증가로 연산속도 저하시 데이터 구조 변경(양방향 선형 구조 -> 트리 구조)

//////////////////////////////////////////////////////////////////////////////////////////////////// 0-1. Search 함수 return형 함수로 변경 후 인자값(순번, 이름, 번호) 설정 후 주소 반환으로 변경
//////////////////////////////////////////////////////////////////////////////////////////////////// 0-2. Search 함수 return 기능 추가 후 현재 단계에서 수정할 대상이 없다면 메시지 출력

//////////////////////////////////////////////////////////////////////////////////////////////////// 전체 설명 주석 추가
//////////////////////////////////////////////////////////////////////////////////////////////////// UI 수정
//////////////////////////////////////////////////////////////////////////////////////////////////// 메뉴, 선택, 결과, 성공, 실패 구문 수정

//////////////////////////////////////////////////////////////////////////////////////////////////// Add 함수 // 이름은 숫자 입력 불가 // 전화번호는 숫자만 입력 가능(하이픈까지)

//////////////////////////////////////////////////////////////////////////////////////////////////// 종료시 동적 메모리 해제 기능 구현

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
            getchar();
            fflush(stdin);
            // head -> node . . . -> tail
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

// View 함수 정의
void View()
{
    printf("\tNo.\t이름\t\t전화번호\n\n");

    if (head == NULL)
        printf("\t등록된 번호가 없습니다.\n");
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

// Search 함수 정의
void Search()
{
    // Search 지역변수 선언
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
        scanf_s("%d", &search_select, sizeof(search_select));
        fflush(stdin);

        if (search_select == 0)
        {
            break;
        }
        else if (search_select == 1)
        {
            printf("\n\t검색할 순번 : ");
            scanf_s("%d", &search_idx, sizeof(search_idx));
        }
        else if (search_select == 2)
        {
            printf("\n\t검색할 이름 : ");
            scanf_s("%s", search_name, sizeof(search_name));
        }
        else if (search_select == 3)
        {
            printf("\n\t검색할 번호 : ");
            scanf_s("%s", search_number, sizeof(search_number));
        }
        else
        {
            printf("\n\t[실패] 잘못 입력 하셨습니다. (엔터)");
            getchar();
        }

        // 버퍼 초기화
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
                printf("\n\t[결과]\t%-5d\t%-15s\t%-15s (엔터)", ptr->idx, ptr->name, ptr->number);
            else
                printf("\n\t[실패] 검색된 결과가 없습니다. (엔터)");

            // 버퍼 초기화
            getchar();
            fflush(stdin);
        }
    }
}

// Add 함수 정의
void Add()
{
    // Add 지역변수 선언
    char add_name[15];
    char add_number[15];

    while (1)
    {
        // 초기화
        memset(add_name, 0, sizeof(add_name));
        memset(add_number, 0, sizeof(add_number));

        system("cls");

        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎    추가    ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");

        printf("\n\t이름(이전으로 0) : ");
        scanf_s("%s", add_name, sizeof(add_name));
        fflush(stdin);

        if (strlen(add_name) == 1 && strchr(add_name, '0'))
            break;

        printf("\n\t전화번호(이전으로 0) : ");
        scanf_s("%s", add_number, sizeof(add_number));
        fflush(stdin);

        if (strlen(add_number) == 1 && strchr(add_number, '0'))
            break;

        // 유효성 검사
        if ((strlen(add_name) < 1 || strlen(add_name) > 14) || (strlen(add_number) < 1 || strlen(add_number) > 14))
        {
            printf("\n\t[실패] 이름이나 전화번호는 영어 14자 또는 한글 7자를 넘을 수 없습니다. (엔터)");
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

            printf("\n\t[성공] 추가 되었습니다. (엔터)");
        }
        // 버퍼 초기화
        getchar();
        fflush(stdin);
    }
}

// Update 함수 정의
void Update()
{
    // Update 지역변수 선언
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
        scanf_s("%d", &update_select, sizeof(update_select));
        fflush(stdin);

        if (update_select == 0)
        {
            break;
        }
        else if (update_select == 1)
        {
            printf("\n\t선택할 순번 : ");
            scanf_s("%d", &update_idx, sizeof(update_idx));
        }
        else if (update_select == 2)
        {
            printf("\n\t선택할 이름 : ");
            scanf_s("%s", update_name, sizeof(update_name));
        }
        else if (update_select == 3)
        {
            printf("\n\t선택할 번호 : ");
            scanf_s("%s", update_number, sizeof(update_number));
        }
        else
        {
            printf("\n\t[실패] 잘못 입력 하셨습니다. (엔터)");
            getchar();
        }

        // 버퍼 초기화
        fflush(stdin);

        //////////////////////////////////////////////////////////////////////////////////////////////////// 0-2

        while (update_select >= 1 && update_select <= 3)
        {
            // 초기화
            update_new_select = 0;
            memset(update_new_name, 0, sizeof(update_new_name));
            memset(update_new_number, 0, sizeof(update_new_number));

            printf("\n\t1. 이름 수정  2. 번호 수정  0. 이전으로 : ");
            scanf_s("%d", &update_new_select, sizeof(update_new_select));
            fflush(stdin);

            if (update_new_select == 0)
            {
                break;
            }
            else if (update_new_select == 1)
            {
                printf("\n\t수정할 이름 : ");
                scanf_s("%s", update_new_name, sizeof(update_new_name));
            }
            else if (update_new_select == 2)
            {
                printf("\n\t수정할 번호 : ");
                scanf_s("%s", update_new_number, sizeof(update_new_number));
            }
            else
            {
                printf("\n\t[실패] 잘못 입력 하셨습니다. (엔터)");
                getchar();
            }

            // 버퍼 초기화
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
                    printf("\n\t[결과] 수정 되었습니다. (엔터)");
                else
                    printf("\n\t[실패] 수정할 대상이 없습니다. (엔터)");

                // 버퍼 초기화
                getchar();
                fflush(stdin);
                break;
            }
        }
    }
}

// Delete 함수 정의
void Delete()
{
    // Delete 지역변수 선언
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
        scanf_s("%d", &delete_select, sizeof(delete_select));
        fflush(stdin);

        if (delete_select == 0)
        {
            break;
        }
        else if (delete_select == 1)
        {
            printf("\n\t삭제할 순번 : ");
            scanf_s("%d", &delete_idx, sizeof(delete_idx));
        }
        else if (delete_select == 2)
        {
            printf("\n\t삭제할 이름 : ");
            scanf_s("%s", delete_name, sizeof(delete_name));
        }
        else if (delete_select == 3)
        {
            printf("\n\t삭제할 번호 : ");
            scanf_s("%s", delete_number, sizeof(delete_number));
        }
        else
        {
            printf("\n\t[실패] 잘못 입력 하셨습니다. (엔터)");
            getchar();
        }

        // 버퍼 초기화
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
                printf("\n\t[결과] 삭제 되었습니다. (엔터)");
            else
                printf("\n\t[실패] 삭제할 대상이 없습니다. (엔터)");

            // 버퍼 초기화
            getchar();
            fflush(stdin);
        }
    }
}

// DeleteAll 함수 정의
void DeleteAll()
{
    // DeleteAll 지역변수 선언
    char answer[10];

    while (1)
    {
        // 초기화
        memset(answer, 0, sizeof(answer));

        system("cls");

        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎  전부삭제  ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");

        printf("\n\t전부 삭제를 원하실 경우 \"전부삭제\"를 입력 해주세요(이전으로 0) : ");
        scanf_s("%s", answer, sizeof(answer));
        fflush(stdin);

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
            idx_cnt = 0;

            printf("\n\t[성공] 전부 삭제 되었습니다. (엔터)");
            // 버퍼 초기화
            getchar();
            fflush(stdin);
            break;
        }
        else
        {
            printf("\n\t[실패] 잘못 입력 하셨습니다. (엔터)");
            // 버퍼 초기화
            getchar();
            fflush(stdin);
        }
    }
}