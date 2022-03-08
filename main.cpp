#include "mainwindow.h"
#include "lab/Lab.h"
#include <iostream>
#include <QApplication>
#include <QtQml/qqmlextensionplugin.h>
//Q_IMPORT_PLUGIN(labPlugin)

auto main(int argc, char *argv[]) -> int
{
    Lab l;
    int sum = l.sum(1, 2);
    std::cout << sum << std::endl;

    QApplication a(argc, argv);
    auto w = MainWindow();
    w.resize(800, 600);
    w.show();
    return a.exec();
}

