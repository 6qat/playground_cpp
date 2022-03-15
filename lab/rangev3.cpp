//
// Created by cesch on 3/14/2022.
//
#include <string>
#include <iostream>
#include <range/v3/all.hpp>
#include <vector>
#include <list>
#include <array>
#include <deque>
#include <forward_list>

using std::cout;

auto hello()
{
	std::string s{"hello"};

	// output: h e l l o
	ranges::for_each(s, [](char c)
	{ cout << c << ' '; });
	cout << '\n';
};

auto is_six = [](int i)
{ return i == 6; };

auto anyAllNone()
{
	std::vector<int> v{6, 2, 3, 4, 5, 6};

	cout << std::boolalpha; // https://en.cppreference.com/w/cpp/io/manip/boolalpha

	cout << "vector: " << ranges::views::all(v) << '\n';
	cout << "vector any_of is_six: " << ranges::any_of(v, is_six) << '\n';
	cout << "vector all_of is_six: " << ranges::all_of(v, is_six) << '\n';
	cout << "vector none_of is_six: " << ranges::none_of(v, is_six) << '\n';

	cout << std::noboolalpha;
}

auto count()
{
	auto v = std::vector<int>{6, 2, 3, 4, 5, 6};
	// note the count return is a numeric type
	// like int or long -- auto below make sure
	// it matches the implementation
	auto c = ranges::count(v, 9);
	cout << "vector:   " << c << '\n';

	auto a = std::array<int, 6>{6, 2, 3, 4, 5, 6};
	c = ranges::count(a, 3);
	cout << "array:    " << c << '\n';
}

auto count_if()
{
	std::vector<int> v{6, 2, 3, 4, 5, 6};
	auto c = ranges::count_if(v, is_six);
	cout << "vector:   " << c << '\n'; // 2

	std::array<int, 6> a{6, 2, 3, 4, 5, 6};
	c = ranges::count_if(a, is_six);
	cout << "array:    " << c << '\n'; // 2
}

auto find()
{
	cout << "vector:   ";

	std::vector<int> v{6, 2, 6, 4, 6, 1};
	{
		auto i = ranges::find(v, 6); // 1 2 3 4 5 6
		cout << "*i: " << *i << '\n';
	}
	{
		auto i = ranges::find(v, 10); // 1 2 3 4 5 6
		if (i == ranges::end(v)) {
			cout << "didn't find 10\n";
		}
	}
	{
		auto i = ranges::find_if(v, is_six);
		if (i != ranges::end(v)) {
			cout << "*i: " << *i << '\n';
		}
	}
	{
		auto i = ranges::find_if_not(v, is_six);
		if (i != ranges::end(v)) {
			cout << "*i: " << *i << '\n';
		}
	}
	{
		auto i = ranges::find(v, 6);
		i++;
		if (i != ranges::end(v)) {
			cout << "*i after ++ (2 expected): " << *i;
		}
	}

	cout << "\narray:    ";

	std::array<int, 6> a{6, 2, 3, 4, 5, 1};
	{
		auto i = ranges::find(a, 6);
		if (i != ranges::end(a)) {
			cout << "*i: " << *i;
		}
	}
	cout << "\nlist:     ";

	std::list<int> li{6, 2, 3, 4, 5, 1};
	{
		auto i = ranges::find(li, 6);
		if (i != ranges::end(li)) {
			cout << "*i: " << *i;
		}
	}

	cout << "\nfwd_list: ";

	std::forward_list<int> fl{6, 2, 3, 4, 5, 1};
	{
		auto i = ranges::find(fl, 4);
		if (i != ranges::end(fl)) {
			cout << "*i: " << *i;
		}
	}
	cout << "\ndeque:    ";

	std::deque<int> d{6, 2, 3, 4, 5, 1};
	{
		auto i = ranges::find(d, 6);
		if (i != ranges::end(d)) {
			cout << "*i: " << *i;
		}
	}
	cout << '\n';
}

auto main() -> int
{
	hello();
	anyAllNone();
	count();
	count_if();
	find();

	exit(0);
}