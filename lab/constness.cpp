//
// Created by guiga on 16/03/2022.
//

#include <iostream>

using std::cout;
using std::endl;

auto id() -> int {
	static int id = 1;
	return id++;
}

class MyClass {
private:

	int id_;
	int old_id_{};

public:

	auto use() -> void {

	}

	auto operator&&(MyClass &&other) -> MyClass {
		return MyClass{0};
	}

	friend std::ostream &operator<<(std::ostream &os, const MyClass &self) {
		os
			<< "Current id: " << self.id_
			<< ", old id: " << self.old_id_;

		return os;
	}

	//MyClass() = delete;

	explicit MyClass(int i) : id_{i} {
		cout << *this << " << Constructor >>" << endl;
	}

	MyClass(const MyClass &other) {
		old_id_ = id_;
		id_ = other.id_;
		cout << *this << " << COPY Constructor >>" << endl;
	}

	MyClass(MyClass &&other) noexcept {
		old_id_ = id_;
		id_ = other.id_;
		other.id_ = 0;
		other.old_id_ = 0;
		cout << *this << " << MOVE Constructor >>" << endl;
	}

	MyClass &operator=(const MyClass &other) {
		old_id_ = id_;
		id_ = other.id_;
		cout << *this << " << COPY Assignment >>" << endl;
		return *this;
	}

	MyClass &operator=(MyClass &&other) noexcept {
		old_id_ = id_;
		id_ = other.id_;
		other.id_ = 0;
		other.old_id_ = 0;
		cout << *this << " << MOVE Assignment >>" << endl;
		return *this;
	}

	~MyClass() {
		cout << *this << " ## Destructor ##" << endl;
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
	MyClass mc1(id());
	mc1 = foo(id());
	mc1.use();

	auto mc2 = MyClass{id()};
	return 0;
}