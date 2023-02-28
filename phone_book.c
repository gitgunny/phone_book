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

//////////////////////////////////////////////////////////////////////////////////////////////////// 파일입출력 추가
//////////////////////////////////////////////////////////////////////////////////////////////////// 추가 후 데이터량 증가로 연산속도 저하시 데이터 구조 변경(양방향 선형 구조 -> 트리 구조)

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

        select_menu = _getch(); //////////////////////////////////////////////////////////////////////////////////////////////////// 전체 함수 메뉴선택시 getch 기능으로 수정

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

//////////////////////////////////////////////////////////////////////////////////////////////////// 순번 자동정렬 추가(현재 중간 데이터 삭제 후 추가시 중간 순번 공백)

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

//////////////////////////////////////////////////////////////////////////////////////////////////// Search 함수 return형 함수로 바꿔서 인자값(순번, 이름, 번호) 설정 후 주소 반환으로 변경

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
        strcpy(search_name, "");
        strcpy(search_number, "");

        system("cls");

        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎    검색    ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");

        printf("\n\t1. 순번 검색  2. 이름 검색  3. 번호 검색  0. 이전으로 : ");
        //////////////////////////////////////////////////////////////////////////////////////////////////// 문자열 입력시 문제점
        scanf("%d", &search_select);
        fflush(stdin);

        if (search_select == 0)
            break;

        //////////////////////////////////////////////////////////////////////////////////////////////////// 현재 부분 if 삭제 후 아래 if들만 사용하면?? (else 위로 올려서 가독성 향상)
        if (search_select >= 1 && search_select <= 3)
        {
            if (search_select == 1)
            {
                printf("\n\t검색할 순번 : ");
                scanf("%d", &search_idx);
                fflush(stdin);
            }
            else if (search_select == 2)
            {
                printf("\n\t검색할 이름 : ");
                scanf("%s", search_name);
                fflush(stdin);
            }
            else if (search_select == 3)
            {
                printf("\n\t검색할 번호 : ");
                scanf("%s", search_number);
                fflush(stdin);
            }

            ptr = head;

            while (ptr != NULL)
            {
                //////////////////////////////////////////////////////////////////////////////////////////////////// 비슷한 부분들 하나로 합치면?? (Update 함수 처럼)
                if (search_select == 1 && ptr->idx == search_idx)
                    break;
                if (search_select == 2 && strcmp(ptr->name, search_name) == 0)
                    break;
                if (search_select == 3 && strcmp(ptr->number, search_number) == 0)
                    break;

                ptr = ptr->next;
            }

            if (ptr != NULL)
                printf("\n\t[결과]\t%-5d\t%-15s\t%-15s (엔터)", ptr->idx, ptr->name, ptr->number);
            else
                printf("\n\t[실패] 검색된 결과가 없습니다. (엔터)");

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
    char add_name[15];
    char add_number[15];

    while (1)
    {
        // 초기화
        strcpy(add_name, "");
        strcpy(add_number, "");

        system("cls");

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
        strcpy(update_name, "");
        strcpy(update_number, "");

        //////////////////////////////////////////////////////////////////////////////////////////////////// 아래 해당부분 while 구현시 아래 변수들 해당부분으로 이동
        // 초기화
        update_new_select = 0;
        strcpy(update_new_name, "");
        strcpy(update_new_number, "");

        system("cls");

        //////////////////////////////////////////////////////////////////////////////////////////////////// 2. (수정 함수) 1단계 입력 2단계 입력 질문 부분 수정(UI부분 변경시 전체 수정 검토)
        //////////////////////////////////////////////////////////////////////////////////////////////////// 3. 이전으로 -> 메인으로 구문 수정???
        //////////////////////////////////////////////////////////////////////////////////////////////////// 4. (수정 함수) 2단계 입력 while 추가로 잘못 입력시 반복 입력 기능 추가구현(메인으로 -> 이전으로)???

        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎    수정    ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");

        //////////////////////////////////////////////////////////////////////////////////////////////////// 3. 이전으로 -> 메인으로 구문 수정???

        printf("\n\t1. 순번 수정  2. 이름 수정  3. 번호 수정  0. 이전으로 : ");
        scanf("%d", &update_select);
        fflush(stdin);

        if (update_select == 0)
            break;

        if (update_select >= 1 && update_select <= 3)
        {
            if (update_select == 1)
            {
                printf("\n\t수정할 순번 : ");
                scanf("%d", &update_idx);
                fflush(stdin);
            }
            else if (update_select == 2)
            {
                printf("\n\t수정할 이름 : ");
                scanf("%s", update_name);
                fflush(stdin);
            }
            else if (update_select == 3)
            {
                printf("\n\t수정할 번호 : ");
                scanf("%s", update_number);
                fflush(stdin);
            }

            //////////////////////////////////////////////////////////////////////////////////////////////////// 3. 이전으로 -> 메인으로 구문 수정???
            //////////////////////////////////////////////////////////////////////////////////////////////////// 4-1. (수정 함수) 2단계 입력 while 추가로 잘못 입력시 반복 입력 기능 추가구현(메인으로 -> 이전으로)???
            //////////////////////////////////////////////////////////////////////////////////////////////////// 4-2. 이 단계에서 수정할 대상이 없다면 메시지 출력(Search 함수 개선)

            printf("\n\t1. 이름 수정  2. 번호 수정  0. 메인으로 : ");
            scanf("%d", &update_new_select);
            fflush(stdin);

            if (update_new_select == 0)
                break;

            if (update_new_select >= 1 && update_new_select <= 2)
            {
                if (update_new_select == 1)
                {
                    printf("\n\t수정할 이름 : ");
                    scanf("%s", update_new_name);
                }
                else if (update_new_select == 2)
                {
                    printf("\n\t수정할 번호 : ");
                    scanf("%s", update_new_number);
                }
                fflush(stdin);
            }
            else
            {
                printf("\n\t[실패] 잘못 입력 하셨습니다. (엔터)");
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
                printf("\n\t[결과] 수정 되었습니다. (엔터)");
            else
                printf("\n\t[실패] 수정할 대상이 없습니다. (엔터)");

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
        strcpy(delete_name, "");
        strcpy(delete_number, "");

        system("cls");

        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎    삭제    ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");

        printf("\n\t1. 순번 삭제  2. 이름 삭제  3. 번호 삭제  0. 이전으로 : ");
        scanf("%d", &delete_select);
        fflush(stdin);

        if (delete_select == 0)
            break;

        if (delete_select >= 1 && delete_select <= 3)
        {
            if (delete_select == 1)
            {
                printf("\n\t삭제할 순번 : ");
                scanf("%d", &delete_idx);
                fflush(stdin);
            }
            else if (delete_select == 2)
            {
                printf("\n\t삭제할 이름 : ");
                scanf("%s", delete_name);
                fflush(stdin);
            }
            else if (delete_select == 3)
            {
                printf("\n\t삭제할 번호 : ");
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
                printf("\n\t[결과] 삭제 되었습니다. (엔터)");
            else
                printf("\n\t[실패] 삭제할 대상이 없습니다. (엔터)");

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

void DeleteAll()
{
    char answer[10];

    while (1)
    {
        // 초기화
        strcpy(answer, "");

        system("cls");

        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎  전부삭제  ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");

        printf("\n\t전부 삭제를 원하실 경우 \"전부삭제\"를 입력 해주세요(이전으로 0) : ");
        scanf("%s", answer);
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
            idx_cnt = 1;

            printf("\n\t[성공] 전부 삭제 되었습니다. (엔터)");
            getchar();
            fflush(stdin);
            break;
        }
        else
        {
            printf("\n\t[실패] 잘못 입력 하셨습니다. (엔터)");
            getchar();
            fflush(stdin);
        }
    }
}