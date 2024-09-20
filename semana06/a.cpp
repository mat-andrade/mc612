#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

int main() {
    string str;
    cin >> str;
    uint64_t a = 61;
    uint64_t a_pow = 1;
    uint64_t left_hash, right_hash;
    left_hash = 0;
    right_hash = 0;
    for (size_t i = 0; i < str.size() - 1; i++, a_pow = (a_pow * a) % MOD) {
        left_hash = (((left_hash * a) % MOD) + str[i]) % MOD;
        right_hash = (right_hash + ((a_pow * str[str.size() - i - 1]) % MOD)) % MOD;
        if (left_hash == right_hash) {
            cout << i + 1 << ' ';
        }
    }
    cout << endl;
}
