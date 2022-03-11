#include <string>
#include <vector>
#include <iostream>
#include <map>
void strings();
void vectors();
void userDefined();
using namespace std;

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
    class foo
    {
        int a_;
        double b_;
    public:
        foo()
            : a_(0), b_(0)
        {}
        foo(int a, double b = 0.0)
            : a_(a), b_(b)
        {}
    };

    foo f1{};
    foo f2{42, 1.2};
    foo f3{42};

    struct bar
    {
        int a_;
        double b_;
    };
    bar b{42, 1.2};

}

auto vectors() -> void
{
    vector<int> v1{5};
    vector<int> v2(5);
    vector<int> v3({5});

    auto v4 = vector<int>{5};
    auto v5 = vector<int>(5);
    auto v6 = vector<int>({5});

    std::vector<int> v{1, 2, 3};
    std::map<int, std::string> m{{1, "one"}, {2, "two"}};

    int *arr2 = new int[3]{1, 2, 3};

    int arr1[3]{1, 2, 3};

    int i{42};
    double d{1.2};

}
auto strings() -> void
{
    string s1("t");   // direct initialization
    string s2 = "t";  //  copy initialization

    auto s3 = string("t");
    auto s4 = string{"t"};
    auto s5 = "t";
}



