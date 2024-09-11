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


int main() {
    __int128_t a, b, c;
    cin >> a >> b >> c;
    auto [r, x, y] = gcd(a, b);
    if ((-c) % r == 0) {
        __int128_t razao = (-c) / r;
        cout << x * razao << " " << y * razao << endl;
    } else {
        cout << "-1" << endl;
    }
}
