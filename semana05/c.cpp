#include <bits/stdc++.h>

using namespace std;

int64_t sieve_size;
bitset<10001> isprime;
vector<int64_t> primes;


/**
 * funções sieve, is_prime e prime_factors tomadas do slide
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

vector<int64_t> prime_factors(int64_t n) {
    vector<int64_t> factors;
    if (n == 1) {
        factors.push_back(1);
        return factors;
    }
    int64_t pf_idx = 0, pf = primes[pf_idx];
    while (n != 1 && (pf * pf <= n)) {
        while (n % pf == 0) {
            n /= pf;
            factors.push_back(pf);
        }
        pf = primes[++pf_idx];
    }
    if (n != 1) {
        factors.push_back(n);
    }
    return factors;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int64_t n;
    cin >> n;
    sieve(10001);
    for (;n > 0; n--) {
        int64_t x;
        cin >> x;
        if (x == 1) {
            cout << x << "\n";
            continue;
        }
        vector<int64_t> factors = prime_factors(x);
        int64_t c = 1;
        for (int i = 0; i < factors.size(); i++) {
            int64_t e = 1;
            int j = i + 1;
            while (j < factors.size() && factors[i] == factors[j]) {
                e++;
                j++;
            }
            c *= (e + 1);
            i = j - 1;
        }
        cout << c << "\n";
    }
}
