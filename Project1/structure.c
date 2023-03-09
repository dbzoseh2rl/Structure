
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