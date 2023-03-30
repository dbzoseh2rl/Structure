
#include <stdio.h>
#include <stdlib.h>

// 스택 구조체 정의
struct stack {
    int* data; // 동적 배열 포인터
    int top; // 스택의 탑 인덱스
    int max_size; // 스택의 최대 크기
};

// 스택 초기화 함수
void init_stack(struct stack* s, int max_size) {
    s->data = (int*)malloc(max_size * sizeof(int)); // 동적 배열 생성
    s->top = -1; // 스택이 비어있음을 표시
    s->max_size = max_size;
}

// 스택 삽입 함수
void push(struct stack* s, int item) {
    if (s->top >= s->max_size - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++s->top] = item;
}

// 스택 삭제 함수
int pop(struct stack* s) {
    if (s->top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[s->top--];
}

// 스택 출력 함수
void print_stack(struct stack* s) {
    printf("Stack contents: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

// 스택 해제 함수
void destroy_stack(struct stack* s) {
    free(s->data); // 동적 배열 해제
    s->top = -1;
    s->max_size = 0;
}

// 테스트 코드
int main() {
    struct stack s;
    init_stack(&s, 5);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5); // 스택이 가득참

    print_stack(&s);

    pop(&s);
    pop(&s);

    print_stack(&s);

    destroy_stack(&s);

    return 0;
}
