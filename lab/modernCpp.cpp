#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <array>
#include <string>

#include <range/v3/all.hpp> // get everything

void strings();
void vectors();
void userDefined();
using namespace std;

//using namespace

std::vector<std::string> createAndInsertOldWay()
{
    vector<std::string> coll; // create vector of strings
    coll.reserve(3); // reserve memory for 3 elements

    string s = "data"; // create string object

    coll.push_back(s); // insert string object
    coll.push_back(s + s); // insert temporary string
    coll.push_back(s); // insert string

    return coll; // return vector of strings
}

std::vector<std::string> createAndInsert()
{
    vector<string> coll; // create vector of strings
    coll.reserve(3); // reserve memory for 3 elements
    string s = "data"; // create string object
    coll.push_back(s); // insert string object
    coll.push_back(s + s); // insert temporary string
    coll.push_back(move(s)); // insert string (we no longer need the value of s)
    return coll; // return vector of strings
}

auto f()
{
    auto v = createAndInsertOldWay();
    auto u = createAndInsert();
}

auto func(int const a, int const b, int const c)
{
    std::cout << a << b << c;
}
auto func(std::initializer_list<int> const l)
{
    for (auto const &e: l)
        std::cout << e;
}

auto main(int argc, char *argv[]) -> int
{
    f();
    func(1, 2, 3);
    func({1, 2, 3});

    vectors();
    strings();
    userDefined();

}

auto userDefined() -> void
{
    class Foo
    {
        int a_;
        double b_;
    public:
        Foo()
            : a_(0), b_(0)
        {}
        explicit Foo(int a, double b = 0.0)
            : a_(a), b_(b)
        {}
    };

    Foo f1{};
    Foo f2{42, 1.2};
    Foo f3{42};

    auto f4 = Foo{};
    auto f5 = Foo{42, 1.2};
    auto f6 = Foo(1, 1.1);

    struct Bar
    {
        int a_;
        double b_;
    };
    Bar b1{42, 1.2};
    auto b2 = Bar{2, 2.2};

    auto i = 1;
    auto j = 1.1;
    auto k = int{1};
    auto l = float{1.1};

    auto a = {42}; // std::initializer_list<int>
    auto b
        {42}; // 42.  C++17 has changed the rules for list initialization, differentiating between the direct- and copy-list-initialization. The new rules for type deduction are as follows:
    auto c = {4, 2}; // std::initializer_list<int>
    //auto d {4, 1}; // ERRO: 'auto' can only be deduced from a single initializer expression

    double d1 = 47.0 / 13;
    double d2{d1};
    // float f1{d1}; // ERRO: cannot narrow from double to float
    auto fl1 = float{10.1};
    float fl2 = 10.2; // warning C4305: 'initializing': truncation from 'double' to 'float'
    float fl3 = 10.2f; // No warning here
    double d3{fl1}; // OK, converting from float to double

    // int i1{1.2}; // error C2397: conversion from 'double' to 'int' requires a narrowing conversion
    int i1{static_cast<int>(1.2)};
    auto i2 = static_cast<int>(1.2);

    auto i3 = {42};
    auto i4{42};
    auto i5 = {4, 2};
    // auto i6{4, 2}; // ERRO! 'auto' can only be deduced from a single initializer expression
    int array[] = {1, 2, 3};

    auto lam = [](int x) -> bool
    {
        return true;
    };

    auto list = initializer_list<long>{2, 3, 5, 7, 9, 13, 17, 19};
    for (int i_: {2, 3, 5, 7, 9, 13, 17, 19}) {
        cout << i_ << endl;
    }

    auto vec = vector<double>{};
    for (auto &elem: vec) {
        elem *= 3;
    }
}

template<typename T>
auto printElements(const T &coll) -> void
{
    for (const auto &elem: coll) {
        cout << elem << endl;
    }
}

auto vectors() -> void
{
    vector<int> v1{5};
    vector<int> v2(5);
    vector<int> v3({5});

//    printElements(v3);

    auto v4 = vector<int>{5};
    auto v5 = vector<int>(5);
    auto v6 = vector<int>({5});

    vector<int> v{1, 2, 3};
    map<int, string> m1{{1, "one"}, {2, "two"}};
    auto m2 = map<int, string>{{1, "one"}, {2, "two"}};

    int *arr2 = new int[3]{1, 2, 3};
//    auto arr3 =

    int arr1[3]{1, 2, 3};
    auto arr3 = array<int, 3>{1, 2, 3};
    auto arr4 = {1, 2, 3};
//    int arr5[] = arr4;

    int i{42};
    double d{1.2};

}
auto strings() -> void
{
    string s1("t");   // direct initialization
    string s2 = "t";  //  copy initialization

    auto s3 = string("t");
    auto s4 = string{"t"};

    // *** CLion debugger cannot understand u8 (char8_t*) strings.
    auto s5 = "my string";
    auto s6 = L"my string L";
    auto s7 = u8"my string u8";
    auto s8 = u"my string u";
    auto s9 = U"my string U";

    auto s10 = R"(\n my string R)";
    auto s11 = LR"(\n my string LR)";
    auto s12 = u8R"(my \n \t string u8R)";

    cout << endl;
    cout << s5 << endl; // char*
    wcout << s6 << endl; // wchar_t*
    cout << reinterpret_cast<const char *>(s7) << endl; // char8_t*
    wcout << reinterpret_cast<const wchar_t *>(s8) << endl; // char16_t*
//    cout << s9 << endl; // char32_t*

    cout << s10 << endl; // char16_t*
    cout << reinterpret_cast<const char *>(s12) << endl; // char16_t*

    char32_t c1;
    c1 = U'ç';
    auto c2 = u'è';
    auto c3 = U'ç';
    auto c4 = u8"8"s;
    auto c5 = u"bla"s;
//    auto c6 = basic_string<char16_t>("bla");

}



