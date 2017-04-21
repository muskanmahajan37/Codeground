#include <cstdio>
#include <iostream>

using namespace std;

int P[10001];
int Q[10001];
int INCOME[10001];

#define MAX(x, y)	((x > y) ? (x) : (y))

int main(int argc, char** argv) {
	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	// 테이트 케이스 수
	int T;
	scanf("%d", &T);
	
	for(int test_case = 1; test_case <= T; test_case++) {
		printf("Case #%d\n", test_case);
        
		// 주의 수
		int NUM_WEEK;
		scanf("%d", &NUM_WEEK);

		// P, Q, INCOME 정보 초기화
		for (int week=1; week <= NUM_WEEK; ++week)
			scanf("%d", &P[week]);
		for (int week=1; week <= NUM_WEEK; ++week)
			scanf("%d", &Q[week]);
		for (int week=1; week <= NUM_WEEK; ++week)
			INCOME[week] = 0;
		
		// 첫 번째 주
		INCOME[1] = MAX(P[1], Q[1]);

		// 그 이후의 주
		for (int week=2; week <= NUM_WEEK; ++week) {
			int select_p = INCOME[week-1] + P[week];
			int select_q = INCOME[week-2] + Q[week];
			INCOME[week] = MAX(select_p, select_q);
		}

		printf("%d\n", INCOME[NUM_WEEK]);
	}

	return 0;
}