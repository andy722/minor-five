#include <stdbool.h>
#include <stddef.h>

#ifndef elem_t 
#define elem_t    int
#endif


bool equals(elem_t *a, elem_t *b, size_t n) {
    size_t i;
    for (i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}


/* Task 5.1 */
size_t find_first(elem_t *a, size_t n, elem_t *b, size_t m) {
    size_t i;

    for (i = 0; i < n; i++) {
        if (i+m > n) {
            return -1;
        }

        if (equals(&a[i], b, m)) {
            return i;
        }
    }

    return -1;
}


/* Task 5.2 */
size_t find_num(elem_t *a, size_t n, elem_t *b, size_t m) {
    size_t i;
    size_t count = 0;

    for (i = 0; i < n; i++) {
        if (i+m > n) {
            return 0;
        }

        if (equals(&a[i], b, m)) {
            count++;
        }
    }

    return count;
}


/* Task 5.3 */
size_t find_last(elem_t *a, size_t n, elem_t *b, size_t m) {
    size_t i;
    size_t last = 0;

    for (i = 0; i < n; i++) {
        if (i+m > n) {
            return last;
        }

        if (equals(&a[i], b, m)) {
            last = i;
        }
    }

    return last;
}

