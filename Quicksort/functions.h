//
// Created by Florian on 01.01.2022.
//

#ifndef QUICKSORT_FUNCTIONS_H
#define QUICKSORT_FUNCTIONS_H

#include <stdbool.h>

typedef struct item {
    int number;
    char* string;
};

void checkArray(struct item* startPtr, int size);

struct item * quicksort(struct item *items, int size, bool desc);

void printItemArray(struct item* items, int size);

struct item* getItems (int size);

struct item* getRandomItem();

#endif //QUICKSORT_FUNCTIONS_H
