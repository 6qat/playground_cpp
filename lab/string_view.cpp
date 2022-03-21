//
// Created by cesch on 3/21/2022.
//

#include <string_view>
#include <iostream>

int main() {

	using std::cout;
	using std::endl;

	auto hello = std::string_view{"hello"};
	auto str = std::string{"hello"};
	auto str2 = std::string_view{str};
	auto str3 = std::string_view{str2};
	auto str4 = "";

	cout << hello << str << str2 << str3  << endl;

	return 0;
}
