#include <bits/stdc++.h>

using namespace std;

const int64_t EPS = 1e-9;
#define PI acos(-1.0)
#define EQUALS(a, b) fabs(a - b) < EPS

struct Point {
    int64_t x, y;
    Point() {x = y = 0.0;}
    Point(int64_t _x, int64_t _y) : x(_x), y(_y) {}
    bool operator < (Point other) const {
        if (fabs(x - other.x) > EPS) 
            return x < other.x;
        else if (fabs(y - other.y))
            return y < other.y;
        return false;
    }
    bool operator == (Point other) const {
        return fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS);
    }
};

struct Line {
    int64_t a, b, c;
};

int64_t dist(Point p1, Point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

int64_t deg_to_rad(int64_t d) {
    return d * PI / 180.0;
}

Point rotate(Point p, int64_t angle) {
    int64_t rad = deg_to_rad(angle);
    return Point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad));
}

void points_to_line(Point p1, Point p2, Line &l) {
    if (fabs(p1.x - p2.x) < EPS) {
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
    } else {
        l.a = -(int64_t)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(int64_t)(l.a * p1.x) - p1.y;
    }
}

bool are_parallel(Line l1, Line l2) {
    return fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS;
}

bool are_same(Line l1, Line l2) {
    return are_parallel(l1, l2) && fabs(l1.c - l2.c) < EPS;
}

bool are_intersect(Line l1, Line l2, Point &p) {
    if (are_parallel(l1, l2)) return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS)
        p.y = -(l1.a * p.x + l1.c);
    else
        p.y = -(l2.a * p.x + l2.c);
    return true;
}

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

int64_t dist_to_line(Point p, Point a, Point b, Point &c) {
    Vec ap(a, p);
    Vec ab(a, b);
    int64_t u = (ab * ap) / ab.norm_sq();
    c = ab.scaled(u).translate(a);
    return dist(p, c);
}

int64_t dist_to_line_segment(Point p, Point a, Point b, Point &c) {
    Vec ap(a, p), ab(a, b);
    int64_t u = ap * ab / ab.norm_sq();
    if (u < 0.0) {
        c = Point(a.x, a.y);
        return dist(p, a);
    } else if (u > 1.0) {
        c = Point(b.x, b.y);
        return dist(p, b);
    }
    return dist_to_line(p, a, b, c);
}

int64_t angle(Point a, Point o, Point b) {
    Vec oa(o, a), ob(o, b);
    return acos((oa * ob) / sqrt(oa.norm_sq() * ob.norm_sq()));
}

int64_t cross_scalar(Vec a, Vec b) {
    return a.x * b.y - a.y * b.x;
}

bool ccw(Point p, Point q, Point r) {
    return cross_scalar(Vec(p, q), Vec(p, r)) > 0;
}

bool collinear(Point p, Point q, Point r) {
    return fabs(cross_scalar(Vec(p, q), Vec(p, r))) < EPS;
}

int main() {
    int t;
    for(cin >> t; t > 0; t--) {
        int64_t x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Point p1(x1, y1), p2(x2, y2), p3(x3, y3);
        Vec v(p1, p2), u(p1, p3);
        int64_t a = v.x * u.y - v.y * u.x;
        if (a < 0) {
            cout << "RIGHT\n";
        } else if (a > 0) {
            cout << "LEFT\n";
        } else {
            cout << "TOUCH\n";
        }
    }
}
