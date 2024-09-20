#include <bits/stdc++.h>

using namespace std;

#define WALK(_f, _ptr) _ptr = (f)(_ptr)

int64_t z, i, m, l;

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

int64_t rng(int64_t l) {
    return (z * l + i) % m;
}

int main() {
    int64_t j = 1;
    while (true) {
        cin >> z >> i >> m >> l;
        if (z == 0 && i == 0 && m == 0 && l == 0) {
            break;
        }
        auto [mu, lambda] = floydCycleFinding(l, rng);
        cout << "Case " << j++ << ": " << lambda << endl;
    }
}

