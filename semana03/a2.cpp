#include <inttypes.h>
#include <stdio.h>
#include <iostream>

using namespace std;

typedef __int128_t i128;

i128 pow(i128 q, int64_t n, int64_t m) {
    for (int i = 0; i < n; i++) {
        q *= q % m;
    }
    return q % m;
}

int main() {
    i128 a;
    int64_t temp, n, m;
    cin >> temp >> n >> m;
    a = temp;
    
}
