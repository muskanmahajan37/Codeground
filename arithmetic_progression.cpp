#include <cstdio>
#include <iostream>

using namespace std;

long data[100000];

int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	int T;
	int test_case;
    
	scanf("%d", &T);
	for(test_case = 1; test_case <= T; test_case++) {
		// 데이터의 개수
		int M;
		scanf("%d", &M);

		// 데이터 입력 받음
		bool is_all_same = true;
		for (int i=0; i<M; ++i) {
			scanf("%ld", &data[i]);
			if (i > 0 && is_all_same) {
				if (data[i] != data[i-1]){ 
					is_all_same = false;
				}
			}
		}
		
		int num_gongcha = 0;

		// 모든 데이터가 동일하면 공차의 개수를 1로 처리
		if (is_all_same) {
			num_gongcha = 1;
		}
		// 
		else {
			// 연속된 데이터의 차이 diff 중 가장 작은 값을 min_diff에 저장
			long min_diff = data[1] - data[0];
			long diff;
			for (int i=2; i<M; ++i) {
				diff = (data[i] - data[i-1]);
				if (diff < min_diff) {
					min_diff = diff;
				}
			}

			// 공차 후보 gongcha를 1부터 min_diff까지 늘려나가며 검증
			bool is_valid;
			for (int gongcha=1; gongcha<=min_diff; ++gongcha) {
				is_valid = true;
				// 연속된 데이터의 차이 diff 가 공차 후보 gongcha 의 배수가 않으면 해당 공차는 무효
				for (int i=1; i<M; ++i) {
					diff = (data[i] - data[i-1]);
					if (diff % gongcha != 0) {
						is_valid = false;
						break;
					}
				}
				if (is_valid) {
					num_gongcha += 1;
				}
			}
		}

		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
        printf("%d\n", num_gongcha);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}