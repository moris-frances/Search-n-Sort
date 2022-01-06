#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"


int main() {
    int size = 100;
    struct item* items = getItems(size);
    checkArray(items, size);

    struct item* arr = quicksort(items, size, false);

    printItemArray(arr, size);

    for(int i = 0; i<size;i++){
        free(&items[i]);
    }

    return 0;
}


