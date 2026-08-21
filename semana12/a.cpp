#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;
#define PI acos(-1.0)
#define EQUALS(a, b) fabs(a - b) < EPS

struct Point {
    double x, y;
    Point() {x = y = 0.0;}
    Point(double _x, double _y) : x(_x), y(_y) {}
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
    double a, b, c;
};

double dist(Point p1, Point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double deg_to_rad(double d) {
    return d * PI / 180.0;
}

Point rotate(Point p, double angle) {
    double rad = deg_to_rad(angle);
    return Point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad));
}

void points_to_line(Point p1, Point p2, Line &l) {
    if (fabs(p1.x - p2.x) < EPS) {
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
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

double angle(Point a, Point o, Point b) {
    Vec oa(o, a), ob(o, b);
    return acos((oa * ob) / sqrt(oa.norm_sq() * ob.norm_sq()));
}

double cross_scalar(Vec a, Vec b) {
    return a.x * b.y - a.y * b.x;
}

bool ccw(Point p, Point q, Point r) {
    return cross_scalar(Vec(p, q), Vec(p, r)) > 0;
}

bool collinear(Point p, Point q, Point r) {
    return fabs(cross_scalar(Vec(p, q), Vec(p, r))) < EPS;
}

int main() {
    int n;
    cout << "INTERSECTING LINES OUTPUT\n";
    for (cin >> n; n > 0; n--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        Line l1, l2;
        points_to_line(Point(a, b), Point(c, d), l1);
        cin >> a >> b >> c >> d;
        points_to_line(Point(a, b), Point(c, d), l2);
        Point p;
        if (are_same(l1, l2)) {
            cout << "LINE\n";
        } else if (are_intersect(l1, l2, p)) {
            printf("POINT %.2lf %.2lf\n", p.x, p.y);
        } else {
            cout << "NONE\n";
        }
    }
    cout << "END OF OUTPUT\n";
}
