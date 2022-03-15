//
// Created by cesch on 3/15/2022.
//

#include <cstdlib>
#include <iostream>
#include <array>
#include <range/v3/all.hpp>
#include <ranges> // std ranges
#include <boost/container/flat_map.hpp>

namespace rv3 = ranges::cpp20;
namespace rng = std::ranges;
using std::string, std::cout, boost::container::flat_map;

// From STL to Ranges: Using Ranges Effectively - Jeff Garland - CppCon 2019
// https://www.youtube.com/watch?v=vJ290qlAbbw

auto lab()
{

	auto num1 = new const int{42};
	const auto num2{10u};

	static auto colors1 = std::array<int, 5>{3, 2, 1, 8, 6};
	static const auto colors2 = std::array<string, 3>{};

	auto sa = std::array{string{"ble ble"}, string{"bla bla"}};

//	colors1[0] = 1;
//	colors2[0] = 1;

	auto colors3 = rng::sort(colors1);

	std::sort(colors1.begin(), colors1.end());
	rv3::sort(sa);

	auto is_six = [](int i) -> bool
	{ return i == 6; };
	for (int i : rng::filter_view(colors1, is_six)) {
		cout << i << " ";
	}
	cout << "\n";
}

auto flatMapExample()
{
	flat_map<string, int> fm;
	fm["world"] = 2;
	fm["hello"] = 1;

	for (auto[k, v] : rng::reverse_view{fm}) {
		cout << k << ":" << v << "\n";
	}
}

auto filterView()
{
	auto v = std::vector{0, 1, 2, 3, 5, 6, 7, 8, 9};
	auto is_even = [](int i)
	{
		return 0 == i % 2;
	};

	auto evens = rng::filter_view{v, is_even};
	for (int i : evens) {
		cout << i << " ";
	}
	cout << "\n";
	for (int i : rng::filter_view{v, is_even}) {
		cout << i << " ";
	}
	cout << "\n";
	for (int i :  v | rng::views::filter(is_even)) {
		cout << i << " ";
	}

}

auto main() -> int
{
	flatMapExample();
	filterView();

	exit(0);
}