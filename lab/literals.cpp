//
// Created by cesch on 3/15/2022.
//

#include <cstdlib>
#include <iostream>
#include <array>
#include <range/v3/all.hpp>
#include <ranges> // std ranges

namespace rv3 = ranges::cpp20;
namespace rng = std::ranges;
using std::string;
using std::cout;

// From STL to Ranges: Using Ranges Effectively - Jeff Garland - CppCon 2019
// https://www.youtube.com/watch?v=vJ290qlAbbw

auto main() -> int
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
	rng::sort(sa);

	auto is_six = [](int i) -> bool
	{ return i == 6; };
	for (int i : rng::filter_view(colors1, is_six)){
		cout << i << " ";
	}
	cout << "\n";

	exit(0);
}