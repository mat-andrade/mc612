#include <stdio.h>
#include <iostream>

using namespace std;

#define MOD 1000000007LL
#define MAX_N 50

typedef struct matriz {
    long long mat[MAX_N][MAX_N];
    long long n;
} matriz;

void printMat(matriz *m) {
    for (int i = 0; i < m->n; i++) {
        cout << m->mat[i][0];
        for (int j = 1; j < m->n; j++) {
            cout << ' ' << m->mat[i][j];
        }
        cout << endl;
    }
}

void matMul(matriz *a, matriz *b, matriz *ret) {
    int k;
    for (int i = 0; i < a->n; i++) {
        for (int j = 0; j < a->n; j++) {
            for (ret->mat[i][j] = k = 0; k < a->n; k++) {
                ret->mat[i][j] += ((a->mat[i][k] % MOD) * (b->mat[k][j] % MOD));
                ret->mat[i][j] %= MOD;
            }
        }
    }
}

void copyMat(matriz *dst, matriz *src) {
    for (int i = 0; i < dst->n; i++) {
        for (int j = 0; j < dst->n; j++) {
            dst->mat[i][j] = src->mat[i][j];
        }
    }
}

void matPow(matriz *base, long long n, matriz *ret) {
    matriz ans;
    ans.n = base->n;
    for (int i = 0; i < base->n; i++) {
        for (int j = 0; j < base->n; j++) {
            ans.mat[i][j] = i == j;
        }
    }
    for(;n > 0;n /= 2) {
        if (n % 2 == 1) {
            matMul(&ans, base, ret);
            copyMat(&ans, ret);
        }
        matMul(base, base, ret);
        copyMat(base, ret);
    }
    copyMat(ret, &ans);
    return;
}

int main(void) {
    int t;
    scanf("%d", &t);
    matriz base, ret;
    for (int _ = 0; _ < t; _++) {
        long long m, n;
        scanf("%d %d", &m, &n);
        base.n = m;
        ret.n = m;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cin >> base.mat[i][j];
            }
        }
        matPow(&base, n, &ret);
        printMat(&ret);
    }
}
