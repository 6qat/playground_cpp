#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>

class MainWindow: public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    auto createMenus() -> void;
    auto createToolBars() -> void;

private:
    QAction * newAct;
    QAction * quitAct;

protected:
    void mousePressEvent(QMouseEvent *event) override {

    }

    void closeEvent(QCloseEvent *event) override {
        std::cout << "<< CloseEvent >>" << std::endl;
    }

};
#endif // MAINWINDOW_H
