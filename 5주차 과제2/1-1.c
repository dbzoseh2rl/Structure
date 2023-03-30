#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

void push(int element) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    top++;
    stack[top] = element;
}

int pop() {
    int element;
    if (top == -1) {
        printf("Stack underflow!\n");
        return -1;
    }
    element = stack[top];
    top--;
    return element;
}

int peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack[top];
}

int main() {
    push(1);
    push(2);
    push(3);

    printf("%d\n", pop());
    printf("%d\n", peek());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());

    return 0;
}
