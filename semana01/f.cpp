#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    int acc = 1;
    for (int i = 0; i < n; i++) {
        if (acc < k) {
            acc *= 2;
        } else {
            acc += k;
        }
    }
    cout << acc << '\n';
}
