#include <stdio.h>
#define MAX_STACK_SIZE 10 // 스택의 최대 크기

// 스택을 구조체 배열로 정의
struct stack {
    int data[MAX_STACK_SIZE];
    int top; // 스택의 탑 인덱스
};

// 스택 초기화 함수
void init_stack(struct stack* s) {
    s->top = -1; // 스택이 비어있음을 표시
}

// 스택 삽입 함수
void push(struct stack* s, int item) {
    if (s->top >= MAX_STACK_SIZE - 1) {
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

// 테스트 코드
int main() {
    struct stack s;
    init_stack(&s);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);

    print_stack(&s);

    pop(&s);
    pop(&s);

    print_stack(&s);

    return 0;
}
