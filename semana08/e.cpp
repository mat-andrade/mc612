#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    string txt;
    cin >> txt;
    int n = txt.size();
    int lcp[n];
    int sa[n];
    for (int i = 0; i < n; i++) {
        sa[i] = i;
    }
    sort(sa, sa + n, [&](int a, int b) {
        return txt.substr(a) < txt.substr(b);
    });
    int ans = (n*n + n)/2;
    for (int i = 1; i < n; i++) {
        int j = 0;
        while (txt[sa[i] + j] == txt[sa[i - 1] + j]) {
            j++;
        }
        lcp[i] = j;
        ans -= j;
    }
    cout << ans << endl;
}
