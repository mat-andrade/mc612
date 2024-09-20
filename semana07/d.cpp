#include <bits/stdc++.h>

using namespace std;

#define WALK(_f, _ptr) _ptr = (f)(_ptr)

/**
 * Algorithm from class slides.
 */
tuple<int64_t, int64_t> floydCycleFinding (int64_t x0, int64_t (*f)(int64_t)) {
    int64_t tortoise = f(x0), hare = f(f(x0));
    while (tortoise != hare) {
        WALK(f, tortoise);
        WALK(f, hare);
        WALK(f, hare);
    }
    int64_t mu = 0;
    hare = x0;
    while (tortoise != hare) {
        WALK(f, tortoise);
        WALK(f, hare);
        mu++;
    }
    int64_t lambda = 1;
    hare = f(tortoise);
    while (tortoise != hare) {
        WALK(f, hare);
        lambda++;
    }
    return make_tuple(mu, lambda);
}
