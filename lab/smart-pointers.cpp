//
// Created by cesch on 3/15/2022.
//

#include <memory>

//auto notify(std::observer_ptr<> opt_e) {
//
//}

// https://www.youtube.com/watch?v=CKCR5eFVrmc
auto main() -> int {


	auto foo = std::make_unique<int>(0);
	auto val = foo.get();
//	delete &*foo;
//	delete &foo;

	return 0;
};