#include <stddef.h>
#include <stdbool.h>

#ifndef elem_t 
#define elem_t    int
#endif

#define MAX(a, b)   ( ((a) > (b)) ? (a) : (b))


/* Task 1.1 */
elem_t* longest_sequence(elem_t* array, size_t n, size_t *length) {
    size_t i, count, pos;
    size_t max_count = 0;
    elem_t *seq;

    i = pos = count = 0;
    while (i < n) {
        if (array[pos] == array[i]) {
            count++;
            i++;
        }
        if ((array[pos] != array[i]) || (i == n)){
            if (count > max_count) {
                seq = &array[pos];
                max_count = count;
            }
            count = 0;
            pos = i;
        }
    }
    
    *length = max_count;
    return seq;
}


/* Task 1.2 */
elem_t* longest_rising_sequence(elem_t* array, size_t n, size_t *length) {
    size_t i, count, pos;
    size_t max_count = 0;
    elem_t *seq;

    i = pos = 0;
    count = 1;    
    while ((i+1) < n) {
        if (array[i] < array[i+1]) {
            count++;
            i++;
        }
        if ((array[i] >= array[i+1]) || ((i+1) == n)){
            if (count > max_count) {
                seq = &array[pos];
                max_count = count;
            }
            count = 1;
            pos = ++i;
        }
    }
    
    *length = max_count;
    return seq;
}


bool same_symbol(elem_t *array, size_t n, size_t *len) {
    size_t i;
    for (i = 1; i < n; i++) {
        if (array[0] != array[i]) {
            if (len != NULL) {
                *len = i;
            }
            return false;
        }
    }
    if (len != NULL) {
        *len = n;
    }
    return true;
}


bool contains_triple(elem_t *array, size_t n, size_t *len) {
    size_t i;
    for (i = 0; i < n-2; i += 1) {
        if (same_symbol(&array[i], 3, len)) {
            return true;
        }        
    }
    return false;
}


/* Task 1.3 */
size_t seqs_contain_triples(elem_t** arrays, size_t* n, size_t narrays) {

    size_t i, count;
    i = count = 0;

    for (i = 0; i < narrays; i++) {
        if (contains_triple(arrays[i], n[i], NULL)) {
            count++;
        }
    }
    return count;
}


/* Task 1.3: another interpretation */
size_t seqs_contain_triples2(elem_t* array, size_t n) {

    size_t i, count, pos;
    pos = i = count = 0;

    while (i < n) {
        if (same_symbol(&array[i], 3, &pos)) {
            count++;            
        }
        i += pos;
    }

    return count;
}


size_t div(size_t sum, size_t count) {
    return count == 0 ? 0 : (size_t) (((float) sum)/count);
}


/* Task 1.4: probably wrong interpretation */
size_t average_seqs_of_same_sym(elem_t **arrays, size_t *n, size_t narrays) {
    size_t sum, count, i;
    i = sum = count = 0;
    
    for (i = 0; i < narrays; i++) {
        if ((n[i] >= 2) && same_symbol(arrays[i], n[i], NULL)) {
            sum += n[i];
            count++;
        }
    }

    return div(sum, count);
}


/* Task 1.4: another interpretation  */
size_t average_seqs_of_same_sym2(elem_t *array, size_t n) {
    size_t sum, count, i, pos;
    i = sum = count = 0;
    
    while (i < n) {
        same_symbol(&array[i], n - i, &pos);
        if (pos > 1) {
            sum += pos;
            count++;
        }
        i += pos + 1;
    }

    return div(sum, count);
}


bool is_rising(elem_t *a, size_t n, size_t *len) {
    size_t i;
    for (i = 0; i < n-1; i++) {
        if (!(a[i+1] > a[i])) {
            *len = i;
            return false;
        }
    }
    *len = n - 1;
    return true;
}


/* Task 1.5 */
size_t seqs_rising(elem_t *a, size_t n) {
    size_t sum, count, i;
    i = sum = count = 0;
    size_t pos = 0;

    while (i < n) {
        is_rising(&a[i], n - i, &pos);
        if (pos > 0) {
            sum += pos + 1;
            count++;
        }
        i += pos + 1;
    }

    return div(sum, count);
}

