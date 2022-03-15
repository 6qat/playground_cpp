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
#include <set>
#include <map>
#include <unordered_set>

using std::cout;
using std::string;

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

auto forEachSequence()
{
	auto print = [](int i)
	{ cout << i << ' '; };

	cout << "vector:   ";
	auto v = std::vector<int>{1, 2, 3, 4, 5, 6};
	ranges::for_each(v, print); // 1 2 3 4 5 6

	cout << "\narray:    ";
	auto a = std::array<int, 6>{1, 2, 3, 4, 5, 6};
	ranges::for_each(a, print);

	cout << "\nlist:     ";
	auto ll = std::list<int>{1, 2, 3, 4, 5, 6};
	ranges::for_each(ll, print);

	cout << "\nfwd_list: ";
	auto fl = std::forward_list<int>{1, 2, 3, 4, 5, 6};
	ranges::for_each(fl, print);

	cout << "\ndeque:    ";
	auto d = std::deque<int>{1, 2, 3, 4, 5, 6};
	ranges::for_each(d, print);
	cout << '\n';
}

auto forEachAssociative()
{

	auto print = [](int i)
	{ cout << i << ' '; };

	auto printm = [](const std::pair<string, int> &p)
	{
		cout << p.first << ":" << p.second << ' ';
	};

	cout << "set:           ";
	auto si = std::set<int>{1, 2, 3, 4, 5, 6};
	ranges::for_each(si, print);

	cout << "\nmap:           ";
	auto msi = std::map<string, int>{{"one", 1}, {"two", 2}, {"three", 3}};
	ranges::for_each(msi, printm);

	cout << "\nunordered map: ";
	std::unordered_map<string, int> umsi{{"one", 1}, {"two", 2}, {"three", 3}};
	ranges::for_each(umsi, printm);

	cout << "\nunordered set: ";
	std::unordered_set<int> usi{1, 2, 3, 4, 5, 6};
	ranges::for_each(usi, print);
	cout << '\n';

}

auto isSorted()
{
	cout << std::boolalpha;
	std::vector<int> v{1, 2, 3, 4, 5, 6, 6};
	cout << "vector:   " << ranges::is_sorted(v) << '\n';

	std::array<int, 6> a{6, 2, 3, 4, 5, 6};
	cout << "array:    " << ranges::is_sorted(a) << '\n';

}

auto filterAndTransform()
{
	std::vector<int> const vi{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	using namespace ranges;

	auto rng = vi
		| views::filter([](int i)
						{ return i % 2 == 0; })
		|
			views::transform([](int i)
							 { return std::to_string(i); });
	// prints: [2,4,6,8,10]
	cout << rng << '\n';
}

auto main() -> int
{
	hello();
	anyAllNone();
	count();
	count_if();
	find();
	forEachSequence();
	forEachAssociative();
	isSorted();
	filterAndTransform();

	exit(0);
}