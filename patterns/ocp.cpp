//
// Created by cesch on 3/17/2022.
//

// Open-Closed Principle

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <boost/lexical_cast.hpp>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::ofstream;

enum class Color
{
	red, green, blue
};
enum class Size
{
	small, medium, large
};

struct Product
{
	string name;
	Color color;
	Size size;
};

struct ProductFilter
{
	static auto by_color(const vector<Product *> &items, Color color) -> vector<Product *>
	{
		auto result = vector<Product *>{};

		for (auto i : items)
			if (i->color == color)
				result.push_back(i);

		return result;
	}
};

int main()
{
	auto apple = Product{"Apple", Color::green, Size::small};
	auto tree = Product{"Tree", Color::green, Size::large};
	auto house = Product{"Hose", Color::blue, Size::large};

	auto items = vector<Product *>{&apple, &tree, &house};

	for (auto p : ProductFilter::by_color(items, Color::green))
		cout << p->name << endl;

	return 0;
}