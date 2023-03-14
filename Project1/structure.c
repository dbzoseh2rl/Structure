/* 1���� ���� 
#include <stdio.h>
int main(void){
	int result = 0;                        // ����� ������ 0���� �ʱ�ȭ�Ѵ�.
	int k = 0;                             // ���� k�� 0���� �ʱ�ȭ
	for (int i = 2; i <= 100; i++){
		for (k = 2; k < i; k++){
			if (i % k == 0) break;         // i�� k�� ���� ���� 0�̸� �Ҽ��� �ƴϴ�.
		}
		if (k == i)                        // �� ��� �Ҽ��̹Ƿ� ��� ���� k�� �����ش�.
			result += k;
	}
	printf("1���� 100���� �Ҽ��� �� = %d\n", result);        // ��� ���� ����Ѵ�
}
*/

/* 2���� ���� */
#include <stdio.h>
double factorial_iter(double n) {
	if (n == 1) return 1;
	else return n * factorial_iter(n - 1);
}

double factorial_rec(double n) {
	double result = 1;
	for (int i = 2; i <= n; i++) {
		result *= i;
	}
	return result;
}

int main(void) {
	int n = 20;
	double result_iter = factorial_iter(n);
	printf("Iterative factorial result : %.lf\n", result_iter);

	double result_rec = factorial_rec(n);
	printf("Recursive factorial result : %.lf\n", result_rec);
	return 0;
}

