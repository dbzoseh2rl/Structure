
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 10

struct stack {
    int data[STACK_SIZE];
    int top;
};

void push(struct stack* s, int item) {
    if (s->top >= STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++s->top] = item;
}

int pop(struct stack* s) {
    if (s->top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[s->top--];
}

int main() {
    struct stack s;
    s.top = -1;

    srand(time(NULL)); // seed값으로 현재 시간을 사용하여 초기화

    for (int i = 0; i < 10; i++) {
        int random_num = rand() % 100 + 1; // 1~100 범위의 난수 생성
        printf("Random number: %d\n", random_num);
        if (random_num % 2 == 0) {
            printf("Pushing %d\n", random_num);
            push(&s, random_num);
        }
        else {
            printf("Popping %d\n", pop(&s));
        }
    }

    return 0;
}
