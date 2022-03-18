//
// Created by cesch on 3/18/2022.
//

// ==================================================================================================
//  Dependence Inversion Principle:

// 	- 	High-level modules should not depend on low-level modules. Both should depend on abstractions
//  -	Abstractions should not depend on details. Details should depend on abstractions
// ==================================================================================================

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::tuple;
using std::cout;
using std::endl;
using std::ofstream;

/**
 * - Enum classes - enumerator names are local to the enum and their values do not implicitly convert
 * to other types (like another enum or int).
 *
 * - Plain enums - where enumerator names are in the same scope as the enum and their values
 * implicitly convert to integers and other types
 *
 */

enum class RelationShip {
	parent,
	child,
	sibling,
};

struct Person {
	string name;
};

struct RelationShips { // low-level
	vector<tuple<Person, RelationShip, Person>> relations;
	void add_parent_and_child(const Person &parent, const Person &child) {
		relations.emplace_back(parent, RelationShip::parent, child);
		relations.emplace_back(child, RelationShip::child, parent);
	}
};

struct Research { // high-level
	explicit Research(RelationShips &relationShips) {
		auto &relations = relationShips.relations;
		for (auto &&[first, rel, second] : relations) {

		}
	}
};

int main() {

	Person parent{"John"};
	Person child1{"Chris"}, child2{"Matt"};
	RelationShips relationShips;
	relationShips.add_parent_and_child(parent, child1);
	relationShips.add_parent_and_child(parent, child2);


	return 0;
}