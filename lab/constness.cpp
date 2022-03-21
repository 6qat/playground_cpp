//
// Created by guiga on 16/03/2022.
//

#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;

class MyClass {
private:

	int id_;
	int old_id_{};

public:

	MyClass() = delete;

	explicit MyClass(int i) : id_{i} {
		cout << "Current id: " << i << ", old id: " << old_id_ << " << Constructor >>" << endl;
	}

	MyClass(const MyClass &other) {
		old_id_ = id_;
		id_ = other.id_;
		cout << "Current id: " << id_ << ", old id: " << old_id_ << " << COPY constructor >>" << endl;
	}

	MyClass(MyClass &&other) noexcept {
		old_id_ = id_;
		id_ = other.id_;
		cout << "Current id: " << id_ << ", old id: " << old_id_ << " << MOVE constructor >>" << endl;
	}

	MyClass &operator=(const MyClass &other) {
		old_id_ = id_;
		id_ = other.id_;
		cout << "Current id: " << id_ << ", old id: " << old_id_ << " << COPY assignment >>" << endl;
		return *this;
	}

	MyClass &operator=(MyClass &&other) noexcept {
		old_id_ = id_;
		id_ = other.id_;
		cout << "Current id: " << id_ << ", old id: " << old_id_ << " << MOVE assignment >>" << endl;
		return *this;
	}

	~MyClass() {
		cout << "Current id: " << id_ << ", old id: " << old_id_ << " >> Destructor <<" << endl;
	}
};

MyClass foo(int i) {
	MyClass ret(i);
	return ret;
}

const MyClass const_foo(int i) {
	MyClass ret(i);
	return ret;
}

int main() {
	MyClass mc1(1);
	mc1 = foo(2);


	return 0;
}