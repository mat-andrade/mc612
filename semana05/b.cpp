#include <bits/stdc++.h>

using namespace std;

tuple<__int128_t, __int128_t, __int128_t> gcd(__int128_t a, __int128_t b) {
    __int128_t r0 = a, r1 = b;
    __int128_t s0 = 1, s1 = 0;
    __int128_t t0 = 0, t1 = 1;

    while (r1 != 0) {
        __int128_t q = r0 / r1;
        __int128_t tmp;

        tmp = r0;
        r0 = r1;
        r1 = tmp - q * r1;
        
        tmp = s0;
        s0 = s1;
        s1 = tmp - q * s1;

        tmp = t0;
        t0 = t1;
        t1 = tmp - q * t1;
    }
    return make_tuple(r0, s0, t0);
}


__int128_t lcm(__int128_t a, __int128_t b, __int128_t g) {
    return a * (b / g);
}

int main() {
    int t;
    cin >> t;
    for (; t > 0; t--) {
        int32_t _a, _n, _b, _m, _k;
        __int128_t a, n, b, m, k;
        cin >> _a >> _n >> _b >> _m;
        a = _a; b = _b; n = _n; m = _m; 
        auto [r, s, t] = gcd(n, m);
        k = lcm(n, m, r);
        if ((b - a) % r != 0) {
            cout << "no solution" << endl;
        } else {
            auto k2 = ((b - a) / r) * s % (m / r);
            auto x = (a + (k2 * n)) % k;
            cout << (int32_t) x << " " << (int32_t) k << endl;
        }
    }
}
