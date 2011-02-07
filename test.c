#include "task3.c"
#include <stdio.h>

void print(elem_t *a, size_t n) {
    int i;
    printf("%i: ", n);
    for (i = 0; i < n; i++) {
        printf("%i ", a[i]);
    }
    printf("\n");
}

void print_matrix(elem_t *a[], size_t n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%i ", a[j][i]);
        }
        printf("\n");
    }
}

int main() {
    elem_t array[2][2] = { {1, 2}, {3, 4} };
    size_t N = 2;
    elem_t *res;
    size_t l;

    print_matrix(array, N);
    return 0;
}
