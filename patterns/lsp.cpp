//
// Created by cesch on 3/17/2022.
//

// Liskov Substitution Principle

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::ofstream;

class Rectangle {

protected:
	int width, height;

public:

	Rectangle(
		int width,
		int height
	) : width(width), height(height) {}

	[[nodiscard]]
	auto getWidth()
	const -> int {
		return width;
	}

	[[nodiscard]]
	auto getHeight()
	const -> int {
		return height;
	}

	auto setWidth(
		int w
	) -> void {
		width = w;
	}

	auto setHeight(
		int h
	) -> void {
		height = h;
	}

	[[nodiscard]]
	auto area()
	const -> int {
		return width * height;
	}

};

auto process(
	Rectangle &r
) -> void {
	int w = r.getWidth();
	r.setHeight(10);
}

auto main()
-> int {

	auto rect = Rectangle{1, 2};

	rect.setHeight(10);
	rect.setWidth(20);
	auto h = rect.getHeight();
	auto w = rect.getWidth();

	return 0;

}

