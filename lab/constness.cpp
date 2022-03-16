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
    MyClass(const MyClass& other) {
        cout << "Copy constructor" << endl;
    }
    MyClass(MyClass && other) noexcept {
        cout << "Move constructor" << endl;
    }
    MyClass& operator=(const MyClass& other) {
        cout << "Copy assignment" << endl;
        return *this;
    }
    MyClass& operator=(MyClass&& other) noexcept {
        cout << "Move assignment" << endl;
        return *this;
    }
    ~MyClass(){
        cout << "Destructor" << endl;
    }
};

int main() {
    MyClass mc1;
    auto mc2 = MyClass{};
    return 0;
}