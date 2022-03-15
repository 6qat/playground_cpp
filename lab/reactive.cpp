//
// Created by cesch on 3/15/2022.
//

#include <rxcpp/rx.hpp>
namespace Rx
{
using namespace rxcpp;
using namespace rxcpp::sources;
using namespace rxcpp::operators;
using namespace rxcpp::util;
}
using namespace Rx;

#include <regex>
#include <random>

// https://github.com/ReactiveX/RxCpp

int main()
{
	std::random_device rd;   // non-deterministic generator
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(4, 18);

	return 0;
}
