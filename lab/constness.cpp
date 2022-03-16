//
// Created by guiga on 16/03/2022.
//

#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;

class MyClass {
public:
    MyClass() {
        cout << "Default constructor" << endl;
    }

    MyClass(const MyClass &other) {
        cout << "Copy constructor" << endl;
    }

    MyClass(MyClass &&other) noexcept {
        cout << "Move constructor" << endl;
    }

    MyClass &operator=(const MyClass &other) {
        cout << "Copy assignment" << endl;
        return *this;
    }

    MyClass &operator=(MyClass &&other) noexcept {
        cout << "Move assignment" << endl;
        return *this;
    }

    ~MyClass() {
        cout << "Destructor" << endl;
    }
};

MyClass foo() {
    MyClass ret;
    return ret;
}

const MyClass const_foo() {
    MyClass ret;
    return ret;
}

int main() {
    MyClass mc1;

    mc1 = foo();

    cout << "====" << endl;

//    mc1 = const_foo();

    return 0;
}