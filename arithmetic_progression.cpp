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
		// �������� ����
		int M;
		scanf("%d", &M);

		// ������ �Է� ����
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

		// ��� �����Ͱ� �����ϸ� ������ ������ 1�� ó��
		if (is_all_same) {
			num_gongcha = 1;
		}
		// 
		else {
			// ���ӵ� �������� ���� diff �� ���� ���� ���� min_diff�� ����
			long min_diff = data[1] - data[0];
			long diff;
			for (int i=2; i<M; ++i) {
				diff = (data[i] - data[i-1]);
				if (diff < min_diff) {
					min_diff = diff;
				}
			}

			// ���� �ĺ� gongcha�� 1���� min_diff���� �÷������� ����
			bool is_valid;
			for (int gongcha=1; gongcha<=min_diff; ++gongcha) {
				is_valid = true;
				// ���ӵ� �������� ���� diff �� ���� �ĺ� gongcha �� ����� ������ �ش� ������ ��ȿ
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

		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
        printf("%d\n", num_gongcha);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}