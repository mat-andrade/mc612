#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x, y;
    Point() {x = y = 0.0;}
    Point(double _x, double _y) : x(_x), y(_y) {}
    // bool operator < (Point other) const {
    //     if (!EQUALS(x, other.x)) 
    //         return x < other.x;
    //     return y < other.y;
    // }
    // bool operator == (Point other) const {
    //     return EQUALS(x, other.x) && EQUALS(y, other.y);
    // }
};

struct Rectangle {
    int64_t x1, x2, y1, y2;
    Rectangle() {
        x1 = x2 = y1 = y2 = 0;
    }

    Rectangle(Point a, Point b) {
        x1 = a.x;
        y1 = a.y;
        x2 = b.x;
        y2 = b.y;
    }

    Rectangle operator&(Rectangle other) {
        Rectangle ret;
        ret.x1 = max(x1, other.x1);
        ret.x2 = min(x2, other.x2);
        ret.y1 = max(y1, other.y1);
        ret.y2 = min(y2, other.y2);
        return ret;
    }
};

int main() {
    int n;
    cin >> n;

    Rectangle r0;
    cin >> r0.x1 >> r0.y1 >> r0.x2 >> r0.y2;
    for (int i = 1; i < n; i++) {
        Rectangle r1;
        cin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;

    }
}