#include <bits/stdc++.h>

using namespace std;

#define MAX_N 500'005

int tempra[MAX_N], tempsa[MAX_N];
int ra[MAX_N], sa[MAX_N];

int c[MAX_N];

void countingSort(int k, int n) {
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++) {
        if (i + k < n) {
            c[ra[i + k]]++;
        } else {
            c[0]++;
        }
    }
    int sum = 0;
    for (int i = 0; i < MAX_N; i++) {
        int tmp = c[i];
        c[i] = sum;
        sum += tmp;
    }
    for (int i = 0; i < n; i++) {
        if (sa[i] + k < n) {
            tempsa[c[ra[sa[i] + k]]++] = sa[i];
        } else {
            tempsa[c[0]++] = sa[i];
        }
    }
    for (int i = 0; i < n; i++) {
        sa[i] = tempsa[i];
    }
}

void constructSA(char *str, int n) {
    for (int i = 0; i < n; i++) {
        ra[i] = str[i];
        sa[i] = i;
    }
    for (int k = 1; k < n; k <<= 1) {
        countingSort(k, n);
        countingSort(0, n);
        int r = tempra[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            tempra[sa[i]]
                = (ra[sa[i]] == ra[sa[i - 1]]
                && ra[sa[i] + k] == ra[sa[i - 1] + k])
                ? r
                : ++r;
        }
        for (int i = 0; i < n; i++) {
            ra[i] = tempra[i];
        }
    }
}

char buf[MAX_N];

int main() {
    cin >> buf;
    int l = strlen(buf);
    buf[l++] = '$';
    buf[l] = '\0';
    constructSA(buf, l);
    cout << sa[1];
    for (int i = 2; i < l; i++) {
        cout << ' ' << sa[i];
    }
    cout << endl;
}
