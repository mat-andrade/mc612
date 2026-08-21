#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;
#define PI acos(-1.0)
#define EQUALS(a, b) (fabs((a) - (b)) < EPS)

struct Point {
    double x, y;
    Point() {x = y = 0.0;}
    Point(double _x, double _y) : x(_x), y(_y) {}
    bool operator < (Point other) const {
        if (!EQUALS(x, other.x)) 
            return x < other.x;
        return y < other.y;
    }
    bool operator == (Point other) const {
        return EQUALS(x, other.x) && EQUALS(y, other.y);
    }
};


struct Line {
    double a, b, c;
};

void points_to_line(Point p1, Point p2, Line &l) {
    if (EQUALS(p1.x, p2.x)) {
        l.a = 1;
        l.b = 0;
        l.c = -p1.x;
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}


struct Vec {
    double x, y;
    Vec(double _x, double _y) : x(_x), y(_y) {}
    Vec(Point a, Point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }

    double operator * (Vec other) const {
        return x * other.x + y * other.y;
    }

    double norm_sq() {
        return x * x + y * y;
    }

    Vec scaled(double s) {
        return Vec(x * s, y * s);

    }

    Point translate(Point p) {
        return Point(p.x + x, p.y + y);
    }
};

struct LineSeg {
    Point a, b;
    LineSeg(Point _a, Point _b) : a(_a), b(_b) {}

    Line to_line() {
        Line l;
        points_to_line(a, b, l);
        return l;
    }

    Vec to_vec() {
        return Vec(a, b);
    }
};


bool are_parallel(Line l1, Line l2) {
    return EQUALS(l1.a, l2.a) && EQUALS(l1.b, l2.b);
}

bool are_same(Line l1, Line l2) {
    return are_parallel(l1, l2) && EQUALS(l1.c, l2.c);
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


double cross_scalar(Vec a, Vec b) {
    return a.x * b.y - a.y * b.x;
}

double dist(Point p1, Point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double dist_to_line(Point p, Point a, Point b, Point &c) {
    Vec ap(a, p);
    Vec ab(a, b);
    double u = (ab * ap) / ab.norm_sq();
    c = ab.scaled(u).translate(a);
    return dist(p, c);
}

double dist_to_line_segment(Point p, Point a, Point b, Point &c) {
    Vec ap(a, p), ab(a, b);
    double u = ap * ab / ab.norm_sq();
    if (u < 0.0) {
        c = Point(a.x, a.y);
        return dist(p, a);
    } else if (u > 1.0) {
        c = Point(b.x, b.y);
        return dist(p, b);
    }
    return dist_to_line(p, a, b, c);
}

bool lineseg_intersect(LineSeg a, LineSeg b, Point &p) {
    if (!are_intersect(a.to_line(), b.to_line(), p)) {
        return false;
    }
    Point d;
    if (fabs(dist_to_line_segment(p, a.a, a.b, d)) > EPS
        || fabs(dist_to_line_segment(p, b.a, b.b, d)) > EPS) {
        return false;
    }
    return true;
}

int main() {
    for (;;) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }

        vector<LineSeg> linesegs;
        linesegs.reserve(n);
        int count = 0;
        for (; n > 0; n--) {
            double a, b, c, d;
            cin >> a >> b >> c >> d;
            LineSeg ls(Point(a, b), Point(c, d));
            linesegs.push_back(ls);
        }
        for (int i = 0; i < linesegs.size(); i++) {
            LineSeg a = linesegs[i];
            Vec u = a.to_vec();
            for (int j = i + 1; j < linesegs.size(); j++) {
                LineSeg b = linesegs[j];
                Vec v = b.to_vec();
                if (cross_scalar(u, v) == 0) {
                    continue;
                }
                Point p1;
                if (!lineseg_intersect(a, b, p1)) {
                    continue;
                }
                for (int k = j + 1; k < linesegs.size(); k++) {
                    LineSeg c = linesegs[k];
                    Vec w = c.to_vec();
                    if (cross_scalar(w, u) == 0 || cross_scalar(w, v) == 0) {
                        continue;
                    }
                    Point p2;
                    if (!lineseg_intersect(a, c, p2)) {
                        continue;
                    }
                    Point p3;
                    if (!lineseg_intersect(b, c, p3)) {
                        continue;
                    }
                    count++;
                }
            }
        }
        cout << count << '\n';
    }
}
