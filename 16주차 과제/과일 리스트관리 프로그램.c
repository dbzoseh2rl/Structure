#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FRUITS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
} Fruit;

typedef struct {
    Fruit fruits[MAX_FRUITS];
    int count;
} FruitList;

void addFruit(FruitList* list, const char* name) {
    if (list->count < MAX_FRUITS) {
        Fruit fruit;
        strncpy(fruit.name, name, MAX_NAME_LENGTH);
        list->fruits[list->count++] = fruit;
        printf("과일이 추가되었습니다.\n");
    }
    else {
        printf("더 이상 과일을 추가할 수 없습니다.\n");
    }
}

void printFruits(const FruitList* list) {
    printf("과일 목록:\n");
    for (int i = 0; i < list->count; i++) {
        printf("- %s\n", list->fruits[i].name);
    }
}

int main() {
    FruitList list;
    list.count = 0;

    while (1) {
        printf("1. 과일 추가\n");
        printf("2. 과일 목록 출력\n");
        printf("3. 종료\n");
        printf("원하는 작업을 선택하세요: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            printf("추가할 과일의 이름을 입력하세요: ");
            char name[MAX_NAME_LENGTH];
            scanf("%s", name);
            addFruit(&list, name);
            break;
        }
        case 2:
            printFruits(&list);
            break;
        case 3:
            printf("프로그램을 종료합니다.\n");
            exit(0);
        default:
            printf("잘못된 선택입니다. 다시 선택하세요.\n");
        }

        printf("\n");
    }

    return 0;
}
