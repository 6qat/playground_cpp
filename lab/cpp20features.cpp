#include <concepts>
#include <compare>
#include <vector>
#include <map>
#include <iostream>
#include <chrono>
#include <array>
#include <ctime>

// https://en.cppreference.com/w/cpp/types/is_signed
// https://www.geeksforgeeks.org/features-of-c-20/

/**
 * Immediate Functions
 *
 */

consteval int sqr(int n)
{
    return n * n;
}

constexpr int r = sqr(100); // OK
int x = 100;

// ERROR: the value of 'x' is not usable in a constant expression
// OK if `sqr` were a `constexpr` function
//int r2 = sqr(x);

/**
 * Using ENUM
 */

enum class rgba_color_channel
{
    red, green, blue, alpha
};

// Bring an enum's members into scope to improve readability. Before:
std::string_view to_string(rgba_color_channel channel)
{
    switch (channel) {
        case rgba_color_channel::red:
            return "red";
        case rgba_color_channel::green:
            return "green";
        case rgba_color_channel::blue:
            return "blue";
        case rgba_color_channel::alpha:
            return "alpha";
    }
}
// AFTER

std::string_view to_string2(rgba_color_channel my_channel)
{
    switch (my_channel) {
        using enum rgba_color_channel;
        case red:
            return "red";
        case green:
            return "green";
        case blue:
            return "blue";
        case alpha:
            return "alpha";
    }
}

/**
 * Concepts
 *
 */

// `T` is not limited by any constraints.
template<typename T>
concept always_satisfied = true;

// Limit `T` to integrals.
template<typename T>
concept integral = std::is_integral_v<T>;

// Limit `T` to both the `integral` constraint and signedness.
template<typename T>
concept signed_integral = integral<T> && std::is_signed_v<T>();

// Limit `T` to both the `integral` constraint and the negation of the `signed_integral` constraint.
template<typename T>
concept unsigned_integral = integral<T> && !signed_integral<T>;

/**
 * 3 Way comparison
 * https://www.geeksforgeeks.org/3-way-comparison-operator-space-ship-operator-in-c-20/
 */

auto threeWayComparison()
{
    int a = 91, b = 110;
    auto ans1 = a <=> b;

    if (ans1 < 0) {
        std::cout << "a < b\n";
    }
    else if (ans1 == 0) {
        std::cout << "a == b\n";
    }
    else if (ans1 > 0) {
        std::cout << "a > b\n";
    }

    std::vector<int> v1{3, 6, 9};
    std::vector<int> v2{3, 6, 9};
    auto ans2 = v1 <=> v2;

    if (ans2 < 0) {
        std::cout << "v1 < v2\n";
    }
    else if (ans2 == 0) {
        std::cout << "v1 == v2\n";
    }
    else if (ans2 > 0) {
        std::cout << "v1 > v2\n";
    }
}

/**
* Map/Set contains(). Replaces find()
 *
*/

auto mapSetContains()
{
    std::map<int, char> M = {{1, 'a'},
                             {2, 'b'}};
    if (M.contains(2)) {
        std::cout << "Found\n";
    }
    else {
        std::cout << "Not found\n";
    }
}

/**
 * Range-based for loop with Initialization
 *
 * The range-based for loop changed in C++17 to allow the begin() and end() expressions
 * to be of different types and in C++20, an init-statement is introduced for initializing
 * the variables in the loop-scope. It allows us to initialize the container we wish to
 * loop through in the range-declaration itself.
 *
 * https://www.geeksforgeeks.org/range-based-loop-c/
 *
 */

auto rangeBasedForLoopWithInitialization()
{
    for (std::vector v{1, 2, 3}; auto &e : v) {
        std::cout << e;
    }
}

/**
 * New identifies(import, modules): NOT WORKING YET!!!
 *
 * https://en.cppreference.com/w/cpp/language/modules#Importing_modules_and_headers
 *
 * With modules, there is now no need to separate your source code into an interface and an implementation part.
 *
 * https://www.geeksforgeeks.org/dividing-a-large-file-into-separate-modules-in-c-c-java-and-python/
 *
*/

/**
 * Calendar and time zone library
 *
 * https://www.geeksforgeeks.org/chrono-in-c/
 *
 */

auto fibonacci(unsigned n) -> long
{
    if (n < 2) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

auto calendarTimeZoneLibrary()
{
    using namespace std::chrono;
    using namespace std;

    auto date1 = 2020y / September / 8;
    auto date2 = 21d / October / 2018;
    auto date3 = January / 27d / 2019;

    auto mil = milliseconds(1000);
    mil = mil * 60;

    std::cout << "duration (in periods): ";
    std::cout << mil.count() << " milliseconds.\n";
    std::cout << "duration (in seconds): ";
    std::cout << (mil.count() * milliseconds::period::num / milliseconds::period::den);
    std::cout << " seconds.\n";

    time_point<system_clock> start, end;
    start = system_clock::now();
    std::cout << "f(42) = " << fibonacci(42) << '\n';
    end = std::chrono::system_clock::now();

    duration<double> elapsed_seconds = end - start;
    time_t end_time = system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";

}

/**
* Array bounded/unbounded:
 *
*/

auto arrayBoundedUnbounded()
{

    class A
    {
    };

    std::cout << std::is_unbounded_array_v<A> << '\n';
    std::cout << std::is_unbounded_array_v<A[3]> << '\n';
    std::cout << std::is_unbounded_array_v<int[]> << '\n';
    std::cout << std::is_unbounded_array_v<int> << '\n';
    std::cout << std::is_bounded_array_v<A> << '\n';
    std::cout << std::is_bounded_array_v<A[3]> << '\n';
    std::cout << std::is_bounded_array_v<float> << '\n';
    std::cout << std::is_bounded_array_v<int> << '\n';

}

/**
* std::to_array:
 *
*/

auto stdToArray()
{
    auto x = std::to_array("Geeks");

    auto y = std::to_array<int>({1, 2, 3, 4});

    int a[] = {1, 2, 3};

    // Returns std::array<int, 3>`
    auto z = std::to_array(a);
}


