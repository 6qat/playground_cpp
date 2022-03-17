//
// Created by cesch on 3/17/2022.
//

// Single Responsibility Principle


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

struct Journal
{
	string title{};
	vector<string> entries{};

	Journal(const string &title)
		: title(title)
	{}

	auto add_entry(const string &entry)
	{
		static int count = 1;
		entries.push_back(boost::lexical_cast<string>(count++) + ": " + entry);
	}

	auto save(const string &filename)
	{
		ofstream ofs(filename);
		for (auto &e : entries)
			ofs << e << endl;
	}

};

struct PersistenceManager
{
	static auto save(const Journal &j, const string &filename)
	{
		auto ofs = ofstream{filename};
		for(auto &e: j.entries)
			ofs << e << endl;
	}
};

int main()
{
	auto journal = Journal{"Dear Diary"};
	journal.add_entry("Bla bla");
	journal.add_entry("Ble ble");
	journal.add_entry("Bli bli");

//	auto pm = PersistenceManager{};
	PersistenceManager::save(journal, "my_file.txt");

	//getchar();
	return 0;
}


