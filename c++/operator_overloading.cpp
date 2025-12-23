#include <iostream>
using namespace std;

class Point {
    int x, y;

public:
    // Constructor
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Display
    void show() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    // + operator
    Point operator+(const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    // - operator
    Point operator-(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    // * operator (component-wise)
    Point operator*(const Point& p) const {
        return Point(x * p.x, y * p.y);
    }

    // / operator (component-wise)
    Point operator/(const Point& p) const {
        if (p.x == 0 || p.y == 0) {
            throw runtime_error("Division by zero coordinate");
        }
        return Point(x / p.x, y / p.y);
    }

    // % operator (component-wise)
    Point operator%(const Point& p) const {
        if (p.x == 0 || p.y == 0) {
            throw runtime_error("Modulo by zero coordinate");
        }
        return Point(x % p.x, y % p.y);
    }

    // Prefix ++
    Point& operator++() {
        ++x;
        ++y;
        return *this;
    }

    // Postfix ++
    Point operator++(int) {
        Point temp = *this;
        ++(*this);
        return temp;
    }

    // Prefix --
    Point& operator--() {
        --x;
        --y;
        return *this;
    }

    // Postfix --
    Point operator--(int) {
        Point temp = *this;
        --(*this);
        return temp;
    }
};


/*Usage */

int main() {
    Point p1(4, 6), p2(2, 3);

    (p1 + p2).show();   // (6, 9)
    (p1 - p2).show();   // (2, 3)
    (p1 * p2).show();   // (8, 18)
    (p1 / p2).show();   // (2, 2)
    (p1 % p2).show();   // (0, 0)

    ++p1;
    p1.show();          // (5, 7)

    p1++;
    p1.show();          // (6, 8)

    --p1;
    p1.show();          // (5, 7)

    p1--;
    p1.show();          // (4, 6)

    return 0;
}
