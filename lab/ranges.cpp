//
// Created by cesch on 3/14/2022.
//
#include <iostream>

// From the video: https://www.youtube.com/watch?v=3MBtLeyJKg0&t=475


// https://en.cppreference.com/w/cpp/iterator/input_iterator
// https://en.cppreference.com/w/cpp/utility/exchange
// https://en.cppreference.com/w/cpp/named_req/MoveConstructible

struct fib_generator
{
    std::size_t operator()()
    {
        auto temp = cur_;
        cur_ = std::exchange(next_, cur_ + next_);
        return temp;
    }
private:
    std::size_t cur_ = 0;
    std::size_t next_ = 1;
};

struct fib_iterator
{
    using value_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    const value_type &operator*() const
    { return cur_; }

    fib_iterator &operator++()
    {
        cur_ = std::exchange(next_, cur_ + next_);
        return *this;
    }
    void operator++(int){ ++*this; }

private:
    value_type cur_ = 0;
    value_type next_ = 1;
};

auto main() -> int
{

    // Check concept at compile time
    static_assert(std::is_integral_v<int>);
    static_assert(std::input_iterator<fib_iterator>);


    auto gen = fib_generator();

    std::cout << gen() << std::endl;
    std::cout << gen() << std::endl;
    std::cout << gen() << std::endl;
    std::cout << gen() << std::endl;
    std::cout << gen() << std::endl;

    return 0;
}