#include <stdbool.h>
#include <stddef.h>

#ifndef elem_t 
#define elem_t    int
#endif


size_t avg(size_t a, size_t b) {
    return (b - a) / 2.0 + a;
}


/* Task 2.1 */
elem_t min_bigger(elem_t *array, size_t n, elem_t x) {
    size_t l, r, pos;
    l = 0;
    r = n-1;

    if (x > array[n-1]) {
        return -1;
    }

    while (true) {
        pos = avg(l, r);
        if (pos == l) {
            if (array[l] > x) {
                return array[l];
            }
            return array[r];
        } else if (pos == r) {
            return array[l];
        }
        if (array[pos] <= x) {
            l = pos;
        } else {
            r = pos;
        }
    }

    return -1;
}


/* Task 2.2 */
elem_t max_smaller(elem_t *array, size_t n, elem_t x) {
    size_t l, r, pos;
    l = 0;
    r = n-1;

    if (x < array[0]) {
        return -1;
    }

    while (true) {
        pos = avg(l, r);
        if (pos == l) {
            if (array[r] < x) {
                return array[r];
            }
            return array[l];
        } else if (pos == r) {
            return array[r];
        }
        if (array[pos] <= x) {
            l = pos;
        } else {
            r = pos;
        }
    }

    return -1;
}


/* Task 2.3 */
elem_t num_bigger(elem_t *array, size_t n, elem_t x) {
    size_t l, r, pos;
    l = 0;
    r = n-1;

    if (x > array[n-1]) {
        return 0;
    }

    while (true) {
        pos = avg(l, r);
        if (pos == l) {
            if (array[l] > x) {
                return n - l;                
            }
            return n - r;
        } else if (pos == r) {
            return n - l;
        }
        if (array[pos] <= x) {
            l = pos;
        } else {
            r = pos;
        }
    }

    return -1;
}


/* Task 2.4 */
elem_t num_smaller(elem_t *array, size_t n, elem_t x) {
    size_t l, r, pos;
    l = 0;
    r = n-1;

    if (x < array[0]) {
        return 0;
    }

    while (true) {
        pos = avg(l, r);
        if (pos == l) {
            if (array[r] < x) {
                return r + 1;
            }
            return l + 1;
        } else if (pos == r) {
            return r + 1;
        }
        if (array[pos] <= x) {
            l = pos;
        } else {
            r = pos;
        }
    }

    return 0;
}


size_t ind_min(elem_t *array, size_t n, elem_t x) {
    size_t l, r, pos;
    l = 0;
    r = n-1;

    while (true) {
        pos = avg(l, r);
        if (pos == l) {
            if (array[l] > x) {
                return l;
            }
            return r;
        } else if (pos == r) {
            return l;
        }
        if (array[pos] <= x) {
            l = pos;
        } else {
            r = pos;
        }
    }
}


size_t ind_max(elem_t *array, size_t n, elem_t x) {
    size_t l, r, pos;
    l = 0;
    r = n-1;

    while (true) {
        pos = avg(l, r);
        if (pos == l) {
            if (array[r] < x) {
                return r;
            }
            return l;
        } else if (pos == r) {
            return r;
        }
        if (array[pos] <= x) {
            l = pos;
        } else {
            r = pos;
        }
    }

    return -1;
}


/* Task 2.5 */
elem_t num_between(elem_t *array, size_t n, elem_t x, elem_t y) {

    if ((y < array[0]) || (x > array[n-1])) {
        return 0;
    }

    return ind_min(array, n, y) - ind_max(array, n, x);
}

