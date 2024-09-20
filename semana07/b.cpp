#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

#define WALK(_f, _ptr) do{_ptr = (f)(_ptr); if((_ptr) == 1) return true;}while(0)


/**
 * Algorithm from class slides.
 */
bool floydCycleFinding (int32_t x0, int32_t (*f)(int32_t)) {
    if (x0 == 1) {
        return true;
    }
    int32_t tortoise = f(x0), hare = f(f(x0));
    if (tortoise == 1 || hare == 1) {
        return true;
    }
    while (tortoise != hare) {
        WALK(f, tortoise);
        WALK(f, hare);
        WALK(f, hare);
    }
    int32_t mu = 0;
    hare = x0;
    while (tortoise != hare) {
        WALK(f, tortoise);
        WALK(f, hare);
        mu++;
    }
    int32_t lambda = 1;
    hare = f(tortoise);
    if (hare == 1) {
        return true;
    }
    while (tortoise != hare) {
        WALK(f, hare);
        lambda++;
    }
    return false;
}

int32_t ssd(int32_t n) {
    int32_t sum = 0;
    while (n > 0) {
        int32_t d = n % 10;
        n /= 10;
        sum += d * d;
    }
    return sum;
}

int main() {
    int32_t t;
    cin >> t;
    int32_t n;
    for (int j = 1; j <= t; j++) {
        cin >> n;
        string happy;
        if(floydCycleFinding(n, ssd)) {
            happy = " Happy";
        } else {
            happy = "n Unhappy";
        }
        cout << "Case #" << j << ": " << n << " is a" << happy << " number." << endl;
    }
}
