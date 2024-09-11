#include <iostream>
#include <stdio.h>

#define MOD 1000000007LL

using namespace std;

struct matriz {
    long long mat[2][2];
};

matriz matMul(matriz a, matriz b) {
    matriz ret;
    ret.mat[0][0] = (((a.mat[0][0] % MOD * b.mat[0][0] % MOD) % MOD) + (a.mat[0][1] % MOD * b.mat[1][0] % MOD) % MOD) % MOD;
    ret.mat[0][1] = (((a.mat[0][0] % MOD * b.mat[0][1] % MOD) % MOD) + (a.mat[0][1] % MOD * b.mat[1][1] % MOD) % MOD) % MOD;
    ret.mat[1][0] = (((a.mat[1][0] % MOD * b.mat[0][0] % MOD) % MOD) + (a.mat[1][1] % MOD * b.mat[1][0] % MOD) % MOD) % MOD;
    ret.mat[1][1] = (((a.mat[1][0] % MOD * b.mat[0][1] % MOD) % MOD) + (a.mat[1][1] % MOD * b.mat[1][1] % MOD) % MOD) % MOD;
    return ret;
}

matriz matPow(matriz base, long long n) {
    matriz ans;
    ans.mat[0][0] = 1; ans.mat[0][1] = 0;
    ans.mat[1][0] = 0; ans.mat[1][1] = 1;
    for (;n > 0; n /= 2) {
        if (n % 2 == 1) {
            ans = matMul(ans, base);
        }
        base = matMul(base, base);
    }
    return ans;
}

int main() {
    long long n;
    cin >> n;
    matriz i;
    i.mat[0][0] = 1; i.mat[0][1] = 1;
    i.mat[1][0] = 1; i.mat[1][1] = 0;
    matriz x = matPow(i, n);
    cout << x.mat[0][1] << '\n';
}

