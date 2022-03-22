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
using namespace std;

auto createApplication(int &argc, char *argv[])
-> variant<unique_ptr<QApplication>,
		   unique_ptr<QCoreApplication> > {

	for (int i = 1; i < argc; ++i) {
		if (!qstrcmp(argv[i], "-no-gui"))
			return make_unique<QCoreApplication>(argc, argv);
	}

	return make_unique<QApplication>(argc, argv);
}

auto main(int argc, char *argv[]) -> int {


	auto app = createApplication(argc, argv);

	if (app.index() == 0) {

		auto w = new MainWindow();
		w->resize(800, 600);
		w->show();
		return get<unique_ptr<QApplication>>(app)->exec();

	}
	else if (app.index() == 1) {

		std::cout << "No GUI" << std::endl;
		return get<unique_ptr<QCoreApplication>>(app)->exec();

	}
	else return 0;

}


