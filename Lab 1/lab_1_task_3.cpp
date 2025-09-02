#include <iostream>
using namespace std;

class Container {
private:
    int* ptr;

public:
    Container(int val = 0) {
        ptr = new int(val);
    }

    ~Container() {
        delete ptr;
    }

    Container(const Container& source) {
        ptr = new int(*source.ptr);
    }

    Container& operator=(const Container& source) {
        if (this != &source) {
            delete ptr;
            ptr = new int(*source.ptr);
        }
        return *this;
    }

    void assign(int val) {
        *ptr = val;
    }

    int fetch() const {
        return *ptr;
    }

    void show() const {
        cout << "Stored Value: " << *ptr 
             << " | Memory Address: " << ptr << endl;
    }
};

int main() {
    cout << "==== Deep Copy Demonstration ====" << endl;

    Container c1(10);
    cout << "c1: "; c1.show();

    Container c2 = c1;
    cout << "c2 (copied from c1): "; c2.show();

    c2.assign(20);
    cout << "\nAfter updating c2:" << endl;
    cout << "c1: "; c1.show();
    cout << "c2: "; c2.show();

    Container c3;
    c3 = c1;
    cout << "\nc3 (assigned from c1): "; c3.show();

    c3.assign(30);
    cout << "\nAfter updating c3:" << endl;
    cout << "c1: "; c1.show();
    cout << "c3: "; c3.show();

    return 0;
}
