//
// Created by Florian on 01.01.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"
#include <time.h>

void checkArray(struct item* startPtr, int size){
    struct item items[size];
    int intArr[size];

    for(int i =0; i < size; i++){
        items[i] = *(startPtr + i);
        intArr[i] = (startPtr + i)->number;
    }

}

struct item * quicksort(struct item *items, int size, bool desc) {
    int temp = 0;

    if (size < 2) {
        return items;
    }
    if (size == 2) {
        if (desc) {
            if (items[0].number > items[1].number) {
                return items;
            }
            else {
                temp = items[0].number;
                items[0].number = items[1].number;
                items[1].number = temp;
                return items;
            }
        }
        else {
            if (items[0].number < items[1].number) {
                return items;
            }
            else {
                temp = items[0].number;
                items[0].number = items[1].number;
                items[1].number = temp;
                return items;
            }
        }
    }


    int pivot = items->number;
    int lesser[size];
    int greater[size];
    int greaterCounter = 0;
    int lesserCounter = 0;

    for (int i=1; i < size;i++) {                                   //i = 1 weil pivot nicht mit selbst
        if (pivot < (items+i)->number) {
            greater[greaterCounter++] = (items+i)->number;
        }
        else {
            lesser[lesserCounter++] = (items+i)->number;
        }
    }

    int* lesserSorted = quicksort(lesser, lesserCounter, desc);
    int* greaterSorted = quicksort(greater, greaterCounter, desc);
    struct item sorted[size];
    struct item* sortedPtr = sorted;

    //struct item* sorted = malloc(size * sizeof(struct item));

    int sortedCounter = 0;

    if (desc) {
        for(int y = 0;y<greaterCounter;y++) {
            sortedPtr[sortedCounter++].number = *(greaterSorted + y);
        }

        sortedPtr[sortedCounter++].number = pivot;

        for(int z = 0;z<lesserCounter;z++) {
            sortedPtr[sortedCounter++].number = *(lesserSorted + z);
        }
    } else {
        for(int z = 0;z<lesserCounter;z++) {
            sortedPtr[sortedCounter++].number = *(lesserSorted + z);
        }

        sortedPtr[sortedCounter++].number = pivot;

        for(int y = 0;y<greaterCounter;y++) {
            sortedPtr[sortedCounter++].number = *(greaterSorted + y);
        }
    }

    return sortedPtr;
}

void printItemArray(struct item* items, int size) {
    for(int i=0;i<size;i++) {
        printf("%d. %d\n", i, (items+i)->number);
    }
}

struct item* getItems (int size){
    srand(time(0));
    struct item items[size];
    struct item* itemsPtr = items;

    for(int i = 0; i < size; i++){
        items[i] = *(getRandomItem());
    }
    return itemsPtr;
}

//https://stackoverflow.com/questions/15767691/whats-the-c-library-function-to-generate-random-string
char* rand_str(char *dest, size_t length) {
    char *firstIndex = dest;
    char charset[] = "0123456789"
                     "abcdefghijklmnopqrstuvwxyz"
                     "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (length-- > 0) {
        //size_t index = (double) rand() / RAND_MAX * (sizeof charset - 1);
        size_t index = rand() % (sizeof(charset) - 1);
        *dest++ = charset[index];
    }
    *dest = '\0';
    return firstIndex;
}

struct item *getRandomItem() {
    char str[] = { [10] = '\1' };
    struct item item;

    item.number = rand()%100;
    item.string = rand_str(str, sizeof str - 1);


    return &item;
}



