#include <stdbool.h>
#include <stddef.h>

#ifndef elem_t 
#define elem_t    int
#endif

/* Task 3.1 */
void max_sum(elem_t **a, size_t n, elem_t **res) {
    elem_t max_sum, sum;
    max_sum = sum = 0;

    size_t max_x, max_y, x, y;

    for (x = 0; x < n-1; x++) {
        for (y = 0; y < n-1; y++) {
            sum = a[x][y] + a[x+1][y] + a[x][y+1] + a[x+1][y+1];
            if (sum > max_sum) {
                max_x = x;
                max_y = y;
            }
        }
    }

    res[0][0] = a[x][y];
    res[0][1] = a[x][y+1];
    res[1][0] = a[x+1][y];
    res[1][1] = a[x+1][y+1];
}


bool bigger_then_neighbors(elem_t **a, size_t n, size_t x, size_t y) {
    if ((x-1 > 0) && (a[x-1][y] >= a[x][y])) {
        return false;
    }
    if ((x+1 < n) && (a[x+1][y] >= a[x][y])) {
        return false;
    }
    if ((y-1 > 0) && (a[x][y-1] >= a[x][y])) {
        return false;
    }
    if ((y+1 < n) && (a[x][y+1] >= a[x][y])) {
        return false;
    }
    return true;
}


/* Task 3.2 */
size_t num_bigger_then_neighbors(elem_t **a, size_t n) {
    size_t count;
    size_t x, y;

    count = 0;
    for (x = 0; x < n; x++) {
        for (y = 0; y < n; y++) {
            if (bigger_then_neighbors(a, n, x, y)) {
                count++;
            }
        }
    }
    return count;
}


bool lesser_then_neighbors(elem_t **a, size_t n, size_t x, size_t y) {
    if ((x-1 > 0) && (a[x-1][y] <= a[x][y])) {
        return false;
    }
    if ((x+1 < n) && (a[x+1][y] <= a[x][y])) {
        return false;
    }
    if ((y-1 > 0) && (a[x][y-1] <= a[x][y])) {
        return false;
    }
    if ((y+1 < n) && (a[x][y+1] <= a[x][y])) {
        return false;
    }
    return true;
}


/* Task 3.3 */
size_t num_lesser_then_neighbors(elem_t **a, size_t n) {
    size_t count;
    size_t x, y;

    count = 0;
    for (x = 0; x < n; x++) {
        for (y = 0; y < n; y++) {
            if (lesser_then_neighbors(a, n, x, y)) {
                count++;
            }
        }
    }
    return count;
}


/* Task 3.4 */
size_t num_eq_linenum(elem_t **a, size_t n) {
    size_t count;
    size_t x, y;

    count = 0;
    for (x = 0; x < n; x++) {
        for (y = 0; y < n; y++) {
            if (a[x][y] == y) {
                count++;
            }
        }
    }
    return count;
}


/* Task 3.5 */
size_t num_eq_numsum(elem_t **a, size_t n) {
    size_t count;
    size_t x, y;

    count = 0;
    for (x = 0; x < n; x++) {
        for (y = 0; y < n; y++) {
            if (a[x][y] == x+y) {
                count++;
            }
        }
    }
    return count;
}
