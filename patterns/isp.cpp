//
// Created by cesch on 3/17/2022.
//

// Interface Segregation Principle

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::ofstream;

struct Document;

//struct IMachine {
//	virtual void print(Document &doc) = 0;
//	virtual void scan(Document &doc) = 0;
//	virtual void fax(Document &doc) = 0;
//};
//
//struct MFP: IMachine {
//	void print(Document &doc) override {
//
//	}
//	void scan(Document &doc) override {
//
//	}
//	void fax(Document &doc) override {
//
//	}
//};

struct IPrinter {
	virtual void print(Document &doc) = 0;
};
struct Printer: IPrinter {
	void print(Document &doc) override {

	}
};
struct IScanner {
	virtual void scan(Document &doc) = 0;
};
struct IFax {
	virtual void fax(Document &doc) = 0;
};
struct IMachine: IPrinter, IScanner {};

struct Machine: IMachine {
	IPrinter &printer;
	IScanner &scanner;

	Machine(IPrinter &printer, IScanner &scanner)
		: printer(printer), scanner(scanner) {}

	void print(Document &doc) override {
		printer.print(doc);
	}
	void scan(Document &doc) override {
		scanner.scan(doc);
	}
};

int main() {

	return 0;

}