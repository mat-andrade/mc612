
#include <bits/stdc++.h>

using namespace std;

#define WALK(_f, _ptr) _ptr = (f)(_ptr)

/**
 * Algorithm from class slides.
 */
tuple<int64_t, int64_t> floydCycleFinding (int64_t x0, int64_t (*f)(int64_t)) {
    int64_t tortoise = f(x0), hare = f(f(x0));
    while (tortoise != hare) {
        WALK(f, tortoise);
        WALK(f, hare);
        WALK(f, hare);
    }
    int64_t mu = 0;
    hare = x0;
    while (tortoise != hare) {
        WALK(f, tortoise);
        WALK(f, hare);
        mu++;
    }
    int64_t lambda = 1;
    hare = f(tortoise);
    while (tortoise != hare) {
        WALK(f, hare);
        lambda++;
    }
    return make_tuple(mu, lambda);
}

int64_t N;

#define POP2 do {\
    a = stack.back();\
    stack.pop_back();\
    b = stack.back();\
    stack.pop_back();\
} while(0)

enum tipo {
    PLUS, TIMES, MOD, X, NUMBER
};

struct a {
    enum tipo t;
    int64_t x;
};

vector<struct a> fun;

int64_t exec(int64_t x) {
    vector<int64_t> stack;
    for (auto s : fun) {
        if (s.t == PLUS) {
            int64_t a, b;
            POP2;
            stack.push_back((a + b) % N);
        } else if (s.t == TIMES) {
            int64_t a, b;
            POP2;
            stack.push_back((a * b) % N);
        } else if (s.t == MOD) {
            int64_t a, b;
            POP2;
            stack.push_back(b % a);
        } else if (s.t == X) {
            stack.push_back(x);
        }
        else {
            stack.push_back(s.x);
        }
    }
    return stack.back();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int64_t x;
    for(cin >> N >> x; N != 0;cin >> N >> x) {
        string s;
        do {
            cin >> s;
            if (s == "+") {
                fun.push_back({PLUS});
            } else if (s == "*") {
                fun.push_back({TIMES});
            } else if (s == "%") {
                fun.push_back({MOD});
            } else if (s == "x") {
                fun.push_back({X});
            } else if (s == "N") {
                fun.push_back({NUMBER, N});
            } else {
                fun.push_back({NUMBER, stoll(s)});
            }
        } while(s != "%");
        auto [mu, lambda] = floydCycleFinding(x, exec);
        cout << lambda << '\n';
    }
}
