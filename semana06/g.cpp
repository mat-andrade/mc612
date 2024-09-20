#include <bits/stdc++.h>

using namespace std;

int64_t sieve_size;
bitset<100010> isprime;
vector<int64_t> primes;


/**
 * funções sieve, totiente tomadas do slide da aula 6
 */
void sieve(int64_t upperbound) {
    sieve_size = upperbound + 1;
    isprime.set();
    isprime[0] = isprime[1] = 0;
    for (int64_t i = 2; i <= sieve_size; i++) {
        for (int64_t j = i * i; j <= sieve_size; j += i) {
            isprime[j] = 0;
        }
        primes.push_back(i);
    }
}

int64_t totiente(int64_t n) {
    int64_t idx = 0, pf = primes[idx], ans = n;
    while (n != 1 && (pf * pf <= n)) {
        if (n % pf == 0) {
            ans -= ans / pf;
        }
        for (;n % pf == 0; n /= pf);
        pf = primes[++idx];
    }
    if (n != 1) {
        ans -= ans / n;
    }
    return ans;
}

int main() {
    sieve(10001);
    int t;
    for (cin >> t; t > 0; t--) {
        int64_t n;
        cin >> n;
        cout << totiente(n) << endl;
    }
}
