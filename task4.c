#include <stdbool.h>
#include <stddef.h>

#ifndef elem_t 
#define elem_t    int
#endif

typedef bool (*comp_t)(elem_t, elem_t);

#define ABS(a)   ((a) > 0 ? (a) : (-(a)))


void swap(elem_t *a, elem_t *b) {
    if (*a == *b) {
        return;
    }

    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}


void sort(elem_t *a, size_t n, comp_t comp) {
    size_t i, j;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (!comp(a[j], a[i])) {
                swap(&a[i], &a[j]);
            }
        }
    }
}


bool gte(elem_t a, elem_t b) {
    return a >= b;
}


bool lte(elem_t a, elem_t b) {
    return a <= b;
}


bool gteabs(elem_t a, elem_t b) {
    return ABS(a) >= ABS(b);
}


bool lteabs(elem_t a, elem_t b) {
    return ABS(a) <= ABS(b);
}


unsigned short nbits(elem_t a) {
    unsigned short n = 0;

    while (a != 0) {
        if (a % 2 == 1) {
            //a--;
            n++;
        }
        n >>= 2;
    }

    return n;
}


bool bitmore(elem_t a, elem_t b) {
    return nbits(a) <= nbits(b);
}


/* Task 4.1 */
void sort_incr(elem_t *a, size_t n) {
    sort(a, n, gte);
}


/* Task 4.2 */
void sort_decr(elem_t *a, size_t n) {
    sort(a, n, lte);
}


/* Task 4.3 */
void sort_incr_abs(elem_t *a, size_t n) {
    sort(a, n, gteabs);
}


/* Task 4.4 */
void sort_decr_abs(elem_t *a, size_t n) {
    sort(a, n, lteabs);
}


/* Task 4.5 */
void sort_incr_bits(elem_t *a, size_t n) {
    sort(a, n, bitmore);
}

