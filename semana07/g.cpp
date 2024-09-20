#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t n;
    cin >> n;
    int64_t _b, _t1, _a1, _t2, _a2;
    double b, t1, a1, t2, a2;
    for (; n > 0; n--) {
        cin >> _b >> _t1 >> _a1 >> _t2 >> _a2;
        b = _b, t1 = _t1, a1 = _a1, t2 = _t2, a2 = _a2;
        double t = t2 - t1;
        double h1 = t * b;
        if (h1 <= a1) {
            cout << setprecision(10) << a1 / b << a2 / b << endl;
        } else if (a1 - h1 <= a2) {
            double r1 = t + 2 * (a1 - h1) / b;
            double h2 = b * (r1 - t) / 2;
            double r2 = (r1 - t) + (a2 - h2);
            cout << setprecision(10) << r1 << r2 << endl;
        } else {
            double r2 = 2 * a2 / b;
            double h2 = (r2 - t) * b / 2;
            double r1 = (r2 - t) + (a1 - h1 - h2) / b;
            cout << setprecision(10) << r1 << r2 << endl;
        }
    }
}
