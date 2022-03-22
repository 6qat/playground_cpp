#include "MainWindow.h"
#include "lab/Lab.h"
#include <iostream>
#include <QApplication>
#include <QtQml/qqmlextensionplugin.h>
#include <chrono>
#include <ctime>
#include <iomanip>

//#include <boost/chrono.hpp>
//#include "toml.hpp"

//#include <range/v3/all.hpp> // get everything
//#include "argparse/argparse.hpp" // https://github.com/p-ranav/argparse
//Q_IMPORT_PLUGIN(labPlugin)

auto createApplication(int &argc, char *argv[])
-> std::variant<std::unique_ptr<QCoreApplication>, std::unique_ptr<QApplication>> {

	for (int i = 1; i < argc; ++i) {
		if (!qstrcmp(argv[i], "-no-gui"))
			//return new QCoreApplication(argc, argv);
			return std::make_unique<QCoreApplication>(argc, argv);
	}


	return std::make_unique<QApplication>(argc, argv);

}

auto main(int argc, char *argv[]) -> int {

	auto app = createApplication(argc, argv);

	if (std::get<std::unique_ptr<QApplication>>(app)) {

		auto w = new MainWindow();
		w->resize(800, 600);
		w->show();
		return std::get<std::unique_ptr<QApplication>>(app)->exec();

	}
	else {

		std::cout << "No GUI" << std::endl;
		return std::get<std::unique_ptr<QCoreApplication>>(app)->exec();

	}

}

auto fibonacci(unsigned n) -> long {
	if (n < 2) return n;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

auto calendarTimeZoneLibrary() {

	using namespace std::chrono;
	using namespace std;

	auto date1 = 2020y / September / 8;
	auto date2 = 21d / October / 2018;
	auto date3 = January / 27d / 2019;

	cout << date1 << endl << date2 << endl << date3 << endl;

	auto mil = milliseconds(1000);
	mil = mil * 60;

	cout << "duration (in periods): ";
	cout << mil.count() << " milliseconds.\n";
	cout << "duration (in seconds): ";
	cout << (mil.count() * milliseconds::period::num / milliseconds::period::den);
	cout << " seconds.\n";

	time_point<system_clock> start, end;
	start = system_clock::now();
	cout << "f(42) = " << fibonacci(42) << '\n';
	end = std::chrono::system_clock::now();

	duration<double> elapsed_seconds = end - start;
	time_t end_time = system_clock::to_time_t(end);

	cout << "finished computation at " << std::put_time(std::localtime(&end_time), "%c %Z")
		 << "elapsed time: " << elapsed_seconds.count() << "s\n";

}

