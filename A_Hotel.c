/************************************************************************
*																		*
*  Problem 13 : A_Hotel													*
*																		*
************************************************************************/
/************************************************************************
*	전자정보통신대학 컴퓨터공학부 3학년		CLC팀						*
*	20103378 임종호, 20103389 최원범, 20123426 최진성					* 
************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* in_file; 
	int test_case; // test case 수
	
	in_file = fopen("input.txt", "r"); // 파일 열기
	/* 에러처리 */
	if(in_file == NULL) {
		printf("file open error\n");
		exit(1);
	}

	fscanf(in_file, "%d ", &test_case); // test case 개수 입력
	while(test_case--) {
		int h, w, n; // 호텔의 층수, 호텔의 호수, n번째로 온 손님
		int line; // n 손님의 배정 층수
		int ho;   // n 손님의 배정 호수

		fscanf(in_file, "%d %d %d", &h, &w, &n); // 호텔의 크기와 몇번째 손님인지 입력

		/* 배정 층수 계산, n%h의 값은 배정되어야 할 층수 ( 단 h==n일때는 맨 꼭대기 층) */
		line = (n%h!=0)? n%h : h;
		/* 배정 호수 계산, (n-1)/h+1에서 (n-1)은 (0~h-1(h명)번째까지는 같은 호수, h~2h-1(h명)은 다음 호수 .....), */
		/* +1은 0<n<h 일 때는 결과가 0이지만 호수는 1부터 시작해야 하기 때문 */
		ho = (n-1)/h+1;
		printf("%d%d%d\n", line,ho/10,ho%10); // 층수와 호수 출력
	}
}