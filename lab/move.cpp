#include <string>
#include <vector>
#include <iostream>
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

    vector<int> v1{5};
    vector<int> v2(5);
    vector<int> v3({5});

    auto v4 = vector<int>{5};
    auto v5 = vector<int>(5);
    auto v6 = vector<int>({5});

}



