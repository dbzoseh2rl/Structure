#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FRUITS 100

typedef struct {
    char name[20];
} Fruit;

void addFruit(Fruit* fruits, int* count, const char* name) {
    if (*count >= MAX_FRUITS) {
        printf("리스트가 가득 찼습니다.\n");
        return;
    }

    Fruit newFruit;
    strcpy(newFruit.name, name);
    fruits[*count] = newFruit;
    (*count)++;

    printf("%s이(가) 리스트에 추가되었습니다.\n", name);
}

void removeFruit(Fruit* fruits, int* count, const char* name) {
    int foundIndex = -1;

    for (int i = 0; i < *count; i++) {
        if (strcmp(fruits[i].name, name) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("%s이(가) 리스트에 존재하지 않습니다.\n", name);
        return;
    }

    for (int i = foundIndex; i < *count - 1; i++) {
        fruits[i] = fruits[i + 1];
    }

    (*count)--;
    printf("%s이(가) 리스트에서 제거되었습니다.\n", name);
}

void printFruitList(Fruit* fruits, int count) {
    if (count == 0) {
        printf("리스트가 비어 있습니다.\n");
        return;
    }

    printf("과일 리스트:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", fruits[i].name);
    }
}

int main() {
    Fruit fruits[MAX_FRUITS];
    int count = 0;

    while (1) {
        printf("1. 과일 추가\n");
        printf("2. 과일 제거\n");
        printf("3. 리스트 확인\n");
        printf("4. 종료\n");
        printf("선택: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char fruitName[20];
                printf("추가할 과일 이름: ");
                scanf("%s", fruitName);
                addFruit(fruits, &count, fruitName);
                break;
            }
            case 2: {
                char fruitName[20];
                printf("제거할 과일 이름: ");
                scanf("%s", fruitName);
                removeFruit(fruits, &count, fruitName);
                break;
            }
            case 3:
                printFruitList(fruits, count);
                break;
            case 4:
                printf("프로그램을 종료합니다.\n");
                exit(0);
            default:
                printf("잘못된 선택입니다. 다시 선택해주세요.\n");
        }

        printf("\n");
    }

    return 0;
}
