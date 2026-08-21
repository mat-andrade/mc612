#include <bits/stdc++.h>

using namespace std;

struct Point {
    int64_t x, y;
    Point() {x = y = 0.0;}
    Point(int64_t _x, int64_t _y) : x(_x), y(_y) {}
    bool operator < (Point other) const {
        if (x != other.x) 
            return x < other.x;
        
        return y < other.y;
    }
    bool operator == (Point other) const {
        return x == other.x && y == other.y;
    }
};

struct Triangle {
    int64_t x1, y1, x2, y2, x3, y3;
    Triangle operator&(Triangle other) {
        
    }
};

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        Triangle tri1, tri2;
        cin >> tri1.x1 >> tri1.y1 >> tri1.x2 >> tri1.y2 >> tri1.x3 >> tri1.y3;
        cin >> tri2.x1 >> tri2.y1 >> tri2.x2 >> tri2.y2 >> tri2.x3 >> tri2.y3;
    }
}