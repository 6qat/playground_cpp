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

enum class Color {
	red, green, blue
};
enum class Size {
	small, medium, large
};

struct Product {
	string name;
	Color color;
	Size size;
};

struct ProductFilter {

	static auto by_color(
		const vector<Product *> &items,
		Color color
	) -> vector<Product *> {

		auto result = vector<Product *>{};

		for (auto i : items)
			if (i->color == color)
				result.push_back(i);

		return result;
	}

	static auto by_size(
		const vector<Product *> &items,
		Size size
	) -> vector<Product *> {

		auto result = vector<Product *>{};

		for (auto i : items)
			if (i->size == size)
				result.push_back(i);

		return result;

	}

	static auto by_size_and_color(
		const vector<Product *> &items,
		Size size, Color color
	) -> vector<Product *> {

		auto result = vector<Product *>{};

		for (auto i : items)
			if (i->size == size && i->color == color)
				result.push_back(i);

		return result;

	}
};

template <typename T>
struct AndSpecification;

template<typename T>
struct Specification {

	virtual auto is_satisfied(
		T *item
	) -> bool = 0;

	AndSpecification<T> operator&&(Specification<T> &&other) {
		return AndSpecification{*this, other};
	}

};

template<typename T>
struct Filter {

	virtual auto filter(
		vector<T *> items,
		Specification<T> &spec
	) -> vector<T *> = 0;

};

struct BetterFilter
	: Filter<Product> {

	auto filter(
		vector<Product *> items,
		Specification<Product> &spec
	) -> vector<Product *> override {

		auto result = vector<Product *>{};

		for (auto item : items)
			if (spec.is_satisfied(item))
				result.push_back(item);

		return result;
	}

};

struct ColorSpecification
	: Specification<Product> {

	Color color;

	explicit ColorSpecification(
		Color color
	) : color(color) {}

	auto is_satisfied(
		Product *item
	) -> bool override {
		return item->color == color;
	}

};

struct SizeSpecification
	: Specification<Product> {

	Size size;

	explicit SizeSpecification(
		Size size
	) : size(size) {}

	auto is_satisfied(
		Product *item
	) -> bool override {
		return item->size == size;
	}

};

template<typename T>
struct AndSpecification
	: Specification<T> {

	Specification<T> &first;
	Specification<T> &second;

	AndSpecification(
		Specification<T> &first,
		Specification<T> &second
	) : first(first), second(second) {}

	auto is_satisfied(
		T *item
	) -> bool override {
		return first.is_satisfied(item) && second.is_satisfied(item);
	}

};

int main() {

	auto apple = Product{"Apple", Color::green, Size::small};
	auto tree = Product{"Tree", Color::green, Size::large};
	auto house = Product{"Hose", Color::blue, Size::large};

	auto items = vector<Product *>{&apple, &tree, &house};

	// Old way (using BetterFilter)
	for (auto p : ProductFilter::by_color(items, Color::green))
		cout << p->name << endl;

	// OCP Way
	auto green = ColorSpecification{Color::green};
	for (auto p : BetterFilter{}.filter(items, green))
		cout << p->name << endl;

	auto small = SizeSpecification{Size::small};
	for (auto p : BetterFilter{}.filter(items, small))
		cout << p->name << endl;

	auto smallAndGreen = AndSpecification{small, green};
	for (auto p : BetterFilter{}.filter(items, smallAndGreen))
		cout << p->name << endl;

	auto largeAndBlue = ColorSpecification{Color::blue} && SizeSpecification{Size::large};
	for(auto p :BetterFilter{}.filter(items, largeAndBlue))
		cout << p->name << endl;


	return 0;
	}