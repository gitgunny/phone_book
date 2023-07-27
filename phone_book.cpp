/*
////////////////////////////////////////////////////////////////////////////////////////////////////
(완료)
search.cpp : C++ 스타일화(string 클래스 추가로 오버플로우 방지)
search.cpp : 이름 및 번호 비교 버그 수정
search.cpp : search 기능으로 delete, update 기능 최적화
delete.cpp : C++ 스타일화(string 클래스 추가로 오버플로우 방지)
delete.cpp : 삭제 시 리스트간 버그 수정
show.cpp : 버퍼 비우기 기능 추가

(예정)
updata.cpp : C++ 스타일화(string 클래스 추가로 오버플로우 방지)
update.cpp : 이름 및 번호 무결성 확인 기능 추가

ALL : 입력처리 변경(cin 연산자 오버로딩 -> cin getline 함수)

common.cpp : C++ 스타일화(C 스타일(_fscanf, _fgets) 함수 삭제)
common.cpp : _getchar 버퍼 문제 해결
common.cpp : 연산자 오버로딩 Search만 활성화 이외 제거

search.cpp : 중복 찾기 기능 추가(이후 중복 데이터 선택 후 수정, 삭제 기능 추가)
////////////////////////////////////////////////////////////////////////////////////////////////////
* (향후)
* 전체 설명 주석 추가
* XOR 데이터 암호화 복호화 기능 추가
* 데이터량 증가로 연산속도 저하시 데이터 구조 변경(양방향 선형 구조 -> 트리 구조)
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
        cout << "▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦" << endl;
        cout << "▦ 1. 검색  ▦ 2. 추가  ▦ 3. 수정  ▦ 4. 삭제  ▦ 5. 전부삭제  ▦ 0. 종료  ▦" << endl;
        cout << "▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦" << endl;

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
            cout << endl << "\t프로그램을 종료합니다. (엔터)";
            _getchar();
            return 0;
        default:
            cout << endl << "\t잘못 입력 하셨습니다. 다시 입력 해주세요 (엔터)";
            _getchar();
            break;
        }
    }

    return 0;
}
