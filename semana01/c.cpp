#include <iostream>
#include <stdio.h>
using namespace std;

/**
 * Algorítmo de Euclides
 */
int gcd(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int main () {
    int v[100000];
    int n;
    cin >> n;
    cin >> v[0];
    cin >> v[1];
    int dist = v[1] - v[0];
    for (int i = 2; i < n; i++) {
        cin >> v[i];
        dist = gcd(dist, v[i] - v[i - 1]);
    }
    int a = 0;
    for (int i = 1; i < n; i++) {
        a += (v[i] - v[i - 1]) / dist - 1;
    }
    cout << a << '\n';
}
