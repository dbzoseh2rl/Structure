#include <stdio.h>
#include <stdlib.h>

// 연결 리스트의 노드 구조체
struct Node {
    int data;
    struct Node* next;
};

// 연결 리스트의 헤드 포인터
struct Node* head = NULL;

// 새로운 노드를 생성하여 연결 리스트에 추가하는 함수
void appendNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    printf("새로운 노드가 추가되었습니다.\n");
}

// 연결 리스트의 모든 노드를 출력하는 함수
void printList() {
    if (head == NULL) {
        printf("연결 리스트가 비어 있습니다.\n");
        return;
    }

    struct Node* current = head;
    printf("연결 리스트의 노드들: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 연결 리스트를 초기화하는 함수
void clearList() {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;

    printf("연결 리스트가 초기화되었습니다.\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\n Menu \n");
        printf("1. Insert \n");
        printf("2. Delete\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        printf("Enter the menu ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("추가할 노드의 데이터 입력: ");
            scanf("%d", &data);
            appendNode(data);
            break;
        case 2:
            printList();
            break;
        case 3:
            clearList();
            break;
        case 4:
            printf("프로그램을 종료합니다.\n");
            exit(0);
        default:
            printf("잘못된 메뉴 선택입니다. 다시 선택하세요.\n");
        }
    }

    return 0;
}
