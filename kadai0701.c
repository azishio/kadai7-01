#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

#define NUM 5

void QSort(int*, int, int);

int main(void) {
    printf("整数を%dつ入力", NUM);
    int array[NUM];
    for (int i = 0; i < NUM; ++i) {
        scanf("%d", &array[i]);
    }

    QSort(&array, 0, NUM - 1);

    printf("\n");
    for (int i = 0; i < NUM; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void QSort(int* ARRAY, int LEFT, int RIGHT) {
    int temp, left = LEFT, right = RIGHT, canon = ARRAY[LEFT];

    while (1) {
        while (ARRAY[left] < canon) ++left;

        while (ARRAY[right] > canon) --right;

        if (left < right) {
            temp         = ARRAY[left];
            ARRAY[left]  = ARRAY[right];
            ARRAY[right] = temp;

            ++left;
            --right;
        } else {
            break;
        }
    }
    if (left - LEFT > 1) {
        QSort(ARRAY, LEFT, left - 1);
    }
    if (RIGHT - right > 1) {
        QSort(ARRAY, right + 1, RIGHT);
    }
}
