#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define MAX_DIGITS 128
#define BASE 256

#define BIGN_IS_ZERO(n) (((n)->lastdigit == 0) && ((n)->digits[0] == 0))

// Modificado dos algorítmos dos slides da aula.

typedef struct {
    unsigned char digits[MAX_DIGITS];
    int sign;
    int lastdigit;
} bignum;

void add_bignum(bignum *a, bignum *b, bignum *c);
void subtract_bignum(bignum *a, bignum *b, bignum *c);

void initialize_bignum(bignum *n) {
    for (int i = 0; i < MAX_DIGITS; i++) {
        n->digits[i] = 0;
    }
    n->lastdigit = 0;
    n->sign = 1;
}

void ll_to_bignum(long long s, bignum *n) {
    initialize_bignum(n);
    if (s < 0) {
        n->sign = -1;
        s = -s;
    }
    n->lastdigit = -1;
    while (s > 0) {
        n->digits[n->lastdigit++] = (unsigned char) (s % BASE);
        s = s / BASE;
    }
}

int compare_bignum(bignum *a, bignum *b) {
    if (a->sign != b->sign) {
        return b->sign;
    }

    if (a->lastdigit > b->lastdigit) {
        return -a->sign;
    } else if (b->lastdigit > a->lastdigit) {
        return a->sign;
    }
    
    for (int i = a->lastdigit; i >= 0; i--) {
        if (a->digits[i] > b->digits[i]) {
            return -a->sign;
        } else if (a->digits[i] < b->digits[i]) {
            return a->sign;
        }
    }
    return 0;
}

void digit_shift(bignum *n, int d) {
    if (BIGN_IS_ZERO(n)) {
        return;
    }

    for (int i = n->lastdigit; i >= 0; i--) {
        n->digits[i + d] = n->digits[i];
    }
    for (int i = 0; i < d; i++) {
        n->digits[i] = 0;
    }
    n->lastdigit += d;
}

void zero_justify(bignum *n) {
    while ((n->lastdigit > 0) && n->digits[n->lastdigit] == 0) {
        n->lastdigit--;
    }
    if (BIGN_IS_ZERO(n)) {
        n->sign = 1;
    }
}

void add_bignum(bignum *a, bignum *b, bignum *c) {
    int i, carry;
    initialize_bignum(c);
    if (a->sign == b->sign) {
        c->sign = a->sign;
        c->lastdigit = 0;
    } else if (a->sign == -1) {
        a->sign = 1;
        subtract_bignum(b, a, c);
        a->sign = -1;
    } else {
        b->sign = 1;
        subtract_bignum(a, b, c);
        b->sign = -1;
    }
}

