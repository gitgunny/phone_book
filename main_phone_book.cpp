/*

* 전체 설명 주석 추가
* 이후 XOR만을 사용한 데이터 암호화 복호화 기능 추가
* 이후 데이터량 증가로 연산속도 저하시 데이터 구조 변경(양방향 선형 구조 -> 트리 구조)
*
* ALL : 순번 이름 번호 입력 단계에서 추가 모드 처럼 0 입력시 이전으로 기능 추가
* _create.cpp : 버퍼 오버플로우 방지 함수 다듬기
* _create.cpp : 이름 전화번호 입력 즉시 실패 메시지 출력 여부 판단 추가
* _search.cpp : 중복 찾기 기능 추가(이후 중복 데이터 선택 후 수정, 삭제 기능 추가)
* _update.cpp : 이름 전화번호 제한 조건 추가(CheckLength, CheckNumber 이용)

////////////////////////////////////////////////////////////////////////////////////////////////////
파일 입출력 기능 추가(phone_book.pb)
멤버 함수 추가 ReadFile, WriteFile
WriteFile 동적 할당 해제 기능 통합
많은양의 연락처 출력시 참고를 위해 각 기능의 메뉴 출력시 콘솔 클리어 기능 제거

함수명 변경(Create -> Push)
동적 할당 해제 코드 수정(new PBData[1] -> new PBData)
일부 함수 매개변수 const 상수화

연산자 오버로딩 임시 구현
< 	PushBack
<<	PushFront
>	Delete
>> 	DeleteAll
*	Search(Address)
&	Search(Reference)
NameNumber 구조체 추가(멤버 변수 name, number)
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////

*/

#include "phone_book.h"

int main()
{
	PhoneBook phone_book;
	int select_menu;

	while (1)
	{
		system("cls");

		printf("▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦ ☎ 전화번호부 ☎ ▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦\n");
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