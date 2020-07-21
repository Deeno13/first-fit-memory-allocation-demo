/* 
 * Copyright © 2020, 
 * Awang Hafizuddin bin Awang Hamdani
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 5

void cleanUp();
void pause();
void initAlloc(int* arr, int i, int j, int holeSize[]);
void finalAlloc(int* arr, int i, int j, int holeSize[]);
void firstFit(int i, int j, int dataBlockSize, int holeSize[SIZE], bool full[SIZE]);
void fullCheck(int i, bool full[]);

int main() {
    int i, j, dataBlockSize;
    int* arr = (int*)calloc(3, sizeof(int));
    int holeSize[SIZE] = {4, 3, 8, 2, 3};
    bool full[SIZE] = {false, false, false, false, false};

    cleanUp();
    printf("Welcome to Awang's demo of First Fit Memory Allocation!\n\n");

    initAlloc(arr, i, j, holeSize);
    firstFit(i, j, dataBlockSize, holeSize, full);
    fullCheck(i, full);
    finalAlloc(arr, i, j, holeSize);
    pause();

    printf("hello");

    return 0;
}

void cleanUp() { system("cls"); }

void pause() { system("pause"); }

void initAlloc(int* arr, int i, int j, int holeSize[]) {
    printf("Initial space allocation\n");
    for (i = 0; i < SIZE; i++) {
        printf("Hole %d : ", i);
        arr = realloc(arr, holeSize[i] * sizeof(int));
        for (j = 0; j < holeSize[i]; j++)
            printf("%d ", arr[j]);
        printf("\n");
    }
}

void finalAlloc(int* arr, int i, int j, int holeSize[]) {
    printf("\n\nFinal space allocation\n");
    for (i = 0; i < SIZE; i++) {
        printf("Hole %d : ", i);
        arr = realloc(arr, holeSize[i] * sizeof(int));
        for (j = 0; j < holeSize[i]; j++)
            printf("%d ", arr[j]);
        printf("\n");
    }
}

void firstFit(int i, int j, int dataBlockSize, int holeSize[SIZE], bool full[SIZE]) {
    for (i = 0; i < SIZE; i++) {
        printf("\nEnter the data block size: ");
        scanf("%d", &dataBlockSize);

        for (j = 0; j < SIZE; j++) {
            if ((holeSize[j] >= dataBlockSize) && (full[j] == false)) {
                if ((holeSize[j] > dataBlockSize) && (full[j + 1] == false) && !(j == 4))
                    holeSize[j + 1] += (holeSize[j] - dataBlockSize);
                if (!(j == 4) && (full[j + 1] == false)) {
                    holeSize[j] = dataBlockSize;
                    full[j] = true;
                } else {
                    full[j] = true;
                }
                printf("Allocated to hole %d\n", j);
                break;
            } else {
                printf("Unable to allocate to hole %d\n", j);
            }
        }
    }
}

void fullCheck(int i, bool full[]) {
    printf("\nAll holes occupied?\n");
    for (i = 0; i < SIZE; i++) {
        if (full[i] == true)
            printf("true\t");
        else
            printf("false\t");
    }
}
