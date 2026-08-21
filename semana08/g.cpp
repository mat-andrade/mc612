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
    size_t i;
    if (str.size() <= 2) {
        cout << "NO\n";
        return 0;
    }
    for (i = 0; i < str.size() / 2 + 1; i++, a_pow = (a_pow * a) % MOD) {
        left_hash = (((left_hash * a) % MOD) + str[i]) % MOD;
        right_hash = (right_hash + ((a_pow * str[str.size() - i - 1]) % MOD)) % MOD;
    }
    i--;
    if (left_hash == right_hash) {
        bool equal = true;
        // for (size_t j = 0, k = str.size() - i - 1; j < i; j++) {
        //     if (str[j] != str[j]) {
        //         equal = false;
        //         break;
        //     }
        // }
        if (equal) {
            str.resize(i + 1);
            cout << "YES\n" << str << endl;
            return 0;
        }
    }
    for (i++;i < str.size() - 1; i++, a_pow = (a_pow * a) % MOD) {
        left_hash = (((left_hash * a) % MOD) + str[i]) % MOD;
        right_hash = (right_hash + ((a_pow * str[str.size() - i - 1]) % MOD)) % MOD;
        if (left_hash == right_hash) {
            bool equal = true;
            // for (size_t j = 0, k = str.size() - i - 1; j < i; j++) {
            //     if (str[j] != str[j]) {
            //         equal = false;
            //         break;
            //     }
            // }
            if (equal) {
                str.resize(i + 1);
                cout << "YES\n" << str << endl;
                return 0;
            }
        }
    }
    cout << "NO\n";
}
