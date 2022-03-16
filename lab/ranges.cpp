//
// Created by cesch on 3/14/2022.
//
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>
#include <concepts>
#include <algorithm>
#include <optional>

//import std.core;

// From the video: https://www.youtube.com/watch?v=3MBtLeyJKg0&t=475


// https://en.cppreference.com/w/cpp/iterator/input_iterator
// https://en.cppreference.com/w/cpp/utility/exchange
// https://en.cppreference.com/w/cpp/named_req/MoveConstructible
// https://en.cppreference.com/w/cpp/language/operators

//template<class F, class I>
//concept indirect_unary_predicate =
//std::indirectly_readable<I> &&
//	std::copy_constructible<F> &&
//	std::predicate<F &, std::iter_value_t<I> &> &&
//	std::predicate<F &, std::iter_reference_t<I>> &&
//	std::predicate<F &, std::iter_common_reference_t<I>>;

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
	using iterator_category = std::forward_iterator_tag;

	const value_type &operator*() const
	{
		return cur_;
	}

	fib_iterator &operator++()
	{
		cur_ = std::exchange(next_, cur_ + next_);
		return *this;
	}

	fib_iterator operator++(int i)
	{
		auto temp = *this;
		++*this;
		return temp;
	}

	bool operator==(const fib_iterator &) const = default;

private:
	value_type cur_ = 0;
	value_type next_ = 1;
};

namespace views
{
constexpr auto fibonacci = std::ranges::subrange<fib_iterator, std::unreachable_sentinel_t>{};
}

auto fibfun(int n, int k)
{

	auto view = views::fibonacci
		| std::views::filter([k](auto i)
							 { return i % k == 0; })
		| std::views::take(n);

	std::ranges::copy(view, std::ostream_iterator<std::size_t>(std::cout, " ,"));

}


auto is_space = [] (const int t) {
    return std::isspace(t);
};

inline constexpr auto trim_front = std::ranges::views::drop_while(is_space);

inline constexpr auto trim_back =
	std::views::reverse
		| trim_front
		| std::views::reverse;
//inline constexpr auto trim_back2 = drop_last_while(std::isspace);

inline constexpr auto trim = trim_front | trim_back;

template<std::ranges::view  V, typename Pred> requires std::ranges::bidirectional_range<V> &&
	std::indirect_unary_predicate<Pred, std::ranges::iterator_t<V>>
class drop_last_while_view
	: public std::ranges::view_interface<drop_last_while_view<V, Pred>>
{
	V base_;
	Pred pred_;
	std::optional<std::ranges::iterator_t<V>> cached_end_;

public:
	drop_last_while_view() = default;

	drop_last_while_view(V base, Pred pred)
		: base_(std::move(base)),
		  pred_(std::move(pred))
	{}

	auto begin()
	{
		return std::ranges::begin(base_);
	}

	auto end()
	{
		if (!cached_end_) {
			cached_end_ = std::ranges::find_if_not(std::ranges::rbegin(base_),
												   std::ranges::rend(base_),
												   pred_).base();
		}
		return *cached_end_;

	}

	// https://d.pr/i/0Gp60u

};

auto main() -> int
{
	// Check concept at compile time
	static_assert(std::is_integral_v<int>);
	static_assert(std::input_iterator<fib_iterator>);
//	static_assert(std::is_move_constructible_v<QString>);
	//static_assert(std::is_move_constructible_v<QObject>);
	//static_assert(std::is_move_constructible_v<QWidget>);

	auto gen = fib_generator();

	std::cout << gen.operator()() << std::endl;
	std::cout << gen() << std::endl;
	std::cout << gen() << std::endl;
	std::cout << gen() << std::endl;
	std::cout << gen() << std::endl;

	auto iter = fib_iterator();
	iter.operator++(10);
	iter.operator++();
	auto i = *iter;
	iter++;

	fibfun(5, 3);

	return 0;
}