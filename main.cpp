#include "mainwindow.h"
#include "lab/Lab.h"
#include <iostream>
#include <QApplication>
#include <QtQml/qqmlextensionplugin.h>
//Q_IMPORT_PLUGIN(labPlugin)

auto main(int argc, char *argv[]) -> int
{
    int sum = Lab::sum(1, 2);
    qDebug() << sum;

    auto a = QApplication(argc, argv);
    auto w = MainWindow();
    w.resize(800, 600);
    w.show();
    return QApplication::exec();
}

