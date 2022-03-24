#include "MainWindow.h"
#include <iostream>
#include <QApplication>

using namespace std;


auto main(int argc, char *argv[]) -> int {

	auto app = QApplication{argc, argv};
	auto w = new MainWindow{};
	w->resize(800, 600);
	w->show();

	return QApplication::exec();
}


