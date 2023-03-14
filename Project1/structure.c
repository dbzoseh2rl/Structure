/* 1주차 과제 
#include <stdio.h>
int main(void){
	int result = 0;                        // 결과값 변수를 0으로 초기화한다.
	int k = 0;                             // 변수 k를 0으로 초기화
	for (int i = 2; i <= 100; i++){
		for (k = 2; k < i; k++){
			if (i % k == 0) break;         // i를 k로 나눈 값이 0이면 소수가 아니다.
		}
		if (k == i)                        // 이 경우 소수이므로 결과 값에 k를 더해준다.
			result += k;
	}
	printf("1부터 100까지 소수의 합 = %d\n", result);        // 결과 값을 출력한다
}
*/

/* 2주차 과제 */
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

