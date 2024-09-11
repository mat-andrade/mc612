#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i < n; i++) {
        int j;
        for (j = 0; j < n - i; j++) {
            if (s.at(j) == s.at(j + i)) {
                break;
            }
        }
        cout << j << '\n';
    }
}
