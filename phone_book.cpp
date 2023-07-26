/*

* 전체 설명 주석 추가
* 이후 XOR만을 사용한 데이터 암호화 복호화 기능 추가
* 이후 데이터량 증가로 연산속도 저하시 데이터 구조 변경(양방향 선형 구조 -> 트리 구조)
*
* ALL : 순번 이름 번호 입력 단계에서 추가 모드 처럼 0 입력시 이전으로 기능 추가
* search.cpp : 중복 찾기 기능 추가(이후 중복 데이터 선택 후 수정, 삭제 기능 추가)
* update.cpp : 이름 전화번호 제한 조건 추가(CheckLength, CheckNumber 이용)

////////////////////////////////////////////////////////////////////////////////////////////////////
show.cpp : C++ 스타일화
create.cpp : 이름 전화번호 입력 즉시 무결성 확인
create.cpp : C++ 스타일화
create.cpp : create 관련 멤버함수 수정
phonebook.h : PBData 생성자 추가(create 최적화)

(예정)
show.cpp : 정렬 맞추기
updata.cpp : C++ 스타일화

delete.cpp : delete_all 합치기
delete_all.cpp

search.cpp
common.cpp : 연산자 오버로딩 Search만 활성화

(이후 재활성화)
파일 입출력 기능 비활성화
연산자 오버로딩 기능 비활성화(NameNumber 클래스 제거)
< 	PushBack
<<	PushFront
>	Delete
>> 	DeleteAll
*	Search(Address)
&	Search(Reference)
////////////////////////////////////////////////////////////////////////////////////////////////////

*/

#include "phone_book.h"

int main()
{
    PhoneBook phone_book;
    int select_menu;

    while (1)
    {
        phone_book.Show();
        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");
        printf("▦ 1. 검색  ▦ 2. 추가  ▦ 3. 수정  ▦ 4. 삭제  ▦ 5. 전부삭제  ▦ 0. 종료  ▦\n");
        printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");

        switch (select_menu = _getch())
        {
        case MENU_1:
            phone_book.Search();
            break;
        case MENU_2:
            phone_book.Create();
            break;
        case MENU_3:
            phone_book.Update();
            break;
        case MENU_4:
            phone_book.Delete();
            break;
        case MENU_5:
            phone_book.DeleteAll();
            break;
        case MENU_0:
            printf("\n\t프로그램을 종료합니다. (엔터)");
            _getchar();
            return 0;
        default:
            printf("\n\t잘못 입력 하셨습니다. 다시 입력 해주세요 (엔터)");
            _getchar();
            break;
        }
    }

    return 0;
}
