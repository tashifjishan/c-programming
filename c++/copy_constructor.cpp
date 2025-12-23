#include <iostream>
using namespace std;

class Demo {
    int x;

public:
    // Parameterized constructor
    Demo(int val) {
        x = val;
        cout << "Parameterized constructor called" << endl;
    }

    // Copy constructor
    Demo(const Demo& obj) {
        x = obj.x;
        cout << "Copy constructor called" << endl;
    }

    void show() const {
        cout << "x = " << x << endl;
    }
};

int main() {
    Demo d1(10);     // parameterized constructor
    Demo d2 = d1;    // copy constructor

    d1.show();
    d2.show();

    return 0;
}
