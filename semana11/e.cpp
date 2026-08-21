#include <bits/stdc++.h>

using namespace std;

int main() {
    int p;
    cin >> p;
    if (p <= 2) {
        cout << "0\n";
    } else if (p == 3) {
        cout << "1\n";
    } else {
        cout << p - 2 << '\n';
    }
}
