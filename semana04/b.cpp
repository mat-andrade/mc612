#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double m, n;
    double resp = 0;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        double prob = pow((i / m), n) - pow(((i-1)/m), n);
        resp += (prob * i);
    }
    cout << resp << endl;
    return 0;
}

