#include <cstdint>
#include <bitset>
#include <vector>
#include <iostream>


using namespace std;

int32_t sieve_size;
bitset<100000010> isprime;
vector<int32_t> primes;


/**
 * funções sieve, is_prime e prime_factors tomadas do slide
 */
void sieve(int32_t upperbound) {
    sieve_size = upperbound + 1;
    isprime.set();
    isprime[0] = isprime[1] = 0;
    for (int32_t i = 2; i <= sieve_size; i++) {
        for (int32_t j = i * i; j <= sieve_size; j += i) {
            isprime[j] = 0;
        }
        primes.push_back(i);
    }
}

bool is_prime(int32_t n) {
    if (n <= sieve_size) {
        return isprime[n];
    }
    for (int32_t i = 0; i < primes.size(); i++) {
        if (n % primes[i] == 0) {
            return false;
        }
    }
    return true;
}

vector<int32_t> prime_factors(int32_t n) {
    vector<int32_t> factors;
    int32_t pf_idx = 0, pf = primes[pf_idx];
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
    sieve(31622777);
    int32_t n;
    for (cin >> n; n != 0; cin >> n) {
        vector<int32_t> factors =  prime_factors(n);
        int32_t last_factor = factors[0];
        int32_t e = 1;
        for (size_t i = 1; i < factors.size(); i++) {
            int32_t new_factor = factors[i];
            if (new_factor == last_factor) {
                e++;
            } else {
                cout << last_factor << "^" << e << " ";
                last_factor = new_factor;
                e = 1;
            }
        }
        cout << last_factor << "^" << e << endl;
    }
}
