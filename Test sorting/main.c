#include <stdlib.h>
#include <stdio.h>
#define array_size 10


void main() {
    int current, next, temp, sort[array_size];
    for (current = 0; current < array_size; current++){
      sort[current] = rand();
      printf("%d  -  ", sort[current]);
    }

    for (current = 0; current < array_size; ++current) {
        for (next = current + 1; next < array_size; ++next) {
            if (sort[current] > sort[next]) {
                temp =  sort[current];
                sort[current] = sort[next];
                sort[next] = temp;
            }
        }
    }
    printf("\nThe numbers arranged in ascending order are given below \n");
    for (current = 0; current < array_size; ++current)
        printf("%d  -  ", sort[current]);
}
