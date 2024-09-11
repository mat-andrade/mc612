#include <stdio.h>
#include <iostream>

using namespace std;

#define MOD 1000000007LL

long long pow2(long long n) {
    long long aux;
    if (n == 0) {
        return 1;
    } else if (n % 2 == 0) {
        aux = pow2(n / 2);
        return (aux * aux) % MOD;
    } else {
        aux = pow2((n - 1) / 2);
        return (2 * ((aux * aux) % MOD))% MOD;
    }
}

int main() {
    long long n;
    cin >> n;
    long long p = pow2(n);
    cout << (((p + 1) * p) / 2) % MOD << endl;
}
