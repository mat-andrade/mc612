#include <bits/stdc++.h>

using namespace std;

const int64_t EPS = 0;
#define PI acos(-1.0)
#define EQUALS(a, b) abs(a - b) < EPS

struct Point {
    int64_t x, y;
    Point() {x = y = 0.0;}
    Point(int64_t _x, int64_t _y) : x(_x), y(_y) {}
    bool operator < (Point other) const {
        if (x != other.x) 
            return x < other.x;
        else return y < other.y;
    }
    bool operator == (Point other) const {
        return abs(x - other.x) < EPS && (abs(y - other.y) < EPS);
    }
};

struct Vec {
    int64_t x, y;
    Vec(int64_t _x, int64_t _y) : x(_x), y(_y) {}
    Vec(Point a, Point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }

    int64_t operator * (Vec other) const {
        return x * other.x + y * other.y;
    }

    int64_t norm_sq() {
        return x * x + y * y;
    }

    Vec scaled(int64_t s) {
        return Vec(x * s, y * s);

    }

    Point translate(Point p) {
        return Point(p.x + x, p.y + y);
    }
};


vector<Point> points;

struct comp_by_y {
    bool operator() (int i, int j) {
        Point a = points[i];
        Point b = points[j];
        if (a.y != b.y) {
            return a.y < b.y;
        }
        return a.x < b.x;
    }
};

int64_t dist_sq(Point p1, Point p2) {
    return Vec(p1, p2).norm_sq();
}

int64_t closest(int l, int r) {
    if (l >= r) {
        return INT64_MAX;
    }
    if (r - l == 1) {
        Point p1 = points[l], p2 = points[r];
        return Vec(p1, p2).norm_sq(); 
    } else if (r - l == 2) {
        Point p1 = points[l], p2 = points[l + 1], p3 = points[r];
        return min(min(Vec(p1, p2).norm_sq(), Vec(p1, p3).norm_sq()), Vec(p2, p3).norm_sq());
    } else {
        int p = (l + r) / 2;
        int64_t d1 = closest(l, p);
        int64_t d2 = closest(p + 1, r);
        int64_t d = min(d1, d2);
        vector<int> strip;
        strip.push_back(p);
        bool has_right = true, has_left = true;
        for (int i = 1; has_right || has_left; i++) {
            if (has_right && p + i <= r && abs(points[p + i].x - points[p].x) * abs(points[p + i].x - points[p].x) < d) {
                strip.push_back(p + i);
            } else {
                has_right = false;
            }
            if (has_left && p - i >= l && abs(points[p - i].x - points[p].x) * abs(points[p - i].x - points[p].x) < d) {
                strip.push_back(p - i);
            } else {
                has_left = false;
            }
        }
        if (strip.size() == 1) {
            return d;
        }
        sort(strip.begin(), strip.end(), comp_by_y());
        for (int i = 0; i < strip.size(); i++) {
            Point p1 = points[strip[i]];
            bool left = strip[i] <= p;
            for (int j = 1; j <= 8 && i + j < strip.size(); j++) {
                if (left && strip[i + j] <= p) {
                    continue;
                } else if (!left && strip[i + j] > p) {
                    continue;
                }
                Point p2 = points[strip[i + j]];
                int64_t dis = dist_sq(p1, p2);
                if (dis < d) {
                    d = dis;
                }
            }
        }
        return d;
    }
}

int main() {
    int n;
    cin >> n;
    points.reserve(n);
    for (int i = 0; i < n; i++) {
        int64_t x, y;
        cin >> x >> y;
        points.push_back(Point(x, y));
    }
    sort(points.begin(), points.end());
    cout << closest(0, n - 1) << endl;
}
