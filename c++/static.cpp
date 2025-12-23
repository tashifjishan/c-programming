#include <iostream>
using namespace std;

class Student {
    int roll;                 // non-static (object specific)
             // static data member

public:
static int count;
    Student() {
        count++;              // shared across all objects
    }

    void setRoll(int r) {
        roll = r;
    }

    void show() const {
        cout << "Roll: " << roll << endl;
    }

    // static member function
    static void showCount() {
        cout << "Total students: " << count << endl;
        // roll = 5; ❌ NOT allowed (non-static member)
    }
};

// definition of static data member
int Student::count = 0;

int main() {
    Student s1, s2, s3;

    s1.setRoll(1);
    s2.setRoll(2);
    s3.setRoll(3);

    s1.show();
    s2.show();
    s3.show();

    Student::showCount();   // called without object
    cout<<Student::count<<endl;
    return 0;
}
